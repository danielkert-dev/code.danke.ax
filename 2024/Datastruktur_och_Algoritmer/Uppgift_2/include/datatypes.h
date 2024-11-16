#ifndef CONFIG_H
#define CONFIG_H

// Alla Struct

/*
 *
 * datum (dag/månad/år)
 * klockslag (timmar/minuter)
 * plats (en sträng)
 * beskrivning av observationen (en sträng)
 *
 */

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    int hour;
    int minute;
    int second;
} Time;

typedef struct
{
    Date date;
    Time time;
} TimeStamp;

typedef struct
{
    int name;
    int classification;
    char place[50];
    char description[1024];
} Data;

typedef struct
{
    TimeStamp timeStamp;
    Data data;
} Observation;

#endif // CONFIG_H