#include <stdio.h>
#include <stdlib.h>

int getChoice(int max)
{
    printf("Enter choice: ");
    int choice = 0;

    do
    {
        printf("Invalid choice. Please enter a number between 1 and %d: ", max);
        scanf("%d", &choice);
        while (getchar() != '\n');
    } while (choice < 1 || choice > max);

    return choice;
}

void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
