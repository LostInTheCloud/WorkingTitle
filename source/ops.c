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

// 0x40
void OP_LD_B_B(void)
{
    B=B;
}

// 0x41
void OP_LD_B_C(void)
{
    B=C;
}

// 0x42
void OP_LD_B_D(void)
{
    B=D;
}

// 0x43
void OP_LD_B_E(void)
{
    B=E;
}

// 0x44
void OP_LD_B_H(void)
{
    B=H;
}

// 0x45
void OP_LD_B_L(void)
{
    B=L;
}

// 0x46
void OP_LD_B_PHL(void)
{
    B=MEM[HL];
}

// 0x47
void OP_LD_B_A(void)
{
    B=A;
}

// 0x48
void OP_LD_C_B(void)
{
    C=B;
}

// 0x49
void OP_LD_C_C(void)
{
    C=C;
}

// 0x4A
void OP_LD_C_D(void)
{
    C=D;
}

// 0x4B
void OP_LD_C_E(void)
{
    C=E;
}

// 0x4C
void OP_LD_C_H(void)
{
    C=H;
}

// 0x4D
void OP_LD_C_L(void)
{
    C=L;
}

// 0x4E
void OP_LD_C_PHL(void)
{
    C=MEM[HL];
}

// 0x4F
void OP_LD_C_A(void)
{
    C=A;
}

// 0x50
void OP_LD_D_B(void)
{
    D=B;
}

// 0x51
void OP_LD_D_C(void)
{
    D=C;
}

// 0x52
void OP_LD_D_D(void)
{
    D=D;
}

// 0x53
void OP_LD_D_E(void)
{
    D=E;
}

// 0x54
void OP_LD_D_H(void)
{
    D=H;
}

// 0x55
void OP_LD_D_L(void)
{
    D=L;
}

// 0x56
void OP_LD_D_PHL(void)
{
    D=MEM[HL];
}

// 0x57
void OP_LD_D_A(void)
{
    D=A;
}

// 0x58
void OP_LD_E_B(void)
{
    E=B;
}

// 0x59
void OP_LD_E_C(void)
{
    E=C;
}

// 0x5A
void OP_LD_E_D(void)
{
    E=D;
}

// 0x5B
void OP_LD_E_E(void)
{
    E=E;
}

// 0x5C
void OP_LD_E_H(void)
{
    E=H;
}

// 0x5D
void OP_LD_E_L(void)
{
    E=L;
}

// 0x5E
void OP_LD_E_PHL(void)
{
    E=MEM[HL];
}

// 0x5F
void OP_LD_E_A(void)
{
    E=A;
}

// 0x60
void OP_LD_H_B(void)
{
    H=B;
}

// 0x61
void OP_LD_H_C(void)
{
    H=C;
}

// 0x62
void OP_LD_H_D(void)
{
    H=D;
}

// 0x63
void OP_LD_H_E(void)
{
    H=E;
}

// 0x64
void OP_LD_H_H(void)
{
    H=H;
}

// 0x65
void OP_LD_H_L(void)
{
    H=L;
}

// 0x66
void OP_LD_H_PHL(void)
{
    H=MEM[HL];
}

// 0x67
void OP_LD_H_A(void)
{
    H=A;
}

// 0x68
void OP_LD_L_B(void)
{
    L=B;
}

// 0x69
void OP_LD_L_C(void)
{
    L=C;
}

// 0x6A
void OP_LD_L_D(void)
{
    L=D;
}

// 0x6B
void OP_LD_L_E(void)
{
    L=E;
}

// 0x6C
void OP_LD_L_H(void)
{
    L=H;
}

// 0x6D
void OP_LD_L_L(void)
{
    L=L;
}

// 0x6E
void OP_LD_L_PHL(void)
{
    L=MEM[HL];
}

// 0x6F
void OP_LD_L_A(void)
{
    L=A;
}

// 0x70
void OP_LD_PHL_B(void)
{
    MEM[HL]=B;
}

// 0x71
void OP_LD_PHL_C(void)
{
    MEM[HL]=C;
}

// 0x72
void OP_LD_PHL_D(void)
{
    MEM[HL]=D;
}

// 0x73
void OP_LD_PHL_E(void)
{
    MEM[HL]=E;
}

// 0x74
void OP_LD_PHL_H(void)
{
    MEM[HL]=H;
}

// 0x75
void OP_LD_PHL_L(void)
{
    MEM[HL]=L;
}

// 0x76
void OP_HALT(void)
{

}

// 0x77
void OP_LD_PHL_A(void)
{
    MEM[HL]=A;
}

// 0x78
void OP_LD_A_B(void)
{
    A=B;
}

// 0x79
void OP_LD_A_C(void)
{
    A=C;
}

// 0x7A
void OP_LD_A_D(void)
{
    A=D;
}

// 0x7B
void OP_LD_A_E(void)
{
    A=E;
}

// 0x7C
void OP_LD_A_H(void)
{
    A=H;
}

// 0x7D
void OP_LD_A_L(void)
{
    A=L;
}

// 0x7E
void OP_LD_A_PHL(void)
{
    A=MEM[HL];
}

// 0x7F
void OP_LD_A_A(void)
{
    A=A;
}

// 0x80 if first 4 bits add to more than 1111 then set H
void OP_ADD_A_B(void)
{
    if((A&15)+(B&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+B>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

}

// 0x81
void OP_ADD_A_C(void)
{
    if((A&15)+(C&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

}

// 0x82
void OP_ADD_A_D(void)
{
    if((A&15)+(D&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+D>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x83
void OP_ADD_A_E(void)
{
    if((A&15)+(E&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+E>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x84
void OP_ADD_A_H(void)
{
    if((A&15)+(H&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+H>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x85
void OP_ADD_A_L(void)
{
    if((A&15)+(L&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+L>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x86
void OP_ADD_A_PHL(void)
{
    if((A&15)+(MEM[HL]&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+MEM[HL]>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x87
void OP_ADD_A_A(void)
{
    if((A&15)+(A&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+A>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+A; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x88
void OP_ADC_A_B(void)
{
    if((A&15)+(B&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+B+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+B+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x89
void OP_ADC_A_C(void)
{
    if((A&15)+(C&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+C+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+C+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x8A
void OP_ADC_A_D(void)
{
    if((A&15)+(D&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+D+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+D+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x8B
void OP_ADC_A_E(void)
{
    if((A&15)+(E&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+E+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+E+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x8C
void OP_ADC_A_H(void)
{
    if((A&15)+(H&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+H+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+H+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x8D
void OP_ADC_A_L(void)
{
    if((A&15)+(L&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+L+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+L+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x8E
void OP_ADC_A_PHL(void)
{
    if((A&15)+(MEM[HL]&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
    if(A+MEM[HL]+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
    A=A+MEM[HL]+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}


// 0x8F
void OP_ADC_A_A(void)
{
    if((A&15)+(A&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+A+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+A+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x90
void OP_SUB_A_B(void)
{
    if((A&15)<(B&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<B){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);
}

// 0x91
void OP_SUB_A_C(void)
{
    if((A&15)<(C&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);
}

// 0x92
void OP_SUB_A_D(void)
{
    if((A&15)<(D&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<D){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);
}

// 0x93
void OP_SUB_A_E(void)
{
    if((A&15)<(E&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<E){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);
}

// 0x94
void OP_SUB_A_H(void)
{
    if((A&15)<(H&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<H){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);
}

// 0x95
void OP_SUB_A_L(void)
{
    if((A&15)<(L&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<L){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);
}

// 0x96
void OP_SUB_A_PHL(void)
{
    if((A&15)<(MEM[HL]&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<MEM[HL]){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);
}

// 0x97
void OP_SUB_A_A(void)
{
    SET_FLAG_H(0);SET_FLAG_C(0);A=0;SET_FLAG_Z(1);SET_FLAG_N(1);
}

// 0x98
void OP_SBC_A_B(void)
{
    if((A&15)<(B&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<B+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-B+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x99
void OP_SBC_A_C(void)
{
    if((A&15)<(C&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<C+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-C+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x9A
void OP_SBC_A_D(void)
{
    if((A&15)<(D&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<D+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-D+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x9B
void OP_SBC_A_E(void)
{
    if((A&15)<(E&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<E+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-E+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x9C
void OP_SBC_A_H(void)
{
    if((A&15)<(H&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<H+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-H+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x9D
void OP_SBC_A_L(void)
{
    if((A&15)<(L&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<L+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-L+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x9E
void OP_SBC_A_PHL(void)
{
    if((A&15)<(MEM[HL]&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A<MEM[HL]+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A-MEM[HL]+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0x9F
void OP_SBC_A_A(void)
{
    if(FLAG_C){SET_FLAG_H(1); SET_FLAG_C(1);}else{SET_FLAG_H(0); SET_FLAG_C(0);}
    A=FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0xA0
void OP_AND_B(void)
{
    A=A&B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);
}

// 0xA1
void OP_AND_C(void)
{
    A=A&C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);
}

// 0xA2
void OP_AND_D(void)
{
    A=A&D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);
}

// 0xA3
void OP_AND_E(void)
{
    A=A&E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);
}

// 0xA4
void OP_AND_H(void)
{
    A=A&H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);
}

// 0xA5
void OP_AND_L(void)
{
    A=A&L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);
}

// 0xA6
void OP_AND_PHL(void)
{
    A=A&MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);
}

// 0xA7
void OP_AND_A(void)
{
    if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);
}

// 0xA8
void OP_XOR_B(void)
{
    A=A^B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xA9
void OP_XOR_C(void)
{
    A=A^C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xAA
void OP_XOR_D(void)
{
    A=A^D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xAB
void OP_XOR_E(void)
{
    A=A^E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xAC
void OP_XOR_H(void)
{
    A=A^H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xAD
void OP_XOR_L(void)
{
    A=A^L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xAE
void OP_XOR_PHL(void)
{
    A=A^MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xAF
void OP_XOR_A(void)
{
    A=0; SET_FLAG_Z(1); SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xB0
void OP_OR_B(void)
{
    A=A|B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xB1
void OP_OR_C(void)
{
    A=A|C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xB2
void OP_OR_D(void)
{
    A=A|D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xB3
void OP_OR_E(void)
{
    A=A|E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xB4
void OP_OR_H(void)
{
    A=A|H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xB5
void OP_OR_L(void)
{
    A=A|L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xB6
void OP_OR_PHL(void)
{
    A=A|MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xB7
void OP_OR_A(void)
{
    if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xB8
void OP_CP_B(void)
{
    if(!(A-B)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)};
    if(A<B){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    if((A&15)<(B&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xB9
void OP_CP_C(void)
{
    if(!(A-C)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)};
    if(A<C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    if((A&15)<(C&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBA
void OP_CP_D(void)
{
    if(!(A-D)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)};
    if(A<D){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    if((A&15)<(D&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBB
void OP_CP_E(void)
{
    if(!(A-E)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)};
    if(A<E){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    if((A&15)<(E&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBC
void OP_CP_H(void)
{
    if(!(A-H)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)};
    if(A<H){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    if((A&15)<(H&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBD
void OP_CP_L(void)
{
    if(!(A-L)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)};
    if(A<L){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    if((A&15)<(L&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBE
void OP_CP_PHL(void)
{
    if(!(A-MEM[HL])){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)};
    if(A<MEM[HL]){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    if((A&15)<(MEM[HL]&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBF
void OP_CP_A(void)
{
    SET_FLAG_Z(1); SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(1);
}

// 0xC0
void OP_RET_NZ(void)
{
    if(!FLAG_Z){(*((int8_t*)MEM+SP+2)); SP+=2;   }
}

// 0xC1
void OP_POP_BC(void)
{
    C=MEM[SP+1];B=MEM[SP+2]; SP+=2;
}

// 0xC2
void OP_JP_NZ_A16(void)
{
    if(!FLAG_Z){PC= *((uint16_t*) (MEM+PC+1)); }
}

// 0xC3
void OP_JP_A16(void)
{
    PC= *((uint16_t*) (MEM+PC+1));
}

// 0xC4
void OP_CALL_NZ_A16(void)
{
    if(!FLAG_Z){MEM[SP-2]=PC+3; SP=SP-2; PC= *((uint16_t*) (MEM+PC+1));   }
}

// 0xC5
void OP_PUSH_BC(void)
{
    MEM[SP-1]=B; MEM[SP-2]=C; SP=SP-2;
}

// 0xC6
void OP_ADD_A_D8(void)
{
    if((A&15)+(MEM[PC+1]&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+MEM[PC+1]>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0xC7
void OP_RST_00(void)
{
    *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x00;
}

// 0xC8
void OP_RET_Z(void)
{
    if(FLAG_Z){(*((int8_t*)MEM+SP+2)); SP+=2;   }
}

// 0xC9
void OP_RET(void)
{
    (*((int8_t*)MEM+SP+2)); SP+=2;
}

// 0xCA
void OP_JP_Z_A16(void)
{
    if(FLAG_Z){PC= *((uint16_t*) (MEM+PC+1)); }
}

// 0xCB
// prefix CB is defined below

// 0xCC
void OP_CALL_Z_A16(void)
{
    if(FLAG_Z){MEM[SP-2]=PC+3; SP=SP-2; PC= *((uint16_t*) (MEM+PC+1));   }
}

// 0xCD
void OP_CALL_A16(void)
{
    MEM[SP-2]=PC+3; SP=SP-2; PC= *((uint16_t*) (MEM+PC+1));
}

// 0xCE
void OP_ADC_A_D8(void)
{
    if((A&15)+MEM[PC+1]+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);}
    if(A+MEM[PC+1]+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    A=A+MEM[PC+1]+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0xCF
void OP_RST_08(void)
{
    *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x08;
}

// 0xD0
void OP_RET_NC(void)
{
*(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x08;
}

// 0xD1
void OP_POP_DE(void)
{
    E=MEM[SP+1];D=MEM[SP+2]; SP+=2;
}

// 0xD2
void OP_JP_NC_A16(void)
{
    if(!FLAG_C){PC= *((uint16_t*) (MEM+PC+1)); }
}

// 0xD4
void OP_CALL_NC_A16(void)
{
    if(!FLAG_Z){MEM[SP-2]=PC+3; SP=SP-2; PC= *((uint16_t*) (MEM+PC+1));   }
}

// 0xD5
void OP_PUSH_DE(void)
{
    MEM[SP-1]=D; MEM[SP-2]=E; SP=SP-2;
}

// 0xD6
void OP_SUB_A_D8(void)
{
    if((A&15)<(MEM[PC+1]&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
    if(A<MEM[PC+1]){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
    A=A-MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);
}

// 0xD7
void OP_RST_10(void)
{
    *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x10;
}

// 0xD8
void OP_RET_C(void)
{
    if(FLAG_C){PC=(*((int8_t*)MEM+SP+2)); SP+=2;   }
}

// 0xD9
void OP_RETI(void)
{
    (*((int8_t*)MEM+SP+2)); SP+=2; ENABLE_IME
}

// 0xDA
void OP_JP_C_A16(void)
{
    if(FLAG_C){PC= *((uint16_t*) (MEM+PC+1)); }
}

// 0xDC
void OP_CALL_C_A16(void)
{
    if(FLAG_C){MEM[SP-2]=PC+3; SP=SP-2; PC= *((uint16_t*) (MEM+PC+1));   }
}

// 0xDE
void OP_SBC_A_D8(void)
{
    if((A&15)<(MEM[PC+1])+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
    if(A<MEM[PC+1]+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
    A=A-MEM[PC+1]+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
}

// 0xDF
void OP_RST_18(void)
{
    *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x18;
}

// 0xE0 load A into FF00+n
void OP_LDH_PA8_A(void)
{
    MEM[65280+MEM[PC+1]]=A;
}

// 0xE1
void OP_POP_HL(void)
{
    L=MEM[SP+1];H=MEM[SP+2]; SP+=2;
}

// 0xE2 load A into FF00+C (Offset)
void OP_LD_OC_A(void)
{
    MEM[65280+C]=A;
}

// 0xE5
void OP_PUSH_HL(void)
{
    MEM[SP-1]=H; MEM[SP-2]=L; SP=SP-2;
}

// 0xE6 todo??
void OP_AND_D8(void)
{
    A=A&MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);
}

// 0xE7
void OP_RST_20(void)
{
    *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x20;
}

// 0xE8 HL&2047
void OP_ADD_SP_R8(void)
{
    if(((HL&2047)+(*((int8_t*)MEM+PC+1)))<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    if(((uint32_t)HL+(*((int8_t*)MEM+PC+1)))<32767){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    HL=HL+(*((int8_t*)MEM+PC+1)); SET_FLAG_Z(0); SET_FLAG_N(0);
}

// 0xE9
void OP_JP_PHL(void)
{
    PC=MEM[HL];
}

// 0xEA
void OP_LD_A16_A(void)
{
    *((uint16_t*) (MEM+PC+1))=A;
}

// 0xEE
void OP_XOR_D8(void)
{
    A=A^MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xEF
void OP_RST_28(void)
{
    *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x28;
}

// 0xF0
void OP_LDH_A_A8(void)
{
    A=MEM[65280+MEM[PC+1]];
}

// 0xF1
void OP_POP_AF(void)
{
    F=MEM[SP+1];A=MEM[SP+2]; SP+=2;
}

// 0xF2
void OP_LD_A_OC(void)
{
    A=MEM[65280+C];
}

// 0xF3
void OP_DI(void)
{
    DISABLE_IME
}

// 0xF5
void OP_PUSH_AF(void)
{
    MEM[SP-1]=A; MEM[SP-2]=F; SP=SP-2;
}

// 0xF6
void OP_OR_D8(void)
{
    A=A|MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}
    SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);
}

// 0xF7
void OP_RST_30(void)
{
    *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x30;
}

// 0xF8 todo: SP&2047
void OP_LD_HL_SP_R8(void)
{
    if(((SP&2047)+(*((int8_t*)MEM+PC+1)))<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    if(((uint32_t)SP+(*((int8_t*)MEM+PC+1)))<32767){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    HL=SP+(*((int8_t*)MEM+PC+1)); SET_FLAG_Z(0); SET_FLAG_N(0);
}

// 0xF9
void OP_LD_SP_HL(void)
{
    SP=HL;
}

// 0xFA
void OP_LD_A_A16(void)
{
    A=*((uint16_t*) (MEM+PC+1));
}

// 0xFB
void OP_EI(void)
{
    ENABLE_IME
}

// 0xFE
void OP_CP_D8(void)
{
    if(!(A-MEM[PC+1])){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)};
    if(A<MEM[PC+1]){SET_FLAG_C(1);}else{SET_FLAG_C(0);}
    if((A&15)<MEM[PC+1]){SET_FLAG_H(0);}else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xFB
void OP_RST_38(void)
{
    *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x38;
}