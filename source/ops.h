// 0x00
#define OP_NOP WAIT;

// 0x01
#define OP_LD_BC_D16 WAIT; WAIT; WAIT; /* TODO */

// 0x02 ld (BC) A
#define OP_LD_PBC_A WAIT; WAIT; /* TODO */

// 0x03
#define OP_INC_BC BC++; WAIT; WAIT;

// 0x04
#define OP_INC_B B++; if(!A){setFlagZ(1);} setFlagN(0); WAIT; /* TODO flags*/

// 0x05
#define OP_DEC_B B--; WAIT;

// 0x06
#define OP_LD_B_D8 WAIT; WAIT; /* TODO */

// 0x07
#define OP_RLCA if(CHECK_BIT(A,7)){setFlagC(1);}else{setFlagC(0);} \
        A<<1; if(!A){setFlagZ(1);} setFlagN(0); setFlagH(0); WAIT;

// 0x08
#define OP_A16_SP WAIT; WAIT; WAIT; WAIT; WAIT; /* TODO */

// 0x09
#define OP_ADD_HL_BC HL=HL+BC; WAIT; WAIT;

//check if bit n+1 (couting from 1 to 8) is set in X
#define CHECK_BIT(X,n) ((X) & (1<<(n)))
