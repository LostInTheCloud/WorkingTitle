// 0x00
void OP_NOP(void);

// 0x01
void OP_LD_BC_D16(void);

// 0x02 ld (BC) A
void OP_LD_PBC_A(void);

// 0x03
void OP_INC_BC(void);

// 0x04
void OP_INC_B(void);

// 0x05
void OP_DEC_B(void);

// 0x06
void OP_LD_B_D8(void);

// 0x07
void OP_RLCA(void);

// 0x08
void OP_LD_A16_SP(void);

// 0x09
void OP_ADD_HL_BC(void);

// 0x0A
void OP_LD_A_PBC(void);

// 0x0B
void OP_DEC_BC(void);

// 0x0C
void OP_INC_C(void);

// 0x0D
void OP_DEC_BC(void);

// 0x0E
void OP_LD_C_D8(void);

// 0x0F shift right, CarryBit=Bit0 Bit7=Bit0
void OP_RRCA(void);

// 0x10
// todo
void OP_STOP(void);

// 0x11
void OP_LD_DE_D16(void);

// 0x12
void OP_LD_PDE_A(void);

// 0x13
void OP_INC_DE(void);

// 0x14
void OP_INC_D(void);

// 0x15
void OP_DEC_D(void);

// 0x16
void OP_LD_D_D8(void);

// 0x17
void OP_RLA(void);

// 0x18
void OP_JR_R8(void);

// 0x19
void OP_ADD_HL_DE(void);

// 0x1A
void OP_LD_A_PDE(void);

// 0x1B
void OP_DEC_DE(void);

// 0x1C
void OP_INC_E(void);

// 0x1D
void OP_DEC_E(void);

// 0x1E
void OP_LD_E_D8(void);

// 0x1F
void OP_RRA(void);

// 0x20
void OP_JR_NZ_R8(void);

// 0x21
void OP_LD_HL_D16(void);

// 0x22
void OP_LD_PHLI_A(void);

// 0x23
void OP_INC_HL(void);

// 0x24
void OP_INC_H(void);

// 0x25
void OP_DEC_H(void);

// 0x26
void OP_LD_H_D8(void);

// 0x27 decimal adjust register A
// todo
void OP_DAA(void);

// 0x28
void OP_JR_Z_R8(void);

// 0x29
void OP_ADD_HL_HL(void);

// 0x2A
void OP_LD_A_PHLI(void);

// 0x2B
void OP_DEC_HL(void);

// 0x2C
void OP_INC_L(void);

// 0x2D
void OP_DEC_L(void);

// 0x2E
void OP_LD_L_D8(void);

// 0x2F flip all bits in A
void OP_CPL(void);

// 0x30
void OP_JR_NC_R8(void);

// 0x31
void OP_LD_SP_D16(void);

// 0x32
void OP_LD_PHLD_A(void);

// 0x33
void OP_INC_SP(void);

// 0x34
void OP_INC_PHL(void);

// 0x35
void OP_DEC_PHL(void);

// 0x36
void OP_LD_PHL_D8(void);

// 0x37
void OP_SCF(void);

//0x38
void OP_JR_C_R8(void);

// 0x39
void OP_ADD_HL_SP(void);

// 0x3A
void OP_LD_A_PHLD(void);

// 0x3B
void OP_DEC_SP(void);

// 0x3C
void OP_INC_A(void);

// 0x3D
void OP_DEC_A(void);

// 0x3E
void OP_LD_A_D8(void);

// 0x3F complement carry flag
void OP_CCF(void);

// 0x40
void OP_LD_B_B(void);

// 0x41
void OP_LD_B_C(void);

// 0x42
void OP_LD_B_D(void);

// 0x43
void OP_LD_B_E(void);

// 0x44
void OP_LD_B_H(void);

// 0x45
void OP_LD_B_L(void);

// 0x46
void OP_LD_B_PHL(void);

// 0x47
void OP_LD_B_A(void);

// 0x48
void OP_LD_C_B(void);

// 0x49
void OP_LD_C_C(void);

// 0x4A
void OP_LD_C_D(void);

// 0x4B
void OP_LD_C_E(void);

// 0x4C
void OP_LD_C_H(void);

// 0x4D
void OP_LD_C_L(void);

// 0x4E
void OP_LD_C_PHL(void);

// 0x4F
void OP_LD_C_A(void);

// 0x50
void OP_LD_D_B(void);

// 0x51
void OP_LD_D_C(void);

// 0x52
void OP_LD_D_D(void);

// 0x53
void OP_LD_D_E(void);

// 0x54
void OP_LD_D_H(void);

// 0x55
void OP_LD_D_L(void);

// 0x56
void OP_LD_D_PHL(void);

// 0x57
void OP_LD_D_A(void);

// 0x58
void OP_LD_E_B(void);

// 0x59
void OP_LD_E_C(void);

// 0x5A
void OP_LD_E_D(void);

// 0x5B
void OP_LD_E_E(void);

// 0x5C
void OP_LD_E_H(void);

// 0x5D
void OP_LD_E_L(void);

// 0x5E
void OP_LD_E_PHL(void);

// 0x5F
void OP_LD_E_A(void);

// 0x60
void OP_LD_H_B(void);

// 0x61
void OP_LD_H_C(void);

// 0x62
void OP_LD_H_D(void);

// 0x63
void OP_LD_H_E(void);

// 0x64
void OP_LD_H_H(void);

// 0x65
void OP_LD_H_L(void);

// 0x66
void OP_LD_H_PHL(void);

// 0x67
void OP_LD_H_A(void);

// 0x68
void OP_LD_L_B(void);

// 0x69
void OP_LD_L_C(void);

// 0x6A
void OP_LD_L_D(void);

// 0x6B
void OP_LD_L_E(void);

// 0x6C
void OP_LD_L_H(void);

// 0x6D
void OP_LD_L_L(void);

// 0x6E
void OP_LD_L_PHL(void);

// 0x6F
void OP_LD_L_A(void);

// 0x70
void OP_LD_PHL_B(void);

// 0x71
void OP_LD_PHL_C(void);

// 0x72
void OP_LD_PHL_D(void);

// 0x73
void OP_LD_PHL_E(void);

// 0x74
void OP_LD_PHL_H(void);

// 0x75
void OP_LD_PHL_L(void);

// 0x76
// todo
void OP_HALT(void);

// 0x77
void OP_LD_PHL_A(void);

// 0x78
void OP_LD_A_B(void);

// 0x79
void OP_LD_A_C(void);

//0 x7A
void OP_LD_A_E(void);

// 0x7B
void OP_LD_A_E(void);

//0 x7C
void OP_LD_A_H(void);

// 0x7D
void OP_LD_A_L(void);

// 0x7E
void OP_LD_A_PHL(void);

// 0x7F
void OP_LD_A_A(void);

// 0x80 if first 4 bits add to more than 1111 then set H
void OP_ADD_A_B(void);

// 0x81
void OP_ADD_A_C(void);

// 0x82
void OP_ADD_A_D(void);

// 0x83
void OP_ADD_A_E(void);

// 0x84
void OP_ADD_A_H(void);

// 0x85
void OP_ADD_A_L(void);

// 0x86
void OP_ADD_A_PHL(void);

// 0x87
void OP_ADD_A_A(void);

// 0x88
void OP_ADC_A_B(void);

// 0x89
void OP_ADC_A_C(void);

// 0x8A
void OP_ADC_A_D(void);

// 0x8B
void OP_ADC_A_E(void);

// 0x8C
void OP_ADC_A_H(void);

// 0x8D
void OP_ADC_A_L(void);

// 0x8E
void OP_ADC_A_PHL(void);

// 0x8F
void OP_ADC_A_A(void);

// 0x90
void OP_SUB_A_B(void);

// 0x91
void OP_SUB_A_C(void);

// 0x92
void OP_SUB_A_D(void);

// 0x93
void OP_SUB_A_E(void);

// 0x94
void OP_SUB_A_H(void);

// 0x95
void OP_SUB_A_L(void);

// 0x96
void OP_SUB_A_PHL(void);

// 0x97
void OP_SUB_A_A(void);

// 0x98
void OP_SBC_A_B(void);

// 0x99
void OP_SBC_A_C(void);

// 0x9A
void OP_SBC_A_D(void);

// 0x9B
void OP_SBC_A_E(void);

// 0x9C
void OP_SBC_A_H(void);

// 0x9D
void OP_SBC_A_L(void);

// 0x9E
void OP_SBC_A_PHL(void);

// 0x9F
void OP_SBC_A_A(void);

// 0xA0
void OP_AND_B(void);

// 0xA1
void OP_AND_C(void);
// 0xA2
void OP_AND_D(void);

// 0xA3
void OP_AND_E(void);

// 0xA4
void OP_AND_H(void);

// 0xA5
void OP_AND_L(void);
// 0xA6
void OP_AND_PHL(void);

// 0xA7
void OP_AND_A(void);

// 0xA8
void OP_XOR_B(void);

// 0xA9
void OP_XOR_C(void);

// 0xAA
void OP_XOR_D(void);

// 0xAB
void OP_XOR_E(void);

// 0xAC
void OP_XOR_H(void);

// 0xAD
void OP_XOR_L(void);

// 0xAE
void OP_XOR_PHL(void);

// 0xAF
void OP_XOR_A(void);

// 0xB0
void OP_OR_B(void);

// 0xB1
void OP_OR_C(void);

// 0xB2
void OP_OR_D(void);

// 0xB3
void OP_OR_E(void);

// 0xB4
void OP_OR_H(void);

// 0xB5
void OP_OR_L(void);

// 0xB6
void OP_OR_PHL(void);

// 0xB7
void OP_OR_A(void);

// 0xB8
void OP_CP_B(void);

// 0xB9
void OP_CP_C(void);

// 0xBA
void OP_CP_D(void);

// 0xBB
void OP_CP_E(void);

// 0xBC
void OP_CP_H(void);

// 0xBD
void OP_CP_L(void);

// 0xBE
void OP_CP_PHL(void);

// 0xBF
void OP_CP_A(void);

// 0xC0
void OP_RET_NZ(void);

// 0xC1
void OP_POP_BC(void);

// 0xC2
void OP_JP_NZ_A16(void);

// 0xC3
void OP_JP_A16(void);

// 0xC4
void OP_CALL_NZ_A16(void);

// 0xC5
void OP_PUSH_BC(void);

// 0xC6
void OP_ADD_A_D8(void);

// 0xC7
void OP_RST_00(void);

// 0xC8
void OP_RET_Z(void);

// 0xC9
void OP_RET(void);

// 0xCA
void OP_JP_Z_A16(void);

// 0xCB
/* prefix CB is defined below*/

// 0xCC
void OP_CALL_Z_A16(void);

// 0xCD
void OP_CALL_A16(void);

// 0xCE
void OP_ADC_A_D8(void);

// 0xCF
void OP_RST_08(void);

// 0xD0
void OP_RET_NC(void);

// 0xD1
void OP_POP_DE(void);

// 0xD2
void OP_JP_NC_A16(void);

// 0xD4
void OP_CALL_NC_A16(void);

// 0xD5
void OP_PUSH_DE(void);

// 0xD6
void OP_SUB_A_D8(void);

// 0xD7
void OP_RST_10(void);

// 0xD8
void OP_RET_C(void);

// 0xD9
void OP_RETI(void);

// 0xDA
void OP_JP_C_A16(void);

// 0xDC
void OP_CALL_C_A16(void);

// 0xDE
void OP_SBC_A_D8(void);

// 0xDF
void OP_RST_18(void);


// 0xE0 load A into FF00+n
void OP_LDH_PA8_A(void);

// 0xE1
void OP_POP_HL(void);

// 0xE2 load A into FF00+C (Offset)
void OP_LD_OC_A(void);

// 0xE5
void OP_PUSH_HL(void);

// 0xE6 // todo ??
void OP_AND_D8(void);

// 0xE7
void OP_RST_20(void);

// 0xE8
// todo: HL&2047
void OP_ADD_SP_R8(void);

// 0xE9
void OP_JP_PHL(void);

// 0xEA
void OP_LD_A16_A(void);

// 0xEE
void OP_XOR_D8(void);

// 0xEF
void OP_RST_28(void);

// 0xF0
void OP_LDH_A_A8(void);

// 0xF1
void OP_POP_AF(void);

// 0xF2
void OP_LD_A_OC(void);

// 0xF3 disable interrupts
void OP_DI(void);

// 0xF5
void OP_PUSH_AF(void);

// 0xF6
void OP_OR_D8(void);

// 0xF7
void OP_RST_30(void);

// 0xF8
// todo: SP&2047
void OP_LD_HL_SP_R8(void);

// 0xF9
void OP_LD_SP_HL(void);

// 0xFA
void OP_LD_A_A16(void);

// 0xFB enable interrupts
void OP_EI(void);

// 0xFE
void OP_CP_D8(void);

// 0xFF 
void OP_RST_38(void);



// prefix CB

// 0x00
#define OP_RLC_B if(CHECK_BIT(B,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 B=B<<1; if(!B){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x01
#define OP_RLC_C if(CHECK_BIT(C,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 C=C<<1; if(!C){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x02
#define OP_RLC_D if(CHECK_BIT(D,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 D=D<<1; if(!D){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x03
#define OP_RLC_E if(CHECK_BIT(E,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 E=E<<1; if(!E){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x04
#define OP_RLC_H if(CHECK_BIT(H,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 H=H<<1; if(!H){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x05
#define OP_RLC_L if(CHECK_BIT(L,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 L=L<<1; if(!L){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x06
#define OP_RLC_PHL if(CHECK_BIT(MEM[HL],7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                   MEM[HL]=MEM[HL]<<1; if(!MEM[HL]){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}    

// 0x07
#define OP_RLC_A if(CHECK_BIT(A,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 A=A<<1; if(!A){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x08
#define OP_RRC_B if(CHECK_BIT(B,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 B=B>>1; if(!B){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x09
#define OP_RRC_C if(CHECK_BIT(C,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 C=C>>1; if(!C){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x0A
#define OP_RRC_D if(CHECK_BIT(D,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 D=D>>1; if(!D){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x0B
#define OP_RRC_E if(CHECK_BIT(E,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 E=E>>1; if(!E){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x0C
#define OP_RRC_H if(CHECK_BIT(H,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 H=H>>1; if(!H){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x0D
#define OP_RRC_L if(CHECK_BIT(L,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 L=L>>1; if(!L){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x0E
#define OP_RRC_PHL if(CHECK_BIT(MEM[HL],0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                   MEM[HL]=MEM[HL]>>1; if(!MEM[HL]){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}    

// 0x0F
#define OP_RRC_A if(CHECK_BIT(A,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 A=A>>1; if(!A){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x10
#define OP_RL_B t8[0] = FLAG_C; \
                if(CHECK_BIT(B,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                B=B<<1; if(t8[0]){B=B|1;}else{B=B&254;} \
                if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x11
#define OP_RL_C t8[0] = FLAG_C; \
                if(CHECK_BIT(C,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                C=C<<1; if(t8[0]){C=C|1;}else{C=C&254;} \
                if(!C){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x12
#define OP_RL_D t8[0] = FLAG_C; \
                if(CHECK_BIT(D,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                D=D<<1; if(t8[0]){D=D|1;}else{D=D&254;} \
                if(!D){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x13
#define OP_RL_E t8[0] = FLAG_C; \
                if(CHECK_BIT(E,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                E=E<<1; if(t8[0]){E=E|1;}else{E=E&254;} \
                if(!E){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x14
#define OP_RL_H t8[0] = FLAG_C; \
                if(CHECK_BIT(H,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                H=H<<1; if(t8[0]){H=H|1;}else{H=H&254;} \
                if(!H){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x15
#define OP_RL_L t8[0] = FLAG_C; \
                if(CHECK_BIT(L,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                L=L<<1; if(t8[0]){L=L|1;}else{L=L&254;} \
                if(!L){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x16
#define OP_RL_PHL t8[0] = FLAG_C; \
                  if(CHECK_BIT(MEM[HL],7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                  MEM[HL]=MEM[HL]<<1; if(t8[0]){MEM[HL]=MEM[HL]|1;}else{MEM[HL]=MEM[HL]&254;} \
                  if(!MEM[HL]){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);    

// 0x17
#define OP_RL_A t8[0] = FLAG_C; \
                if(CHECK_BIT(A,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                A=A<<1; if(t8[0]){A=A|1;}else{A=A&254;} \
                if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x18
#define OP_RR_B t8[0] = FLAG_C; \
                if(CHECK_BIT(B,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                B=B<<1; if(t8[0]){B=B|128;}else{B=B&127;} \
                if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x19
#define OP_RR_C t8[0] = FLAG_C; \
                if(CHECK_BIT(C,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                C=C<<1; if(t8[0]){C=C|128;}else{C=C&127;} \
                if(!C){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x1A
#define OP_RR_D t8[0] = FLAG_C; \
                if(CHECK_BIT(D,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                D=D<<1; if(t8[0]){D=D|128;}else{D=D&127;} \
                if(!D){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x1B
#define OP_RR_E t8[0] = FLAG_C; \
                if(CHECK_BIT(E,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                E=E<<1; if(t8[0]){E=E|128;}else{B=B&127;} \
                if(!E){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x1C
#define OP_RR_H t8[0] = FLAG_C; \
                if(CHECK_BIT(H,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                H=H<<1; if(t8[0]){H=H|128;}else{H=H&127;} \
                if(!H){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x1D
#define OP_RR_L t8[0] = FLAG_C; \
                if(CHECK_BIT(L,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                L=L<<1; if(t8[0]){L=L|128;}else{L=L&127;} \
                if(!L){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x1E
#define OP_RR_PHL t8[0] = FLAG_C; \
                  if(CHECK_BIT(MEM[HL],0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                  MEM[HL]=MEM[HL]<<1; if(t8[0]){MEM[HL]=MEM[HL]|128;}else{MEM[HL]=MEM[HL]&127;} \
                  if(!MEM[HL]){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);    

// 0x1F
#define OP_RR_A t8[0] = FLAG_C; \
                if(CHECK_BIT(A,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                A=A<<1; if(t8[0]){A=A|128;}else{A=A&127;} \
                if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0);  

// 0x20
#define OP_SLA_B if(CHECK_BIT(B,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 B=B<<1; B=B&254; if(!B){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x21
#define OP_SLA_C if(CHECK_BIT(C,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 C=C<<1; C=C&254; if(!C){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x22
#define OP_SLA_D if(CHECK_BIT(D,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 D=D<<1; D=D&254; if(!D){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x23
#define OP_SLA_E if(CHECK_BIT(E,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 E=E<<1; E=E&254; if(!C){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x24
#define OP_SLA_H if(CHECK_BIT(H,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 H=H<<1; H=H&254; if(!H){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x25
#define OP_SLA_L if(CHECK_BIT(L,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 L=L<<1; L=L&254; if(!L){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x26
#define OP_SLA_PHL if(CHECK_BIT(MEM[HL],7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                   MEM[HL]=MEM[HL]<<1; MEM[HL]=MEM[HL]&254; if(!MEM[HL]){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}    

// 0x27
#define OP_SLA_A if(CHECK_BIT(A,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 A=A<<1; A=A&254; if(!A){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x28
#define OP_SRA_B if(CHECK_BIT(B,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 B=B>>1; if(!B){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x29
#define OP_SRA_C if(CHECK_BIT(C,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 C=C>>1; if(!C){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x2A
#define OP_SRA_D if(CHECK_BIT(D,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 D=D>>1; if(!D){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x2B
#define OP_SRA_E if(CHECK_BIT(E,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 E=E>>1; if(!E){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x2C
#define OP_SRA_H if(CHECK_BIT(H,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 H=H>>1; if(!H){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x2D
#define OP_SRA_L if(CHECK_BIT(L,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 L=L>>1; if(!L){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x2E
#define OP_SRA_PHL if(CHECK_BIT(MEM[HL],0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                   MEM[HL]=MEM[HL]>>1; if(!MEM[HL]){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}    

// 0x2F
#define OP_SRA_A if(CHECK_BIT(A,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 A=A>>1; if(!A){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x30
#define OP_SWAP_B t8[0]=B; B=B>>4; t8[0]=t8[0]<<4; B=B+t8[0]; SET_FLAG_H(0); SET_FLAG_N(0); SET_FLAG_C(0); \
                  if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}  

// 0x31
#define OP_SWAP_C t8[0]=C; C=C>>4; t8[0]=t8[0]<<4; C=C+t8[0]; SET_FLAG_H(0); SET_FLAG_N(0); SET_FLAG_C(0); \
                  if(!C){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}  

// 0x32
#define OP_SWAP_D t8[0]=D; D=D>>4; t8[0]=t8[0]<<4; D=D+t8[0]; SET_FLAG_H(0); SET_FLAG_N(0); SET_FLAG_C(0); \
                  if(!D){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}  

// 0x33
#define OP_SWAP_E t8[0]=E; B=B>>4; t8[0]=t8[0]<<4; E=E+t8[0]; SET_FLAG_H(0); SET_FLAG_N(0); SET_FLAG_C(0); \
                  if(!E){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}  

// 0x34
#define OP_SWAP_H t8[0]=H; H=H>>4; t8[0]=t8[0]<<4; H=H+t8[0]; SET_FLAG_H(0); SET_FLAG_N(0); SET_FLAG_C(0); \
                  if(!H){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}  

// 0x35
#define OP_SWAP_L t8[0]=L; L=L>>4; t8[0]=t8[0]<<4; L=L+t8[0]; SET_FLAG_H(0); SET_FLAG_N(0); SET_FLAG_C(0); \
                  if(!L){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}  

// 0x36
#define OP_SWAP_PHL t8[0]=MEM[HL]; MEM[HL]=MEM[HL]>>4; t8[0]=t8[0]<<4; MEM[HL]=MEM[HL]+t8[0]; SET_FLAG_H(0); SET_FLAG_N(0); SET_FLAG_C(0); \
                    if(!MEM[HL]){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}    

// 0x37
#define OP_SWAP_A t8[0]=A; A=A>>4; t8[0]=t8[0]<<4; A=A+t8[0]; SET_FLAG_H(0); SET_FLAG_N(0); SET_FLAG_C(0); \
                  if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);}  

// 0x38
#define OP_SRL_B if(CHECK_BIT(B,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 B=B>>1; B=B&127; if(!B){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x39
#define OP_SRL_C if(CHECK_BIT(C,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 C=C>>1; C=C&127; if(!C){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x3A
#define OP_SRL_D if(CHECK_BIT(D,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 D=D>>1; D=D&127; if(!D){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x3B
#define OP_SRL_E if(CHECK_BIT(E,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 E=E>>1; E=E&127; if(!E){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x3C
#define OP_SRL_H if(CHECK_BIT(H,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 H=H>>1; H=H&127; if(!H){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x3D
#define OP_SRL_L if(CHECK_BIT(L,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 L=L>>1; L=L&127; if(!L){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x3E
#define OP_SRL_PHL if(CHECK_BIT(MEM[HL],0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                   MEM[HL]=MEM[HL]>>1; MEM[HL]=MEM[HL]&127; if(!MEM[HL]){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}    

// 0x3F
#define OP_SRL_A if(CHECK_BIT(A,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} SET_FLAG_N(0); SET_FLAG_H(0); \
                 A=A>>1; A=A&127; if(!A){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);}  

// 0x40
#define OP_BIT_0_B if(CHECK_BIT(B,0)){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x41
#define OP_BIT_0_C if(CHECK_BIT(C,0)){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x42
#define OP_BIT_0_D if(CHECK_BIT(D,0)){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x43
#define OP_BIT_0_E if(CHECK_BIT(E,0)){SET_FLAG_Z(0);}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x44
#define OP_BIT_0_H if(CHECK_BIT(H,0)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x45
#define OP_BIT_0_L if(CHECK_BIT(L,0)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x46
#define OP_BIT_0_PHL if(CHECK_BIT(MEM[HL],0)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);    

// 0x47
#define OP_BIT_0_A if(CHECK_BIT(A,0)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x48
#define OP_BIT_1_B if(CHECK_BIT(B,1)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x49
#define OP_BIT_1_C if(CHECK_BIT(C,1)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x4A
#define OP_BIT_1_D if(CHECK_BIT(D,1)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x4B
#define OP_BIT_1_E if(CHECK_BIT(E,1)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x4C
#define OP_BIT_1_H if(CHECK_BIT(H,1)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x4D
#define OP_BIT_1_L if(CHECK_BIT(L,1)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x4E
#define OP_BIT_1_PHL if(CHECK_BIT(MEM[HL],1)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);    

// 0x4F
#define OP_BIT_1_A if(CHECK_BIT(A,1)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x50
#define OP_BIT_2_B if(CHECK_BIT(B,2)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x51
#define OP_BIT_2_C if(CHECK_BIT(C,2)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x52
#define OP_BIT_2_D if(CHECK_BIT(D,2)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x53
#define OP_BIT_2_E if(CHECK_BIT(E,2)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x54
#define OP_BIT_2_H if(CHECK_BIT(H,2)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x55
#define OP_BIT_2_L if(CHECK_BIT(L,2)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x56
#define OP_BIT_2_PHL if(CHECK_BIT(MEM[HL],2)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);    

// 0x57
#define OP_BIT_2_A if(CHECK_BIT(A,2)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x58
#define OP_BIT_3_B if(CHECK_BIT(B,3)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x59
#define OP_BIT_3_C if(CHECK_BIT(C,3)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x5A
#define OP_BIT_3_D if(CHECK_BIT(D,3)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x5B
#define OP_BIT_3_E if(CHECK_BIT(E,3)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x5C
#define OP_BIT_3_H if(CHECK_BIT(H,3)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x5D
#define OP_BIT_3_L if(CHECK_BIT(L,3)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x5E
#define OP_BIT_3_PHL if(CHECK_BIT(MEM[HL],3)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);    

// 0x58
#define OP_BIT_3_A if(CHECK_BIT(A,3)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x60
#define OP_BIT_4_B if(CHECK_BIT(B,4)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x61
#define OP_BIT_4_C if(CHECK_BIT(C,4)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x62
#define OP_BIT_4_D if(CHECK_BIT(D,4)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x63
#define OP_BIT_4_E if(CHECK_BIT(E,4)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x64
#define OP_BIT_4_H if(CHECK_BIT(H,4)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x65
#define OP_BIT_4_L if(CHECK_BIT(L,4)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x66
#define OP_BIT_4_PHL if(CHECK_BIT(MEM[HL],4)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);    

// 0x67
#define OP_BIT_4_A if(CHECK_BIT(A,4)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x68
#define OP_BIT_5_B if(CHECK_BIT(B,5)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x69
#define OP_BIT_5_C if(CHECK_BIT(C,5)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x6A
#define OP_BIT_5_D if(CHECK_BIT(D,5)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x6B
#define OP_BIT_5_E if(CHECK_BIT(E,5)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x6C
#define OP_BIT_5_H if(CHECK_BIT(H,5)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x6D
#define OP_BIT_5_L if(CHECK_BIT(L,5)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x6E
#define OP_BIT_5_PHL if(CHECK_BIT(MEM[HL],5)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);    

// 0x6F
#define OP_BIT_5_A if(CHECK_BIT(A,5)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x70
#define OP_BIT_6_B if(CHECK_BIT(B,6)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x71
#define OP_BIT_6_C if(CHECK_BIT(C,6)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x72
#define OP_BIT_6_D if(CHECK_BIT(D,6)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x73
#define OP_BIT_6_E if(CHECK_BIT(E,6)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x74
#define OP_BIT_6_H if(CHECK_BIT(H,6)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x75
#define OP_BIT_6_L if(CHECK_BIT(L,6)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x76
#define OP_BIT_6_PHL if(CHECK_BIT(MEM[HL],6)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);    

// 0x77
#define OP_BIT_6_A if(CHECK_BIT(A,6)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x78
#define OP_BIT_7_B if(CHECK_BIT(B,7)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x79
#define OP_BIT_7_C if(CHECK_BIT(C,7)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x7A
#define OP_BIT_7_D if(CHECK_BIT(D,7)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x7B
#define OP_BIT_7_E if(CHECK_BIT(E,7)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x7C
#define OP_BIT_7_H if(CHECK_BIT(H,7)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x7D
#define OP_BIT_7_L if(CHECK_BIT(L,7)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x7E
#define OP_BIT_7_PHL if(CHECK_BIT(MEM[HL],7)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);    

// 0x7F
#define OP_BIT_7_A if(CHECK_BIT(A,7)){SET_FLAG_Z(0)}else{SET_FLAG_Z(1);} SET_FLAG_N(1); SET_FLAG_N(0);  

// 0x80
#define OP_RES_0_B B=B&254;  

// 0x81
#define OP_RES_0_C C=C&254;  

// 0x82
#define OP_RES_0_D D=D&254;  

// 0x83
#define OP_RES_0_E E=E&254;  

// 0x84
#define OP_RES_0_H H=H&254;  

// 0x85
#define OP_RES_0_L L=L&254;  

// 0x86
#define OP_RES_0_PHL MEM[HL]=MEM[HL]&254;    

// 0x87
#define OP_RES_0_A A=A&254;  

// 0x88
#define OP_RES_1_B B=B&253;  

// 0x89
#define OP_RES_1_C C=C&253;  

// 0x8A
#define OP_RES_1_D D=D&253;  

// 0x8B
#define OP_RES_1_E E=E&253;  

// 0x8C
#define OP_RES_1_H H=H&253;  

// 0x8D
#define OP_RES_1_L L=L&253;  

// 0x8E
#define OP_RES_1_PHL MEM[HL]=MEM[HL]&253;    

// 0x8F
#define OP_RES_1_A A=A&253;  

// 0x90
#define OP_RES_2_B B=B&251;  

// 0x91
#define OP_RES_2_C C=C&251;  

// 0x92
#define OP_RES_2_D D=D&251;  

// 0x93
#define OP_RES_2_E E=E&251;  

// 0x94
#define OP_RES_2_H H=H&251;  

// 0x95
#define OP_RES_2_L L=L&251;  

// 0x96
#define OP_RES_2_PHL MEM[HL]=MEM[HL]&251;    

// 0x97
#define OP_RES_2_A A=A&251;  

// 0x98
#define OP_RES_3_B B=B&247;  

// 0x99
#define OP_RES_3_C C=C&247;  

// 0x9A
#define OP_RES_3_D D=D&247;  

// 0x9B
#define OP_RES_3_E E=E&247;  

// 0x9C
#define OP_RES_3_H H=H&247;  

// 0x9D
#define OP_RES_3_L L=L&247;  

// 0x9E
#define OP_RES_3_PHL MEM[HL]=MEM[HL]&247;    

// 0x9F
#define OP_RES_3_A A=A&247;  

// 0xA0
#define OP_RES_4_B B=B&239;  

// 0xA1
#define OP_RES_4_C C=C&239;  

// 0xA2
#define OP_RES_4_D D=D&239;  

// 0xA3
#define OP_RES_4_E E=E&239;  

// 0xA4
#define OP_RES_4_H H=H&239;  

// 0xA5
#define OP_RES_4_L L=L&239;  

// 0xA6
#define OP_RES_4_PHL MEM[HL]=MEM[HL]&239;    

// 0xA7
#define OP_RES_4_A A=A&239;  

// 0xA8
#define OP_RES_5_B B=B&223;  

// 0xA9
#define OP_RES_5_C C=C&223;  

// 0xAA
#define OP_RES_5_D D=D&223;  

// 0xAB
#define OP_RES_5_E E=E&223;  

// 0xAC
#define OP_RES_5_H H=H&223;  

// 0xAD
#define OP_RES_5_L L=L&223;  

// 0xAE
#define OP_RES_5_PHL MEM[HL]=MEM[HL]&223;    

// 0xAF
#define OP_RES_5_A A=A&223;  

// 0xB0
#define OP_RES_6_B B=B&191;  

// 0xB1
#define OP_RES_6_C C=C&191;  

// 0xB2
#define OP_RES_6_D D=D&191;  

// 0xB3
#define OP_RES_6_E E=E&191;  

// 0xB4
#define OP_RES_6_H H=H&191;  

// 0xB5
#define OP_RES_6_L L=L&191;  

// 0xB6
#define OP_RES_6_PHL MEM[HL]=MEM[HL]&191;    

// 0xB7
#define OP_RES_6_A A=A&191;  

// 0xB8
#define OP_RES_7_B B=B&127;  

// 0xB9
#define OP_RES_7_C C=C&127;  

// 0xBA
#define OP_RES_7_D D=D&127;  

// 0xBB
#define OP_RES_7_E E=E&127;  

// 0xBC
#define OP_RES_7_H H=H&127;  

// 0xBD
#define OP_RES_7_L L=L&127;  

// 0xBE
#define OP_RES_7_PHL MEM[HL]=MEM[HL]&127;    

// 0xBF
#define OP_RES_7_A A=A&127;  

// 0xC0
#define OP_SET_0_B B=B|1;  

// 0xC1
#define OP_SET_0_C C=C|1;  

// 0xC2
#define OP_SET_0_D D=D|1;  

// 0xC3
#define OP_SET_0_E E=E|1;  

// 0xC4
#define OP_SET_0_H H=H|1;  

// 0xC5
#define OP_SET_0_L L=L|1;  

// 0xC6
#define OP_SET_0_PHL MEM[HL]=MEM[HL]|1;    

// 0xC7
#define OP_SET_0_A A=A|1;  

// 0xC8
#define OP_SET_1_B B=B|2;  

// 0xC9
#define OP_SET_1_C C=C|2;  

// 0xCA
#define OP_SET_1_D D=D|2;  

// 0xCB
#define OP_SET_1_E E=E|2;  

// 0xCC
#define OP_SET_1_H H=H|2;  

// 0xCD
#define OP_SET_1_L L=L|2;  

// 0xCE
#define OP_SET_1_PHL MEM[HL]=MEM[HL]|2;    

// 0xCF
#define OP_SET_1_A A=A|2;  

// 0xD0
#define OP_SET_2_B B=B|4;  

// 0xD1
#define OP_SET_2_C C=C|4;  

// 0xD2
#define OP_SET_2_D D=D|4;  

// 0xD3
#define OP_SET_2_E E=E|4;  

// 0xD4
#define OP_SET_2_H H=H|4;  

// 0xD5
#define OP_SET_2_L L=L|4;  

// 0xD6
#define OP_SET_2_PHL MEM[HL]=MEM[HL]|4;    

// 0xD7
#define OP_SET_2_A A=A|4;  

// 0xD7
#define OP_SET_3_B B=B|8;  

// 0xD8
#define OP_SET_3_C C=C|8;  

// 0xD9
#define OP_SET_3_D D=D|8;  

// 0xDA
#define OP_SET_3_E E=E|8;  

// 0xDB
#define OP_SET_3_H H=H|8;  

// 0xDC
#define OP_SET_3_L L=L|8;  

// 0xDE
#define OP_SET_3_PHL MEM[HL]=MEM[HL]|8;    

// 0xDF
#define OP_SET_3_A A=A|8;  

// 0xE0
#define OP_SET_4_B B=B|16;  

// 0xE1
#define OP_SET_4_C C=C|16;  

// 0xE2
#define OP_SET_4_D D=D|16;  

// 0xE3
#define OP_SET_4_E E=E|16;  

// 0xE4
#define OP_SET_4_H H=H|16;  

// 0xE5
#define OP_SET_4_L L=L|16;  

// 0xE6
#define OP_SET_4_PHL MEM[HL]=MEM[HL]|16;    

// 0xE7
#define OP_SET_4_A A=A|16;  

// 0xE8
#define OP_SET_5_B B=B|32;  

// 0xE9
#define OP_SET_5_C C=C|32;  

// 0xEA
#define OP_SET_5_D D=D|32;  

// 0xEB
#define OP_SET_5_E E=E|32;  

// 0xEC
#define OP_SET_5_H H=H|32;  

// 0xED
#define OP_SET_5_L L=L|32;  

// 0xEE
#define OP_SET_5_PHL MEM[HL]=MEM[HL]|32;    

// 0xEF
#define OP_SET_5_A A=A|32;  

// 0xF0
#define OP_SET_6_B B=B|64;  

// 0xF1
#define OP_SET_6_C C=C|64;  

// 0xF2
#define OP_SET_6_D D=D|64;  

// 0xF3
#define OP_SET_6_E E=E|64;  

// 0xF4
#define OP_SET_6_H H=H|64;  

// 0xF5
#define OP_SET_6_L L=L|64;  

// 0xF6
#define OP_SET_6_PHL MEM[HL]=MEM[HL]|64;    

// 0xF7
#define OP_SET_6_A A=A|64;  

// 0xF8
#define OP_SET_7_B B=B|128;  

// 0xF9
#define OP_SET_7_C C=C|128;  

// 0xFA
#define OP_SET_7_D D=D|128;  

// 0xFB
#define OP_SET_7_E E=E|128;  

// 0xFC
#define OP_SET_7_H H=H|128;  

// 0xFD
#define OP_SET_7_L L=L|128;  

// 0xFE
#define OP_SET_7_PHL MEM[HL]=MEM[HL]|128;    

// 0xFF
#define OP_SET_7_A A=A|128;  



//check if bit n (counting from 0 to 7) is set in X
#define CHECK_BIT(X,n) ((X) & (1<<(n)))
