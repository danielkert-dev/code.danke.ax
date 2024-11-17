#include <stdio.h>
#include <stdlib.h>

#include "../include/sorting.h"

// Bubble Sort
void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j+1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int* array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        // Move elements that are greater than key to one position ahead
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Quick Sort Helper Function: Partition
int partition(int* array, int low, int high) {
    int pivot = array[high];  // Pivot element
    int i = low - 1;          // Index of smaller element

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            // Swap array[i] and array[j]
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // Swap array[i+1] and array[high] (pivot)
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}

// Quick Sort Wrapper Function
void quickSortHelper(int* array, int low, int high);

void quickSort(int* array, int size) {
    quickSortHelper(array, 0, size - 1);
}

void quickSortHelper(int* array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        // Recursively sort elements before and after partition
        quickSortHelper(array, low, pi - 1);
        quickSortHelper(array, pi + 1, high);
    }
}

// Merge Sort Helper Function: Merge
void merge(int* array, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Allocate memory for temporary arrays
    int* leftArray = (int*)malloc(n1 * sizeof(int));
    int* rightArray = (int*)malloc(n2 * sizeof(int));

    if (leftArray == NULL || rightArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = array[mid + 1 + i];

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArray
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArray
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    // Free dynamically allocated memory
    free(leftArray);
    free(rightArray);
}

// Merge Sort Wrapper Function
void mergeSortHelper(int* array, int left, int right);

void mergeSort(int* array, int size) {
    mergeSortHelper(array, 0, size - 1);
}

void mergeSortHelper(int* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort both halves
        mergeSortHelper(array, left, mid);
        mergeSortHelper(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}
