#include <stdio.h>
#include <stdbool.h>
#include "../include/utils.h"
#include "../include/ui.h"
#include "../include/observations.h"
#include "../include/datatypes.h"

int main(void)
{

    Observation observations[100];
    int observationAmount = 0;
    
    addPredefinedObservations(observations, &observationAmount);

    bool running = true;

    do
    {
        choicesMainMenu();
        int mainMenuChoice = getChoice(5);

        switch (mainMenuChoice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            printObservations(observations, observationAmount);
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