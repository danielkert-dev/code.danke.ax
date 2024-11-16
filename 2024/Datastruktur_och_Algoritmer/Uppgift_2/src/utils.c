#include <stdio.h>

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

void clearScreen(void)
{
    printf("\e[1;1H\e[2J");
}