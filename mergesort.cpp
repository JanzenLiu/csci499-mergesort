#include "mergesort.h"

#include <stdlib.h>

#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

int* GetRandomInput(int n) {
    int* arr = reinterpret_cast<int*>(malloc(n * sizeof(int)));
    if (arr == nullptr) { return arr; }
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }
    return arr;
}

int* ParseInput(std::string str, int n) {
    int* arr = reinterpret_cast<int*>(malloc(n * sizeof(int)));
    if (arr == nullptr) {
        std::cerr << "Failed to allocate memory." << std::endl;
        exit(1);
    }

    int i = 0;  // The i-th (starting from 0) number to be parsed.
    int index = 0;  // The index of the next character in the string.
    while (index < str.length()) {
        if (i >= n)
            break;
        // Check whether the number is negative.
        bool negative = false;
        if (str[index] == '-') {
            negative = true;
            ++index;
            if (index == str.length() || !isdigit(str[index])) {
                return nullptr;
            }
        }
        // Parse number digit by digit.
        int num = 0;
        while (index < str.length() && str[index] != ' ') {
            char c = str[index];
            if (!isdigit(c)) {
                return nullptr;
            }
            num *= 10;
            num += (str[index] - '0');
            ++index;
        }
        arr[i++] = negative? -num:num;
        ++index;  // Pass the white space, assuming there is only one between two adjacent numbers.
    }
    // Set missing numbers, if any, to zeros.
    if(i < n) {
        memset(arr + i, 0, (n - i) * sizeof(int));
    }
    return arr;
}

void MergeSort(int* arr, int n) {
    // Handle corner cases: n <= 2.
    if (n <= 1) return;
    if (n == 2) {
        if (arr[0] > arr[1]) std::swap(arr[0], arr[1]);
        return;
    }

    // Sort the left and right half respectively.
    int leftSize = n/2, rightSize = (n+1) / 2;
    MergeSort(arr, leftSize);
    MergeSort(arr+leftSize, rightSize);

    // Merge the two halves.
    int* buf = reinterpret_cast<int*>(malloc(n * sizeof(int)));
    for (int left = 0, right = leftSize, i = 0; i < n; ++i) {
        if (right == n || (left < leftSize && arr[left] < arr[right]))
            buf[i] = arr[left++];
        else
            buf[i] = arr[right++];
    }

    // Copy the merged result back so that we can free the allocated memory
    memcpy(arr, buf, n * sizeof(int));
    free(buf);
}