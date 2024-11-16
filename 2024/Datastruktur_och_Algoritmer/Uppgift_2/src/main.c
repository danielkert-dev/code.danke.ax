#include <stdio.h>
#include <stdbool.h>
#include "../include/utils.h"
#include "../include/ui.h"

int main(void)
{

    bool running = true;

    do
    {
        clearScreen();
        choicesMainMenu();
        int mainMenuChoice = getChoice(5);

        switch (mainMenuChoice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            running = false;
            break;
        default:
            break;
        }


    } while (running);

    return 0;
}