/*
 * schm.c
 *
 *  Created on: Mar 24, 2025
 *      Author: Roger
 */
#include "stm32g0xx_hal.h"
#include <stdbool.h>

#define MAX_TASKS 10

// Task structure
typedef struct {
    void (*taskFunction)(void); // Pointer to the task function
    uint32_t period;            // Task period in milliseconds
    uint32_t lastRun;           // Last time the task was run (in ms)
} Task;

Task scheduler[MAX_TASKS]; // Array to hold tasks
uint32_t systemTime = 0;   // Keeps track of the system time (in ms)

 //Timer Interrupt Handler (SysTick) to update system time
void SysTick_Handler(void)
{
    systemTime++; // Increment the system time every 1ms

    // Run tasks that are due
    for (int i = 0; i < 2; i++) {
        if (scheduler[i].taskFunction != NULL && systemTime - scheduler[i].lastRun >= scheduler[i].period) {
            scheduler[i].taskFunction();         // Execute the task function
            scheduler[i].lastRun = systemTime;   // Update the last run time
        }
    }
}

// Add a task to the scheduler
bool addTask(void (*task)(void), uint32_t period) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (scheduler[i].taskFunction == NULL) {
            scheduler[i].taskFunction = task;
            scheduler[i].period = period;
            scheduler[i].lastRun = 0;  // The task is considered to be ready immediately
            return true;
        }
    }
    return false; // Scheduler is full
}


