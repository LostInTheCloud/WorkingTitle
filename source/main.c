#include "main.h"

int main()
{
    printf("Hello, DMG\n");

    struct timespec t0;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    uint32_t nanosecs;

    long x = 0;

    loop:
    
    // do CPU Instruction

    if(++x == 4190000)
    {
        fprintf(stderr, "4.19 Million clocks passed!\n");
        x=0;
    }
    
    instruction_cycles = 1;

    nanosecs = t0.tv_nsec;
    nanosecs += instruction_cycles;
    nanosecs *= cycle_duration;
    if(unlikely(nanosecs > 999999999))
    {
        nanosecs -= 1000000000;
        t0.tv_sec ++;
    }
    t0.tv_nsec += nanosecs;
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t0, NULL);

    goto loop;
    end:
    return EXIT_SUCCESS;
}