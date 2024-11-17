#include <stdio.h>
#include <stdlib.h>

#include "../include/datatypes.h"


int getChoice(int max)
{
    int choice = 0;

    do
    {
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');
        } else {
            if (choice < 1 || choice > max)
            {
                printf("Invalid choice. Try again.\n");
            }
        }

    } while (choice < 1 || choice > max);

    return choice;
}

void clearScreen(void) {
    system("cls"); // Windows
    system("clear"); // UNIX/Linux
}