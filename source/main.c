#include "main.h"

int main()
{
    printf("Hello, DMG\n");

    struct timespec t0, t1, rem;
    uint32_t nanosecs;

    loop:
    clock_gettime(CLOCK_MONOTONIC, &t0);

    // do CPU Instruction
    printf("x\n");
    instruction_cycles = 1;

    clock_gettime(CLOCK_MONOTONIC, &t1);

    nanosecs = t1.tv_sec==t0.tv_sec?0:10e9;

    nanosecs += t1.tv_nsec;

    nanosecs -= t0.tv_nsec;

    rem.tv_sec = 0;
    // rem.tv_nsec = cycle_duration * instruction_cycles - nanosecs;

    nanosleep(&rem, NULL);

    goto loop;
    
    return EXIT_SUCCESS;
}