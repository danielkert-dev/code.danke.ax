#include "../include/sorting.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Random number generator
int RNG(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Create a random array filled with integers
void createRandomArray(int numberOfElements, int elementSize, int sort) {
    // Allocate enough memory for the array
    int* array = (int*)malloc(numberOfElements * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Create array and add random numbers
    for (int i = 0; i < numberOfElements; i++) {
        array[i] = RNG(0, elementSize);
    }

    // Sort the array if 'sort' is true
    if (sort) {
        mergeSort(array, numberOfElements);
    }

    /* Print the array
    printf("Generated array:\n");
    for (int i = 0; i < numberOfElements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    */
}