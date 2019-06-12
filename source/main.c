#include "main.h"

int main()
{
    int err;
    printf("Hello, DMG\n");

    PC = 0;

	setvbuf(stdout, NULL, _IONBF,0);

    uint8_t* MEM = malloc(sizeof(uint8_t) * 65536);
    if(!MEM)
    {
      fprintf(stderr, "ERROR: could not allocate memory!\n");
      return EXIT_FAILURE;
    }

    err = readfff(MEM, "ROMs/Tetris.gb");

    if(err == EXIT_FAILURE) {return EXIT_FAILURE;}

	print_mem(0,32,'h',MEM);
	create_coredump(MEM,65536);
	reset_coredump(MEM,65536);


    struct timespec t0;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    uint32_t nanosecs;
    uint8_t opcode;
    uint8_t extended_opcode;

    uint8_t   t8 [8];
    uint16_t  t16[8];
    uint32_t  t32[8];

    long x = 0;

    loop:

    opcode = MEM[PC];

    switch(opcode)
    {
        case 0x0:
					OP_NOP
					break;

		case 0x1:
					OP_LD_BC_D16
					break;

		case 0x2:
					OP_LD_PBC_A
					break;

		case 0x3:
					OP_INC_BC
					break;

		case 0x4:
					OP_INC_B
					break;

		case 0x5:
					OP_DEC_B
					break;

		case 0x6:
					OP_LD_B_D8
					break;

		case 0x7:
					OP_RLCA
					break;

		case 0x8:
					OP_LD_A16_SP
					break;

		case 0x9:	OP_ADD_HL_BC
					
					break;

		case 0xa:
					OP_LD_A_PBC
					break;

		case 0xb:
					OP_DEC_BC
					break;

		case 0xc:
					OP_INC_C
					break;

		case 0xd:
					OP_DEC_C
					break;

		case 0xe:
					OP_LD_C_D8
					break;

		case 0xf:
					OP_RRCA
					break;

		case 0x10:
					printf("STOP isn't implemented yet\n");
					break;

		case 0x11:
					OP_LD_DE_D16
					break;

		case 0x12:
					OP_LD_PDE_A
					break;

		case 0x13:
					OP_INC_DE
					break;

		case 0x14:
					OP_INC_D
					break;

		case 0x15:
					OP_DEC_D
					break;

		case 0x16:
					OP_LD_D_D8
					break;

		case 0x17:
					OP_RLA
					break;

		case 0x18:
					OP_JR_R8
					break;

		case 0x19:
					OP_ADD_HL_DE
					break;

		case 0x1a:
					OP_LD_A_PDE
					break;

		case 0x1b:
					OP_DEC_DE
					break;

		case 0x1c:
					OP_INC_E
					break;

		case 0x1d:
					OP_DEC_E
					break;

		case 0x1e:
					OP_LD_E_D8
					break;

		case 0x1f:
					OP_RRA
					break;

		case 0x20:
					OP_JR_NZ_R8
					break;

		case 0x21:
					OP_LD_HL_D16
					break;

		case 0x22:
					OP_LD_PHLI_A
					break;

		case 0x23:
					OP_INC_HL
					break;

		case 0x24:
					OP_INC_H
					break;

		case 0x25:
					OP_DEC_H
					break;

		case 0x26:
					OP_LD_H_D8
					break;

		case 0x27:
					printf("DAA isn't implented yet\n");
					break;

		case 0x28:
					OP_JR_Z_R8
					break;

		case 0x29:
					OP_ADD_HL_HL
					break;

		case 0x2a:
					OP_LD_A_PHLI
					break;

		case 0x2b:
					OP_DEC_HL
					break;

		case 0x2c:
					OP_INC_L
					break;

		case 0x2d:
					OP_DEC_L
					break;

		case 0x2e:
					OP_LD_L_D8
					break;

		case 0x2f:
					OP_CPL
					break;

		case 0x30:
					OP_JR_NC_R8
					break;

		case 0x31:
					OP_LD_SP_D16
					break;

		case 0x32:
					OP_LD_PHLD_A
					break;

		case 0x33:
					OP_INC_SP
					break;

		case 0x34:
					OP_INC_PHL
					break;

		case 0x35:
					OP_DEC_PHL
					break;

		case 0x36:
					OP_LD_PHL_D8
					break;

		case 0x37:
					OP_SCF
					break;

		case 0x38:
					OP_JR_C_R8
					break;

		case 0x39:
					OP_ADD_HL_SP
					break;

		case 0x3a:
					OP_LD_A_PHLI
					break;

		case 0x3b:
					OP_DEC_SP
					break;

		case 0x3c:
					OP_INC_A
					break;

		case 0x3d:
					OP_DEC_A
					break;

		case 0x3e:
					OP_LD_A_D8
					break;

		case 0x3f:
					OP_CCF
					break;

		case 0x40:
					OP_LD_B_B
					break;

		case 0x41:
					OP_LD_B_C
					break;

		case 0x42:
					OP_LD_B_D
					break;

		case 0x43:
					OP_LD_B_E
					break;

		case 0x44:
					OP_LD_B_H
					break;

		case 0x45:
					OP_LD_B_L
					break;

		case 0x46:
					OP_LD_B_PHL
					break;

		case 0x47:
					OP_LD_B_A
					break;

		case 0x48:
					OP_LD_C_B
					break;

		case 0x49:
					OP_LD_C_C
					break;

		case 0x4a:
					OP_LD_C_D
					break;

		case 0x4b:
					OP_LD_C_E
					break;

		case 0x4c:
					OP_LD_C_H
					break;

		case 0x4d:
					OP_LD_C_L
					break;

		case 0x4e:
					OP_LD_C_PHL
					break;

		case 0x4f:
					OP_LD_C_A
					break;

		case 0x50:
					OP_LD_D_B
					break;

		case 0x51:
					OP_LD_D_C
					break;

		case 0x52:
					OP_LD_D_D
					break;

		case 0x53:
					OP_LD_D_E
					break;

		case 0x54:
					OP_LD_D_H
					break;

		case 0x55:
					OP_LD_D_L
					break;

		case 0x56:
					OP_LD_D_PHL
					break;

		case 0x57:
					OP_LD_D_A
					break;

		case 0x58:
					OP_LD_E_B
					break;

		case 0x59:
					OP_LD_E_C
					break;

		case 0x5a:
					OP_LD_E_D
					break;

		case 0x5b:
					OP_LD_E_E
					break;

		case 0x5c:
					OP_LD_E_H
					break;

		case 0x5d:
					OP_LD_E_L
					break;

		case 0x5e:
					OP_LD_E_PHL
					break;

		case 0x5f:
					OP_LD_E_A
					break;

		case 0x60:
					OP_LD_H_B
					break;

		case 0x61:
					OP_LD_H_C
					break;

		case 0x62:
					OP_LD_H_D
					break;

		case 0x63:
					OP_LD_H_E
					break;

		case 0x64:
					OP_LD_H_H
					break;

		case 0x65:
					OP_LD_H_L
					break;

		case 0x66:
					OP_LD_H_PHL
					break;

		case 0x67:
					OP_LD_H_A
					break;

		case 0x68:
					OP_LD_L_B
					break;

		case 0x69:
					OP_LD_L_C
					break;

		case 0x6a:
					OP_LD_L_D
					break;

		case 0x6b:
					OP_LD_L_E
					break;

		case 0x6c:
					OP_LD_L_H
					break;

		case 0x6d:
					OP_LD_L_L
					break;

		case 0x6e:
					OP_LD_L_PHL
					break;

		case 0x6f:
					OP_LD_L_A
					break;

		case 0x70:
					OP_LD_PHL_B
					break;

		case 0x71:
					OP_LD_PHL_C
					break;

		case 0x72:
					OP_LD_PHL_D
					break;

		case 0x73:
					OP_LD_PHL_E
					break;

		case 0x74:
					OP_LD_PHL_H
					break;

		case 0x75:
					OP_LD_PHL_L
					break;

		case 0x76:
					printf("HALT isn't implemented yet\n");
					break;

		case 0x77:
					OP_LD_PHL_A
					break;

		case 0x78:
					OP_LD_A_B
					break;

		case 0x79:
					OP_LD_A_C
					break;

		case 0x7a:
					OP_LD_A_D
					break;

		case 0x7b:
					OP_LD_A_E
					break;

		case 0x7c:
					OP_LD_A_H
					break;

		case 0x7d:
					OP_LD_A_L
					break;

		case 0x7e:
					OP_LD_A_PHL
					break;

		case 0x7f:
					OP_LD_A_A
					break;

		case 0x80:
					OP_ADD_A_B
					break;

		case 0x81:
					OP_ADD_A_C
					break;

		case 0x82:
					OP_ADD_A_D
					break;

		case 0x83:
					OP_ADD_A_E
					break;

		case 0x84:
					OP_ADD_A_H
					break;

		case 0x85:
					OP_ADD_A_L
					break;

		case 0x86:
					OP_ADD_A_PHL
					break;

		case 0x87:
					OP_ADD_A_A
					break;

		case 0x88:
					OP_ADC_A_B
					break;

		case 0x89:
					OP_ADC_A_C
					break;

		case 0x8a:
					OP_ADC_A_D
					break;

		case 0x8b:
					OP_ADC_A_E
					break;

		case 0x8c:
					OP_ADC_A_H
					break;

		case 0x8d:
					OP_ADC_A_L
					break;

		case 0x8e:
					OP_ADC_A_PHL
					break;

		case 0x8f:
					OP_ADC_A_A
					break;

		case 0x90:
					OP_SUB_A_B
					break;

		case 0x91:
					OP_SUB_A_C
					break;

		case 0x92:
					OP_SUB_A_D
					break;

		case 0x93:
					OP_SUB_A_E
					break;

		case 0x94:
					OP_SUB_A_H
					break;

		case 0x95:
					OP_SUB_A_L
					break;

		case 0x96:
					OP_SUB_A_PHL
					break;

		case 0x97:
					OP_SUB_A_A
					break;

		case 0x98:
					OP_SBC_A_B
					break;

		case 0x99:
					OP_SBC_A_C
					break;

		case 0x9a:
					OP_SBC_A_D
					break;

		case 0x9b:
					OP_SBC_A_E
					break;

		case 0x9c:
					OP_SBC_A_H
					break;

		case 0x9d:
					OP_SBC_A_L
					break;

		case 0x9e:
					OP_SBC_A_PHL
					break;

		case 0x9f:
					OP_SBC_A_A
					break;

		case 0xa0:
					OP_AND_B
					break;

		case 0xa1:
					OP_AND_C
					break;

		case 0xa2:
					OP_AND_D
					break;

		case 0xa3:
					OP_AND_E
					break;

		case 0xa4:
					OP_AND_H
					break;

		case 0xa5:
					OP_AND_L
					break;

		case 0xa6:
					OP_AND_PHL
					break;

		case 0xa7:
					OP_AND_A
					break;

		case 0xa8:
					OP_XOR_B
					break;

		case 0xa9:
					OP_XOR_C
					break;

		case 0xaa:
					OP_XOR_D
					break;

		case 0xab:
					OP_XOR_E
					break;

		case 0xac:
					OP_XOR_H
					break;

		case 0xad:
					OP_XOR_L
					break;

		case 0xae:
					OP_XOR_PHL
					break;

		case 0xaf:
					OP_XOR_A
					break;

		case 0xb0:
					OP_OR_B
					break;

		case 0xb1:
					OP_OR_C
					break;

		case 0xb2:
					OP_OR_D
					break;

		case 0xb3:
					OP_OR_E
					break;

		case 0xb4:
					OP_OR_H
					break;

		case 0xb5:
					OP_OR_L
					break;

		case 0xb6:
					OP_OR_PHL
					break;

		case 0xb7:
					OP_OR_A
					break;

		case 0xb8:
					OP_CP_B
					break;

		case 0xb9:
					OP_CP_C
					break;

		case 0xba:
					OP_CP_D
					break;

		case 0xbb:
					OP_CP_E
					break;

		case 0xbc:
					OP_CP_H
					break;

		case 0xbd:
					OP_CP_L
					break;

		case 0xbe:
					OP_CP_PHL
					break;

		case 0xbf:
					OP_CP_A
					break;

		case 0xc0:
					OP_RET_NZ
					break;

		case 0xc1:
					OP_POP_BC
					break;

		case 0xc2:
					OP_JP_NZ_A16
					break;

		case 0xc3:
					OP_JP_A16
					break;
        
		case 0xc4:
					OP_CALL_NZ_A16
					break;

		case 0xc5:
					OP_PUSH_BC
					break;

		case 0xc6:
					OP_ADD_A_D8
					break;

		case 0xc7:
					OP_RST_00
					break;
        
		case 0xc8:
					OP_RET_Z
					break;

		case 0xc9:
					OP_RET
					break;

		case 0xca:
					OP_JP_Z_A16
					break;
        
		case 0xcb:
					extended_opcode = MEM[PC+1];
                    switch(extended_opcode)
                    {
                        case 0x0:
									OP_RLC_B
									break;

						case 0x1:
									OP_RLC_C
									break;

						case 0x2:
									OP_RLC_D
									break;

						case 0x3:
									OP_RLC_E
									break;

						case 0x4:
									OP_RLC_H
									break;

						case 0x5:
									OP_RLC_L
									break;

						case 0x6:
									OP_RLC_PHL
									break;

						case 0x7:
									OP_RLC_A
									break;

						case 0x8:
									OP_RRC_B
									break;

						case 0x9:	OP_RRC_C
									
									break;

						case 0xa:
									OP_RRC_D
									break;

						case 0xb:
									OP_RRC_E
									break;

						case 0xc:
									OP_RRC_H
									break;

						case 0xd:
									OP_RRC_L
									break;

						case 0xe:
									OP_RRC_PHL
									break;

						case 0xf:
									OP_RRC_A
									break;

						case 0x10:
									OP_RL_B
									break;

						case 0x11:
									OP_RL_C
									break;

						case 0x12:
									OP_RL_D
									break;

						case 0x13:
									OP_RL_E
									break;

						case 0x14:
									OP_RL_H
									break;

						case 0x15:
									OP_RL_L
									break;

						case 0x16:
									OP_RL_PHL
									break;

						case 0x17:
									OP_RL_A
									break;

						case 0x18:
									OP_RR_B
									break;

						case 0x19:
									OP_RR_C
									break;

						case 0x1a:
									OP_RR_D
									break;

						case 0x1b:
									OP_RR_E
									break;

						case 0x1c:
									OP_RR_H
									break;

						case 0x1d:
									OP_RR_L
									break;

						case 0x1e:
									OP_RR_PHL
									break;

						case 0x1f:
									OP_RR_A
									break;

						case 0x20:
									OP_SLA_B
									break;

						case 0x21:
									OP_SLA_C
									break;

						case 0x22:
									OP_SLA_D
									break;

						case 0x23:
									OP_SLA_E
									break;

						case 0x24:
									OP_SLA_H
									break;

						case 0x25:
									OP_SLA_L
									break;

						case 0x26:
									OP_SLA_PHL
									break;

						case 0x27:
									OP_SLA_A
									break;

						case 0x28:
									OP_SRA_B
									break;

						case 0x29:
									OP_SRA_C
									break;

						case 0x2a:
									OP_SRA_D
									break;

						case 0x2b:
									OP_SRA_E
									break;

						case 0x2c:
									OP_SRA_H
									break;

						case 0x2d:
									OP_SRA_L
									break;

						case 0x2e:
									OP_SRA_PHL
									break;

						case 0x2f:
									OP_SRA_A
									break;

						case 0x30:
									OP_SWAP_B
									break;

						case 0x31:
									OP_SWAP_C
									break;

						case 0x32:
									OP_SWAP_D
									break;

						case 0x33:
									OP_SWAP_E
									break;

						case 0x34:
									OP_SWAP_H
									break;

						case 0x35:
									OP_SWAP_L
									break;

						case 0x36:
									OP_SWAP_PHL
									break;

						case 0x37:
									OP_SWAP_A
									break;

						case 0x38:
									OP_SRL_B
									break;

						case 0x39:
									OP_SRL_C
									break;

						case 0x3a:
									OP_SRL_D
									break;

						case 0x3b:
									OP_SRL_E
									break;

						case 0x3c:
									OP_SRL_H
									break;

						case 0x3d:
									OP_SRL_L
									break;

						case 0x3e:
									OP_SRL_PHL
									break;

						case 0x3f:
									OP_SRL_A
									break;

						case 0x40:
									OP_BIT_0_B
									break;

						case 0x41:
									OP_BIT_0_C
									break;

						case 0x42:
									OP_BIT_0_D
									break;

						case 0x43:
									OP_BIT_0_E
									break;

						case 0x44:
									OP_BIT_0_H
									break;

						case 0x45:
									OP_BIT_0_L
									break;

						case 0x46:
									OP_BIT_0_PHL
									break;

						case 0x47:
									OP_BIT_0_A
									break;

						case 0x48:
									OP_BIT_1_B
									break;

						case 0x49:
									OP_BIT_1_C
									break;

						case 0x4a:
									OP_BIT_1_D
									break;

						case 0x4b:
									OP_BIT_1_E
									break;

						case 0x4c:
									OP_BIT_1_H
									break;

						case 0x4d:
									OP_BIT_1_L
									break;

						case 0x4e:
									OP_BIT_1_PHL
									break;

						case 0x4f:
									OP_BIT_1_A
									break;

						case 0x50:
									OP_BIT_2_B
									break;

						case 0x51:
									OP_BIT_2_C
									break;

						case 0x52:
									OP_BIT_2_D
									break;

						case 0x53:
									OP_BIT_2_E
									break;

						case 0x54:
									OP_BIT_2_H
									break;

						case 0x55:
									OP_BIT_2_L
									break;

						case 0x56:
									OP_BIT_2_PHL
									break;

						case 0x57:
									OP_BIT_2_A
									break;

						case 0x58:
									OP_BIT_3_B
									break;

						case 0x59:
									OP_BIT_3_C
									break;

						case 0x5a:
									OP_BIT_3_D
									break;

						case 0x5b:
									OP_BIT_3_E
									break;

						case 0x5c:
									OP_BIT_3_H
									break;

						case 0x5d:
									OP_BIT_3_L
									break;

						case 0x5e:
									OP_BIT_3_PHL
									break;

						case 0x5f:
									OP_BIT_3_A
									break;

						case 0x60:
									OP_BIT_4_B
									break;

						case 0x61:
									OP_BIT_4_C
									break;

						case 0x62:
									OP_BIT_4_D
									break;

						case 0x63:
									OP_BIT_4_E
									break;

						case 0x64:
									OP_BIT_4_H
									break;

						case 0x65:
									OP_BIT_4_L
									break;

						case 0x66:
									OP_BIT_4_PHL
									break;

						case 0x67:
									OP_BIT_4_A
									break;

						case 0x68:
									OP_BIT_5_B
									break;

						case 0x69:
									OP_BIT_5_C
									break;

						case 0x6a:
									OP_BIT_5_D
									break;

						case 0x6b:
									OP_BIT_5_E
									break;

						case 0x6c:
									OP_BIT_5_H
									break;

						case 0x6d:
									OP_BIT_5_L
									break;

						case 0x6e:
									OP_BIT_5_PHL
									break;

						case 0x6f:
									OP_BIT_5_A
									break;

						case 0x70:
									OP_BIT_6_B
									break;

						case 0x71:
									OP_BIT_6_C
									break;

						case 0x72:
									OP_BIT_6_D
									break;

						case 0x73:
									OP_BIT_6_E
									break;

						case 0x74:
									OP_BIT_6_H
									break;

						case 0x75:
									OP_BIT_6_L
									break;

						case 0x76:
									OP_BIT_6_PHL
									break;

						case 0x77:
									OP_BIT_6_A
									break;

						case 0x78:
									OP_BIT_7_B
									break;

						case 0x79:
									OP_BIT_7_C
									break;

						case 0x7a:
									OP_BIT_7_D
									break;

						case 0x7b:
									OP_BIT_7_E
									break;

						case 0x7c:
									OP_BIT_7_H
									break;

						case 0x7d:
									OP_BIT_7_L
									break;

						case 0x7e:
									OP_BIT_7_PHL
									break;

						case 0x7f:
									OP_BIT_7_A
									break;

						case 0x80:
									OP_RES_0_B
									break;

						case 0x81:
									OP_RES_0_C
									break;

						case 0x82:
									OP_RES_0_D
									break;

						case 0x83:
									OP_RES_0_E
									break;

						case 0x84:
									OP_RES_0_H
									break;

						case 0x85:
									OP_RES_0_L
									break;

						case 0x86:
									OP_RES_0_PHL
									break;

						case 0x87:
									OP_RES_0_A
									break;

						case 0x88:
									OP_RES_1_B
									break;

						case 0x89:
									OP_RES_1_C
									break;

						case 0x8a:
									OP_RES_1_D
									break;

						case 0x8b:
									OP_RES_1_E
									break;

						case 0x8c:
									OP_RES_1_H
									break;

						case 0x8d:
									OP_RES_1_L
									break;

						case 0x8e:
									OP_RES_1_PHL
									break;

						case 0x8f:
									OP_RES_1_A
									break;

						case 0x90:
									OP_RES_2_B
									break;

						case 0x91:
									OP_RES_2_C
									break;

						case 0x92:
									OP_RES_2_D
									break;

						case 0x93:
									OP_RES_2_E
									break;

						case 0x94:
									OP_RES_2_H
									break;

						case 0x95:
									OP_RES_2_L
									break;

						case 0x96:
									OP_RES_2_PHL
									break;

						case 0x97:
									OP_RES_2_A
									break;

						case 0x98:
									OP_RES_3_B
									break;

						case 0x99:
									OP_RES_3_C
									break;

						case 0x9a:
									OP_RES_3_D
									break;

						case 0x9b:
									OP_RES_3_E
									break;

						case 0x9c:
									OP_RES_3_H
									break;

						case 0x9d:
									OP_RES_3_L
									break;

						case 0x9e:
									OP_RES_3_PHL
									break;

						case 0x9f:
									OP_RES_3_A
									break;

						case 0xa0:
									OP_RES_4_B
									break;

						case 0xa1:
									OP_RES_4_C
									break;

						case 0xa2:
									OP_RES_4_D
									break;

						case 0xa3:
									OP_RES_4_E
									break;

						case 0xa4:
									OP_RES_4_H
									break;

						case 0xa5:
									OP_RES_4_L
									break;

						case 0xa6:
									OP_RES_4_PHL
									break;

						case 0xa7:
									OP_RES_4_A
									break;

						case 0xa8:
									OP_RES_5_B
									break;

						case 0xa9:
									OP_RES_5_C
									break;

						case 0xaa:
									OP_RES_5_D
									break;

						case 0xab:
									OP_RES_5_E
									break;

						case 0xac:
									OP_RES_5_H
									break;

						case 0xad:
									OP_RES_5_L
									break;

						case 0xae:
									OP_RES_5_PHL
									break;

						case 0xaf:
									OP_RES_5_A
									break;

						case 0xb0:
									OP_RES_6_B
									break;

						case 0xb1:
									OP_RES_6_C
									break;

						case 0xb2:
									OP_RES_6_D
									break;

						case 0xb3:
									OP_RES_6_E
									break;

						case 0xb4:
									OP_RES_6_H
									break;

						case 0xb5:
									OP_RES_6_L
									break;

						case 0xb6:
									OP_RES_6_PHL
									break;

						case 0xb7:
									OP_RES_6_A
									break;

						case 0xb8:
									OP_RES_7_B
									break;

						case 0xb9:
									OP_RES_7_C
									break;

						case 0xba:
									OP_RES_7_D
									break;

						case 0xbb:
									OP_RES_7_E
									break;

						case 0xbc:
									OP_RES_7_H
									break;

						case 0xbd:
									OP_RES_7_L
									break;

						case 0xbe:
									OP_RES_7_PHL
									break;

						case 0xbf:
									OP_RES_7_A
									break;

						case 0xc0:
									OP_SET_0_B
									break;

						case 0xc1:
									OP_SET_0_C
									break;

						case 0xc2:
									OP_SET_0_D
									break;

						case 0xc3:
									OP_SET_0_E
									break;
						
						case 0xc4:
									OP_SET_0_H
									break;

						case 0xc5:
									OP_SET_0_L
									break;

						case 0xc6:
									OP_SET_0_PHL
									break;

						case 0xc7:
									OP_SET_0_A
									break;
						
						case 0xc8:
									OP_SET_1_B
									break;

						case 0xc9:
									OP_SET_1_C
									break;

						case 0xca:
									OP_SET_1_D
									break;
						
						case 0xcb:
									OP_SET_1_E               
									break;
						
						case 0xcc:
									OP_SET_1_H
									break;
						
						case 0xcd:
									OP_SET_1_L
									break;
						
						case 0xce:
									OP_SET_1_PHL
									break;
						
						case 0xcf:
									OP_SET_1_A
									break;
						
						case 0xd0:
									OP_SET_2_B
									break;
						
						case 0xd1:
									OP_SET_2_C
									break;
						
						case 0xd2:
									OP_SET_2_D
									break;
						
						case 0xd3:
									OP_SET_2_E
									break;
						
						case 0xd4:
									OP_SET_2_H
									break;
						
						case 0xd5:
									OP_SET_2_L
									break;

						case 0xd6:
									OP_SET_2_PHL
									break;

						case 0xd7:
									OP_SET_2_A
									break;
						
						case 0xd8:
									OP_SET_3_B
									break;
						
						case 0xd9:
									OP_SET_3_C
									break;
						
						case 0xda:
									OP_SET_3_D
									break;
						
						case 0xdb:
									OP_SET_3_E
									break;
						
						case 0xdc:
									OP_SET_3_H
									break;
						
						case 0xdd:
									OP_SET_3_L
									break;

						case 0xde:
									OP_SET_3_PHL
									break;

						case 0xdf:
									OP_SET_3_A
									break;

						case 0xe0:
									OP_SET_4_B
									break;

						case 0xe1:
									OP_SET_4_C
									break;

						case 0xe2:
									OP_SET_4_D
									break;

						case 0xe3:
									OP_SET_4_E
									break;

						case 0xe4:
									OP_SET_4_H
									break;

						case 0xe5:
									OP_SET_4_L
									break;

						case 0xe6:
									OP_SET_4_PHL
									break;

						case 0xe7:
									OP_SET_4_A
									break;

						case 0xe8:
									OP_SET_5_B
									break;

						case 0xe9:
									OP_SET_5_C
									break;

						case 0xea:
									OP_SET_5_D
									break;

						case 0xeb:
									OP_SET_5_E
									break;

						case 0xec:
									OP_SET_5_H
									break;

						case 0xed:
									OP_SET_5_L
									break;

						case 0xee:
									OP_SET_5_PHL
									break;

						case 0xef:
									OP_SET_5_A
									break;

						case 0xf0:
									OP_SET_6_B
									break;

						case 0xf1:
									OP_SET_6_C
									break;

						case 0xf2:
									OP_SET_6_D
									break;

						case 0xf3:
									OP_SET_6_E
									break;

						case 0xf4:
									OP_SET_6_H
									break;

						case 0xf5:
									OP_SET_6_L
									break;

						case 0xf6:
									OP_SET_6_PHL
									break;

						case 0xf7:
									OP_SET_6_A
									break;

						case 0xf8:
									OP_SET_7_B
									break;

						case 0xf9:
									OP_SET_7_C
									break;

						case 0xfa:
									OP_SET_7_D
									break;

						case 0xfb:
									OP_SET_7_E
									break;

						case 0xfc:
									OP_SET_7_H
									break;

						case 0xfd:
									OP_SET_7_L
									break;

						case 0xfe:
									OP_SET_7_PHL
									break;

						case 0xff:
									OP_SET_7_A
									break;
                    }                    
					break;
        
		case 0xcc:
					OP_CALL_Z_A16
					break;
        
		case 0xcd:
					OP_CALL_A16
					break;
        
		case 0xce:
					OP_ADC_A_D8
					break;
        
		case 0xcf:
					OP_RST_08
					break;
        
		case 0xd0:
					OP_RET_NC
					break;
        
		case 0xd1:
					OP_POP_DE
					break;
        
		case 0xd2:
					OP_JP_NC_A16
					break;
        
		case 0xd3:
					printf("unknown opcode\n");
					break;
        
		case 0xd4:
					OP_CALL_NC_A16
					break;
        
		case 0xd5:
					OP_PUSH_DE
					break;

		case 0xd6:
					OP_SUB_A_D8
					break;

		case 0xd7:
					OP_RST_10
					break;
        
		case 0xd8:
					OP_RET_C
					break;
        
		case 0xd9:
					OP_RETI
					break;
        
		case 0xda:
					OP_JP_C_A16
					break;
        
		case 0xdb:
					printf("unknown opcode\n");
					break;
        
		case 0xdc:
					OP_CALL_C_A16
					break;
        
		case 0xdd:
					printf("unknown opcode\n");
					break;

		case 0xde:
					OP_SBC_A_D8
					break;

		case 0xdf:
					OP_RST_18
					break;

		case 0xe0:
					OP_LDH_PA8_A
					break;

		case 0xe1:
					OP_POP_HL
					break;

		case 0xe2:
					OP_LD_OC_A
					break;

		case 0xe3:
					printf("unknown opcode\n");
					break;

		case 0xe4:
					printf("unknown opcode\n");
					break;

		case 0xe5:
					OP_PUSH_HL
					break;

		case 0xe6:
					OP_AND_D8
					break;

		case 0xe7:
					OP_RST_20
					break;

		case 0xe8:
					OP_ADD_SP_R8
					break;

		case 0xe9:
					OP_JP_PHL
					break;

		case 0xea:
					OP_LD_A16_A
					break;

		case 0xeb:
					printf("unknown opcode\n");
					break;

		case 0xec:
					printf("unknown opcode\n");
					break;

		case 0xed:
					printf("unknown opcode\n");
					break;

		case 0xee:
					OP_XOR_D8
					break;

		case 0xef:
					OP_RST_28
					break;

		case 0xf0:
					OP_LDH_A_A8
					break;

		case 0xf1:
					OP_POP_AF
					break;

		case 0xf2:
					OP_LD_A_OC
					break;

		case 0xf3:
					OP_DI
					break;

		case 0xf4:
					printf("unknown opcode\n");
					break;

		case 0xf5:
					OP_PUSH_AF
					break;

		case 0xf6:
					OP_OR_D8
					break;

		case 0xf7:
					OP_RST_30
					break;

		case 0xf8:
					OP_LD_HL_SP_R8
					break;

		case 0xf9:
					OP_LD_SP_HL
					break;

		case 0xfa:
					OP_LD_A_A16
					break;

		case 0xfb:
					OP_EI
					break;

		case 0xfc:
					printf("unknown opcode\n");
					break;

		case 0xfd:
					printf("unknown opcode\n");
					break;

		case 0xfe:
					OP_CP_D8
					break;

		case 0xff:
					OP_RST_38
					break;


    }

    PC += OPCODE_LENGTH[opcode];

    if(++x == 4190000)
    {
        fprintf(stderr, "4.19 Million clocks passed!\n\n");
        x=0;
    }

    goto loop;
    end:

    free(MEM);

    return EXIT_SUCCESS;
}

void print_mem(uint16_t low, uint16_t high, char mode, uint8_t* MEM)
{
	int n=high-low;
	if(n<=0)
	{
		printf("invalid range\n");
	}

	// mode d for decimal output
	if(mode=='d')
	{
		for(int i=0; i<n; i++)
		{
			printf("%u ",MEM[low+i]);
			if(i%8==7){printf("\n");}
		}
	}
	// mode h for hexadecimal output
	if(mode=='h')
	{
		for(int i=0; i<n; i++)
        {
            printf("%02x%s", MEM[i], (i+1)%8?" ":((i+1)%n?"\n":"\n\n"));
        }
	}
	// mode b for binary output
	if(mode=='b')
	{
		uint8_t* buf = malloc(sizeof(uint8_t)*8);
		for(int i=0; i<n; i++)
		{
			buf[0]=MEM[low+i]&1 ? 1 : 0;
			buf[1]=MEM[low+i]&2 ? 1 : 0;
			buf[2]=MEM[low+i]&4 ? 1 : 0;
			buf[3]=MEM[low+i]&8 ? 1 : 0;
			buf[4]=MEM[low+i]&16 ? 1 : 0;
			buf[5]=MEM[low+i]&32 ? 1 : 0;
			buf[6]=MEM[low+i]&64 ? 1 : 0;
			buf[7]=MEM[low+i]&128 ? 1 : 0;
			for(int j=0; j<8; j++)
			{
				printf("%u ",buf[j]);
			}
			printf(" ");
			if(i%8==7){printf("\n");}
		}
	}
}

void read_header(uint8_t* buf)
{
	// read name
	uint8_t* name = malloc(16*(sizeof(uint8_t)));
	for(int i=0; i<16; i++)
	{
		name[i]=(char)buf[0x134+i];
		if(buf[0x135+i]==0xFF){break;}
	}
	//read cartridgetype
	char* cartridgetype = malloc(sizeof(char)*32);
	if(buf[0x147]==0x00){cartridgetype="ROM ONLY";}
	if(buf[0x147]==0x01){cartridgetype="MBC1";}
	if(buf[0x147]==0x02){cartridgetype="MBC1+RAM";}
	if(buf[0x147]==0x03){cartridgetype="MBC1+RAM+BATTERY";}
	if(buf[0x147]==0x05){cartridgetype="MBC2";}
	if(buf[0x147]==0x05){cartridgetype="MBC2+BATTERY";}
	if(buf[0x147]==0x08){cartridgetype="ROM+RAM";}
	if(buf[0x147]==0x09){cartridgetype="ROM+RAM+BATTERY";}
	if(buf[0x147]==0x0B){cartridgetype="MMM01";}
	if(buf[0x147]==0x0C){cartridgetype="MMM01+RAM";}
	if(buf[0x147]==0x0D){cartridgetype="MMM01+RAM+BATTERY";}
	if(buf[0x147]==0x11){cartridgetype="MBC3";}
	if(buf[0x147]==0x12){cartridgetype="MBC3+RAM";}
	if(buf[0x147]==0x13){cartridgetype="MBC3+RAM+BATTERY";}

	// read ROM Size
	uint16_t banks;
	if(buf[0x148]==0x00){banks=0;}
	if(buf[0x148]==0x01){banks=4;}
	if(buf[0x148]==0x02){banks=8;}
	if(buf[0x148]==0x03){banks=16;}
	if(buf[0x148]==0x04){banks=32;}
	if(buf[0x148]==0x05){banks=64;}
	if(buf[0x148]==0x06){banks=128;}
	if(buf[0x148]==0x07){banks=256;}
	if(buf[0x148]==0x08){banks=512;}

	// read RAM Size
	uint8_t ramsize;
	if(buf[0x149]==0x00){ramsize=0;}
	if(buf[0x149]==0x01){ramsize=2;}
	if(buf[0x149]==0x02){ramsize=8;}
	if(buf[0x149]==0x03){ramsize=32;}
	if(buf[0x149]==0x04){ramsize=128;}
	if(buf[0x149]==0x05){ramsize=64;}
}

int readfff(uint8_t* buffer, char* name)
{
    int err;
    FILE* cartridge = fopen(name, "r");
    if(!cartridge) {fprintf(stderr, "%s failed: fopen returned NULL\n", __func__); return EXIT_FAILURE;}
    err = fseek(cartridge, 0, SEEK_END);
    if(err == -1) {fprintf(stderr, "%s failed: fseek returned -1\n", __func__); return EXIT_FAILURE;}
    long cartridge_size = ftell(cartridge);
    if(cartridge_size == -1) {fprintf(stderr, "%s failed: ftell returned -1\n", __func__); return EXIT_FAILURE;}
    
    // WIP: this only takes 32kiB = 2^15 Bytes Cartridges so far. 
    if(cartridge_size != 32768) {fprintf(stderr, "%s failed: Cartridge is not sized 32kiB\n", __func__); return EXIT_FAILURE;}
    err = fseek(cartridge, 0, SEEK_SET);
    if(err == -1) {fprintf(stderr, "%s failed: fseek returned -1\n", __func__); return EXIT_FAILURE;}
    err = fread(buffer, 1, 32768, cartridge);
    if(err != 32768) {fprintf(stderr, "%s failed: fread could not complete - only %i bytes copied\n", __func__, err); return EXIT_FAILURE;}

    fclose(cartridge);

    return EXIT_SUCCESS;
}

void create_coredump(uint8_t* MEM, uint32_t length)
{
	FILE* coredump;
	coredump = fopen("coredump.txt","w");
	//write register
	fprintf(coredump, "%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,",A,F,B,C,D,E,H,L,PC,SP);
	//write memory
	for(uint32_t i=0; i<length ;i++)
	{
		fprintf(coredump, "%u,", MEM[i]);
	}
	fclose(coredump);
}


void reset_coredump(uint8_t* MEM, uint32_t length)
{
	FILE* coredump;
	coredump = fopen("coredump.txt","r");
	uint8_t* buf = malloc(sizeof(uint8_t)*5);
	int comma = 0; // boolean if comma has been read
	// reset register
	CHAR_TO_INT8(A);
	CHAR_TO_INT8(F);
	CHAR_TO_INT8(B);
	CHAR_TO_INT8(C);
	CHAR_TO_INT8(D);
	CHAR_TO_INT8(E);
	CHAR_TO_INT8(H);
	CHAR_TO_INT8(L);
	CHAR_TO_INT16(PC);
	CHAR_TO_INT16(SP);
	
	// reset memory
	for(uint32_t i = 0; i<length; i++)
	{
		CHAR_TO_INT8(MEM[i]);
	}
	printf("%i\n",MEM[0]);
	

	fclose(coredump);
}

