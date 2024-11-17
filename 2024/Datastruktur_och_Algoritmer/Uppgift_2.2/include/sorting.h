#ifndef SORTING_H
#define SORTING_H

// Tests different sorting algorithms by testing their speed sorting integer arrays
void sortingAlgoritmSpeedTest();

// Returns a random number
int RNG(int min, int max);

// Creates integer arrays
// First number decides amount of elements
// Second number decides how large the individual integers should be
// Third number decides if the array should be sorted
void createRandomArray(int numberOfElements, int elementSize, int sort);

// Sorts integer array with bubble sort
void bubbleSort(int* array, int size);

// Sorts integer array with insertion sort
void insertionSort(int* array, int size);

// Sorts integer array with quick sort
void quickSort(int* array, int size);

// Sorts integer array with merge sort
void mergeSort(int* array, int size);

#endif