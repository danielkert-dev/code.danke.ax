#include <stdio.h>

#include "../include/datatypes.h"

void choicesMainMenu(void) {
printf("-----------------------\n");
printf("1. Add observations\n");
printf("2. Delete observations\n");
printf("3. List all observations\n");
printf("4. Search observations\n");
printf("5. Exit program\n");
printf("-----------------------\n");      
}

void printObservations(Observation *observations, int observationAmount)
{
    printf("Current observations: %d\n", observationAmount);
    printf("\033[43m\033[30m");

    char classification[50] = "";

    for (int i = 0; i < observationAmount; i++)
    {
        switch (observations[i].data.classification){
            case 0:
                strcpy(classification, "Safe");
                break;
            case 1:
                strcpy(classification, "Keter");
                break;
            case 2:
                strcpy(classification, "Euclid");
                break;
        }
        printf("-----------------------------\n");
        printf("-- Observation %d\n", i + 1);
        printf("-- Name: SCP-%d\n", observations[i].data.name);
        printf("-- Date: %d/%d/%d\n", observations[i].timeStamp.date.day, observations[i].timeStamp.date.month, observations[i].timeStamp.date.year);
        printf("-- Time: %d:%d:%d\n", observations[i].timeStamp.time.hour, observations[i].timeStamp.time.minute, observations[i].timeStamp.time.second);
        printf("-- Classification: %s\n", classification);
        printf("-- Place: %s\n", observations[i].data.place);
        printf("-- Description: %s\n", observations[i].data.description);
    }
    printf("\033[0m");
    printf("\n");

}