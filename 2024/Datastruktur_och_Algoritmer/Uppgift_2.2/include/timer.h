#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>  // For Linux

// Function declarations for timer functionality
void startTimer(struct timeval* t1);
double stopTimer(struct timeval* t1, struct timeval* t2);

#endif