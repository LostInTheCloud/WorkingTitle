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

uint8_t interrupt_master_enable;

#define IME 			(interrupt_master_enable&0x01)
#define ENABLE_IME		interrupt_master_enable|=0x01;
#define DISABLE_IME		interrupt_master_enable&=0xFE;

#define INTERRUPT_ENABLE			(MEM[0xFFFF])
#define INTERRUPT_FLAGS 			(MEM[0xFF0F])
#define INTERRUPT_VBLANK 			(INTERRUPT_FLAGS&0x01)
#define SET_INTERRUPT_VBLANK(X)		INTERRUPT_FLAGS&=0x01; INTERRUPT_FLAGS|=X;
#define INTERRUPT_LCD				(INTERRUPT_FLAGS&0x02)
#define SET_INTERRUPT_LCD(X)		INTERRUPT_FLAGS&=0x02; INTERRUPT_FLAGS|=X<<1;
#define INTERRUPT_TIMER				(INTERRUPT_FLAGS&0x04)
#define SET_INTERRUPT_TIMER(X)		INTERRUPT_FLAGS&=0x04; INTERRUPT_FLAGS|=X<<2;
#define INTERRUPT_SERIAL			(INTERRUPT_FLAGS&0x08)
#define SET_INTERRUPT_SERIAL(X)		INTERRUPT_FLAGS&=0x08; INTERRUPT_FLAGS|=X<<3;
#define INTERRUPT_JOYPAD			(INTERRUPT_FLAGS&0x10)
#define SET_INTERRUPT_JOYPAD(X)		INTERRUPT_FLAGS&=0x10; INTERRUPT_FLAGS|=X<<4;

#define ENABLE_VBLANK				INTERRUPT_ENABLE|=0x01;
#define DISABLE_VBLANK				INTERRUPT_ENABLE&=0xFE;
#define ENABLE_LCD					INTERRUPT_ENABLE|=0x02;
#define DISABLE_LCD					INTERRUPT_ENABLE&=0xFD;
#define ENABLE_TIMER				INTERRUPT_ENABLE|=0x04;
#define DISABLE_TIMER				INTERRUPT_ENABLE&=0xFB;
#define ENABLE_SERIAL				INTERRUPT_ENABLE|=0x08;
#define DISABLE_SERIAL				INTERRUPT_ENABLE&=0xF7;
#define ENABLE_JOYPAD				INTERRUPT_ENABLE|=0x10;
#define DISABLE_JOYPAD				INTERRUPT_ENABLE&=0xEF;

#define GENERATE_VBLANK				INTERRUPT_FLAGS|=0x01;if(IME&&INTERRUPT_ENABLE&0x01){DISABLE_IME;SP-=2;(((uint16_t*)MEM)+SP)=PC;PC=0x40;}
#define GENERATE_LCD				INTERRUPT_FLAGS|=0x02;if(IME&&INTERRUPT_ENABLE&0x02){DISABLE_IME;SP-=2;(((uint16_t*)MEM)+SP)=PC;PC=0x48;}
#define GENERATE_TIMER				INTERRUPT_FLAGS|=0x04;if(IME&&INTERRUPT_ENABLE&0x04){DISABLE_IME;SP-=2;(((uint16_t*)MEM)+SP)=PC;PC=0x50;}
#define GENERATE_SERIAL				INTERRUPT_FLAGS|=0x08;if(IME&&INTERRUPT_ENABLE&0x08){DISABLE_IME;SP-=2;(((uint16_t*)MEM)+SP)=PC;PC=0x58;}
#define GENERATE_JOYPAD				INTERRUPT_FLAGS|=0x10;if(IME&&INTERRUPT_ENABLE&0x10){DISABLE_IME;SP-=2;(((uint16_t*)MEM)+SP)=PC;PC=0x60;}

// Memory Map
#define MEM_INTERRUPT (MEM+0x00)
#define MEM_ROM (MEM+0x100)
#define MEM_USER_PROG (MEM+0x150)
#define MEM_BANK0 (MEM+0x8000)
#define MEM_EXT_RAM (MEM+0xA000)
#define MEM_RAM (MEM+0xC000)
#define MEM_ECHO_RAM (MEM+0xE000)
#define MEM_OAM (MEM+0xFE00)
#define MEM_IO_PORTS (MEM+0xFF00)
#define MEM_RAM2 (MEM+0xFF80)

#define TIMER_DIV 	MEM[0xFF04]
// Timer Flags
#define TIMER_TIMA	MEM[0xFF05]
#define TIMER_TMA 	MEM[0xFF06]
#define TIMER_TAC 	MEM[0xFF07]

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
