#ifndef CSCI499_MERGESORT_H
#define CSCI499_MERGESORT_H

#include <string>

// Gets random int array of size n, whose values are in [0, 99].
int* GetRandomInput(int n);

// Parses int array from a string, assuming the integers are
// separated by a single white space. Returns nullptr if the
// input string is invalid.
int* ParseInput(std::string str, int n);

// Sorts an int array inplace.
void MergeSort(int* arr, int n);

#endif //CSCI499_MERGESORT_H
