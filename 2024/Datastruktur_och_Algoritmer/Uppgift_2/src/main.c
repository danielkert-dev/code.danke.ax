#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../include/utils.h"
#include "../include/datatypes.h"

// Function to increase the array size
void changeObservationsSizeByMultibleOf3(Observation **observations, int *currentSize, int observationAmount, bool increaseOrDecrease) {

    int newSize = 0;

    if (increaseOrDecrease) {
        newSize = observationAmount + (3 - (observationAmount % 3)); // Add enough to make it a multiple of 3
    } else {
        newSize = observationAmount - (observationAmount % 3);
    }

    // If the new size is smaller than the current size, it means we are not increasing the array, so don't do anything
    if (newSize <= *currentSize) {
        return;
    }

    // Allocate new memory for the increased size
    Observation *newObservations = realloc(*observations, sizeof(Observation) * newSize);
    
    if (newObservations == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Update the observations pointer to point to the new memory
    *observations = newObservations;
    
    // Update the current size
    *currentSize = newSize;
}


void addObservation(Observation **observations, int *observationSize, int *observationAmount) {
    if (*observationAmount >= *observationSize) {
        changeObservationsSizeByMultibleOf3(observations, observationSize, *observationAmount + 1, true);
    }

    printf("Enter observation name (number): ");
    scanf("%d", &(*observations)[*observationAmount].data.name);
    printf("Enter classification (0-2): ");
    scanf("%d", &(*observations)[*observationAmount].data.classification);
    printf("Enter place (text): ");
    getchar(); // Consume the newline character left by scanf
    fgets((*observations)[*observationAmount].data.place, 100, stdin);
    (*observations)[*observationAmount].data.place[strcspn((*observations)[*observationAmount].data.place, "\n")] = '\0'; // Remove newline

    printf("Enter description: ");
    fgets((*observations)[*observationAmount].data.description, 500, stdin);
    (*observations)[*observationAmount].data.description[strcspn((*observations)[*observationAmount].data.description, "\n")] = '\0'; // Remove newline

    printf("Enter observation date (day month year): ");
    scanf("%d %d %d", &(*observations)[*observationAmount].timeStamp.date.day, &(*observations)[*observationAmount].timeStamp.date.month, &(*observations)[*observationAmount].timeStamp.date.year);

    printf("Enter observation time (hour minute second): ");
    scanf("%d %d %d", &(*observations)[*observationAmount].timeStamp.time.hour, &(*observations)[*observationAmount].timeStamp.time.minute, &(*observations)[*observationAmount].timeStamp.time.second);

    (*observationAmount)++;
}


void deleteObservation(Observation *observations, int *observationSize, int *observationAmount, int name) {
    int index = -1;

    // Locate the observation to delete
    for (int i = 0; i < *observationAmount; i++) {
        if (observations[i].data.name == name) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Observation not found. No observation deleted.\n");
        return;
    }

    // Shift elements using memmove
    if (index < *observationAmount - 1) { // Only shift if it's not the last element
        memmove(&observations[index], &observations[index + 1], 
                (*observationAmount - index - 1) * sizeof(Observation));
    }

    (*observationAmount)--;

    // Resize array if necessary
    changeObservationsSizeByMultibleOf3(&observations, observationSize, *observationAmount, false);

    printf("Observation with name %d deleted successfully.\n", name);
}




// Function to add predefined observations
void addPredefinedObservations(Observation **observations, int *observationSize, int *observationAmount)
{
    *observationAmount = 5;
    changeObservationsSizeByMultibleOf3(observations, observationSize, *observationAmount, true);

    (*observations)[0] = (Observation){
        .timeStamp = {
            .date = {.day = 26, .month = 5, .year = 2004},
            .time = {.hour = 12, .minute = 26, .second = 42}},
        .data = {.name = 3008, .classification = 0, .place = "Uppsala", .description = "SCP-3008 is a large retail unit previously owned by and branded as IKEA..."}
    };

    (*observations)[1] = (Observation){
        .timeStamp = {
            .date = {.day = 13, .month = 8, .year = 2019},
            .time = {.hour = 18, .minute = 48, .second = 20}},
        .data = {.name = 1471, .classification = 2, .place = "Amsterdam", .description = "SCP-1471 is a free 9.8MB application for mobile devices named 'MalO ver1.0.0'..."}
    };

    (*observations)[2] = (Observation){
        .timeStamp = {
            .date = {.day = 2, .month = 1, .year = 2020},
            .time = {.hour = 12, .minute = 0, .second = 0}},
        .data = {.name = 5000, .classification = 0, .place = "Santa Cruz", .description = "SCP-5000 is a non-functional mechanical suit identified as 'Absolute Exclusion Harness'..."}
    };

    (*observations)[3] = (Observation){
        .timeStamp = {
            .date = {.day = 24, .month = 3, .year = 2002},
            .time = {.hour = 2, .minute = 21, .second = 52}},
        .data = {.name = 343, .classification = 0, .place = "London", .description = "SCP-343 is a male, seemingly race-less, humanoid in appearance with apparent omnipotence..."}
    };


    (*observations)[4] = (Observation){
        .timeStamp = {
            .date = {.day = 12, .month = 11, .year = 1920},
            .time = {.hour = 12, .minute = 2, .second = 53}},
        .data = {.name = 173, .classification = 1, .place = "Riga", .description = "SCP-173 is a statue constructed from concrete and rebar with traces of Krylon brand spray paint..."}
    };

}

int compareDates(Date date1, Date date2)
{
    if (date1.year < date2.year)
    {
        return -1;
    }
    else if (date1.year > date2.year)
    {
        return 1;
    }
    else
    {
        if (date1.month < date2.month)
        {
            return -1;
        }
        else if (date1.month > date2.month)
        {
            return 1;
        }
        else
        {
            if (date1.day < date2.day)
            {
                return -1;
            }
            else if (date1.day > date2.day)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

void sortObservations(Observation *observations, int observationAmount, int type) {
    // Insertion sort
    switch (type) {
    case 1:
        // Sort by name (numerical)
        for (int i = 1; i < observationAmount; ++i) {
            Observation key = observations[i];  // Store the whole observation
            int j = i - 1;
            // Shift observations that are greater than key
            while (j >= 0 && observations[j].data.name > key.data.name) {
                observations[j + 1] = observations[j];  // Shift observation
                j = j - 1;
            }
            observations[j + 1] = key;  // Place key in correct position
        }
        break;
    case 2:
        // Sort by classification
        for (int i = 1; i < observationAmount; ++i) {
            Observation key = observations[i];  // Store the whole observation
            int j = i - 1;
            // Shift observations that are greater than key
            while (j >= 0 && observations[j].data.classification > key.data.classification) {
                observations[j + 1] = observations[j];  // Shift observation
                j = j - 1;
            }
            observations[j + 1] = key;  // Place key in correct position
        }
        break;
    case 3:
        // Sort by place (alphabetical)
        for (int i = 1; i < observationAmount; ++i) {
            Observation key = observations[i];  // Store the whole observation
            int j = i - 1;

            // Shift observations that are greater than key
            while (j >= 0 && strcmp(observations[j].data.place, key.data.place) > 0) {
                observations[j + 1] = observations[j];  // Shift observation
                j = j - 1;
            }
            observations[j + 1] = key;  // Place key in correct position
        }
        break;
    case 4:
        // Sort by full date (year, month, day)
        for (int i = 1; i < observationAmount; ++i) {
            Observation key = observations[i];  // Store the whole observation
            int j = i - 1;

            // Use compareDates to sort observations based on date
            while (j >= 0 && compareDates(observations[j].timeStamp.date, key.timeStamp.date) > 0) {
                observations[j + 1] = observations[j];  // Shift observation
                j = j - 1;
            }
            observations[j + 1] = key;  // Place key in correct position
        }
        break;
    default:
        printf("Invalid sorting type\n");
    }
}


int searchObservations(Observation *observations, int observationAmount, int type, char *searchInput) {
    bool found = false;
    int foundName = 0;

    for (int i = 0; i < observationAmount; i++) {
        bool match = false;

        switch (type) {
        case 1:
            // Search by name (numerical)
            if (observations[i].data.name == atoi(searchInput)) {
                match = true;
            }
            break;
        case 2:
            // Search by classification
            if (observations[i].data.classification == atoi(searchInput)) {
                match = true;
            }
            break;
        case 3:
            // Search by place (alphabetical)
            if (strstr(observations[i].data.place, searchInput) != NULL) {
                match = true;
            }
            break;
        case 4:
            // Search by date (day month year)
            int searchDay, searchMonth, searchYear;
            sscanf(searchInput, "%d %d %d", &searchDay, &searchMonth, &searchYear);
            if (observations[i].timeStamp.date.day == searchDay &&
                observations[i].timeStamp.date.month == searchMonth &&
                observations[i].timeStamp.date.year == searchYear) {
                match = true;
            }
            break;
        default:
            printf("Invalid search type\n");
            return -1;
        }

        if (match) {
            // Print matched observation
            printf("-----------------------\n");
            printf("\033[43m Observation %d: \033[0m\n", i + 1);
            printf("  Name: %d\n", observations[i].data.name);
            printf("  Classification: %d\n", observations[i].data.classification);
            printf("  Place: %s\n", observations[i].data.place);
            printf("  Description: %s\n", observations[i].data.description);
            printf("  Date: %d-%d-%d\n", observations[i].timeStamp.date.day, observations[i].timeStamp.date.month, observations[i].timeStamp.date.year);
            printf("  Time: %d:%d:%d\n", observations[i].timeStamp.time.hour, observations[i].timeStamp.time.minute, observations[i].timeStamp.time.second);
            found = true;
            foundName = observations[i].data.name;
        }
    }

    if (!found) {
        printf("No matching observations found.\n");
    }

    // Return the name of the first matched observation
    return foundName;
}


void printMainMenu(void) {
    printf("-----------------------\n");
    printf("1. Add observations\n");
    printf("2. Delete observations\n");
    printf("3. List all observations\n");
    printf("4. Search observations\n");
    printf("5. Exit program\n");
    printf("-----------------------\n");      
}

void printSearchMenu(void) {
    printf("-----------------------\n");
    printf("1. Search by name (number)\n");
    printf("2. Search by classification (0-2)\n");
    printf("3. Search by place (text)\n");
    printf("4. Search by date (day month year)\n");
    printf("5. Back\n");
    printf("-----------------------\n");
}

void printSearchInput(void) {
    printf("-----------------------\n");
    printf("Enter your search query: ");
}

void printDeleteInput(void) {
    printf("-----------------------\n");
    printf("Enter the name of the observation to delete: ");   
}

void listObservations(Observation *observations, int observationSize) {
    if (observationSize == 0) {
        printf("No observations available.\n");
        return;
    }

    for (int i = 0; i < observationSize; i++) {
        printf("-----------------------\n");
        printf("\033[43m Observation %d: \033[0m\n", i + 1);
        printf("  Name: %d\n", observations[i].data.name);
        printf("  Classification: %d\n", observations[i].data.classification);
        printf("  Place: %s\n", observations[i].data.place);
        printf("  Description: %s\n", observations[i].data.description);
        printf("  Date: %d-%d-%d\n", observations[i].timeStamp.date.day, observations[i].timeStamp.date.month, observations[i].timeStamp.date.year);
        printf("  Time: %d:%d:%d\n", observations[i].timeStamp.time.hour, observations[i].timeStamp.time.minute, observations[i].timeStamp.time.second);
    }
}


int main(void)
{
    int observationSize = 3;
    int observationAmount = 0;
    int type = 0;
    bool sorted = false;
    Observation *observations = malloc(sizeof(Observation) * observationSize);

    if (observations == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 0;
    }

    // Add predefined observations
    addPredefinedObservations(&observations, &observationSize, &observationAmount);

    bool running = true;

    // clearScreen();
    do
    {
        printMainMenu();
        int mainMenuChoice = getChoice(5);
        switch (mainMenuChoice)
        {
        case 1:
            // Add observations
            clearScreen();
            addObservation(&observations, &observationSize, &observationAmount);
            break;
        case 2:
            // Delete observations
            clearScreen();
            int deleteMenuChoice = 1;
            printDeleteInput();

            char deleteInput[100];
            while (getchar() != '\n');
            fgets(deleteInput, sizeof(deleteInput), stdin);
            deleteInput[strcspn(deleteInput, "\n")] = 0;

            if (deleteMenuChoice == type) {
                sorted = true;
            } else {
                sorted = false;
            }

                int deleteName = -1;

            switch (deleteMenuChoice)
            {
            case 1:
                // Search by name
                type = 1;
                if (!sorted) {
                    sortObservations(observations, observationAmount, type);
                    printf("Sorted\n");
                }
                deleteName = searchObservations(observations, observationAmount, type, deleteInput);
                deleteObservation(observations, &observationSize, &observationAmount, deleteName);
                break;
            case 2:
                // Search by classification
                type = 2;
                if (!sorted) {
                    sortObservations(observations, observationAmount, type);
                    printf("Sorted\n");
                }
                deleteName = searchObservations(observations, observationAmount, type, deleteInput);
                deleteObservation(observations, &observationSize, &observationAmount, deleteName);
                break;
            case 3:
                // Search by place
                type = 3;
                if (!sorted) {
                    sortObservations(observations, observationAmount, type);
                    printf("Sorted\n");
                }
                deleteName = searchObservations(observations, observationAmount, type, deleteInput);
                deleteObservation(observations, &observationSize, &observationAmount, deleteName);
                break;
            case 4:
                // Search by date
                type = 4;
                if (!sorted) {
                    sortObservations(observations, observationAmount, type);
                    printf("Sorted\n");
                }
                deleteName = searchObservations(observations, observationAmount, type, deleteInput);
                deleteObservation(observations, &observationSize, &observationAmount, deleteName);
                break;
            case 5:
                // Back
                break;
            default:
                break;
            }
            break;
        case 3:
            // List all observations
            clearScreen();
            listObservations(observations, observationAmount); // List observations
            break;
        case 4:
            // Search observations
            clearScreen();
            printSearchMenu();
            int searchMenuChoice = getChoice(5);

            clearScreen();
            printSearchInput();

            char searchInput[100];
            while (getchar() != '\n');
            fgets(searchInput, sizeof(searchInput), stdin);
            searchInput[strcspn(searchInput, "\n")] = 0;

            if (searchMenuChoice == type) {
                sorted = true;
            } else {
                sorted = false;
            }

            switch (searchMenuChoice)
            {
            case 1:
                // Search by name
                type = 1;
                if (!sorted) {
                    sortObservations(observations, observationAmount, type);
                    printf("Sorted\n");
                }
                searchObservations(observations, observationAmount, type, searchInput);
                break;
            case 2:
                // Search by classification
                type = 2;
                if (!sorted) {
                    sortObservations(observations, observationAmount, type);
                    printf("Sorted\n");
                }
                searchObservations(observations, observationAmount, type, searchInput);
                break;
            case 3:
                // Search by place
                type = 3;
                if (!sorted) {
                    sortObservations(observations, observationAmount, type);
                    printf("Sorted\n");
                }
                searchObservations(observations, observationAmount, type, searchInput);
                break;
            case 4:
                // Search by date
                type = 4;
                if (!sorted) {
                    sortObservations(observations, observationAmount, type);
                    printf("Sorted\n");
                }
                searchObservations(observations, observationAmount, type, searchInput);
                break;
            case 5:
                // Back
                break;
            default:
                break;
            }
            break;
        case 5:
            // Exit program
            running = false;
            break;
        default:
            break;
        }
    } while (running);

    // Free allocated memory
    free(observations);

    return 0;
}
