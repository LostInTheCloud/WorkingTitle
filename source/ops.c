#include "main.h"

// 0x00
void OP_NOP(void)
{

}

// 0x01
void OP_LD_BC_D16(void)
{
    BC = *((uint16_t*) (MEM+PC+1));
}

// 0x02
void OP_LD_PBC_A(void)
{
    MEM[BC]=A;
}

// 0x03
void OP_INC_BC(void)
{
    BC++;
}

// 0x04
void OP_INC_B(void)
{
    if((B&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    B++; if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);
}

// 0x05
void OP_DEC_B(void)
{
    B--; if((B&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);
}

// 0x06
void OP_LD_B_D8(void)
{
    B = MEM[PC+1];
}

// 0x07
void OP_RLCA(void)
{
    if(CHECK_BIT(A,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A<<1; if(FLAG_C){A=A|1;}else{A=A&254;}
    if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);
}

// 0x08
void OP_LD_A16_SP(void)
{
    MEM[*((uint16_t*) (MEM+PC+1))]= SP;
}

// 0x09
void OP_ADD_HL_BC(void)
{
    if(HL&2047+BC&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    if((uint32_t)HL+(uint32_t)BC>65535){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    HL=HL+BC; SET_FLAG_N(0);
}

// 0x0A
void OP_LD_A_PBC(void)
{
    A=MEM[BC];
}

// 0x0B
void OP_DEC_BC(void)
{
    BC--;
}

// 0x0C
void OP_INC_C(void)
{
    if((C&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    C++; if(!C){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);
}

// 0x0D
void OP_DEC_C(void)
{
    if((C&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(!C){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

}

// 0x0E
void OP_LD_C_D8(void)
{
    C = MEM[PC+1];
}

// 0x0F shift right, CarryBit=Bit0 Bit7=Bit0
void OP_RRCA(void)
{
    if(CHECK_BIT(A,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A<<1; if(FLAG_C){A=A|128;}else{A=A&127;}
    if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);

}

// 0x10
void OP_STOP(void)
{
    // todo stop
}

// 0x11
void OP_LD_DE_D16(void)
{
    DE = *((uint16_t*) (MEM+PC+1));
}

// 0x12
void OP_LD_PDE_A(void)
{
    MEM[DE]=A;
}

// 0x13
void OP_INC_DE(void)
{
    DE++;
}

// 0x14
void OP_INC_D(void)
{
    if((D&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    D++; if(!D){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

}

// 0x15
void OP_DEC_D(void)
{
    D--; if((D&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(!D){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

}

// 0x16
void OP_LD_D_D8(void)
{
    D = MEM[PC+1];
}

// 0x17
void OP_RLA(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(A,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A<<1; if(t8[0]){A=A|1;}else{A=A&254;}
    if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);

}

// 0x18
void OP_JR_R8(void)
{
    PC=PC+(*((int8_t*)MEM+PC+1));
}

// 0x19
void OP_ADD_HL_DE(void)
{
    if(HL&2047+DE&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    if((uint32_t)HL+(uint32_t)DE>65535){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    HL=HL+DE; SET_FLAG_N(0);
}

// 0x1A
void OP_LD_A_PDE(void)
{
    A=MEM[DE];
}

// 0x1B
void OP_DEC_DE(void)
{
    DE--;
}

// 0x1C
void OP_INC_E(void)
{
    if((E&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    E++; if(!E){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

}

// 0x1D
void OP_DEC_E(void)
{
    E--; if((E&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
    if(!E){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

}

// 0x1E
void OP_LD_E_D8(void)
{
    E = MEM[PC+1];
}

// 0x1F
void OP_RRA(void)
{
    t8[0] = FLAG_C; \
    if(CHECK_BIT(A,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
    A=A<<1; if(t8[0]){A=A|128;}else{A=A&127;} \
    if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);

}

// 0x20
void OP_JR_NZ_R8(void)
{
    if(!FLAG_Z){PC=PC+MEM[PC+1];}
}

// 0x21
void OP_LD_HL_D16(void)
{
    HL = *((uint16_t*) (MEM+PC+1));
}

// 0x22
void OP_LD_PHLI_A(void)
{
    MEM[HL++]=A;
}

// 0x23
void OP_INC_HL(void)
{
    HL++;
}

// 0x24
void OP_INC_H(void)
{
    if((H&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    H++; if(!H){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

}

// 0x25
void OP_DEC_H(void)
{
    H--; if((H&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
    if(!H){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);
}

// 0x26
void OP_LD_H_D8(void)
{
    H = MEM[PC+1];
}

// 0x27 todo: decimal adjust register A todo
// https://www.tutorialspoint.com/daa-instruction-in-8085-microprocessor
void OP_DAA(void)
{
    if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_H(0);
    // todo
}

// 0x28
void OP_JR_Z_R8(void)
{
    if(FLAG_Z){PC=PC+MEM[PC+1];}
}

// 0x29
void OP_ADD_HL_HL(void)
{
    if(HL&2047+HL&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    if((uint32_t)HL+(uint32_t)BC>65535){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    HL=HL+BC; SET_FLAG_N(0);
}

// 0x2A
void OP_LD_A_PHLI(void)
{
    A=MEM[HL++];
}

// 0x2B
void OP_DEC_HL(void)
{
    HL--;
}

// 0x2C
void OP_INC_L(void)
{
    if((L&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    L++; if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

}

// 0x2D
void OP_DEC_L(void)
{
    L--; if((L&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(!L){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

}

// 0x2E
void OP_LD_L_D8(void)
{
    L = MEM[PC+1];
}

// 0x2F flip all bits in A
void OP_CPL(void)
{
    A=A^255; SET_FLAG_H(1); SET_FLAG_N(1);
}

// 0x30
void OP_JR_NC_R8(void)
{
    if(!FLAG_C){PC=PC+MEM[PC+1];}
}

// 0x31
void OP_LD_SP_D16(void)
{
    SP = *((uint16_t*) (MEM+PC+1));
}

// 0x32
void OP_LD_PHLD_A(void)
{
    MEM[HL--]=A;
}

// 0x33
void OP_INC_SP(void)
{
    SP++;
}

// 0x34
void OP_INC_PHL(void)
{
    if((MEM[HL]&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    MEM[HL]++; if(!MEM[HL]){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

}

// 0x35
void OP_DEC_PHL(void)
{
    MEM[HL]--; if((MEM[HL]&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(!MEM[HL]){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);
}

// 0x36
void OP_LD_PHL_D8(void)
{
    MEM[HL] = MEM[PC+1];
}

// 0x37
void OP_SCF(void)
{
    SET_FLAG_C(1); SET_FLAG_N(0); SET_FLAG_H(0);
}

// 0x38
void OP_JR_C_R8(void)
{
    if(FLAG_C){PC=PC+MEM[PC+1];}
}

// 0x39
void OP_ADD_HL_SP(void)
{
    if(HL&2047+SP&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    if((uint32_t)HL+(uint32_t)SP<32767){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    HL=HL+SP; SET_FLAG_N(0);
}

// 0x3A
void OP_LD_A_PHLD(void)
{
    A=MEM[HL--];
}

// 0x3B
void OP_DEC_SP(void)
{
    SP--;
}

// 0x3C
void OP_INC_A(void)
{
    if((A&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    A++; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);
}

// 0x3D
void OP_DEC_A(void)
{
    A--; if((A&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);
}

// 0x3E
void OP_LD_A_D8(void)
{
    A = MEM[PC+1];
}

// 0x3F complement carry flag
void OP_CCF(void)
{
    SET_FLAG_H(0); SET_FLAG_N(0); SET_FLAG_C(!FLAG_C);
}


