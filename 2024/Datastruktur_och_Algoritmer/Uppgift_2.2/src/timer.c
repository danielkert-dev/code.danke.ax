#include <stdio.h>
#include <sys/time.h>
#include "timer.h"

// Timer function to start the timer
void startTimer(struct timeval* t1) {
    gettimeofday(t1, NULL);  // Start timer
}

// Timer function to stop the timer and return elapsed time in milliseconds
double stopTimer(struct timeval* t1, struct timeval* t2) {
    gettimeofday(t2, NULL);  // Stop timer
    double elapsedTime = (t2->tv_sec - t1->tv_sec) * 1000.0;  // sec to ms
    elapsedTime += (t2->tv_usec - t1->tv_usec) / 1000.0;  // us to ms
    return elapsedTime;
}
