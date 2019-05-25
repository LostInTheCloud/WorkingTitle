// 0x00
#define OP_NOP instruction_cycles = 1;

// 0x01
#define OP_LD_BC_D16 instruction_cycles = 3; /* TODO */

// 0x02 ld (BC) A
#define OP_LD_PBC_A instruction_cycles = 2; /* TODO */

// 0x03
#define OP_INC_BC BC++; instruction_cycles = 2;

// 0x04
#define OP_INC_B B++; if(!A){setFlagZ(1);} setFlagN(0); instruction_cycles = 1; /* TODO flags*/

// 0x05
#define OP_DEC_B B--; instruction_cycles = 1;

// 0x06 
#define OP_LD_B_D8 instruction_cycles = 2; /* TODO */

// 0x07 
#define OP_RLCA if(CHECK_BIT(A,7)){setFlagC(1);}else{setFlagC(0);} \
        A<<1; if(!A){setFlagZ(1);} setFlagN(0); setFlagH(0); instruction_cycles = 1;

// 0x08
#define OP_A16_SP instruction_cycles = 5; /* TODO */

// 0x09
#define OP_ADD_HL_BC HL=HL+BC; instruction_cycles = 2;

//check if bit n+1 (couting from 1 to 8) is set in X
#define CHECK_BIT(X,n) ((X) & (1<<(n)))