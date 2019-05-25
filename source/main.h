#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // nanosleep, gettime
#include <inttypes.h>   // uint8_t, ...

#include "ops.h"

// 4.190MHz 239ns
#define cycle_duration 239;

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
#define SET_FLAG_Z(X) F&=0x7F; F|=X<<7;

// Add/Sub Flag (BCD)
#define FLAG_N ((F&0x40)>>6)
#define SET_FLAG_N(X) F&=0xBF; F|=X<<6;

//Half Carry Flag
#define FLAG_H ((F&0x20)>>5)
#define SET_FLAG_H(X) F&=0xDF; F|=X<<5;

// Carry Flag
#define FLAG_C ((F&0x10)>>4)
#define SET_FLAG_C(X) F&=0xEF; F|=X<<4;

int OPCODE_LENGTH[0x100] =
{
	1,3,1,1,1,1,2,1,3,1,1,1,1,1,2,1,
	0,3,1,1,1,1,2,1,2,1,1,1,1,1,2,1,
	2,3,1,1,1,1,2,1,2,1,1,1,1,1,2,1,
	2,3,1,1,1,1,2,1,2,1,1,1,1,1,2,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,3,3,3,1,2,1,1,1,3,0,3,3,2,1,
	1,1,3,0,3,1,2,1,1,1,3,0,3,0,2,1,
	2,1,1,0,0,1,2,1,2,1,3,0,0,0,2,1,
	2,1,1,1,0,1,2,1,2,1,3,1,0,0,2,1
};

#define WAIT 	nanosecs = cycle_duration; \
							nanosecs += t0.tv_nsec; \
							if(unlikely(nanosecs > 999999999)) \
							{ \
									nanosecs -= 1000000000; \
									t0.tv_sec ++; \
							} \
							t0.tv_nsec = nanosecs; \
							clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t0, NULL);

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
