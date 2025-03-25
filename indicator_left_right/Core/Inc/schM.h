#ifndef SCHM_H
#define SCHM_H

#include <stdint.h>  // Include standard integer types

// Declare the function so main.c can see it
bool addTask(void (*task)(void), uint32_t period);

#endif  // SCHM_H
