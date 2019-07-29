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
void OP_CB(void)
{
    // exec_cb[opcode_extended]();
}

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
void OP_RLC_B(void);

// 0x01
void OP_RLC_C(void);

// 0x02
void OP_RLC_D(void);

// 0x03
void OP_RLC_E(void);

// 0x04
void OP_RLC_H(void);

// 0x05
void OP_RLC_L(void);

// 0x06
void OP_RLC_PHL(void);

// 0x07
void OP_RLC_A(void);

// 0x08
void OP_RRC_B(void);;

// 0x09
void OP_RRC_C(void);

// 0x0A
void OP_RRC_D(void);;

// 0x0B
void OP_RRC_E(void);

// 0x0C
void OP_RRC_H(void);

// 0x0D
void OP_RRC_L(void);

// 0x0E
void OP_RRC_PHL(void);

// 0x0F
void OP_RRC_A(void);

// 0x10
void OP_RL_B(void);

// 0x11
void OP_RL_C(void);

// 0x12
void OP_RL_D(void);

// 0x13
void OP_RL_E(void);

// 0x14
void OP_RL_H(void);

// 0x15
void OP_RL_L(void);

// 0x16
void OP_RL_PHL(void);

// 0x17
void OP_RL_A(void);

// 0x18
void OP_RR_B(void);

// 0x19
void OP_RR_C(void);

// 0x1A
void OP_RR_D(void);

// 0x1B
void OP_RR_E(void);

// 0x1C
void OP_RR_H(void);

// 0x1D
void OP_RR_L(void);

// 0x1E
void OP_RR_PHL(void);

// 0x1F
void OP_RR_A(void);

// 0x20
void OP_SLA_B(void);

// 0x21
void OP_SLA_C(void);

// 0x22
void OP_SLA_D(void);

// 0x23
void OP_SLA_E(void);

// 0x24
void OP_SLA_H(void);

// 0x25
void OP_SLA_L(void);

// 0x26
void OP_SLA_PHL(void);

// 0x27
void OP_SLA_A(void);

// 0x28
void OP_SRA_B(void);

// 0x29
void OP_SRA_C(void);

// 0x2A
void OP_SRA_D(void);

// 0x2B
void OP_SRA_E(void);

// 0x2C
void OP_SRA_H(void);

// 0x2D
void OP_SRA_L(void);

// 0x2E
void OP_SRA_PHL(void);

// 0x2F
void OP_SRA_A(void);

// 0x30
void OP_SWAP_B(void);

// 0x31
void OP_SWAP_C(void);

// 0x32
void OP_SWAP_D(void);

// 0x33
void OP_SWAP_E(void);

// 0x34
void OP_SWAP_H(void);

// 0x35
void OP_SWAP_L(void);

// 0x36
void OP_SWAP_PHL(void);

// 0x37
void OP_SWAP_A(void);

// 0x38
void OP_SRL_B(void);

// 0x39
void OP_SRL_C(void);

// 0x3A
void OP_SRL_D(void);

// 0x3B
void OP_SRL_E(void);

// 0x3C
void OP_SRL_H(void);

// 0x3D
void OP_SRL_L(void);

// 0x3E
void OP_SRL_PHL(void);

// 0x3F
void OP_SRL_A(void);

// 0x40
void OP_BIT_0_B(void);

// 0x41
void OP_BIT_0_C(void);

// 0x42
void OP_BIT_0_D(void);

// 0x43
void OP_BIT_0_E(void);

// 0x44
void OP_BIT_0_H(void);

// 0x45
void OP_BIT_0_L(void);

// 0x46
void OP_BIT_0_PHL(void);

// 0x47
void OP_BIT_0_A(void);

// 0x48
void OP_BIT_1_B(void);

// 0x49
void OP_BIT_1_C(void);

// 0x4A
void OP_BIT_1_D(void);

// 0x4B
void OP_BIT_1_E(void);

// 0x4C
void OP_BIT_1_H(void);

// 0x4D
void OP_BIT_1_L(void);

// 0x4E
void OP_BIT_1_PHL(void);

// 0x4F
void OP_BIT_1_A(void);

// 0x50
void OP_BIT_2_B(void);

// 0x51
void OP_BIT_2_C(void);

// 0x52
void OP_BIT_2_D(void);

// 0x53
void OP_BIT_2_E(void);

// 0x54
void OP_BIT_2_H(void);

// 0x55
void OP_BIT_2_L(void);

// 0x56
void OP_BIT_2_PHL(void);

// 0x57
void OP_BIT_2_A(void);

// 0x58
void OP_BIT_3_B(void);

// 0x59
void OP_BIT_3_C(void);

// 0x5A
void OP_BIT_3_D(void);

// 0x5B
void OP_BIT_3_E(void);

// 0x5C
void OP_BIT_3_H(void);

// 0x5D
void OP_BIT_3_L(void);

// 0x5E
void OP_BIT_3_PHL(void);

// 0x5F
void OP_BIT_3_A(void);

// 0x60
void OP_BIT_4_B(void);

// 0x61
void OP_BIT_4_C(void);

// 0x62
void OP_BIT_4_D(void);

// 0x63
void OP_BIT_4_E(void);

// 0x64
void OP_BIT_4_H(void);

// 0x65
void OP_BIT_4_L(void);

// 0x66
void OP_BIT_4_PHL(void);

// 0x67
void OP_BIT_4_A(void);

// 0x68
void OP_BIT_5_B(void);

// 0x69
void OP_BIT_5_C(void);

// 0x6A
void OP_BIT_5_D(void);

// 0x6B
void OP_BIT_5_E(void);

// 0x6C
void OP_BIT_5_H(void);

// 0x6D
void OP_BIT_5_L(void);

// 0x6E
void OP_BIT_5_PHL(void);

// 0x6F
void OP_BIT_5_A(void);

// 0x70
void OP_BIT_6_B(void);

// 0x71
void OP_BIT_6_C(void);

// 0x72
void OP_BIT_6_D(void);

// 0x73
void OP_BIT_6_E(void);

// 0x74
void OP_BIT_6_H(void);

// 0x75
void OP_BIT_6_L(void);

// 0x76
void OP_BIT_6_PHL(void);

// 0x77
void OP_BIT_6_A(void);

// 0x78
void OP_BIT_7_B(void);

// 0x79
void OP_BIT_7_C(void);

// 0x7A
void OP_BIT_7_D(void);

// 0x7B
void OP_BIT_7_E(void);

// 0x7C
void OP_BIT_7_H(void);

// 0x7D
void OP_BIT_7_L(void);

// 0x7E
void OP_BIT_7_PHL(void);

// 0x7F
void OP_BIT_7_A(void);

// 0x80
void OP_RES_0_B(void);

// 0x81
void OP_RES_0_C(void);

// 0x82
void OP_RES_0_D(void);

// 0x83
void OP_RES_0_E(void);

// 0x84
void OP_RES_0_H(void);

// 0x85
void OP_RES_0_L(void);

// 0x86
void OP_RES_0_PHL(void);

// 0x87
void OP_RES_0_A(void);

// 0x88
void OP_RES_1_B(void);

// 0x89
void OP_RES_1_C(void);

// 0x8A
void OP_RES_1_D(void);

// 0x8B
void OP_RES_1_E(void);

// 0x8C
void OP_RES_1_H(void);

// 0x8D
void OP_RES_1_L(void);

// 0x8E
void OP_RES_1_PHL(void);

// 0x8F
void OP_RES_1_A(void);

// 0x90
void OP_RES_2_B(void);

// 0x91
void OP_RES_2_C(void);

// 0x92
void OP_RES_2_D(void);

// 0x93
void OP_RES_2_E(void);

// 0x94
void OP_RES_2_H(void);

// 0x95
void OP_RES_2_L(void);

// 0x96
void OP_RES_2_PHL(void);

// 0x97
void OP_RES_2_A(void);

// 0x98
void OP_RES_3_B(void);

// 0x99
void OP_RES_3_C(void);

// 0x9A
void OP_RES_3_D(void);

// 0x9B
void OP_RES_3_E(void);

// 0x9C
void OP_RES_3_H(void);

// 0x9D
void OP_RES_3_L(void);

// 0x9E
void OP_RES_3_PHL(void);

// 0x9F
void OP_RES_3_A(void);

// 0xA0
void OP_RES_4_B(void);

// 0xA1
void OP_RES_4_C(void);

// 0xA2
void OP_RES_4_D(void);

// 0xA3
void OP_RES_4_E(void);

// 0xA4
void OP_RES_4_H(void);

// 0xA5
void OP_RES_4_L(void);

// 0xA6
void OP_RES_4_PHL(void);

// 0xA7
void OP_RES_4_A(void);

// 0xA8
void OP_RES_5_B(void);

// 0xA9
void OP_RES_5_C(void);

// 0xAA
void OP_RES_5_D(void);

// 0xAB
void OP_RES_5_E(void);

// 0xAC
void OP_RES_5_H(void);

// 0xAD
void OP_RES_5_L(void);

// 0xAE
void OP_RES_5_A(void);

// 0xAF
void OP_RES_5_A(void);

// 0xB0
void OP_RES_6_B(void);

// 0xB1
void OP_RES_6_C(void);

// 0xB2
void OP_RES_6_D(void);

// 0xB3
void OP_RES_6_E(void);

// 0xB4
void OP_RES_6_H(void);

// 0xB5
void OP_RES_6_L(void);

// 0xB6
void OP_RES_6_PHL(void);

// 0xB7
void OP_RES_6_A(void);

// 0xB8
void OP_RES_7_B(void);

// 0xB9
void OP_RES_7_C(void);

// 0xBA
void OP_RES_7_D(void);

// 0xBB
void OP_RES_7_E(void);

// 0xBC
void OP_RES_7_H(void);

// 0xBD
void OP_RES_7_L(void);

// 0xBE
void OP_RES_7_PHL(void);

// 0xBF
void OP_RES_7_A(void);

// 0xC0
void OP_SET_0_B(void);

// 0xC1
void OP_SET_0_C(void);

// 0xC2
void OP_SET_0_D(void);

// 0xC3
void OP_SET_0_E(void);

// 0xC4
void OP_SET_0_H(void);

// 0xC5
void OP_SET_0_L(void);

// 0xC6
void OP_SET_0_PHL(void);

// 0xC7
void OP_SET_0_A(void);

// 0xC8
void OP_SET_1_B(void);

// 0xC9
void OP_SET_1_C(void);

// 0xCA
void OP_SET_1_D(void);

// 0xCB
void OP_SET_1_E(void);

// 0xCC
void OP_SET_1_H(void);

// 0xCD
void OP_SET_1_L(void);

// 0xCE
void OP_SET_1_PHL(void);

// 0xCF
void OP_SET_1_A(void);

// 0xD0
void OP_SET_2_B(void);

// 0xD1
void OP_SET_2_C(void);

// 0xD2
void OP_SET_2_D(void);

// 0xD3
void OP_SET_2_E(void);

// 0xD4
void OP_SET_2_H(void);

// 0xD5
void OP_SET_2_L(void);

// 0xD6
void OP_SET_2_PHL(void);

// 0xD7
void OP_SET_2_A(void);

// 0xD8
void OP_SET_3_B(void);

// 0xD9
void OP_SET_3_C(void);

// 0xDA
void OP_SET_3_D(void);

// 0xDB
void OP_SET_3_E(void);

// 0xDC
void OP_SET_3_H(void);

// 0xDD
void OP_SET_3_L(void);

// 0xDE
void OP_SET_3_PHL(void);

// 0xDF
void OP_SET_3_A(void);

// 0xE0
void OP_SET_4_B(void);

// 0xE1
void OP_SET_4_C(void);

// 0xE2
void OP_SET_4_D(void);

// 0xE3
void OP_SET_4_E(void);

// 0xE4
void OP_SET_4_H(void);

// 0xE5
void OP_SET_4_L(void);

// 0xE6
void OP_SET_4_PHL(void);

// 0xE7
void OP_SET_4_A(void);

// 0xE8
void OP_SET_5_B(void);

// 0xE9
void OP_SET_5_C(void);

// 0xEA
void OP_SET_5_D(void);

// 0xEB
void OP_SET_5_E(void);

// 0xEC
void OP_SET_5_H(void);

// 0xED
void OP_SET_5_L(void);

// 0xEE
void OP_SET_5_PHL(void);

// 0xEF
void OP_SET_5_A(void);

// 0xF0
void OP_SET_6_B(void);

// 0xF1
void OP_SET_6_C(void);

// 0xF2
void OP_SET_6_D(void);

// 0xF3
void OP_SET_6_E(void);

// 0xF4
void OP_SET_6_H(void);

// 0xF5
void OP_SET_6_L(void);

// 0xF6
void OP_SET_6_PHL(void);

// 0xF7
void OP_SET_6_A(void);

// 0xF8
void OP_SET_7_B(void);

// 0xF9
void OP_SET_7_C(void);

// 0xFA
void OP_SET_7_D(void);

// 0xFB
void OP_SET_7_E(void);

// 0xFC
void OP_SET_7_H(void);

// 0xFD
void OP_SET_7_L(void);

// 0xFE
void OP_SET_7_PHL(void);

// 0xFF
void OP_SET_7_A(void);



//check if bit n (counting from 0 to 7) is set in X
#define CHECK_BIT(X,n) ((X) & (1<<(n)))
