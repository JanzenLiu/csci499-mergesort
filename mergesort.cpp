#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::swap;

// get random int array of size n, whose values are in [0, 99]
int* getRandomInput(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i){
        arr[i] = rand() % 100;
    }
    return arr;
}

void printArray(int* arr, int size) {
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int* arr, int n) {
    // corner cases: n is 1 or 2
    if(n == 1) return;
    if(n == 2) {
        if(arr[0] > arr[1]) swap(arr[0], arr[1]);
        return;
    }

    // sort the left and right half respectively
    int leftSize = n/2, rightSize = (n+1) / 2;
    mergeSort(arr, leftSize);
    mergeSort(arr+leftSize, rightSize);

    // merge the two halves
    int* buf = (int*)malloc(n * sizeof(int));
    for(int left = 0, right = leftSize, i = 0; i < n; ++i){
        if(right == n || (left < leftSize && arr[left] < arr[right]))
            buf[i] = arr[left++];
        else
            buf[i] = arr[right++];
    }

    // copy the merged result back so that we can free the allocated memory
    memcpy(arr, buf, n * sizeof(int));
    free(buf);
}

int main() {
    int n = 20;
    int* arr = getRandomInput(n);

    cout << "input : ";
    printArray(arr, n);

    mergeSort(arr, n);
    cout << "ouptut: ";
    printArray(arr, n);

    free(arr);
    return 0;
}
