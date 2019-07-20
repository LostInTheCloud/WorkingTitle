// 0x00
#define OP_NOP ;

// 0x01
#define OP_LD_BC_D16 BC = *((uint16_t*) (MEM+PC+1));   

// 0x02 ld (BC) A
#define OP_LD_PBC_A MEM[BC]=A;  

// 0x03
#define OP_INC_BC BC++;  

// 0x04
#define OP_INC_B if((B&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 B++; if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

// 0x05
#define OP_DEC_B B--; if((B&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

// 0x06
#define OP_LD_B_D8 B = MEM[PC+1];

// 0x07
#define OP_RLCA if(CHECK_BIT(A,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                A=A<<1; if(FLAG_C){A=A|1;}else{A=A&254;} \
                if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0); 

// 0x08
#define OP_LD_A16_SP MEM[*((uint16_t*) (MEM+PC+1))]= SP;

// 0x09
#define OP_ADD_HL_BC if(HL&2047+BC&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                     if((uint32_t)HL+(uint32_t)BC>65535){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                     HL=HL+BC; SET_FLAG_N(0);

// 0x0A
#define OP_LD_A_PBC A=MEM[BC];

// 0x0B
#define OP_DEC_BC BC--;

// 0x0C
#define OP_INC_C if((C&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 C++; if(!C){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

// 0x0D
#define OP_DEC_C C--; if((C&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!C){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

// 0x0E
#define OP_LD_C_D8 C = MEM[PC+1];

// 0x0F shift right, CarryBit=Bit0 Bit7=Bit0
#define OP_RRCA if(CHECK_BIT(A,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                A=A<<1; if(FLAG_C){A=A|128;}else{A=A&127;} \
                if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0); 

// 0x10
// todo
#define OP_STOP

// 0x11
#define OP_LD_DE_D16 DE = *((uint16_t*) (MEM+PC+1));

// 0x12
#define OP_LD_PDE_A MEM[DE]=A;

// 0x13
#define OP_INC_DE DE++;

// 0x14
#define OP_INC_D if((D&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 D++; if(!D){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

// 0x15
#define OP_DEC_D D--; if((D&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!D){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

// 0x16
#define OP_LD_D_D8 D = MEM[PC+1];

// 0x17
#define OP_RLA t8[0] = FLAG_C; \
               if(CHECK_BIT(A,7)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
               A=A<<1; if(t8[0]){A=A|1;}else{A=A&254;} \
               if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0); 

// 0x18
#define OP_JR_R8 PC=PC+(*((int8_t*)MEM+PC+1));

// 0x19
#define OP_ADD_HL_DE if(HL&2047+DE&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                     if((uint32_t)HL+(uint32_t)DE>65535){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                     HL=HL+DE; SET_FLAG_N(0);

// 0x1A
#define OP_LD_A_PDE A=MEM[DE];

// 0x1B
#define OP_DEC_DE DE--;

// 0x1C
#define OP_INC_E if((E&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 E++; if(!E){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

// 0x1D
#define OP_DEC_E E--; if((E&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!E){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

// 0x1E
#define OP_LD_E_D8 E = MEM[PC+1];

// 0x1F
#define OP_RRA t8[0] = FLAG_C; \
               if(CHECK_BIT(A,0)){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
               A=A<<1; if(t8[0]){A=A|128;}else{A=A&127;} \
               if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0); SET_FLAG_H(0); 

// 0x20
#define OP_JR_NZ_R8 if(!FLAG_Z){PC=PC+MEM[PC+1]; }

// 0x21
#define OP_LD_HL_D16 HL = *((uint16_t*) (MEM+PC+1));

// 0x22
#define OP_LD_PHLI_A MEM[HL++]=A;

// 0x23
#define OP_INC_HL HL++;

// 0x24
#define OP_INC_H if((H&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 H++; if(!H){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

// 0x25
#define OP_DEC_H H--; if((H&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!H){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

// 0x26
#define OP_LD_H_D8 H = MEM[PC+1];

// 0x27 decimal adjust register A
// todo
#define OP_DAA if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_H(0); /* TODO */
// https://www.tutorialspoint.com/daa-instruction-in-8085-microprocessor

// 0x28
#define OP_JR_Z_R8 if(FLAG_Z){PC=PC+MEM[PC+1];}

// 0x29
#define OP_ADD_HL_HL if(HL&2047+HL&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                     if((uint32_t)HL+(uint32_t)BC>65535){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                     HL=HL+BC; SET_FLAG_N(0);

// 0x2A
#define OP_LD_A_PHLI A=MEM[HL++];

// 0x2B
#define OP_DEC_HL HL--;

// 0x2C
#define OP_INC_L if((L&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 L++; if(!B){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

// 0x2D
#define OP_DEC_L L--; if((L&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!L){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

// 0x2E
#define OP_LD_L_D8 L = MEM[PC+1];

// 0x2F flip all bits in A
#define OP_CPL A=A^255; SET_FLAG_H(1); SET_FLAG_N(1);

// 0x30
#define OP_JR_NC_R8 if(!FLAG_C){PC=PC+MEM[PC+1]; }

// 0x31
#define OP_LD_SP_D16 SP = *((uint16_t*) (MEM+PC+1));

// 0x32
#define OP_LD_PHLD_A MEM[HL--]=A;

// 0x33
#define OP_INC_SP SP++;

// 0x34
#define OP_INC_PHL if((MEM[HL]&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 MEM[HL]++; if(!MEM[HL]){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

// 0x35
#define OP_DEC_PHL MEM[HL]--; if((MEM[HL]&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!MEM[HL]){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

// 0x36
#define OP_LD_PHL_D8 MEM[HL] = MEM[PC+1];

// 0x37
#define OP_SCF SET_FLAG_C(1); SET_FLAG_N(0); SET_FLAG_H(0);

//0x38
#define OP_JR_C_R8 if(FLAG_C){PC=PC+MEM[PC+1];}

// 0x39
#define OP_ADD_HL_SP if(HL&2047+SP&2047<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                     if((uint32_t)HL+(uint32_t)SP<32767){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                     HL=HL+SP; SET_FLAG_N(0);
// 0x3A
// todo
#define OP_LD_A_PHLD A=MEM[HL--];

// 0x3B
#define OP_DEC_SP SP--;

// 0x3C
#define OP_INC_A if((A&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 A++; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(0);

// 0x3D
#define OP_DEC_A A--; if((A&0xF)==0xF){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                 if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)} SET_FLAG_N(1);

// 0x3E
#define OP_LD_A_D8 A = MEM[PC+1];

// 0x3F complement carry flag
#define OP_CCF SET_FLAG_H(0); SET_FLAG_N(0); SET_FLAG_C(!FLAG_C);

// 0x40
#define OP_LD_B_B B=B;

// 0x41
#define OP_LD_B_C B=C;

// 0x42
#define OP_LD_B_D B=D;

// 0x43
#define OP_LD_B_E B=E;

// 0x44
#define OP_LD_B_H B=H;

// 0x45
#define OP_LD_B_L B=L;

// 0x46
#define OP_LD_B_PHL B=MEM[HL];

// 0x47
#define OP_LD_B_A B=A;

// 0x48
#define OP_LD_C_B C=B;

// 0x49
#define OP_LD_C_C C=C;

// 0x4A
#define OP_LD_C_D C=D;

// 0x4B
#define OP_LD_C_E C=E;

// 0x4C
#define OP_LD_C_H C=H;

// 0x4D
#define OP_LD_C_L C=L;

// 0x4E
#define OP_LD_C_PHL C=MEM[HL];

// 0x4F
#define OP_LD_C_A C=A;

// 0x50
#define OP_LD_D_B D=B;

// 0x51
#define OP_LD_D_C D=C;

// 0x52
#define OP_LD_D_D D=D;

// 0x53
#define OP_LD_D_E D=E;

// 0x54
#define OP_LD_D_H D=H;

// 0x55
#define OP_LD_D_L D=L;

// 0x56
#define OP_LD_D_PHL D=MEM[HL];

// 0x57
#define OP_LD_D_A D=A;

// 0x58
#define OP_LD_E_B E=B;

// 0x59
#define OP_LD_E_C E=C;

// 0x5A
#define OP_LD_E_D E=D;

// 0x5B
#define OP_LD_E_E E=E;

// 0x5C
#define OP_LD_E_H E=H;

// 0x5D
#define OP_LD_E_L E=L;

// 0x5E
#define OP_LD_E_PHL E=MEM[HL];

// 0x5F
#define OP_LD_E_A E=A;

// 0x60
#define OP_LD_H_B H=B;

// 0x61
#define OP_LD_H_C H=C;

// 0x62
#define OP_LD_H_D H=D;

// 0x63
#define OP_LD_H_E H=E;

// 0x64
#define OP_LD_H_H H=H;

// 0x65
#define OP_LD_H_L H=L;

// 0x66
#define OP_LD_H_PHL H=MEM[HL];

// 0x67
#define OP_LD_H_A H=A;

// 0x68
#define OP_LD_L_B L=B;

// 0x69
#define OP_LD_L_C L=C;

// 0x6A
#define OP_LD_L_D L=D;

// 0x6B
#define OP_LD_L_E L=E;

// 0x6C
#define OP_LD_L_H L=H;

// 0x6D
#define OP_LD_L_L L=L;

// 0x6E
#define OP_LD_L_PHL L=MEM[HL];

// 0x6F
#define OP_LD_L_A L=A;

// 0x70
#define OP_LD_PHL_B MEM[HL]=B;

// 0x71
#define OP_LD_PHL_C MEM[HL]=C;

// 0x72
#define OP_LD_PHL_D MEM[HL]=D;

// 0x73
#define OP_LD_PHL_E MEM[HL]=E;

// 0x74
#define OP_LD_PHL_H MEM[HL]=H;

// 0x75
#define OP_LD_PHL_L MEM[HL]=L;

// 0x76
// todo
#define OP_HALT

// 0x77
#define OP_LD_PHL_A MEM[HL]=A;

// 0x78
#define OP_LD_A_B A=B;

// 0x79
#define OP_LD_A_C A=C;

//0 x7A
#define OP_LD_A_D A=D;

// 0x7B
#define OP_LD_A_E A=E;

//0 x7C
#define OP_LD_A_H A=H;

// 0x7D
#define OP_LD_A_L A=L;

// 0x7E
#define OP_LD_A_PHL A=MEM[HL];

// 0x7F
#define OP_LD_A_A A=A;

// 0x80 if first 4 bits add to more than 1111 then set H
#define OP_ADD_A_B if((A&15)+(B&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+B>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x81
#define OP_ADD_A_C if((A&15)+(C&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x82
#define OP_ADD_A_D if((A&15)+(D&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+D>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x83
#define OP_ADD_A_E if((A&15)+(E&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+E>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x84
#define OP_ADD_A_H if((A&15)+(H&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+H>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x85
#define OP_ADD_A_L if((A&15)+(L&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+L>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x86
#define OP_ADD_A_PHL if((A&15)+(MEM[HL]&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                     if(A+MEM[HL]>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                     A=A+MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x87
#define OP_ADD_A_A if((A&15)+(A&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+A>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+A; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x88
#define OP_ADC_A_B if((A&15)+(B&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+B+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+B+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x89
#define OP_ADC_A_C if((A&15)+(C&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+C+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+C+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x8A
#define OP_ADC_A_D if((A&15)+(D&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+D+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+D+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x8B
#define OP_ADC_A_E if((A&15)+(E&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+E+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+E+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x8C
#define OP_ADC_A_H if((A&15)+(H&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+H+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+H+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x8D
#define OP_ADC_A_L if((A&15)+(L&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+L+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+L+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x8E
#define OP_ADC_A_PHL if((A&15)+(MEM[HL]&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                     if(A+MEM[HL]+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                     A=A+MEM[HL]+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x8F
#define OP_ADC_A_A if((A&15)+(A&15)+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A+A+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A+A+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x90
#define OP_SUB_A_B if((A&15)<(B&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<B){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);

// 0x91
#define OP_SUB_A_C if((A&15)<(C&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);

// 0x92
#define OP_SUB_A_D if((A&15)<(D&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<D){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);

// 0x93
#define OP_SUB_A_E if((A&15)<(E&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<E){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);

// 0x94
#define OP_SUB_A_H if((A&15)<(H&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<H){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);

// 0x95
#define OP_SUB_A_L if((A&15)<(L&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<L){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);

// 0x96
#define OP_SUB_A_PHL if((A&15)<(MEM[HL]&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                     if(A<MEM[HL]){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                     A=A-MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);

// 0x97
#define OP_SUB_A_A SET_FLAG_H(0);SET_FLAG_C(0);A=0;SET_FLAG_Z(1);SET_FLAG_N(1);

// 0x98
#define OP_SBC_A_B if((A&15)<(B&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<B+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-B+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);
// 0x99
#define OP_SBC_A_C if((A&15)<(C&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<C+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-C+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x9A
#define OP_SBC_A_D if((A&15)<(D&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<D+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-D+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x9B
#define OP_SBC_A_E if((A&15)<(E&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<E+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-E+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x9C
#define OP_SBC_A_H if((A&15)<(H&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<H+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-H+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x9D
#define OP_SBC_A_L if((A&15)<(L&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<L+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-L+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x9E
#define OP_SBC_A_PHL if((A&15)<(MEM[HL]&15)+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                     if(A<MEM[HL]+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                     A=A-MEM[HL]+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0x9F
#define OP_SBC_A_A if(FLAG_C){SET_FLAG_H(1); SET_FLAG_C(1);}else{SET_FLAG_H(0); SET_FLAG_C(0);} \
                   A=FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0xA0
#define OP_AND_B A=A&B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);

// 0xA1
#define OP_AND_C A=A&C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);

// 0xA2
#define OP_AND_D A=A&D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);

// 0xA3
#define OP_AND_E A=A&E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);

// 0xA4
#define OP_AND_H A=A&H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);

// 0xA5
#define OP_AND_L A=A&L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);

// 0xA6
#define OP_AND_PHL A=A&MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                   SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);

// 0xA7
#define OP_AND_A if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);

// 0xA8
#define OP_XOR_B A=A^B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xA9
#define OP_XOR_C A=A^C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xAA
#define OP_XOR_D A=A^D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xAB
#define OP_XOR_E A=A^E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xAC
#define OP_XOR_H A=A^H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xAD
#define OP_XOR_L A=A^L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xAE
#define OP_XOR_PHL A=A^MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                   SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xA8
#define OP_XOR_A A=0; SET_FLAG_Z(1); SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xB0
#define OP_OR_B A=A|B; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xB1
#define OP_OR_C A=A|C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xB2
#define OP_OR_D A=A|D; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xB3
#define OP_OR_E A=A|E; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xB4
#define OP_OR_H A=A|H; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xB5
#define OP_OR_L A=A|L; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xB6
#define OP_OR_PHL A=A|MEM[HL]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                  SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xB7
#define OP_OR_A if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xB8
#define OP_CP_B if(!(A-B)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<B){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if((A&15)<(B&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                SET_FLAG_N(1);

// 0xB9
#define OP_CP_C if(!(A-C)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<C){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if((A&15)<(C&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                SET_FLAG_N(1);

// 0xBA
#define OP_CP_D if(!(A-D)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<D){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if((A&15)<(D&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                SET_FLAG_N(1);

// 0xBB
#define OP_CP_E if(!(A-E)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<E){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if((A&15)<(E&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                SET_FLAG_N(1);

// 0xBC
#define OP_CP_H if(!(A-H)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<H){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if((A&15)<(H&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                SET_FLAG_N(1);

// 0xBD
#define OP_CP_L if(!(A-L)){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                if(A<L){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                if((A&15)<(L&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                SET_FLAG_N(1);

// 0xBE
#define OP_CP_PHL if(!(A-MEM[HL])){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                  if(A<MEM[HL]){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                  if((A&15)<(MEM[HL]&15)){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                  SET_FLAG_N(1);

// 0xBF
#define OP_CP_A SET_FLAG_Z(1); SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(1);

// 0xC0
#define OP_RET_NZ if(!FLAG_Z){(*((int8_t*)MEM+SP+2)); SP+=2;   }

// 0xC1
#define OP_POP_BC C=MEM[SP+1];B=MEM[SP+2]; SP+=2;

// 0xC2
#define OP_JP_NZ_A16 if(!FLAG_Z){PC= *((uint16_t*) (MEM+PC+1)); }

// 0xC3
#define OP_JP_A16 PC= *((uint16_t*) (MEM+PC+1));

// 0xC4
#define OP_CALL_NZ_A16 if(!FLAG_Z){MEM[SP-2]=PC+3; SP=SP-2; PC= *((uint16_t*) (MEM+PC+1));   }

// 0xC5
#define OP_PUSH_BC MEM[SP-1]=B; MEM[SP-2]=C; SP=SP-2;

// 0xC6
#define OP_ADD_A_D8 if((A&15)+(MEM[PC+1]&15)>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                    if(A+MEM[PC+1]>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                    A=A+MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);


// 0xC7
#define OP_RST_00 *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x00;

// 0xC8
#define OP_RET_Z if(FLAG_Z){(*((int8_t*)MEM+SP+2)); SP+=2;   }

// 0xC9
#define OP_RET (*((int8_t*)MEM+SP+2)); SP+=2;

// 0xCA
#define OP_JP_Z_A16 if(FLAG_Z){PC= *((uint16_t*) (MEM+PC+1)); }

// 0xCB
/* prefix CB is defined below*/

// 0xCC
#define OP_CALL_Z_A16 if(FLAG_Z){MEM[SP-2]=PC+3; SP=SP-2; PC= *((uint16_t*) (MEM+PC+1));   }

// 0xCD
#define OP_CALL_A16 MEM[SP-2]=PC+3; SP=SP-2; PC= *((uint16_t*) (MEM+PC+1));

// 0xCE
#define OP_ADC_A_D8 if((A&15)+MEM[PC+1]+FLAG_C>15){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                    if(A+MEM[PC+1]+FLAG_C>255){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                    A=A+MEM[PC+1]+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0xCF
#define OP_RST_08 *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x08;

// 0xD0
#define OP_RET_NC if(!FLAG_C){(*((int8_t*)MEM+SP+2)); SP+=2;   }

// 0xD1
#define OP_POP_DE E=MEM[SP+1];D=MEM[SP+2]; SP+=2;

// 0xD2
#define OP_JP_NC_A16 if(!FLAG_C){PC= *((uint16_t*) (MEM+PC+1)); }

// 0xD4
#define OP_CALL_NC_A16 if(!FLAG_Z){MEM[SP-2]=PC+3; SP=SP-2; PC= *((uint16_t*) (MEM+PC+1));   }

// 0xD5
#define OP_PUSH_DE MEM[SP-1]=D; MEM[SP-2]=E; SP=SP-2;

// 0xD6
#define OP_SUB_A_D8 if((A&15)<(MEM[PC+1]&15)){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<MEM[PC+1]){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(1);

// 0xD7
#define OP_RST_10 *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x10;

// 0xD8
#define OP_RET_C if(FLAG_C){PC=(*((int8_t*)MEM+SP+2)); SP+=2;   }

// 0xD9
#define OP_RETI (*((int8_t*)MEM+SP+2)); SP+=2; ENABLE_IME

// 0xDA
#define OP_JP_C_A16 if(FLAG_C){PC= *((uint16_t*) (MEM+PC+1)); }

// 0xDC
#define OP_CALL_C_A16 if(FLAG_C){MEM[SP-2]=PC+3; SP=SP-2; PC= *((uint16_t*) (MEM+PC+1));   }

// 0xDE
#define OP_SBC_A_D8 if((A&15)<(MEM[PC+1])+FLAG_C){SET_FLAG_H(1);}else{SET_FLAG_H(0);} \
                   if(A<MEM[PC+1]+FLAG_C){SET_FLAG_C(1);}else{SET_FLAG_C(0);}\
                   A=A-MEM[PC+1]+FLAG_C; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} SET_FLAG_N(0);

// 0xDF
#define OP_RST_18 *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x18;


// 0xE0 load A into FF00+n
#define OP_LDH_PA8_A MEM[65280+MEM[PC+1]]=A;

// 0xE1
#define OP_POP_HL L=MEM[SP+1];H=MEM[SP+2]; SP+=2;

// 0xE2 load A into FF00+C (Offset)
#define OP_LD_OC_A MEM[65280+C]=A;

// 0xE5
#define OP_PUSH_HL MEM[SP-1]=H; MEM[SP-2]=L; SP=SP-2;

// 0xE6 // todo ??
#define OP_AND_D8 A=A&MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                 SET_FLAG_C(0); SET_FLAG_H(1); SET_FLAG_N(0);

// 0xE7
#define OP_RST_20 *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x20;

// 0xE8
// todo: (HL&(2047+bla))<blub or ((HL&2047)+bla)<blub ?
#define OP_ADD_SP_R8 if((HL&2047)+(*((int8_t*)MEM+PC+1))<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                     if((uint32_t)HL+(*((int8_t*)MEM+PC+1))<32767){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                     HL=HL+(*((int8_t*)MEM+PC+1)); SET_FLAG_Z(0); SET_FLAG_N(0);

// 0xE9
#define OP_JP_PHL PC=MEM[HL];

// 0xEA
#define OP_LD_A16_A *((uint16_t*) (MEM+PC+1))=A;

// 0xEE
#define OP_XOR_D8 A=A^MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                  SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xEF
#define OP_RST_28 *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x28;

// 0xF0
#define OP_LDH_A_A8 A=MEM[65280+MEM[PC+1]];

// 0xF1
#define OP_POP_AF F=MEM[SP+1];A=MEM[SP+2]; SP+=2;

// 0xF2
#define OP_LD_A_OC A=MEM[65280+C];

// 0xF3 disable interrupts
#define OP_DI DISABLE_IME

// 0xF5
#define OP_PUSH_AF MEM[SP-1]=A; MEM[SP-2]=F; SP=SP-2;

// 0xF6
#define OP_OR_D8 A=A|MEM[PC+1]; if(!A){SET_FLAG_Z(1);}else{SET_FLAG_Z(0);} \
                SET_FLAG_C(0); SET_FLAG_H(0); SET_FLAG_N(0);

// 0xF7
#define OP_RST_30 *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x30;

// 0xF8
// todo: (SP&(2047+bla))<blub or ((SP&2047)+bla)<blub ?
#define OP_LD_HL_SP_R8  if((SP&2047)+(*((int8_t*)MEM+PC+1))<2048){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                        if((uint32_t)SP+(*((int8_t*)MEM+PC+1))<32767){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                        HL=SP+(*((int8_t*)MEM+PC+1)); SET_FLAG_Z(0); SET_FLAG_N(0);

// 0xF9
#define OP_LD_SP_HL SP=HL;

// 0xFA
#define OP_LD_A_A16 A=*((uint16_t*) (MEM+PC+1));

// 0xFB enable interrupts
#define OP_EI ENABLE_IME

// 0xFE
#define OP_CP_D8 if(!(A-MEM[PC+1])){SET_FLAG_Z(1);}else{SET_FLAG_Z(0)}; \
                 if(A<MEM[PC+1]){SET_FLAG_C(1);}else{SET_FLAG_C(0);} \
                 if((A&15)<MEM[PC+1]){SET_FLAG_H(0);}else{SET_FLAG_H(1);} \
                 SET_FLAG_N(1);  

// 0xFF 
#define OP_RST_38 *(((uint16_t*)MEM)+SP-1)=PC; SP-=2; PC=0x38;    




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
