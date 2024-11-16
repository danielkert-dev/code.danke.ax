#include <stdio.h>
#include <string.h> // För att modifiera strängar
#include <stdbool.h>
#include "../include/utils.h"

int sortType = 0;

int main(void)
{

    // Seed RNG
    srand(time(0));

    sortingalgoritmSpeedTest();
    return 0;
}