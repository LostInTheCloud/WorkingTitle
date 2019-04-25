#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

// 4.190MHz 239ns
#define cycle_duration_ns 239;
#define cycle_duration_s 0;

void* reg_ptr[12];

#define F *((uint8_t*) reg_ptr + 0)
#define A *((uint8_t*) reg_ptr + 1)
#define C *((uint8_t*) reg_ptr + 2)
#define B *((uint8_t*) reg_ptr + 3)
#define E *((uint8_t*) reg_ptr + 4)
#define D *((uint8_t*) reg_ptr + 5)
#define L *((uint8_t*) reg_ptr + 6)
#define H *((uint8_t*) reg_ptr + 7)

#define SP *((uint16_t*) reg_ptr + 8/2)
#define PC *((uint16_t*) reg_ptr + 10/2)

#define BC *((uint16_t*) reg_ptr + 2/1)
#define DE *((uint16_t*) reg_ptr + 4/2)
#define HL *((uint16_t*) reg_ptr + 6/2)

uint8_t instruction_cycles;

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
