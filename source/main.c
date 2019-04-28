#include "main.h"

int main()
{
    printf("Hello, DMG\n");

    struct timespec t0, t1, rem;
    uint32_t nanosecs;

    long x = 0;

    loop:
    clock_gettime(CLOCK_MONOTONIC, &t0);

    // do CPU Instruction

    if(++x == 4190000)
    {
        fprintf(stderr, "4.19 Million clocks passed!\n");
        x=0;
    }
    
    instruction_cycles = 1;

    clock_gettime(CLOCK_MONOTONIC, &t1);

    nanosecs = t1.tv_sec==t0.tv_sec?0:10e9;
    nanosecs += t1.tv_nsec;
    nanosecs -= t0.tv_nsec;
    rem.tv_sec = 0;
    rem.tv_nsec = cycle_duration
    rem.tv_nsec *= instruction_cycles;
    rem.tv_nsec -= nanosecs;
    clock_nanosleep(CLOCK_MONOTONIC, 0, &rem, NULL);
    // try abstime

    goto loop;
    end:
    return EXIT_SUCCESS;
}