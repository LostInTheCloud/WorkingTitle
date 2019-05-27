// 0x00
#define OP_NOP WAIT;

// 0x01
#define OP_LD_BC_D16 BC = *((uint16_t*) (MEM+PC+1)); WAIT; WAIT; WAIT;

// 0x02 ld (BC) A
#define OP_LD_PBC_A MEM[BC]=A; WAIT; WAIT;

// 0x03
#define OP_INC_BC BC++; WAIT; WAIT;

// 0x04
#define OP_INC_B if(B&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 B++; if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0); WAIT;

// 0x05
#define OP_DEC_B B--; if(B&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1); WAIT;

// 0x06
#define OP_LD_B_D8 B = MEM[PC+1]; WAIT; WAIT;

// 0x07
#define OP_RLCA if(CHECK_BIT(A,7)){SET_FLAG_C(1);;}else{SET_FLAG_C(0);} \
                A<<1; if(FLAG_C){A=A|1;}else{A=A&254;} \
                if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0); WAIT;

// 0x08
#define OP_A16_SP MEM[*((uint16_t*) (MEM+PC+1))]= SP; WAIT; WAIT; WAIT; WAIT; WAIT;

// 0x09
#define OP_ADD_HL_BC if(HL&2047+BC&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                     if((uint32_t)HL+(uint32_t)BC>65535){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                     HL=HL+BC; SET_FLAG_N(0); WAIT; WAIT;

// 0x0A
#define OP_LD_A_PBC A=MEM[BC]; WAIT; WAIT;

// 0x0B
#define OP_DEC_BC BC--; WAIT; WAIT;

// 0x0C
#define OP_INC_C if(C&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 C++; if(!C){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0); WAIT;

// 0x0D
#define OP_DEC_C C--; if(C&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!C){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1); WAIT;

// 0x0E
#define OP_LD_C_D8 C = MEM[PC+1]; WAIT; WAIT;

// 0x0F shift right, CarryBit=Bit0 Bit7=Bit0
#define OP_RRCA if(CHECK_BIT(A,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                A<<1; if(FLAG_C){A=A|128;}else{A=A&127;} \
                if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0); WAIT;

// 0x10
#define OP_STOP WAIT; /* TODO */

// 0x11
#define OP_LD_DE_D16 DE = *((uint16_t*) (MEM+PC+1)); WAIT; WAIT; WAIT;

// 0x12
#define OP_LD_PDE_A MEM[DE]=A; WAIT; WAIT;

// 0x13
#define OP_INC_DE DE++; WAIT; WAIT;

// 0x14
#define OP_INC_D if(D&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 D++; if(!D){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0); WAIT;

// 0x15
#define OP_DEC_D D--; if(D&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!D){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1); WAIT;

// 0x16
#define OP_LD_D_D8 D = MEM[PC+1]; WAIT; WAIT;

// 0x17
#define OP_RLA t8[0] = FLAG_C; \
               if(CHECK_BIT(A,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
               A<<1; if(t8[0]){A=A|1;}else{A=A&254;} \
               if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0); WAIT;

// 0x18
#define OP_JR_R8 PC=PC+ (*((int8_t*)MEM+PC+1)); WAIT; WAIT; WAIT;

// 0x19
#define OP_ADD_HL_DE if(HL&2047+DE&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                     if((uint32_t)HL+(uint32_t)DE>65535){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                     HL=HL+DE; SET_FLAG_N(0); WAIT; WAIT;

// 0x1A
#define OP_LD_A_PDE A=MEM[DE]; WAIT; WAIT;

// 0x1B
#define OP_DEC_DE DE--; WAIT; WAIT;

// 0x1C
#define OP_INC_E if(E&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 E++; if(!E){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0); WAIT;

// 0x1D
#define OP_DEC_E E--; if(E&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!E){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1); WAIT;

// 0x1E
#define OP_LD_E_D8 E = MEM[PC+1]; WAIT; WAIT;

// 0x1F
#define OP_RRA t8[0] = FLAG_C; \
               if(CHECK_BIT(A,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
               A<<1; if(t8[0]){A=A|128;}else{A=A&127;} \
               if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0); WAIT;

// 0x20
#define OP_JR_NZ_R8 if(!FLAG_Z){PC=PC+MEM[PC+1]; WAIT;} WAIT; WAIT;

// 0x21
#define OP_LD_HL_D16 HL = *((uint16_t*) (MEM+PC+1)); WAIT; WAIT; WAIT;

// 0x22
#define OP_LD_PHL_A MEM[HL]=A; WAIT; WAIT;

// 0x23
#define OP_INC_HL HL++; WAIT; WAIT;

// 0x24
#define OP_INC_H if(H&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 H++; if(!H){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0); WAIT;

// 0x25
#define OP_DEC_H H--; if(H&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!H){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1); WAIT;

// 0x26
#define OP_LD_H_D8 H = MEM[PC+1]; WAIT; WAIT;

// 0x27 decial adjust register A
#define OP_DAA if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_H(0); /* TODO */
// https://www.tutorialspoint.com/daa-instruction-in-8085-microprocessor

// 0x28
#define OP_JR_Z_R8 if(FLAG_Z){PC=PC+MEM[PC+1];WAIT;} WAIT; WAIT;

// 0x29
#define OP_ADD_HL_HL if(HL&2047+HL&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                     if((uint32_t)HL+(uint32_t)BC>65535){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                     HL=HL+BC; SET_FLAG_N(0); WAIT; WAIT;

// 0x2A
#define OP_LD_A_PHL_INC A=MEM[HL++]; WAIT; WAIT;

// 0x2B
#define OP_DEC_HL HL--; WAIT; WAIT;

// 0x2C
#define OP_INC_L if(L&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 L++; if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0); WAIT;

// 0x2D
#define OP_DEC_L L--; if(L&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!L){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1); WAIT;

// 0x2E
#define OP_LD_L_D8 L = MEM[PC+1]; WAIT; WAIT;

// 0x2F flip all bits in A
#define OP_CPL A=A^255 SET_FLAG_H(1); SET_FLAG_N(1); WAIT;

// 0x30
#define OP_JR_NC_R8 if(!FLAG_C){PC=PC+MEM[PC+1]; WAIT;} WAIT; WAIT;

// 0x31
#define OP_LD_SP_D16 SP = *((uint16_t*) (MEM+PC+1)); WAIT; WAIT; WAIT;

// 0x32
#define OP_LD_PSP_A MEM[SP]=A; WAIT; WAIT;

// 0x33
#define OP_INC_SP SP++; WAIT; WAIT;

// 0x34
#define OP_INC_PHL if(MEM[HL]&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 MEM[HL]++; if(!MEM[HL]){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0); WAIT;

// 0x35
#define OP_DEC_PHL MEM[HL]--; if(MEM[HL]&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!MEM[HL]){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1); WAIT;

// 0x36
#define OP_LD_PHL_D8 MEM[HL] = MEM[PC+1]; WAIT; WAIT;

// 0x37
#define OP_SCF SET_FLAG_C(1); SET_FLAG_N(0); SET_FLAG_H(0); WAIT;

//0x38
#define OP_JR_C_R8 if(FLAG_C){PC=PC+MEM[PC+1];WAIT;} WAIT; WAIT;

// 0x39 TODO overflow at 32767 ?
#define OP_ADD_HL_SP if(HL&2047+SP&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                     if(HL+SP<32767){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                     HL=HL+SP; SET_FLAG_N(0); WAIT; WAIT;
// 0x3A
#define OP_LD_A_PHL_DEC A=MEM[HL--]; WAIT; WAIT;

// 0x3B
#define OP_DEC_SP SP--; WAIT; WAIT;

// 0x3C
#define OP_INC_A if(A&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 A++; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0); WAIT;

// 0x3D
#define OP_DEC_A A--; if(A&0xF==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1); WAIT;

// 0x3E
#define OP_LD_A_D8 A = MEM[PC+1]; WAIT; WAIT;

// 0x3F complement carry flag
#define OP_CCF SET_FLAG_H(0); SET_FLAG_N(0); SET_FLAG_C(!FLAG_C); WAIT;

// 0x40
#define OP_LD_B_B B=B; WAIT;

// 0x41
#define OP_LD_B_C B=C; WAIT;

// 0x42
#define OP_LD_B_D B=D; WAIT;

// 0x43
#define OP_LD_B_E B=E; WAIT;

// 0x44
#define OP_LD_B_H B=H; WAIT;

// 0x45
#define OP_LD_B_L B=L; WAIT;

// 0x46
#define OP_LD_B_PHL B=MEM[HL]; WAIT; WAIT;

// 0x47
#define OP_LD_B_A B=A; WAIT;

// 0x48
#define OP_LD_C_B C=B; WAIT;

// 0x49
#define OP_LD_C_C C=C; WAIT;

// 0x4A
#define OP_LD_C_D C=D; WAIT;

// 0x4B
#define OP_LD_C_E C=E; WAIT;

// 0x4C
#define OP_LD_C_H C=H; WAIT;

// 0x4D
#define OP_LD_C_L C=L; WAIT;

// 0x4E
#define OP_LD_C_PHL C=MEM[HL]; WAIT; WAIT;

// 0x4F
#define OP_LD_C_A C=A; WAIT;

// 0x50
#define OP_LD_D_B D=B; WAIT;

// 0x51
#define OP_LD_D_C D=C; WAIT;

// 0x52
#define OP_LD_D_D D=D; WAIT;

// 0x53
#define OP_LD_D_E D=E; WAIT;

// 0x54
#define OP_LD_D_H D=H; WAIT;

// 0x55
#define OP_LD_D_L D=L; WAIT;

// 0x56
#define OP_LD_D_PHL D=MEM[HL]; WAIT; WAIT;

// 0x57
#define OP_LD_D_A D=A; WAIT;

// 0x58
#define OP_LD_E_B E=B; WAIT;

// 0x59
#define OP_LD_E_C E=C; WAIT;

// 0x5A
#define OP_LD_E_D E=D; WAIT;

// 0x5B
#define OP_LD_E_E E=E; WAIT;

// 0x5C
#define OP_LD_E_H E=H; WAIT;

// 0x5D
#define OP_LD_E_L E=L; WAIT;

// 0x5E
#define OP_LD_E_PHL E=MEM[HL]; WAIT; WAIT;

// 0x5F
#define OP_LD_E_A E=A; WAIT;

// 0x60
#define OP_LD_H_B H=B; WAIT;

// 0x61
#define OP_LD_H_C H=C; WAIT;

// 0x62
#define OP_LD_H_D H=D; WAIT;

// 0x63
#define OP_LD_H_E H=E; WAIT;

// 0x64
#define OP_LD_H_H H=H; WAIT;

// 0x65
#define OP_LD_H_L H=L; WAIT;

// 0x66
#define OP_LD_H_PHL H=MEM[HL]; WAIT; WAIT;

// 0x67
#define OP_LD_H_A H=A; WAIT;

// 0x68
#define OP_LD_L_B L=B; WAIT;

// 0x69
#define OP_LD_L_C L=C; WAIT;

// 0x6A
#define OP_LD_L_D L=D; WAIT;

// 0x6B
#define OP_LD_L_E L=E; WAIT;

// 0x6C
#define OP_LD_L_H L=H; WAIT;

// 0x6D
#define OP_LD_L_L L=L; WAIT;

// 0x6E
#define OP_LD_L_PHL L=MEM[HL]; WAIT; WAIT;

// 0x6F
#define OP_LD_L_A L=A; WAIT;

// 0x70
#define OP_LD_PHL_B MEM[HL]=B; WAIT; WAIT;

// 0x71
#define OP_LD_PHL_C MEM[HL]=C; WAIT; WAIT;

// 0x72
#define OP_LD_PHL_D MEM[HL]=D; WAIT; WAIT;

// 0x73
#define OP_LD_PHL_E MEM[HL]=E; WAIT; WAIT;

// 0x74
#define OP_LD_PHL_H MEM[HL]=H; WAIT; WAIT;

// 0x75
#define OP_LD_PHL_L MEM[HL]=L; WAIT; WAIT;

// 0x76
#define OP_HALT WAIT; /* TODO HALT */

// 0x77
#define OP_LD_PHL_A MEM[HL]=A; WAIT; WAIT;

// 0x78
#define OP_LD_A_B A=B; WAIT;

// 0x79
#define OP_LD_A_C A=C; WAIT;

//0 x7A
#define OP_LD_A_D A=D; WAIT;

// 0x7B
#define OP_LD_A_E A=E; WAIT;

//0 x7C
#define OP_LD_A_H A=H; WAIT;

// 0x7D
#define OP_LD_A_L A=L; WAIT;

// 0x7E
#define OP_LD_A_PHL A=MEM[HL]; WAIT; WAIT;

// 0x7F
#define OP_LD_A_A A=A; WAIT;

// 0x80 if first 4 bits add to more than 1111 then set H
#define OP_ADD_A_B if((A&15)+(B&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+B>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x81
#define OP_ADD_A_C if((A&15)+(C&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x82
#define OP_ADD_A_D if((A&15)+(D&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+D>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x83
#define OP_ADD_A_E iif((A&15)+(E&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+E>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x84
#define OP_ADD_A_H if((A&15)+(H&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+H>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x85
#define OP_ADD_A_L if((A&15)+(L&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+L>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x86
#define OP_ADD_A_PHL if((A&15)+(MEM[HL]&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                     if(A+MEM[HL]>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                     A=A+MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT; WAIT;

// 0x87
#define OP_ADD_A_A if((A&15)+(A&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+A>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+A; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x88
#define OP_ADC_A_B if((A&15)+(B&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+B+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+B+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x89
#define OP_ADC_A_C if((A&15)+(C&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+C+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+C+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x8A
#define OP_ADC_A_D if((A&15)+(D&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+D+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+D+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x8B
#define OP_ADC_A_E if((A&15)+(E&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+E+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+E+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x8C
#define OP_ADC_A_H if((A&15)+(H&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+H+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+H+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x8D
#define OP_ADC_A_L if((A&15)+(L&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+L+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+L+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x8E
#define OP_ADC_A_PHL if((A&15)+(MEM[HL]&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                     if(A+MEM[HL]+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                     A=A+MEM[HL]+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT; WAIT;

// 0x8F
#define OP_ADC_A_A if((A&15)+(A&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+A+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+A+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x90
#define OP_SUB_A_B if((A&15)<(B&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<B){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1); WAIT;

// 0x91
#define OP_SUB_A_C if((A&15)<(C&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1); WAIT;

// 0x92
#define OP_SUB_A_D if((A&15)<(D&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<D){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1); WAIT;

// 0x93
#define OP_SUB_A_E if((A&15)<(E&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<E){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1); WAIT;

// 0x94
#define OP_SUB_A_H if((A&15)<(H&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<H){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1); WAIT;

// 0x95
#define OP_SUB_A_L if((A&15)<(L&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<L){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1); WAIT;

// 0x96
#define OP_SUB_A_PHL if((A&15)<(MEM[HL]&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                     if(A<MEM[HL]){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                     A=A-MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1); WAIT; WAIT;

// 0x97
#define OP_SUB_A_A SET_FLAG_H(0);SET_FLAG_C(0);A=0;SET_FLAG_Z(1);SET_FLAG_N(1);WAIT;

// 0x98
#define OP_SBC_A_B if((A&15)<(B&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<B+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-B+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;
// 0x99
#define OP_SBC_A_C if((A&15)<(C&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<C+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-C+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x9A
#define OP_SBC_A_D if((A&15)<(D&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<D+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-D+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x9B
#define OP_SBC_A_E if((A&15)<(&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<E+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-E+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x9C
#define OP_SBC_A_H if((A&15)<(H&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<H+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-H+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x9D
#define OP_SBC_A_L if((A&15)<(L&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<L+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-L+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0x9E
#define OP_SBC_A_PHL if((A&15)<(MEM[HL]&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                     if(A<MEM[HL]+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                     A=A-MEM[HL]+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT; WAIT;

// 0x9F
#define OP_SBC_A_A if(FLAG_C){SET_FLAG_H(1); SET_FLAG_C(1);}else{SET_FLAG_H(0); SET_FLAG_C(0);} \
                   A=FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT;

// 0xA0
#define OP_AND_B A=A&B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0); WAIT;

// 0xA1
#define OP_AND_C A=A&C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0); WAIT;

// 0xA2
#define OP_AND_D A=A&D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0); WAIT;

// 0xA3
#define OP_AND_E A=A&E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0); WAIT;

// 0xA4
#define OP_AND_H A=A&H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0); WAIT;

// 0xA5
#define OP_AND_L A=A&L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0); WAIT;

// 0xA6
#define OP_AND_PHL A=A&MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                   SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0); WAIT; WAIT;

// 0xA7
#define OP_AND_A if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0); WAIT;

// 0xA8
#define OP_XOR_B A=A^B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xA9
#define OP_XOR_C A=A^C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xAA
#define OP_XOR_D A=A^D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xAB
#define OP_XOR_E A=A^E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xAC
#define OP_XOR_H A=A^H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xAD
#define OP_XOR_L A=A^L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xAE
#define OP_XOR_PHL A=A^MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                   SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT; WAIT;

// 0xA8
#define OP_XOR_A A=0; SET_FLAG_Z(1); SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xB0
#define OP_OR_B A=A|B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xB1
#define OP_OR_C A=A|C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xB2
#define OP_OR_D A=A|D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xB3
#define OP_OR_E A=A|E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xB4
#define OP_OR_H A=A|H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xB5
#define OP_OR_L A=A|L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xB6
#define OP_OR_PHL A=A|MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                  SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT; WAIT;

// 0xB7
#define OP_OR_A if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT;

// 0xB8
#define OP_CP_B if(!(A-B)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<B){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if(A&15<B&15){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                SET_FLAG_N(1); WAIT;

// 0xB9
#define OP_CP_C if(!(A-C)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<C){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if(A&15<C&15){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                SET_FLAG_N(1); WAIT;

// 0xBA
#define OP_CP_D if(!(A-D)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<D){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if(A&15<D&15){SET_FLAG_H(0);}else{SET_FLAG_H(1;} \
                SET_FLAG_N(1); WAIT;

// 0xBB
#define OP_CP_E if(!(A-E)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<E){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if(A&15<E&15){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                SET_FLAG_N(1); WAIT;

// 0xBC
#define OP_CP_H if(!(A-H)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<H){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if(A&15<H&15){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                SET_FLAG_N(1); WAIT;

// 0xBD
#define OP_CP_L if(!(A-L)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<L){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if(A&15<L&15){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                SET_FLAG_N(1); WAIT;

// 0xBE
#define OP_CP_PHL if(!(A-MEM[HL])){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                  if(A<MEM[HL]){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                  if(A&15<MEM[HL]&15){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                  SET_FLAG_N(1); WAIT; WAIT;

// 0xBF
#define OP_CP_A SET_FLAG_Z(1); SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(1); WAIT;

// 0xC0
#define OP_RET_NZ WAIT; WAIT; /* TODO stack */

// 0xC1
#define OP_POP_BC C=MEM[SP+1];B=MEM[SP+2]; SP+=2; WAIT; WAIT; WAIT;

// 0xC5
#define OP_PUSH_BC MEM[SP-1]=B; MEM[SP-2]=C; SP=SP-2; WAIT; WAIT; WAIT; WAIT;

// 0xC6
#define OP_ADD_A_D8 if((A&15)+(MEM[PC+1]&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                    if(A+MEM[PC+1]>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                    A=A+MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); WAIT; WAIT;

// 0xD1
#define OP_POP_DE E=MEM[SP+1];D=MEM[SP+2]; SP+=2; WAIT; WAIT; WAIT;

// 0xD5
#define OP_PUSH_DE MEM[SP-1]=D; MEM[SP-2]=E; SP=SP-2; WAIT; WAIT; WAIT; WAIT;

// 0xD6
#define OP_SUB_A_D8 if((A&15)<(MEM[PC+1]&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<MEM[PC+1]){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1); WAIT; WAIT;


// 0xE0 load A into FF00+n
#define OP_LDH_A8_A MEM[65280+MEM[PC+1]]=A; WAIT; WAIT; WAIT;

// 0xE1
#define OP_POP_HL L=MEM[SP+1];H=MEM[SP+2]; SP+=2; WAIT; WAIT; WAIT;

// 0xE2 load A into FF00+C (Offset)
#define OP_LD_OC_A MEM[65280+C]=A; WAIT; WAIT;

// 0xE5
#define OP_PUSH_HL MEM[SP-1]=H; MEM[SP-2]=L; SP=SP-2; WAIT; WAIT; WAIT; WAIT;

// 0xE6
#define OP_AND_D8 A=A&MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0); WAIT; WAIT;DE&2047

// 0xE8 TODO overflow at 32767 ?
#define OP_ADD_SP_R8 if(HL&2047+(int8_t)MEM[PC+1]<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                     if(HL+(int8_t)MEM[PC+1]<32767){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                     HL=HL+(int8_t)MEM[PC+1]; SET_FLAG_N(0); WAIT; WAIT; WAIT; WAIT;
// 0xF0
#define OP_LDH_A_A8 A=MEM[65280+MEM[PC+1]]; WAIT; WAIT; WAIT;

// 0xF1
#define OP_POP_AF F=MEM[SP+1];A=MEM[SP+2]; SP+=2; WAIT; WAIT; WAIT;

// 0xF3 disable interrupts TODO
#define OP_DI WAIT;

// 0xF5
#define OP_PUSH_AF MEM[SP-1]=A; MEM[SP-2]=F; SP=SP-2; WAIT; WAIT; WAIT; WAIT;

// 0xF6
#define OP_OR_D8 A=A|MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0); WAIT; WAIT;

// 0xF8
#define OP_LD_SP_R8 WAIT; WAIT; WAIT;




//check if bit n (counting from 0 to 7) is set in X
#define CHECK_BIT(X,n) ((X) & (1<<(n)))
