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

    struct timespec t0;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    uint32_t nanosecs;
    uint8_t opcode;

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
					// TODO prefix code here
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
					// code here
					break;

		case 0xe2:
					// code here
					break;

		case 0xe3:
					// code here
					break;

		case 0xe4:
					// code here
					break;

		case 0xe5:
					// code here
					break;

		case 0xe6:
					// code here
					break;

		case 0xe7:
					// code here
					break;

		case 0xe8:
					// code here
					break;

		case 0xe9:
					// code here
					break;

		case 0xea:
					// code here
					break;

		case 0xeb:
					// code here
					break;

		case 0xec:
					// code here
					break;

		case 0xed:
					// code here
					break;

		case 0xee:
					// code here
					break;

		case 0xef:
					// code here
					break;

		case 0xf0:
					// code here
					break;

		case 0xf1:
					// code here
					break;

		case 0xf2:
					// code here
					break;

		case 0xf3:
					// code here
					break;

		case 0xf4:
					// code here
					break;

		case 0xf5:
					// code here
					break;

		case 0xf6:
					// code here
					break;

		case 0xf7:
					// code here
					break;

		case 0xf8:
					// code here
					break;

		case 0xf9:
					// code here
					break;

		case 0xfa:
					// code here
					break;

		case 0xfb:
					// code here
					break;

		case 0xfc:
					// code here
					break;

		case 0xfd:
					// code here
					break;

		case 0xfe:
					// code here
					break;

		case 0xff:
					// code here
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