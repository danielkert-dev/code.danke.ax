#ifndef UTILS_H
#define UTILS_H

// Tests different sorting algorithms by testing their speed sorting integer arrays
void sortingalgoritmSpeedTest();

// Returns a random number
int RNG();

// Creates integer arrays
// First number decides amount of elements
// Second number decides how large the individual integers should be
// Third number decides if the array should be sorted
void createRandomArray(int numberOfElements, int elementSize, _Bool sort);

// Sorts integer array with bubble sort
void bubbleSort();

// Sorts integer array with insertion sort
void insertionSort();

// Sorts integer array with quick sort
void quickSort();

// Sorts integer array with merge sort
void mergeSort();

#endif