#include <stdio.h>

#include "../include/datatypes.h"
#include "../include/ui.h"

// TODO:
// 1. Add observations
// 2. Delete observations
// 3. List all  observations
// 4. Search observations

void addObservations(void) {
    printf("Add observations\n");
}

void addPredefinedObservations(Observation *observations, int *observationAmount)
{

    observations[0] = (Observation){
        .timeStamp = {
            .date = {.day = 26, .month = 5, .year = 2004},
            .time = {.hour = 12, .minute = 26, .second = 42}},
        .data = {.name = 3008, .classification = 0, .place = "Uppsala", .description = "SCP-3008 is a large retail unit previously owned by and branded as IKEA, a popular furniture retail chain. A person entering SCP-3008 through the main entrance and then passing out of sight of the doors will find themselves translocated to SCP-3008-1. This displacement will typically go unnoticed as no change will occur from the perspective of the victim; they will generally not become aware until they try to return to the entrance. SCP-3008-1 is a space resembling the inside of an IKEA furniture store, extending far beyond the limits of what could physically be contained within the dimensions of the retail unit. Current measurements indicate an area of at least 10km2 with no visible external terminators detected in any direction. Inconclusive results from the use of laser rangefinders has led to the speculation that the space may be infinite."}};
    // https://stackoverflow.com/questions/859770/post-increment-on-a-dereferenced-pointer
    // Lol ok. Annars om man gör observationAmount++ ökar det bara lokalt i funktionen.
    (*observationAmount)++;

    observations[1] = (Observation){
        .timeStamp = {
            .date = {.day = 13, .month = 8, .year = 2019},
            .time = {.hour = 18, .minute = 48, .second = 20}},
        .data = {.name = 1471, .classification = 2, .place = "Amsterdam", .description = "SCP-1471 is a free 9.8MB application for mobile devices named 'MalO ver1.0.0' in online application stores. SCP-1471 has no listed developer and is somehow able to bypass the application approval process to go directly to distribution. SCP-1471 is also able to avoid removal by other program manager applications."}};
    (*observationAmount)++;

    observations[2] = (Observation){
        .timeStamp = {
            .date = {.day = 2, .month = 1, .year = 2020},
            .time = {.hour = 12, .minute = 0, .second = 0}},
        .data = {.name = 5000, .classification = 0, .place = "Santa Cruz", .description = "SCP-5000 is a non-functional mechanical suit identified within its internal schematics as an 'Absolute Exclusion Harness' designed by the SCP Foundation. Although SCP-5000 is believed to have once possessed a number of anomalous functions intended to protect and benefit its occupant, damage inflicted to it in the past means that it is currently only capable of basic file storage. For a record of files contained within SCP-5000 upon recovery, see Archive 5000-1. SCP-5000 first appeared in a flash of light within SCP-579's containment chamber at Site-62C on 12/04/2020, containing a corpse1 genetically identical to Foundation employee Pietro Wilson. Pietro Wilson is currently employed at Exclusionary Site-062, and mnestic therapy has confirmed he has no knowledge of SCP-5000 or memories concerning the events detailed within its archives."}};
    (*observationAmount)++;

    observations[3] = (Observation){
        .timeStamp = {
            .date = {.day = 24, .month = 3, .year = 2002},
            .time = {.hour = 2, .minute = 21, .second = 52}},
        .data = {.name = 343, .classification = 0, .place = "London", .description = "SCP-343 is a male, seemingly race-less, humanoid in appearance with apparent omnipotence. SCP-343 was discovered walking the streets of Prague and detained after a staff member witnessed him disappear from the streets and reappear on a rooftop. SCP-343 is detained willingly in his chamber, as containment has proved impossible (see notes)."}};
    (*observationAmount)++;

    observations[4] = (Observation){
        .timeStamp = {
            .date = {.day = 12, .month = 11, .year = 1920},
            .time = {.hour = 12, .minute = 2, .second = 53}},
        .data = {.name = 173, .classification = 1, .place = "Riga", .description = "SCP-173 is a statue constructed from concrete and rebar with traces of Krylon brand spray paint. SCP-173 is animate and extremely hostile. The object cannot move while within a direct line of sight. Line of sight must not be broken at any time with SCP-173. Personnel assigned to enter container are instructed to alert one another before blinking. Object is reported to attack by snapping the neck at the base of the skull, or by strangulation. In the event of an attack, personnel are to observe Class 4 hazardous object containment procedures."}};
    (*observationAmount)++;

}