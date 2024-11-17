#include <stdio.h>
#include <string.h> // För att modifiera strängar
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "../include/sorting.h"

int sortType = 0;

int main(void)
{

    // Seed RNG
    srand(time(0));

    int numberOfElements = 10;
    int elementSize = 100;  // Numbers will be between 0 and 100
    int sort = 0;

    sortingAlgoritmSpeedTest();

    createRandomArray(numberOfElements, elementSize, sort);
    return 0;
}

void sortingAlgoritmSpeedTest(){
    
}