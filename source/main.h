#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // nanosleep, gettime
#include <inttypes.h>   // uint8_t, ...

#include "ops.h"

// 4.190MHz 239ns
#define cycle_duration 239;
//#define cycle_duration 999999999;

void* reg_ptr[12];

#define F (*((uint8_t*) reg_ptr + 0))
#define A (*((uint8_t*) reg_ptr + 1))
#define C (*((uint8_t*) reg_ptr + 2))
#define B (*((uint8_t*) reg_ptr + 3))
#define E (*((uint8_t*) reg_ptr + 4))
#define D (*((uint8_t*) reg_ptr + 5))
#define L (*((uint8_t*) reg_ptr + 6))
#define H (*((uint8_t*) reg_ptr + 7))

#define SP (*((uint16_t*) reg_ptr + 8/2))
#define PC (*((uint16_t*) reg_ptr + 10/2))

#define BC (*((uint16_t*) reg_ptr + 2/2))
#define DE (*((uint16_t*) reg_ptr + 4/2))
#define HL (*((uint16_t*) reg_ptr + 6/2))

// Zero Flag
#define FLAG_Z ((F&0x80)>>7)

// Add/Sub Flag (BCD)
#define FLAG_N ((F&0x40)>>6)

//Half Carry Flag
#define FLAG_H ((F&0x20)>>5)

// Carry Flag
#define FLAG_C ((F&0x10)>>4)

long instruction_cycles;

void print_regs(void)
{
    // 18 characters per line

    printf("##################\n");
    printf("A: 0x%02"PRIx8"    F: 0x%02"PRIx8"\n", A, F);
    printf("B: 0x%02"PRIx8"    C: 0x%02"PRIx8"\n", B, C);
    printf("D: 0x%02"PRIx8"    E: 0x%02"PRIx8"\n", D, E);
    printf("H: 0x%02"PRIx8"    L: 0x%02"PRIx8"\n", H, L);
    printf("     SP: 0x%02"PRIx16"\n", SP);
    printf("     PC: 0x%02"PRIx16"\n", PC);
    printf("##################\n");
}

// flags

#define unlikely(expr) __builtin_expect(!!(expr), 0)
#define likely(expr) __builtin_expect(!!(expr), 1)