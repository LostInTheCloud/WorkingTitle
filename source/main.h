#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct registers 
{
    uint8_t     A,
                F,  // flags TODO: get single flag bits
                B,
                C,
                D,
                E,
                H,
                L;
    uint16_t    SP, // stack pointer
                PC; // program counter
}

typedef struct registers registers;