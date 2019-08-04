#include "main.h"

// 0x00
void OP_NOP(void)
{

}

// 0x01
void OP_LD_BC_D16(void)
{
    BC = *((uint16_t*) (MEM + PC + 1));
}

// 0x02
void OP_LD_PBC_A(void)
{
    MEM[BC] = A;
}

// 0x03
void OP_INC_BC(void)
{
    BC++;
}

// 0x04
void OP_INC_B(void)
{
    if((B & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    B++;
    if(!B){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(0);
}

// 0x05
void OP_DEC_B(void)
{
    B--;
    if((B & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(!B){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(1);
}

// 0x06
void OP_LD_B_D8(void)
{
    B = MEM[PC + 1];
}

// 0x07
void OP_RLCA(void)
{
    if(CHECK_BIT(A, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A << 1;
    if(FLAG_C){A = A | 1;} else{A = A & 254;}
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x08
void OP_LD_A16_SP(void)
{
    MEM[*((uint16_t*) (MEM + PC + 1))] = SP;
}

// 0x09
void OP_ADD_HL_BC(void)
{
    if((HL & (2047 + BC)) != 0){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    if((uint32_t) HL + (uint32_t) BC > 65535){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    HL = HL + BC;
    SET_FLAG_N(0);
}

// 0x0A
void OP_LD_A_PBC(void)
{
    A = MEM[BC];
}

// 0x0B
void OP_DEC_BC(void)
{
    BC--;
}

// 0x0C
void OP_INC_C(void)
{
    if((C & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    C++;
    if(!C){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(0);
}

// 0x0D
void OP_DEC_C(void)
{
    C--;
    if((C & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(!C){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(1);

}

// 0x0E
void OP_LD_C_D8(void)
{
    C = MEM[PC + 1];
}

// 0x0F shift right, CarryBit=Bit0 Bit7=Bit0
void OP_RRCA(void)
{
    if(CHECK_BIT(A, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A << 1;
    if(FLAG_C){A = A | 128;} else{A = A & 127;}
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);

}

// 0x10
void OP_STOP(void)
{
    // todo stop
}

// 0x11
void OP_LD_DE_D16(void)
{
    DE = *((uint16_t*) (MEM + PC + 1));
}

// 0x12
void OP_LD_PDE_A(void)
{
    MEM[DE] = A;
}

// 0x13
void OP_INC_DE(void)
{
    DE++;
}

// 0x14
void OP_INC_D(void)
{
    if((D & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    D++;
    if(!D){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(0);

}

// 0x15
void OP_DEC_D(void)
{
    D--;
    if((D & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(!D){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(1);

}

// 0x16
void OP_LD_D_D8(void)
{
    D = MEM[PC + 1];
}

// 0x17
void OP_RLA(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(A, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A << 1;
    if(t8[0]){A = A | 1;} else{A = A & 254;}
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);

}

// 0x18
void OP_JR_R8(void)
{
    PC = PC + (*((int8_t*) MEM + PC + 1));
}

// 0x19
void OP_ADD_HL_DE(void)
{
    if((HL & (2047 + DE)) != 0){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    if((uint32_t) HL + (uint32_t) DE > 65535){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    HL = HL + DE;
    SET_FLAG_N(0);
}

// 0x1A
void OP_LD_A_PDE(void)
{
    A = MEM[DE];
}

// 0x1B
void OP_DEC_DE(void)
{
    DE--;
}

// 0x1C
void OP_INC_E(void)
{
    if((E & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    E++;
    if(!E){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(0);

}

// 0x1D
void OP_DEC_E(void)
{
    E--;
    if((E & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(!E){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(1);

}

// 0x1E
void OP_LD_E_D8(void)
{
    E = MEM[PC + 1];
}

// 0x1F
void OP_RRA(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(A, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A << 1;
    if(t8[0]){A = A | 128;} else{A = A & 127;}
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);

}

// 0x20
void OP_JR_NZ_R8(void)
{
    if(!FLAG_Z)
    {
        PC = PC + (((int8_t*) MEM)[PC + 1]);
    }
}

// 0x21
void OP_LD_HL_D16(void)
{
    HL = ((*((uint16_t*) (MEM + PC + 1))));
}

// 0x22
void OP_LD_PHLI_A(void)
{
    MEM[HL++] = A;
}

// 0x23
void OP_INC_HL(void)
{
    HL++;
}

// 0x24
void OP_INC_H(void)
{
    if((H & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    H++;
    if(!H){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(0);

}

// 0x25
void OP_DEC_H(void)
{
    H--;
    if((H & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(!H){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(1);
}

// 0x26
void OP_LD_H_D8(void)
{
    H = MEM[PC + 1];
}

// 0x27 todo: decimal adjust register A todo
// https://www.tutorialspoint.com/daa-instruction-in-8085-microprocessor
void OP_DAA(void)
{
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_H(0);
    // todo
}

// 0x28
void OP_JR_Z_R8(void)
{
    if(FLAG_Z){PC = PC + (((int8_t*) MEM)[PC + 1]);}
}

// 0x29
void OP_ADD_HL_HL(void)
{
    if((HL & (2047 + HL)) != 0){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    if((uint32_t) HL + (uint32_t) BC > 65535){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    HL = HL + BC;
    SET_FLAG_N(0);
}

// 0x2A
void OP_LD_A_PHLI(void)
{
    A = MEM[HL++];
}

// 0x2B
void OP_DEC_HL(void)
{
    HL--;
}

// 0x2C
void OP_INC_L(void)
{
    if((L & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    L++;
    if(!B){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(0);

}

// 0x2D
void OP_DEC_L(void)
{
    L--;
    if((L & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(!L){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(1);

}

// 0x2E
void OP_LD_L_D8(void)
{
    L = MEM[PC + 1];
}

// 0x2F flip all bits in A
void OP_CPL(void)
{
    A = A ^ 255;
    SET_FLAG_H(1);
    SET_FLAG_N(1);
}

// 0x30
void OP_JR_NC_R8(void)
{
    if(!FLAG_C){PC = PC + (((int8_t*) MEM)[PC + 1]);}
}

// 0x31
void OP_LD_SP_D16(void)
{
    SP = *((uint16_t*) (MEM + PC + 1));
}

// 0x32
void OP_LD_PHLD_A(void)
{
    MEM[HL--] = A;
}

// 0x33
void OP_INC_SP(void)
{
    SP++;
}

// 0x34
void OP_INC_PHL(void)
{
    if((MEM[HL] & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    MEM[HL]++;
    if(!MEM[HL]){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(0);

}

// 0x35
void OP_DEC_PHL(void)
{
    MEM[HL]--;
    if((MEM[HL] & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(!MEM[HL]){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(1);
}

// 0x36
void OP_LD_PHL_D8(void)
{
    MEM[HL] = MEM[PC + 1];
}

// 0x37
void OP_SCF(void)
{
    SET_FLAG_C(1);
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x38
void OP_JR_C_R8(void)
{
    if(FLAG_C){PC = PC + (((int8_t*) MEM)[PC + 1]);}
}

// 0x39
void OP_ADD_HL_SP(void)
{
    if((HL & (2047 + SP)) != 0){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    if((uint32_t) HL + (uint32_t) SP < 32767){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    HL = HL + SP;
    SET_FLAG_N(0);
}

// 0x3A
void OP_LD_A_PHLD(void)
{
    A = MEM[HL--];
}

// 0x3B
void OP_DEC_SP(void)
{
    SP--;
}

// 0x3C
void OP_INC_A(void)
{
    if((A & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    A++;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(0);
}

// 0x3D
void OP_DEC_A(void)
{
    A--;
    if((A & 0xF) == 0xF){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)}
    SET_FLAG_N(1);
}

// 0x3E
void OP_LD_A_D8(void)
{
    A = MEM[PC + 1];
}

// 0x3F complement carry flag
void OP_CCF(void)
{
    SET_FLAG_H(0);
    SET_FLAG_N(0);
    SET_FLAG_C(!FLAG_C);
}

// 0x40
void OP_LD_B_B(void)
{
    B = B;
}

// 0x41
void OP_LD_B_C(void)
{
    B = C;
}

// 0x42
void OP_LD_B_D(void)
{
    B = D;
}

// 0x43
void OP_LD_B_E(void)
{
    B = E;
}

// 0x44
void OP_LD_B_H(void)
{
    B = H;
}

// 0x45
void OP_LD_B_L(void)
{
    B = L;
}

// 0x46
void OP_LD_B_PHL(void)
{
    B = MEM[HL];
}

// 0x47
void OP_LD_B_A(void)
{
    B = A;
}

// 0x48
void OP_LD_C_B(void)
{
    C = B;
}

// 0x49
void OP_LD_C_C(void)
{
    C = C;
}

// 0x4A
void OP_LD_C_D(void)
{
    C = D;
}

// 0x4B
void OP_LD_C_E(void)
{
    C = E;
}

// 0x4C
void OP_LD_C_H(void)
{
    C = H;
}

// 0x4D
void OP_LD_C_L(void)
{
    C = L;
}

// 0x4E
void OP_LD_C_PHL(void)
{
    C = MEM[HL];
}

// 0x4F
void OP_LD_C_A(void)
{
    C = A;
}

// 0x50
void OP_LD_D_B(void)
{
    D = B;
}

// 0x51
void OP_LD_D_C(void)
{
    D = C;
}

// 0x52
void OP_LD_D_D(void)
{
    D = D;
}

// 0x53
void OP_LD_D_E(void)
{
    D = E;
}

// 0x54
void OP_LD_D_H(void)
{
    D = H;
}

// 0x55
void OP_LD_D_L(void)
{
    D = L;
}

// 0x56
void OP_LD_D_PHL(void)
{
    D = MEM[HL];
}

// 0x57
void OP_LD_D_A(void)
{
    D = A;
}

// 0x58
void OP_LD_E_B(void)
{
    E = B;
}

// 0x59
void OP_LD_E_C(void)
{
    E = C;
}

// 0x5A
void OP_LD_E_D(void)
{
    E = D;
}

// 0x5B
void OP_LD_E_E(void)
{
    E = E;
}

// 0x5C
void OP_LD_E_H(void)
{
    E = H;
}

// 0x5D
void OP_LD_E_L(void)
{
    E = L;
}

// 0x5E
void OP_LD_E_PHL(void)
{
    E = MEM[HL];
}

// 0x5F
void OP_LD_E_A(void)
{
    E = A;
}

// 0x60
void OP_LD_H_B(void)
{
    H = B;
}

// 0x61
void OP_LD_H_C(void)
{
    H = C;
}

// 0x62
void OP_LD_H_D(void)
{
    H = D;
}

// 0x63
void OP_LD_H_E(void)
{
    H = E;
}

// 0x64
void OP_LD_H_H(void)
{
    H = H;
}

// 0x65
void OP_LD_H_L(void)
{
    H = L;
}

// 0x66
void OP_LD_H_PHL(void)
{
    H = MEM[HL];
}

// 0x67
void OP_LD_H_A(void)
{
    H = A;
}

// 0x68
void OP_LD_L_B(void)
{
    L = B;
}

// 0x69
void OP_LD_L_C(void)
{
    L = C;
}

// 0x6A
void OP_LD_L_D(void)
{
    L = D;
}

// 0x6B
void OP_LD_L_E(void)
{
    L = E;
}

// 0x6C
void OP_LD_L_H(void)
{
    L = H;
}

// 0x6D
void OP_LD_L_L(void)
{
    L = L;
}

// 0x6E
void OP_LD_L_PHL(void)
{
    L = MEM[HL];
}

// 0x6F
void OP_LD_L_A(void)
{
    L = A;
}

// 0x70
void OP_LD_PHL_B(void)
{
    MEM[HL] = B;
}

// 0x71
void OP_LD_PHL_C(void)
{
    MEM[HL] = C;
}

// 0x72
void OP_LD_PHL_D(void)
{
    MEM[HL] = D;
}

// 0x73
void OP_LD_PHL_E(void)
{
    MEM[HL] = E;
}

// 0x74
void OP_LD_PHL_H(void)
{
    MEM[HL] = H;
}

// 0x75
void OP_LD_PHL_L(void)
{
    MEM[HL] = L;
}

// 0x76
void OP_HALT(void)
{

}

// 0x77
void OP_LD_PHL_A(void)
{
    MEM[HL] = A;
}

// 0x78
void OP_LD_A_B(void)
{
    A = B;
}

// 0x79
void OP_LD_A_C(void)
{
    A = C;
}

// 0x7A
void OP_LD_A_D(void)
{
    A = D;
}

// 0x7B
void OP_LD_A_E(void)
{
    A = E;
}

// 0x7C
void OP_LD_A_H(void)
{
    A = H;
}

// 0x7D
void OP_LD_A_L(void)
{
    A = L;
}

// 0x7E
void OP_LD_A_PHL(void)
{
    A = MEM[HL];
}

// 0x7F
void OP_LD_A_A(void)
{
    A = A;
}

// 0x80 if first 4 bits add to more than 1111 then set H
void OP_ADD_A_B(void)
{
    if((A & 15) + (B & 15) > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + B > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + B;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);

}

// 0x81
void OP_ADD_A_C(void)
{
    if((A & 15) + (C & 15) > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + C > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);

}

// 0x82
void OP_ADD_A_D(void)
{
    if((A & 15) + (D & 15) > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + D > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + D;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x83
void OP_ADD_A_E(void)
{
    if((A & 15) + (E & 15) > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + E > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + E;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x84
void OP_ADD_A_H(void)
{
    if((A & 15) + (H & 15) > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + H > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + H;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x85
void OP_ADD_A_L(void)
{
    if((A & 15) + (L & 15) > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + L > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + L;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x86
void OP_ADD_A_PHL(void)
{
    if((A & 15) + (MEM[HL] & 15) > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + MEM[HL] > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + MEM[HL];
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x87
void OP_ADD_A_A(void)
{
    if((A & 15) + (A & 15) > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + A > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + A;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x88
void OP_ADC_A_B(void)
{
    if((A & 15) + (B & 15) + FLAG_C > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + B + FLAG_C > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + B + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x89
void OP_ADC_A_C(void)
{
    if((A & 15) + (C & 15) + FLAG_C > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + C + FLAG_C > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + C + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x8A
void OP_ADC_A_D(void)
{
    if((A & 15) + (D & 15) + FLAG_C > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + D + FLAG_C > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + D + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x8B
void OP_ADC_A_E(void)
{
    if((A & 15) + (E & 15) + FLAG_C > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + E + FLAG_C > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + E + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x8C
void OP_ADC_A_H(void)
{
    if((A & 15) + (H & 15) + FLAG_C > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + H + FLAG_C > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + H + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x8D
void OP_ADC_A_L(void)
{
    if((A & 15) + (L & 15) + FLAG_C > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + L + FLAG_C > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + L + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x8E
void OP_ADC_A_PHL(void)
{
    if((A & 15) + (MEM[HL] & 15) + FLAG_C > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + MEM[HL] + FLAG_C > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + MEM[HL] + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}


// 0x8F
void OP_ADC_A_A(void)
{
    if((A & 15) + (A & 15) + FLAG_C > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + A + FLAG_C > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + A + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x90
void OP_SUB_A_B(void)
{
    if((A & 15) < (B & 15)){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < B){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - B;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(1);
}

// 0x91
void OP_SUB_A_C(void)
{
    if((A & 15) < (C & 15)){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < C){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(1);
}

// 0x92
void OP_SUB_A_D(void)
{
    if((A & 15) < (D & 15)){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < D){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - D;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(1);
}

// 0x93
void OP_SUB_A_E(void)
{
    if((A & 15) < (E & 15)){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < E){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - E;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(1);
}

// 0x94
void OP_SUB_A_H(void)
{
    if((A & 15) < (H & 15)){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < H){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - H;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(1);
}

// 0x95
void OP_SUB_A_L(void)
{
    if((A & 15) < (L & 15)){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < L){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - L;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(1);
}

// 0x96
void OP_SUB_A_PHL(void)
{
    if((A & 15) < (MEM[HL] & 15)){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < MEM[HL]){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - MEM[HL];
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(1);
}

// 0x97
void OP_SUB_A_A(void)
{
    SET_FLAG_H(0);
    SET_FLAG_C(0);
    A = 0;
    SET_FLAG_Z(1);
    SET_FLAG_N(1);
}

// 0x98
void OP_SBC_A_B(void)
{
    if((A & 15) < (B & 15) + FLAG_C){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < B + FLAG_C){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - B + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x99
void OP_SBC_A_C(void)
{
    if((A & 15) < (C & 15) + FLAG_C){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < C + FLAG_C){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - C + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x9A
void OP_SBC_A_D(void)
{
    if((A & 15) < (D & 15) + FLAG_C){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < D + FLAG_C){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - D + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x9B
void OP_SBC_A_E(void)
{
    if((A & 15) < (E & 15) + FLAG_C){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < E + FLAG_C){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - E + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x9C
void OP_SBC_A_H(void)
{
    if((A & 15) < (H & 15) + FLAG_C){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < H + FLAG_C){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - H + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x9D
void OP_SBC_A_L(void)
{
    if((A & 15) < (L & 15) + FLAG_C){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < L + FLAG_C){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - L + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x9E
void OP_SBC_A_PHL(void)
{
    if((A & 15) < (MEM[HL] & 15) + FLAG_C){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < MEM[HL] + FLAG_C){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - MEM[HL] + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0x9F
void OP_SBC_A_A(void)
{
    if(FLAG_C)
    {
        SET_FLAG_H(1);
        SET_FLAG_C(1);
    }
    else
    {
        SET_FLAG_H(0);
        SET_FLAG_C(0);
    }
    A = FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0xA0
void OP_AND_B(void)
{
    A = A & B;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(1);
    SET_FLAG_N(0);
}

// 0xA1
void OP_AND_C(void)
{
    A = A & C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(1);
    SET_FLAG_N(0);
}

// 0xA2
void OP_AND_D(void)
{
    A = A & D;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(1);
    SET_FLAG_N(0);
}

// 0xA3
void OP_AND_E(void)
{
    A = A & E;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(1);
    SET_FLAG_N(0);
}

// 0xA4
void OP_AND_H(void)
{
    A = A & H;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(1);
    SET_FLAG_N(0);
}

// 0xA5
void OP_AND_L(void)
{
    A = A & L;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(1);
    SET_FLAG_N(0);
}

// 0xA6
void OP_AND_PHL(void)
{
    A = A & MEM[HL];
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(1);
    SET_FLAG_N(0);
}

// 0xA7
void OP_AND_A(void)
{
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(1);
    SET_FLAG_N(0);
}

// 0xA8
void OP_XOR_B(void)
{
    A = A ^ B;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xA9
void OP_XOR_C(void)
{
    A = A ^ C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xAA
void OP_XOR_D(void)
{
    A = A ^ D;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xAB
void OP_XOR_E(void)
{
    A = A ^ E;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xAC
void OP_XOR_H(void)
{
    A = A ^ H;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xAD
void OP_XOR_L(void)
{
    A = A ^ L;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xAE
void OP_XOR_PHL(void)
{
    A = A ^ MEM[HL];
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xAF
void OP_XOR_A(void)
{
    A = 0;
    SET_FLAG_Z(1);
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xB0
void OP_OR_B(void)
{
    A = A | B;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xB1
void OP_OR_C(void)
{
    A = A | C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xB2
void OP_OR_D(void)
{
    A = A | D;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xB3
void OP_OR_E(void)
{
    A = A | E;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xB4
void OP_OR_H(void)
{
    A = A | H;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xB5
void OP_OR_L(void)
{
    A = A | L;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xB6
void OP_OR_PHL(void)
{
    A = A | MEM[HL];
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xB7
void OP_OR_A(void)
{
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xB8
void OP_CP_B(void)
{
    if(!(A - B)){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)};
    if(A < B){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    if((A & 15) < (B & 15)){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xB9
void OP_CP_C(void)
{
    if(!(A - C)){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)};
    if(A < C){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    if((A & 15) < (C & 15)){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBA
void OP_CP_D(void)
{
    if(!(A - D)){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)};
    if(A < D){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    if((A & 15) < (D & 15)){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBB
void OP_CP_E(void)
{
    if(!(A - E)){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)};
    if(A < E){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    if((A & 15) < (E & 15)){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBC
void OP_CP_H(void)
{
    if(!(A - H)){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)};
    if(A < H){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    if((A & 15) < (H & 15)){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBD
void OP_CP_L(void)
{
    if(!(A - L)){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)};
    if(A < L){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    if((A & 15) < (L & 15)){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBE
void OP_CP_PHL(void)
{
    if(!(A - MEM[HL])){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)};
    if(A < MEM[HL]){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    if((A & 15) < (MEM[HL] & 15)){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xBF
void OP_CP_A(void)
{
    SET_FLAG_Z(1);
    SET_FLAG_C(0);
    SET_FLAG_H(1);
    SET_FLAG_N(1);
}

// 0xC0
void OP_RET_NZ(void)
{
    if(!FLAG_Z)
    {
        PC = ((uint16_t*) MEM)[SP];
        SP += 2;
    }
}

// 0xC1
void OP_POP_BC(void)
{
    C = MEM[SP + 0];
    B = MEM[SP + 1];
    SP += 2;
}

// 0xC2
void OP_JP_NZ_A16(void)
{
    if(!FLAG_Z){PC = *((uint16_t*) (MEM + PC + 1));}
}

// 0xC3
void OP_JP_A16(void)
{
    PC = *((uint16_t*) (MEM + PC + 1));
}

// 0xC4
void OP_CALL_NZ_A16(void)
{
    if(!FLAG_Z)
    {
        ((uint16_t*)MEM)[SP - 2] = PC + 3;
        SP = SP - 2;
        PC = *((uint16_t*) (MEM + PC + 1));
    }
}

// 0xC5
void OP_PUSH_BC(void)
{
    MEM[SP - 1] = B;
    MEM[SP - 2] = C;
    SP = SP - 2;
}

// 0xC6
void OP_ADD_A_D8(void)
{
    if((A & 15) + (MEM[PC + 1] & 15) > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + MEM[PC + 1] > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + MEM[PC + 1];
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0xC7
void OP_RST_00(void)
{
    *(((uint16_t*) MEM) + SP - 1) = PC;
    SP -= 2;
    PC = 0x00;
}

// 0xC8
void OP_RET_Z(void)
{
    if(FLAG_Z)
    {
        PC = ((uint16_t*) MEM)[SP];
        SP += 2;
    }
}

// 0xC9
void OP_RET(void)
{
    PC = ((uint16_t*) MEM)[SP];
    SP += 2;
}

// 0xCA
void OP_JP_Z_A16(void)
{
    if(FLAG_Z){PC = *((uint16_t*) (MEM + PC + 1));}
}

// 0xCB
void OP_CB(void)
{
    exec_cb[MEM[PC + 1]]();
    // todo: #33: add cycles
}

// 0xCC
void OP_CALL_Z_A16(void)
{
    if(FLAG_Z)
    {
        ((uint16_t*)MEM)[SP - 2] = PC + 3;
        SP = SP - 2;
        PC = *((uint16_t*) (MEM + PC + 1));
    }
}

// 0xCD
void OP_CALL_A16(void)
{
    ((uint16_t*)MEM)[SP - 2] = PC + 3;
    SP = SP - 2;
    PC = *((uint16_t*) (MEM + PC + 1));
}

// 0xCE
void OP_ADC_A_D8(void)
{
    if((A & 15) + MEM[PC + 1] + FLAG_C > 15){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A + MEM[PC + 1] + FLAG_C > 255){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A + MEM[PC + 1] + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0xCF
void OP_RST_08(void)
{
    *(((uint16_t*) MEM) + SP - 1) = PC;
    SP -= 2;
    PC = 0x08;
}

// 0xD0
void OP_RET_NC(void)
{
    if(!FLAG_C)
    {
        PC = ((uint16_t*) MEM)[SP];
        SP += 2;
    }
}

// 0xD1
void OP_POP_DE(void)
{
    E = MEM[SP + 0];
    D = MEM[SP + 1];
    SP += 2;
}

// 0xD2
void OP_JP_NC_A16(void)
{
    if(!FLAG_C){PC = *((uint16_t*) (MEM + PC + 1));}
}

// 0xD3
void OP_ERROR_D3(void)
{
    ERROR("OPCODE 0xD3 executed");
    exit(EXIT_FAILURE);
}

// 0xD4
void OP_CALL_NC_A16(void)
{
    if(!FLAG_Z)
    {
        ((uint16_t*)MEM)[SP - 2] = PC + 3;
        SP = SP - 2;
        PC = *((uint16_t*) (MEM + PC + 1));
    }
}

// 0xD5
void OP_PUSH_DE(void)
{
    MEM[SP - 1] = D;
    MEM[SP - 2] = E;
    SP = SP - 2;
}

// 0xD6
void OP_SUB_A_D8(void)
{
    if((A & 15) < (MEM[PC + 1] & 15)){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < MEM[PC + 1]){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - MEM[PC + 1];
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(1);
}

// 0xD7
void OP_RST_10(void)
{
    *(((uint16_t*) MEM) + SP - 1) = PC;
    SP -= 2;
    PC = 0x10;
}

// 0xD8
void OP_RET_C(void)
{
    if(FLAG_C)
    {
        PC = ((uint16_t*) MEM)[SP];
        SP += 2;
    }
}

// 0xD9
void OP_RETI(void)
{
    PC = ((uint16_t*) MEM)[SP];
    SP += 2;
    ENABLE_IME
}

// 0xDA
void OP_JP_C_A16(void)
{
    if(FLAG_C){PC = *((uint16_t*) (MEM + PC + 1));}
}

// 0xDB
void OP_ERROR_DB(void)
{
    ERROR("OPCODE 0xDB executed");
    exit(EXIT_FAILURE);
}

// 0xDC
void OP_CALL_C_A16(void)
{
    if(FLAG_C)
    {
        ((uint16_t*)MEM)[SP - 2] = PC + 3;
        SP = SP - 2;
        PC = *((uint16_t*) (MEM + PC + 1));
    }
}

// 0xDD
void OP_ERROR_DD(void)
{
    ERROR("OPCODE 0xDD executed");
    exit(EXIT_FAILURE);
}

// 0xDE
void OP_SBC_A_D8(void)
{
    if((A & 15) < (MEM[PC + 1]) + FLAG_C){SET_FLAG_H(1);} else{SET_FLAG_H(0);}
    if(A < MEM[PC + 1] + FLAG_C){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A - MEM[PC + 1] + FLAG_C;
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
}

// 0xDF
void OP_RST_18(void)
{
    *(((uint16_t*) MEM) + SP - 1) = PC;
    SP -= 2;
    PC = 0x18;
}

// 0xE0 load A into FF00+n
void OP_LDH_PA8_A(void)
{
    MEM[65280 + MEM[PC + 1]] = A;
}

// 0xE1
void OP_POP_HL(void)
{
    L = MEM[SP + 0];
    H = MEM[SP + 1];
    SP += 2;
}

// 0xE2 load A into FF00+C (Offset)
void OP_LD_OC_A(void)
{
    MEM[65280 + C] = A;
}

// 0xE3
void OP_ERROR_E3(void)
{
    ERROR("OPCODE 0xE3 executed");
    exit(EXIT_FAILURE);
}

// 0xE4
void OP_ERROR_E4(void)
{
    ERROR("OPCODE 0xE4 executed");
    exit(EXIT_FAILURE);
}

// 0xE5
void OP_PUSH_HL(void)
{
    MEM[SP - 1] = H;
    MEM[SP - 2] = L;
    SP = SP - 2;
}

// 0xE6 todo??
void OP_AND_D8(void)
{
    A = A & MEM[PC + 1];
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(1);
    SET_FLAG_N(0);
}

// 0xE7
void OP_RST_20(void)
{
    *(((uint16_t*) MEM) + SP - 1) = PC;
    SP -= 2;
    PC = 0x20;
}

// 0xE8 HL&2047
void OP_ADD_SP_R8(void)
{
    if(((HL & 2047) + (*((int8_t*) MEM + PC + 1))) < 2048){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    if(((uint32_t) HL + (*((int8_t*) MEM + PC + 1))) < 32767){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    HL = HL + (*((int8_t*) MEM + PC + 1));
    SET_FLAG_Z(0);
    SET_FLAG_N(0);
}

// 0xE9
void OP_JP_PHL(void)
{
    PC = MEM[HL];
}

// 0xEA
void OP_LD_A16_A(void)
{
    *((uint16_t*) (MEM + PC + 1)) = A;
}

// 0xEB
void OP_ERROR_EB(void)
{
    ERROR("OPCODE 0xEB executed");
    exit(EXIT_FAILURE);
}

// 0xEC
void OP_ERROR_EC(void)
{
    ERROR("OPCODE 0xEC executed");
    exit(EXIT_FAILURE);
}

// 0xED
void OP_ERROR_ED(void)
{
    ERROR("OPCODE 0xED executed");
    exit(EXIT_FAILURE);
}

// 0xEE
void OP_XOR_D8(void)
{
    A = A ^ MEM[PC + 1];
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xEF
void OP_RST_28(void)
{
    *(((uint16_t*) MEM) + SP - 1) = PC;
    SP -= 2;
    PC = 0x28;
}

// 0xF0
void OP_LDH_A_A8(void)
{
    A = MEM[65280 + MEM[PC + 1]];
}

// 0xF1
void OP_POP_AF(void)
{
    F = MEM[SP + 0];
    A = MEM[SP + 1];
    SP += 2;
}

// 0xF2
void OP_LD_A_OC(void)
{
    A = MEM[65280 + C];
}

// 0xF3
void OP_DI(void)
{
    DISABLE_IME
}

// 0xF4
void OP_ERROR_F4(void)
{
    ERROR("OPCODE 0xF4 executed");
    exit(EXIT_FAILURE);
}

// 0xF5
void OP_PUSH_AF(void)
{
    MEM[SP - 1] = A;
    MEM[SP - 2] = F;
    SP = SP - 2;
}

// 0xF6
void OP_OR_D8(void)
{
    A = A | MEM[PC + 1];
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_C(0);
    SET_FLAG_H(0);
    SET_FLAG_N(0);
}

// 0xF7
void OP_RST_30(void)
{
    *(((uint16_t*) MEM) + SP - 1) = PC;
    SP -= 2;
    PC = 0x30;
}

// 0xF8 todo: SP&2047
void OP_LD_HL_SP_R8(void)
{
    if(((SP & 2047) + (*((int8_t*) MEM + PC + 1))) < 2048){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    if(((uint32_t) SP + (*((int8_t*) MEM + PC + 1))) < 32767){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    HL = SP + (*((int8_t*) MEM + PC + 1));
    SET_FLAG_Z(0);
    SET_FLAG_N(0);
}

// 0xF9
void OP_LD_SP_HL(void)
{
    SP = HL;
}

// 0xFA
void OP_LD_A_A16(void)
{
    A = *((uint16_t*) (MEM + PC + 1));
}

// 0xFB
void OP_EI(void)
{
    ENABLE_IME
}

// 0xFC
void OP_ERROR_FC(void)
{
    ERROR("OPCODE 0xFC executed");
    exit(EXIT_FAILURE);
}

// 0xFD
void OP_ERROR_FD(void)
{
    ERROR("OPCODE 0xFD executed");
    exit(EXIT_FAILURE);
}

// 0xFE
void OP_CP_D8(void)
{
    if(!(A - MEM[PC + 1])){SET_FLAG_Z(1);} else{SET_FLAG_Z(0)};
    if(A < MEM[PC + 1]){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    if((A & 15) < MEM[PC + 1]){SET_FLAG_H(0);} else{SET_FLAG_H(1);}
    SET_FLAG_N(1);
}

// 0xFF
void OP_RST_38(void)
{
    *(((uint16_t*) MEM) + SP - 1) = PC;
    SP -= 2;
    PC = 0x38;
}


// prefix CB

// 0x00
void OP_RLC_B(void)
{
    if(CHECK_BIT(B, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    B = B << 1;
    if(!B){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x01
void OP_RLC_C(void)
{
    if(CHECK_BIT(C, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    C = C << 1;
    if(!C){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x02
void OP_RLC_D(void)
{
    if(CHECK_BIT(D, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    D = D << 1;
    if(!D){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x03
void OP_RLC_E(void)
{
    if(CHECK_BIT(E, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    E = E << 1;
    if(!E){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x04
void OP_RLC_H(void)
{
    if(CHECK_BIT(H, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    H = H << 1;
    if(!H){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x05
void OP_RLC_L(void)
{
    if(CHECK_BIT(L, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    L = L << 1;
    if(!L){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x06
void OP_RLC_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    MEM[HL] = MEM[HL] << 1;
    if(!MEM[HL]){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x07
void OP_RLC_A(void)
{
    if(CHECK_BIT(A, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    A = A << 1;
    if(!A){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x08
void OP_RRC_B(void)
{
    if(CHECK_BIT(B, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    B = B >> 1;
    if(!B){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x09
void OP_RRC_C(void)
{
    if(CHECK_BIT(C, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    C = C >> 1;
    if(!C){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x0A
void OP_RRC_D(void)
{
    if(CHECK_BIT(D, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    D = D >> 1;
    if(!D){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x0B
void OP_RRC_E(void)
{
    if(CHECK_BIT(E, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    E = E >> 1;
    if(!E){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x0C
void OP_RRC_H(void)
{
    if(CHECK_BIT(H, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    H = H >> 1;
    if(!H){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x0D
void OP_RRC_L(void)
{
    if(CHECK_BIT(L, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    L = L >> 1;
    if(!L){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x0E
void OP_RRC_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    MEM[HL] = MEM[HL] >> 1;
    if(!MEM[HL]){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x0F
void OP_RRC_A(void)
{
    if(CHECK_BIT(A, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    A = A >> 1;
    if(!A){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x10
void OP_RL_B(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(B, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    B = B << 1;
    if(t8[0]){B = B | 1;} else{B = B & 254;}
    if(!B){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x11
void OP_RL_C(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(C, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    C = C << 1;
    if(t8[0]){C = C | 1;} else{C = C & 254;}
    if(!C){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x12
void OP_RL_D(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(D, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    D = D << 1;
    if(t8[0]){D = D | 1;} else{D = D & 254;}
    if(!D){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x13
void OP_RL_E(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(E, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    E = E << 1;
    if(t8[0]){E = E | 1;} else{E = E & 254;}
    if(!E){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x14
void OP_RL_H(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(H, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    H = H << 1;
    if(t8[0]){H = H | 1;} else{H = H & 254;}
    if(!H){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x15
void OP_RL_L(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(L, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    L = L << 1;
    if(t8[0]){L = L | 1;} else{L = L & 254;}
    if(!L){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x16
void OP_RL_PHL(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(MEM[HL], 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    MEM[HL] = MEM[HL] << 1;
    if(t8[0]){MEM[HL] = MEM[HL] | 1;} else{MEM[HL] = MEM[HL] & 254;}
    if(!MEM[HL]){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x17
void OP_RL_A(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(A, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A << 1;
    if(t8[0]){A = A | 1;} else{A = A & 254;}
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x18
void OP_RR_B(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(B, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    B = B << 1;
    if(t8[0]){B = B | 128;} else{B = B & 127;}
    if(!B){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x19
void OP_RR_C(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(C, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    C = C << 1;
    if(t8[0]){C = C | 128;} else{C = C & 127;}
    if(!C){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x1A
void OP_RR_D(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(D, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    D = D << 1;
    if(t8[0]){D = D | 128;} else{D = D & 127;}
    if(!D){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x1B
void OP_RR_E(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(E, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    E = E << 1;
    if(t8[0]){E = E | 128;} else{B = B & 127;}
    if(!E){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x1C
void OP_RR_H(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(H, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    H = H << 1;
    if(t8[0]){H = H | 128;} else{H = H & 127;}
    if(!H){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x1D
void OP_RR_L(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(L, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    L = L << 1;
    if(t8[0]){L = L | 128;} else{L = L & 127;}
    if(!L){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x1E
void OP_RR_PHL(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(MEM[HL], 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    MEM[HL] = MEM[HL] << 1;
    if(t8[0]){MEM[HL] = MEM[HL] | 128;} else{MEM[HL] = MEM[HL] & 127;}
    if(!MEM[HL]){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x1F
void OP_RR_A(void)
{
    t8[0] = FLAG_C;
    if(CHECK_BIT(A, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    A = A << 1;
    if(t8[0]){A = A | 128;} else{A = A & 127;}
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
}

// 0x20
void OP_SLA_B(void)
{
    if(CHECK_BIT(B, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    B = B << 1;
    B = B & 254;
    if(!B){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x21
void OP_SLA_C(void)
{
    if(CHECK_BIT(C, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    C = C << 1;
    C = C & 254;
    if(!C){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x22
void OP_SLA_D(void)
{
    if(CHECK_BIT(D, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    D = D << 1;
    D = D & 254;
    if(!D){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x23
void OP_SLA_E(void)
{
    if(CHECK_BIT(E, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    E = E << 1;
    E = E & 254;
    if(!C){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x24
void OP_SLA_H(void)
{
    if(CHECK_BIT(H, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    H = H << 1;
    H = H & 254;
    if(!H){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x25
void OP_SLA_L(void)
{
    if(CHECK_BIT(L, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    L = L << 1;
    L = L & 254;
    if(!L){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x26
void OP_SLA_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    MEM[HL] = MEM[HL] << 1;
    MEM[HL] = MEM[HL] & 254;
    if(!MEM[HL]){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x27
void OP_SLA_A(void)
{
    if(CHECK_BIT(A, 7)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    A = A << 1;
    A = A & 254;
    if(!A){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x28
void OP_SRA_B(void)
{
    if(CHECK_BIT(B, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    B = B >> 1;
    if(!B){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x29
void OP_SRA_C(void)
{
    if(CHECK_BIT(C, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    C = C >> 1;
    if(!C){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x2A
void OP_SRA_D(void)
{
    if(CHECK_BIT(D, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    D = D >> 1;
    if(!D){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x2B
void OP_SRA_E(void)
{
    if(CHECK_BIT(E, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    E = E >> 1;
    if(!E){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x2C
void OP_SRA_H(void)
{
    if(CHECK_BIT(H, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    H = H >> 1;
    if(!H){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x2D
void OP_SRA_L(void)
{
    if(CHECK_BIT(L, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    L = L >> 1;
    if(!L){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x2E
void OP_SRA_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    MEM[HL] = MEM[HL] >> 1;
    if(!MEM[HL]){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x2F
void OP_SRA_A(void)
{
    if(CHECK_BIT(A, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    A = A >> 1;
    if(!A){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x30
void OP_SWAP_B(void)
{
    t8[0] = B;
    B = B >> 4;
    t8[0] = t8[0] << 4;
    B = B + t8[0];
    SET_FLAG_H(0);
    SET_FLAG_N(0);
    SET_FLAG_C(0);
    if(!B){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
}

// 0x31
void OP_SWAP_C(void)
{
    t8[0] = C;
    C = C >> 4;
    t8[0] = t8[0] << 4;
    C = C + t8[0];
    SET_FLAG_H(0);
    SET_FLAG_N(0);
    SET_FLAG_C(0);
    if(!C){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
}

// 0x32
void OP_SWAP_D(void)
{
    t8[0] = D;
    D = D >> 4;
    t8[0] = t8[0] << 4;
    D = D + t8[0];
    SET_FLAG_H(0);
    SET_FLAG_N(0);
    SET_FLAG_C(0);
    if(!D){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
}

// 0x33
void OP_SWAP_E(void)
{
    t8[0] = E;
    B = B >> 4;
    t8[0] = t8[0] << 4;
    E = E + t8[0];
    SET_FLAG_H(0);
    SET_FLAG_N(0);
    SET_FLAG_C(0);
    if(!E){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
}

// 0x34
void OP_SWAP_H(void)
{
    t8[0] = H;
    H = H >> 4;
    t8[0] = t8[0] << 4;
    H = H + t8[0];
    SET_FLAG_H(0);
    SET_FLAG_N(0);
    SET_FLAG_C(0);
    if(!H){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
}

// 0x35
void OP_SWAP_L(void)
{
    t8[0] = L;
    L = L >> 4;
    t8[0] = t8[0] << 4;
    L = L + t8[0];
    SET_FLAG_H(0);
    SET_FLAG_N(0);
    SET_FLAG_C(0);
    if(!L){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
}

// 0x36
void OP_SWAP_PHL(void)
{
    t8[0] = MEM[HL];
    MEM[HL] = MEM[HL] >> 4;
    t8[0] = t8[0] << 4;
    MEM[HL] = MEM[HL] + t8[0];
    SET_FLAG_H(0);
    SET_FLAG_N(0);
    SET_FLAG_C(0);
    if(!MEM[HL]){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
}

// 0x37
void OP_SWAP_A(void)
{
    t8[0] = A;
    A = A >> 4;
    t8[0] = t8[0] << 4;
    A = A + t8[0];
    SET_FLAG_H(0);
    SET_FLAG_N(0);
    SET_FLAG_C(0);
    if(!A){SET_FLAG_Z(1);} else{SET_FLAG_Z(0);}
}

// 0x38
void OP_SRL_B(void)
{
    if(CHECK_BIT(B, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    B = B >> 1;
    B = B & 127;
    if(!B){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x39
void OP_SRL_C(void)
{
    if(CHECK_BIT(C, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    C = C >> 1;
    C = C & 127;
    if(!C){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x3A
void OP_SRL_D(void)
{
    if(CHECK_BIT(D, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    D = D >> 1;
    D = D & 127;
    if(!D){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x3B
void OP_SRL_E(void)
{
    if(CHECK_BIT(E, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    E = E >> 1;
    E = E & 127;
    if(!E){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x3C
void OP_SRL_H(void)
{
    if(CHECK_BIT(H, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    H = H >> 1;
    H = H & 127;
    if(!H){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x3D
void OP_SRL_L(void)
{
    if(CHECK_BIT(L, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    L = L >> 1;
    L = L & 127;
    if(!L){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x3E
void OP_SRL_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    MEM[HL] = MEM[HL] >> 1;
    MEM[HL] = MEM[HL] & 127;
    if(!MEM[HL]){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x3F
void OP_SRL_A(void)
{
    if(CHECK_BIT(A, 0)){SET_FLAG_C(1);} else{SET_FLAG_C(0);}
    SET_FLAG_N(0);
    SET_FLAG_H(0);
    A = A >> 1;
    A = A & 127;
    if(!A){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
}

// 0x40
void OP_BIT_0_B(void)
{
    if(CHECK_BIT(B, 0)){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x41
void OP_BIT_0_C(void)
{
    if(CHECK_BIT(C, 0)){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x42
void OP_BIT_0_D(void)
{
    if(CHECK_BIT(D, 0)){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x43
void OP_BIT_0_E(void)
{
    if(CHECK_BIT(E, 0)){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x44
void OP_BIT_0_H(void)
{
    if(CHECK_BIT(H, 0)){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x45
void OP_BIT_0_L(void)
{
    if(CHECK_BIT(L, 0)){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x46
void OP_BIT_0_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 0)){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x47
void OP_BIT_0_A(void)
{
    if(CHECK_BIT(A, 0)){SET_FLAG_Z(0);} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x48
void OP_BIT_1_B(void)
{
    if(CHECK_BIT(B, 1)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x49
void OP_BIT_1_C(void)
{
    if(CHECK_BIT(C, 1)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x4A
void OP_BIT_1_D(void)
{
    if(CHECK_BIT(D, 1)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x4B
void OP_BIT_1_E(void)
{
    if(CHECK_BIT(E, 1)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x4C
void OP_BIT_1_H(void)
{
    if(CHECK_BIT(H, 1)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x4D
void OP_BIT_1_L(void)
{
    if(CHECK_BIT(L, 1)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x4E
void OP_BIT_1_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 1)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x4F
void OP_BIT_1_A(void)
{
    if(CHECK_BIT(A, 1)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x50
void OP_BIT_2_B(void)
{
    if(CHECK_BIT(B, 2)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x51
void OP_BIT_2_C(void)
{
    if(CHECK_BIT(C, 2)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x52
void OP_BIT_2_D(void)
{
    if(CHECK_BIT(D, 2)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x53
void OP_BIT_2_E(void)
{
    if(CHECK_BIT(E, 2)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x54
void OP_BIT_2_H(void)
{
    if(CHECK_BIT(H, 2)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x55
void OP_BIT_2_L(void)
{
    if(CHECK_BIT(L, 2)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x56
void OP_BIT_2_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 2)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x57
void OP_BIT_2_A(void)
{
    if(CHECK_BIT(A, 2)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x58
void OP_BIT_3_B(void)
{
    if(CHECK_BIT(B, 3)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x59
void OP_BIT_3_C(void)
{
    if(CHECK_BIT(C, 3)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x5A
void OP_BIT_3_D(void)
{
    if(CHECK_BIT(D, 3)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x5B
void OP_BIT_3_E(void)
{
    if(CHECK_BIT(E, 3)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x5C
void OP_BIT_3_H(void)
{
    if(CHECK_BIT(H, 3)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x5D
void OP_BIT_3_L(void)
{
    if(CHECK_BIT(L, 3)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x5E
void OP_BIT_3_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 3)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x5F
void OP_BIT_3_A(void)
{
    if(CHECK_BIT(A, 3)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x60
void OP_BIT_4_B(void)
{
    if(CHECK_BIT(B, 4)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x61
void OP_BIT_4_C(void)
{
    if(CHECK_BIT(C, 4)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x62
void OP_BIT_4_D(void)
{
    if(CHECK_BIT(D, 4)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x63
void OP_BIT_4_E(void)
{
    if(CHECK_BIT(E, 4)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x64
void OP_BIT_4_H(void)
{
    if(CHECK_BIT(H, 4)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x65
void OP_BIT_4_L(void)
{
    if(CHECK_BIT(L, 4)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x66
void OP_BIT_4_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 4)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x67
void OP_BIT_4_A(void)
{
    if(CHECK_BIT(A, 4)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x68
void OP_BIT_5_B(void)
{
    if(CHECK_BIT(B, 5)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x69
void OP_BIT_5_C(void)
{
    if(CHECK_BIT(C, 5)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x6A
void OP_BIT_5_D(void)
{
    if(CHECK_BIT(D, 5)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x6B
void OP_BIT_5_E(void)
{
    if(CHECK_BIT(E, 5)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x6C
void OP_BIT_5_H(void)
{
    if(CHECK_BIT(H, 5)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x6D
void OP_BIT_5_L(void)
{
    if(CHECK_BIT(L, 5)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x6E
void OP_BIT_5_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 5)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x6F
void OP_BIT_5_A(void)
{
    if(CHECK_BIT(A, 5)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x70
void OP_BIT_6_B(void)
{
    if(CHECK_BIT(B, 6)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x71
void OP_BIT_6_C(void)
{
    if(CHECK_BIT(C, 6)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x72
void OP_BIT_6_D(void)
{
    if(CHECK_BIT(D, 6)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x73
void OP_BIT_6_E(void)
{
    if(CHECK_BIT(E, 6)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x74
void OP_BIT_6_H(void)
{
    if(CHECK_BIT(H, 6)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x75
void OP_BIT_6_L(void)
{
    if(CHECK_BIT(L, 6)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x76
void OP_BIT_6_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 6)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x77
void OP_BIT_6_A(void)
{
    if(CHECK_BIT(A, 6)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x78
void OP_BIT_7_B(void)
{
    if(CHECK_BIT(B, 7)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x79
void OP_BIT_7_C(void)
{
    if(CHECK_BIT(C, 7)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x7A
void OP_BIT_7_D(void)
{
    if(CHECK_BIT(D, 7)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x7B
void OP_BIT_7_E(void)
{
    if(CHECK_BIT(E, 7)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x7C
void OP_BIT_7_H(void)
{
    if(CHECK_BIT(H, 7)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x7D
void OP_BIT_7_L(void)
{
    if(CHECK_BIT(L, 7)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x7E
void OP_BIT_7_PHL(void)
{
    if(CHECK_BIT(MEM[HL], 7)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x7F
void OP_BIT_7_A(void)
{
    if(CHECK_BIT(A, 7)){SET_FLAG_Z(0)} else{SET_FLAG_Z(1);}
    SET_FLAG_N(1);
    SET_FLAG_N(0);
}

// 0x80
void OP_RES_0_B(void)
{
    B = B & 254;
}

// 0x81
void OP_RES_0_C(void)
{
    C = C & 254;
}

// 0x82
void OP_RES_0_D(void)
{
    D = D & 254;
}


// 0x83
void OP_RES_0_E(void)
{
    E = E & 254;
}

// 0x84
void OP_RES_0_H(void)
{
    H = H & 254;
}

// 0x85
void OP_RES_0_L(void)
{
    L = L & 254;
}

// 0x86
void OP_RES_0_PHL(void)
{
    MEM[HL] = MEM[HL] & 254;
}

// 0x87
void OP_RES_0_A(void)
{
    A = A & 254;
}

// 0x88
void OP_RES_1_B(void)
{
    B = B & 253;
}

// 0x89
void OP_RES_1_C(void)
{
    C = C & 253;
}

// 0x8A
void OP_RES_1_D(void)
{
    D = D & 253;
}

// 0x8B
void OP_RES_1_E(void)
{
    E = E & 253;
}

// 0x8C
void OP_RES_1_H(void)
{
    H = H & 253;
}

// 0x8D
void OP_RES_1_L(void)
{
    L = L & 253;
}

// 0x8E
void OP_RES_1_PHL(void)
{
    MEM[HL] = MEM[HL] & 253;
}

// 0x8F
void OP_RES_1_A(void)
{
    A = A & 253;
}

// 0x90
void OP_RES_2_B(void)
{
    B = B & 251;
}

// 0x91
void OP_RES_2_C(void)
{
    C = C & 251;
}

// 0x92
void OP_RES_2_D(void)
{
    D = D & 251;
}

// 0x93
void OP_RES_2_E(void)
{
    E = E & 251;
}

// 0x94
void OP_RES_2_H(void)
{
    H = H & 251;
}

// 0x95
void OP_RES_2_L(void)
{
    L = L & 251;
}

// 0x96
void OP_RES_2_PHL(void)
{
    MEM[HL] = MEM[HL] & 251;
}

// 0x97
void OP_RES_2_A(void)
{
    A = A & 251;
}

// 0x98
void OP_RES_3_B(void)
{
    B = B & 247;
}

// 0x99
void OP_RES_3_C(void)
{
    C = C & 247;
}

// 0x9A
void OP_RES_3_D(void)
{
    D = D & 247;
}

// 0x9B
void OP_RES_3_E(void)
{
    E = E & 247;
}

// 0x9C
void OP_RES_3_H(void)
{
    H = H & 247;
}

// 0x9D
void OP_RES_3_L(void)
{
    L = L & 247;
}

// 0x9E
void OP_RES_3_PHL(void)
{
    MEM[HL] = MEM[HL] & 247;
}

// 0x9F
void OP_RES_3_A(void)
{
    A = A & 247;
}

// 0xA0
void OP_RES_4_B(void)
{
    B = B & 239;
}

// 0xA1
void OP_RES_4_C(void)
{
    C = C & 239;
}

// 0xA2
void OP_RES_4_D(void)
{
    D = D & 239;
}

// 0xA3
void OP_RES_4_E(void)
{
    E = E & 239;
}

// 0xA4
void OP_RES_4_H(void)
{
    H = H & 239;
}

// 0xA5
void OP_RES_4_L(void)
{
    L = L & 239;
}

// 0xA6
void OP_RES_4_PHL(void)
{
    MEM[HL] = MEM[HL] & 239;
}

// 0xA7
void OP_RES_4_A(void)
{
    A = A & 239;
}

// 0xA8
void OP_RES_5_B(void)
{
    B = B & 223;
}

// 0xA9
void OP_RES_5_C(void)
{
    C = C & 223;
}

// 0xAA
void OP_RES_5_D(void)
{
    D = D & 223;
}

// 0xAB
void OP_RES_5_E(void)
{
    E = E & 223;
}

// 0xAC
void OP_RES_5_H(void)
{
    H = H & 223;
}

// 0xAD
void OP_RES_5_L(void)
{
    L = L & 223;
}

// 0xAE
void OP_RES_5_PHL(void)
{
    MEM[HL] = MEM[HL] & 223;
}

// 0xAF
void OP_RES_5_A(void)
{
    A = A & 223;
}

// 0xB0
void OP_RES_6_B(void)
{
    B = B & 191;
}

// 0xB1
void OP_RES_6_C(void)
{
    C = C & 191;
}

// 0xB2
void OP_RES_6_D(void)
{
    D = D & 191;
}

// 0xB3
void OP_RES_6_E(void)
{
    E = E & 191;
}

// 0xB4
void OP_RES_6_H(void)
{
    H = H & 191;
}

// 0xB5
void OP_RES_6_L(void)
{
    L = L & 191;
}

// 0xB6
void OP_RES_6_PHL(void)
{
    MEM[HL] = MEM[HL] & 191;
}

// 0xB7
void OP_RES_6_A(void)
{
    A = A & 191;
}

// 0xB8
void OP_RES_7_B(void)
{
    B = B & 127;
}

// 0xB9
void OP_RES_7_C(void)
{
    C = C & 127;
}

// 0xBA
void OP_RES_7_D(void)
{
    D = D & 127;
}

// 0xBB
void OP_RES_7_E(void)
{
    E = E & 127;
}

// 0xBC
void OP_RES_7_H(void)
{
    H = H & 127;
}

// 0xBD
void OP_RES_7_L(void)
{
    L = L & 127;
}

// 0xBE
void OP_RES_7_PHL(void)
{
    MEM[HL] = MEM[HL] & 127;
}

// 0xBF
void OP_RES_7_A(void)
{
    A = A & 127;
}

// 0xC0
void OP_SET_0_B(void)
{
    B = B | 1;
}

// 0xC1
void OP_SET_0_C(void)
{
    C = C | 1;
}

// 0xC2
void OP_SET_0_D(void)
{
    D = D | 1;
}

// 0xC3
void OP_SET_0_E(void)
{
    E = E | 1;
}

// 0xC4
void OP_SET_0_H(void)
{
    H = H | 1;
}

// 0xC5
void OP_SET_0_L(void)
{
    L = L | 1;
}

// 0xC6
void OP_SET_0_PHL(void)
{
    MEM[HL] = MEM[HL] | 1;
}

// 0xC7
void OP_SET_0_A(void)
{
    A = A | 1;
}

// 0xC8
void OP_SET_1_B(void)
{
    B = B | 2;
}

// 0xC9
void OP_SET_1_C(void)
{
    C = C | 2;
}

// 0xCA
void OP_SET_1_D(void)
{
    D = D | 2;
}

// 0xCB
void OP_SET_1_E(void)
{
    E = E | 2;
}

// 0xCC
void OP_SET_1_H(void)
{
    H = H | 2;
}

// 0xCD
void OP_SET_1_L(void)
{
    L = L | 2;
}

// 0xCE
void OP_SET_1_PHL(void)
{
    MEM[HL] = MEM[HL] | 2;
}

// 0xCF
void OP_SET_1_A(void)
{
    A = A | 2;
}

// 0xD0
void OP_SET_2_B(void)
{
    B = B | 4;
}

// 0xD1
void OP_SET_2_C(void)
{
    C = C | 4;
}

// 0xD2
void OP_SET_2_D(void)
{
    D = D | 4;
}

// 0xD3
void OP_SET_2_E(void)
{
    E = E | 4;
}

// 0xD4
void OP_SET_2_H(void)
{
    H = H | 4;
}

// 0xD5
void OP_SET_2_L(void)
{
    L = L | 4;
}

// 0xD6
void OP_SET_2_PHL(void)
{
    MEM[HL] = MEM[HL] | 4;
}

// 0xD7
void OP_SET_2_A(void)
{
    A = A | 4;
}

// 0xD8
void OP_SET_3_B(void)
{
    B = B | 8;
}

// 0xD9
void OP_SET_3_C(void)
{
    C = C | 8;
}

// 0xDA
void OP_SET_3_D(void)
{
    D = D | 8;
}

// 0xDB
void OP_SET_3_E(void)
{
    E = E | 8;
}

// 0xDC
void OP_SET_3_H(void)
{
    H = H | 8;
}

// 0xDD
void OP_SET_3_L(void)
{
    L = L | 8;
}

// 0xDE
void OP_SET_3_PHL(void)
{
    MEM[HL] = MEM[HL] | 8;
}

// 0xDF
void OP_SET_3_A(void)
{
    A = A | 8;
}

// 0xE0
void OP_SET_4_B(void)
{
    B = B | 16;
}

// 0xE1
void OP_SET_4_C(void)
{
    C = C | 16;
}

// 0xE2
void OP_SET_4_D(void)
{
    D = D | 16;
}

// 0xE3
void OP_SET_4_E(void)
{
    E = E | 16;
}

// 0xE4
void OP_SET_4_H(void)
{
    H = H | 16;
}

// 0xE5
void OP_SET_4_L(void)
{
    L = L | 16;
}

// 0xE6
void OP_SET_4_PHL(void)
{
    MEM[HL] = MEM[HL] | 16;
}

// 0xE7
void OP_SET_4_A(void)
{
    A = A | 16;
}

// 0xE8
void OP_SET_5_B(void)
{
    B = B | 32;
}

// 0xE9
void OP_SET_5_C(void)
{
    C = C | 32;
}

// 0xEA
void OP_SET_5_D(void)
{
    D = D | 32;
}

// 0xEB
void OP_SET_5_E(void)
{
    E = E | 32;
}

// 0xEC
void OP_SET_5_H(void)
{
    H = H | 32;
}

// 0xED
void OP_SET_5_L(void)
{
    L = L | 32;
}

// 0xEE
void OP_SET_5_PHL(void)
{
    MEM[HL] = MEM[HL] | 32;
}

// 0xEF
void OP_SET_5_A(void)
{
    A = A | 32;
}

// 0xF0
void OP_SET_6_B(void)
{
    B = B | 64;
}

// 0xF1
void OP_SET_6_C(void)
{
    C = C | 64;
}

// 0xF2
void OP_SET_6_D(void)
{
    D = D | 64;
}

// 0xF3
void OP_SET_6_E(void)
{
    E = E | 64;
}

// 0xF4
void OP_SET_6_H(void)
{
    H = H | 64;
}

// 0xF5
void OP_SET_6_L(void)
{
    L = L | 64;
}

// 0xF6
void OP_SET_6_PHL(void)
{
    MEM[HL] = MEM[HL] | 64;
}

// 0xF7
void OP_SET_6_A(void)
{
    A = A | 64;
}

// 0xF8
void OP_SET_7_B(void)
{
    B = B | 128;
}

// 0xF9
void OP_SET_7_C(void)
{
    C = C | 128;
}

// 0xFA
void OP_SET_7_D(void)
{
    D = D | 128;
}

// 0xFB
void OP_SET_7_E(void)
{
    E = E | 128;
}

// 0xFC
void OP_SET_7_H(void)
{
    H = H | 128;
}

// 0xFD
void OP_SET_7_L(void)
{
    L = L | 128;
}

// 0xFE
void OP_SET_7_PHL(void)
{
    MEM[HL] = MEM[HL] | 128;
}

// 0xFF
void OP_SET_7_A(void)
{
    A = A | 128;
}







