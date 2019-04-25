#include "main.h"

// !!!!!!!!!!!!!!!!!!!!!!
// WHAT ABOUT NOPS vs 4 cycle instructions????
// !!!!!!!!!!!!!!!!!!!!!!

int main()
{
    printf("Hello, DMG\n");

    loop:
    // gettime();

    // do CPU Instruction
    printf("x\n");

    // gettime();

    // get time difference

    // sleep(250ns - t2 + t1 = 250 - delta t);
    goto loop;
    
    return EXIT_SUCCESS;
}