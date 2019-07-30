#include "main.h"

int main(int argc, char** argv)
{
    int err;

    PC = 0;

    setvbuf(stdout, NULL, _IONBF, 0);

    MEM = malloc(sizeof(uint8_t) * 65536);
    if(!MEM)
    {
        fprintf(stderr, "ERROR: could not allocate memory!\n");
        return EXIT_FAILURE;
    }
    memset(MEM, 0, sizeof(uint8_t) * 65536);

    // ROM into Memory (Bank 0 and Bank 1)
    err = readfff(MEM, "Tetris.gb");
    if(err == EXIT_FAILURE){return EXIT_FAILURE;}

    read_header(MEM);

    // create new BankSwitchingScheme for Boot
    BANKS* bootrom = malloc(sizeof(BANKS));
    if(!bootrom)
    {
        ERROR("ALLOCATING MEMORY FAILED");
        exit(EXIT_FAILURE);
    }
    bootrom->length = 256u;
    bootrom->number = 0x2;
    bootrom->start_addr = 0x0;
    bootrom->active = 1;
    bootrom->BANK_ARRAY = malloc(sizeof(uint8_t*) * bootrom->number);
    bootrom->BANK_ARRAY[0] = malloc(256);
    if(!bootrom->BANK_ARRAY[0])
    {
        ERROR("ALLOCATING MEMORY FAILED");
        exit(EXIT_FAILURE);
    }
    // copy from Bootromfile
    FILE* bootromfile = fopen("DMG_ROM.bin", "r");
    err = (int) fread(bootrom->BANK_ARRAY[0], 1, 256, bootromfile);
    if(err != 256)
    {
        ERROR("COULD NOT READ BOOTROM");
        exit(EXIT_FAILURE);
    }
    fclose(bootromfile);
    // switch banks: this copies bytes 0-256 to bootrom.1 and copies the bootrom in bootrom.1 to the RAM
    switch_banks(bootrom, 0);

    // create coredump folder, if not already existent
    struct stat st = {0};
    if(stat("./coredumps", &st) == -1)
    {
        mkdir("./coredumps", 0777);
    }

    // TEST
//    FILE *coredump = fopen("Tetris.dump", "r");
//    fread(MEM, 1, 65536, coredump);
//    fclose(coredump);
//    LY = 0;
    // background_tiles();
    // /Test

    struct timespec t0;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    int64_t cpu_cycle = 0;
    int64_t ppu_cycle = 0;
    int64_t current_line_cycles = 0;
    uint32_t nanosecs;
    display_init(WIDTH, HEIGHT, 6);
    // todo: fix invalid writes
    char* title = malloc(16 + strlen(GAME_NAME) + 1);
    strcpy(title, "Working Title - ");
    strcpy(title + 16, GAME_NAME);
    display_set_window_title(title);
    LOG_OUTPUT = fopen("log.log", "w");
    SDL_Event close_event;

    loop:

    if(ppu_cycle > cpu_cycle)     // CPU's turn
    {
        // BOOTROM MAPPING
        switch_banks(bootrom, MEM[0xFF50]);

        // todo: after opcodes are implemented, change this
        opcode = MEM[PC];

        fprintf(LOG_OUTPUT, "%x", opcode);
        if(opcode == 0xCB) fprintf(LOG_OUTPUT, " : %x", MEM[PC + 1]);
        fprintf(LOG_OUTPUT, " - %i\n", OPCODE_LENGTH[opcode]);
        fflush(LOG_OUTPUT);

        exec_opcode[opcode]();
        PC += OPCODE_LENGTH[opcode];
        cpu_cycle += CYCLE_LENGTH[opcode];

    }
    else    // PPU's turn
    {
        if((ppu_cycle % 456) < 80)
        {
            // OAM search

            memset(VISIBLE_SPRITE_ARRAY, 0, 10);
            t8[0] = 0; // visible_sprite_array index
            for(int i = 0; i < 40; i++)
            {
                t32[2] = SPRITE_Y_COORDINATE(i);
                t32[3] = LY;
                t32[4] = LY + 8;
                if(SPRITE_Y_COORDINATE(i) > LY && SPRITE_Y_COORDINATE(i) <= LY + 8)
                {
                    VISIBLE_SPRITE_ARRAY[t8[0]] = i; // ((uint32_t *) (MEM + 0xFE00))[i];
                    t8[0]++;
                    if(t8[0] == 10)
                    {
                        fprintf(stderr, "help");
                        break;
                    }
                }
            }

            current_line_cycles = 80;
            ppu_cycle += 80;
            goto loop;
        }


        if(!LX)
        {
            t32[0] = (uint32_t) (16 * MEM[0x9800 + (LX / 8) + (LY / 8) * 32]);
            t8p = (void*) MEM;
            t8p += 0x8000;
            t8p += t32[0];
            t8p += 2 * (LY % 8);
            for(uint8_t mask = 0x80; mask != 0; mask >>= 1u)
            {
                (((uint16_t*) (&fifo))[1]) |= (uint16_t) (t8p[1] & mask);
                (((uint16_t*) (&fifo))[1]) <<= 1u;
                (((uint16_t*) (&fifo))[1]) |= (uint16_t) (t8p[0] & mask);
            }
        }
        if(!(LX % 8))
        {
            t32[0] = (uint32_t) (16 * MEM[0x9800 + (LX / 8) + 1 + (LY / 8) * 32]);
            t8p = (void*) MEM;
            // todo: #6
            t8p += 0x8000;
            t8p += t32[0];
            t8p += 2 * (LY % 8);
            for(uint8_t mask = 0x80; mask != 0; mask >>= 1u)
            {
                (((uint16_t*) (&fifo))[0]) |= (uint16_t) (t8p[1] & mask);
                (((uint16_t*) (&fifo))[0]) <<= 1u;
                (((uint16_t*) (&fifo))[0]) |= (uint16_t) (t8p[0] & mask);
            }
        }

        // check for Sprites and Window
        if(LY - SCY >= 0 && LY - SCY < HEIGHT && (int32_t) LX - SCX >= 0 && LX - SCX < WIDTH)
        {
            for(int i = 0; i < 10; i++)
            {
                if(SPRITE_X_COORDINATE(VISIBLE_SPRITE_ARRAY[i]) == LX + 8)
                {
                    // load CHR code
                    t8[0] = SPRITE_CHR_CODE(VISIBLE_SPRITE_ARRAY[i]);
                    t8[0] *= 0x10;
                    // load 2pixelBytes
                    t8p = (void*) MEM;
                    // todo: #6
                    t8p += 0x8800;
                    t8p += t8[0];
                    t8p += 2 * (8 + LY - SPRITE_Y_COORDINATE(VISIBLE_SPRITE_ARRAY[i]));
                    // todo: #23: pixel mixing
                    // here we just copy the sprite in there
                    for(uint8_t mask = 0x80; mask != 0; mask >>= 1u)
                    {
                        (((uint16_t*) (&fifo))[0]) |= (uint16_t) (t8p[1] & mask);
                        (((uint16_t*) (&fifo))[0]) <<= 1u;
                        (((uint16_t*) (&fifo))[0]) |= (uint16_t) (t8p[0] & mask);
                    }
                }
            }
            OUTPUT_ARRAY[WIDTH * (LY - SCY) + (LX - SCX)] = (0xC0000000 & fifo) >> 30u;
        }
        LX++;
        fifo <<= 2u;
        ppu_cycle++;
        current_line_cycles++;

        if(LX == WIDTH)
        {
            LX = 0;
            LY += 1;
            fifo = 0;
            ppu_cycle += (51 + 43 + 20) * 4 - current_line_cycles;
            current_line_cycles = 0;
            if(LY == HEIGHT)
            {
                LY = 0;
                ppu_cycle = NTH_CYCLE; // build check if this is correct
            }
        }
    }

    if(ppu_cycle >= NTH_CYCLE)
    {
        ppu_cycle -= NTH_CYCLE;
        cpu_cycle -= NTH_CYCLE;

        for(int i = 0; i < WIDTH * HEIGHT; ++i)
        {
            OUTPUT_ARRAY[i + 0] = DEFAULT_PALETTE[OUTPUT_ARRAY[i + 0]];
        }

        display_draw(OUTPUT_ARRAY);

        while(SDL_PollEvent(&close_event))
        {
            if(close_event.type == SDL_QUIT)
            {
                goto end;
            }
        }

        nanosecs = cycle_duration;
        nanosecs += t0.tv_nsec;
        if(unlikely(nanosecs > 999999999))
        {
            nanosecs -= 1000000000;
            t0.tv_sec++;
        }
        t0.tv_nsec = nanosecs;
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t0, NULL);
    }

    goto loop;

    end:
    free(MEM);
    fclose(LOG_OUTPUT);
    free(GAME_NAME);
    free(title);

    return EXIT_SUCCESS;
}

void print_mem(uint16_t low, uint16_t high, char mode)
{
    int n = high - low;
    if(n <= 0)
    {
        printf("invalid range\n");
    }

    // mode d for decimal output
    if(mode == 'd')
    {
        for(int i = 0; i < n; i++)
        {
            printf("%u ", MEM[low + i]);
            if(i % 8 == 7){printf("\n");}
        }
    }
    // mode h for hexadecimal output
    if(mode == 'h')
    {
        for(int i = 0; i < n; i++)
        {
            printf("%02x%s", MEM[i], (i + 1) % 8 ? " " : ((i + 1) % n ? "\n" : "\n\n"));
        }
    }
    // mode b for binary output
    if(mode == 'b')
    {
        uint8_t* buf = malloc(sizeof(uint8_t) * 8);
        for(int i = 0; i < n; i++)
        {
            buf[0] = (uint8_t) (MEM[low + i] & 1u ? 1u : 0u);
            buf[1] = (uint8_t) (MEM[low + i] & 2u ? 1u : 0u);
            buf[2] = (uint8_t) (MEM[low + i] & 4u ? 1u : 0u);
            buf[3] = (uint8_t) (MEM[low + i] & 8u ? 1u : 0u);
            buf[4] = (uint8_t) (MEM[low + i] & 16u ? 1u : 0u);
            buf[5] = (uint8_t) (MEM[low + i] & 32u ? 1u : 0u);
            buf[6] = (uint8_t) (MEM[low + i] & 64u ? 1u : 0u);
            buf[7] = (uint8_t) (MEM[low + i] & 128u ? 1u : 0u);
            for(int j = 0; j < 8; j++)
            {
                printf("%u ", buf[j]);
            }
            printf(" ");
            if(i % 8 == 7){printf("\n");}
            free(buf);
        }
    }
}

void read_header(const uint8_t* buf)
{
    // read GAME_NAME
    GAME_NAME = malloc(17 * sizeof(char));
    int i = 0;
    for(; i < 16 && buf[0x134 + i] != 0x00; i++)
    {
        GAME_NAME[i] = (char) buf[0x134 + i];
    }
    GAME_NAME[i] = '\0';

    //read cartridgetype
    char* cartridgetype = "unreadable";
    if(buf[0x147] == 0x00){cartridgetype = "ROM ONLY";}
    if(buf[0x147] == 0x01){cartridgetype = "MBC1";}
    if(buf[0x147] == 0x02){cartridgetype = "MBC1+RAM";}
    if(buf[0x147] == 0x03){cartridgetype = "MBC1+RAM+BATTERY";}
    if(buf[0x147] == 0x05){cartridgetype = "MBC2";}
    if(buf[0x147] == 0x05){cartridgetype = "MBC2+BATTERY";}
    if(buf[0x147] == 0x08){cartridgetype = "ROM+RAM";}
    if(buf[0x147] == 0x09){cartridgetype = "ROM+RAM+BATTERY";}
    if(buf[0x147] == 0x0B){cartridgetype = "MMM01";}
    if(buf[0x147] == 0x0C){cartridgetype = "MMM01+RAM";}
    if(buf[0x147] == 0x0D){cartridgetype = "MMM01+RAM+BATTERY";}
    if(buf[0x147] == 0x11){cartridgetype = "MBC3";}
    if(buf[0x147] == 0x12){cartridgetype = "MBC3+RAM";}
    if(buf[0x147] == 0x13){cartridgetype = "MBC3+RAM+BATTERY";}

    // read ROM Size
    uint16_t banks = 0;
    if(buf[0x148] == 0x00){banks = 0;}
    if(buf[0x148] == 0x01){banks = 4;}
    if(buf[0x148] == 0x02){banks = 8;}
    if(buf[0x148] == 0x03){banks = 16;}
    if(buf[0x148] == 0x04){banks = 32;}
    if(buf[0x148] == 0x05){banks = 64;}
    if(buf[0x148] == 0x06){banks = 128;}
    if(buf[0x148] == 0x07){banks = 256;}
    if(buf[0x148] == 0x08){banks = 512;}

    // read RAM Size
    uint8_t ramsize = 0;
    if(buf[0x149] == 0x00){ramsize = 0;}
    if(buf[0x149] == 0x01){ramsize = 2;}
    if(buf[0x149] == 0x02){ramsize = 8;}
    if(buf[0x149] == 0x03){ramsize = 32;}
    if(buf[0x149] == 0x04){ramsize = 128;}
    if(buf[0x149] == 0x05){ramsize = 64;}

    printf("Name: %s\nCartridgetype: %s\nBanks:%i\nRAM Size:%i\n", GAME_NAME, cartridgetype, banks, ramsize);
}

int readfff(uint8_t* buffer, const char* filename)
{
    int err;
    FILE* cartridge = fopen(filename, "r");
    if(!cartridge)
    {
        fprintf(stderr, "%s failed: fopen returned NULL\n", __func__);
        return EXIT_FAILURE;
    }
    err = fseek(cartridge, 0, SEEK_END);
    if(err == -1)
    {
        fprintf(stderr, "%s failed: fseek returned -1\n", __func__);
        return EXIT_FAILURE;
    }
    long cartridge_size = ftell(cartridge);
    if(cartridge_size == -1)
    {
        fprintf(stderr, "%s failed: ftell returned -1\n", __func__);
        return EXIT_FAILURE;
    }

    // WIP: this only takes 32kiB = 2^15 Bytes Cartridges so far. 
    if(cartridge_size != 32768)
    {
        fprintf(stderr, "%s failed: Cartridge is not sized 32kiB\n", __func__);
        return EXIT_FAILURE;
    }
    err = fseek(cartridge, 0, SEEK_SET);
    if(err == -1)
    {
        fprintf(stderr, "%s failed: fseek returned -1\n", __func__);
        return EXIT_FAILURE;
    }
    err = (int) fread(buffer, 1, 32768, cartridge);
    if(err != 32768)
    {
        fprintf(stderr, "%s failed: fread could not complete - only %i bytes copied\n", __func__, err);
        return EXIT_FAILURE;
    }

    fclose(cartridge);

    return EXIT_SUCCESS;
}

void create_coredump(uint32_t length, uint16_t coredumpnum)
{
    FILE* coredump;
    char* path = malloc(sizeof(char) * 64);
    sprintf(path, "./coredumps/coredump%u.dmp", coredumpnum);
    coredump = fopen(path, "w");

    fwrite(reg_ptr, 2, 6, coredump);
    fwrite(MEM, 1, length, coredump);

    fclose(coredump);
    free(path);
}


void reset_coredump(uint32_t length, uint16_t coredumpnum)
{
    FILE* coredump;
    char* path = malloc(sizeof(char) * 64);
    sprintf(path, "./coredumps/coredump%u.dmp", coredumpnum);
    coredump = fopen(path, "r");

    fread(reg_ptr, 2, 6, coredump);
    fread(MEM, 1, length, coredump);

    fclose(coredump);
    free(path);
}

void remove_all_coredumps(uint16_t coredumpnum)
{
    for(uint16_t i = 0; i < coredumpnum + 1; i++)
    {
        char* name = malloc(sizeof(char) * 64);
        sprintf(name, "./coredumps/coredump%u.dmp", i);
        remove(name);
        free(name);
    }
}

void convert_tile(uint8_t* input_ptr, uint32_t* output_ptr)
{
    for(int i = 0; i < 8; i++)
    {
        convert_line(input_ptr + i * 2, output_ptr + BG_DBG_WINDOW_WIDTH * i);
    }

}

void convert_line(const uint8_t* input_ptr, uint32_t* output_ptr)
{
    for(int i = 0; i < 8; i++)
    {
        // note: since we have unsigned integers, the shift is logical
        output_ptr[i] = colour[input_ptr[1] >> (7 - i) & 0x1][input_ptr[0] >> (7 - i) & 0x1];
    }
}

void background_tiles()
{
    uint32_t* pixel = malloc(BG_DBG_WINDOW_HEIGHT * BG_DBG_WINDOW_WIDTH * sizeof(uint32_t));
    size_t i = 0;

    for(i = 0; i < BG_DBG_WINDOW_WIDTH * BG_DBG_WINDOW_HEIGHT; ++i)
    {
        pixel[i + 0] = WHITE;
    }

    for(i = 0; i < 24; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            convert_tile((MEM + 0x8000 + 16 * (i * 16 + j)), pixel + (j * 8 + i * 8 * 16 * 8));
        }
    }

    display_init(BG_DBG_WINDOW_WIDTH, BG_DBG_WINDOW_HEIGHT, 6);
    display_set_window_title("Working Title - Tile Viewer");
    display_draw(pixel);
    free(pixel);
}

void print_regs(void)
{
// 18 characters per line

    printf("##################\n");
    printf("A: 0x%02"PRIx8"    F: 0x%02"PRIx8"\n", A, F);
    printf("B: 0x%02"PRIx8"    C: 0x%02"PRIx8"\n", B, C);
    printf("D: 0x%02"PRIx8"    E: 0x%02"PRIx8"\n", D, E);
    printf("H: 0x%02"PRIx8"    L: 0x%02"PRIx8"\n", H, L);
    printf("     SP: 0x%02"PRIx16"\n", SP);
    printf("     PC: 0x%02"PRIx16"\n", PC);
    printf("##################\n");
}

int switch_banks(BANKS* banks, uint8_t target_bank)
{
    // check for NULL
    if(banks == NULL)
    {
        ERROR("BANK IS NULL");
        exit(EXIT_FAILURE);
    }

    // in this case nothing to be done
    if(target_bank == banks->active)
    {
        return 1;
    }

    // check if target bank is in bounds
    if(target_bank > banks->number)
    {
        char* e = malloc(64);
        snprintf(e, 63, "TARGET BANK OUT OF BOUNDS! (TARGET = %u; NUMBER OF BANKS = %u)", target_bank, banks->number);
        ERROR(e);
        free(e);
        // exit(EXIT_FAILURE);
        return -1;
    }

    // if bank has not been initialised, malloc
    if(banks->BANK_ARRAY[banks->active] == NULL)
    {
        banks->BANK_ARRAY[banks->active] = malloc(sizeof(uint8_t) * banks->length);
        if(banks->BANK_ARRAY[banks->active] == NULL)
        {
            ERROR("COULD NOT ALLOCATE MEMORY!");
            exit(EXIT_FAILURE);
        }
    }

    // copy currently active bank into the backup
    memcpy(banks->BANK_ARRAY[banks->active], MEM + banks->start_addr, banks->length);

    // check if target bank is NULL
    if(banks->BANK_ARRAY[target_bank] == NULL)
    {
        banks->BANK_ARRAY[target_bank] = malloc(sizeof(uint8_t) * banks->length);
        if(banks->BANK_ARRAY[target_bank] == NULL)
        {
            ERROR("COULD NOT ALLOCATE MEMORY!");
            exit(EXIT_FAILURE);
        }
        // set the whole bank to NULLBYTES
        memset(banks->BANK_ARRAY[target_bank], '\0', banks->length);
    }

    // copy target bank into memory
    memcpy(MEM + banks->start_addr, banks->BANK_ARRAY[target_bank], banks->length);

}

uint32_t DEFAULT_PALETTE[4] = {WHITE, LIGHT_GREY, DARK_GREY, BLACK};
uint32_t colour[2][2] = {{WHITE, LIGHT_GREY},
                         {DARK_GREY, BLACK}};

void (* exec_opcode[0x100])(void) =
        {OP_NOP, OP_LD_BC_D16, OP_LD_PBC_A, OP_INC_BC, OP_INC_B, OP_INC_B, OP_LD_B_D8, OP_RLCA,
         OP_LD_A16_SP, OP_ADD_HL_BC, OP_LD_A_PBC, OP_DEC_BC, OP_INC_C, OP_DEC_C, OP_LD_C_D8, OP_RRCA,
         OP_STOP, OP_LD_DE_D16, OP_LD_PDE_A, OP_INC_DE, OP_INC_D, OP_DEC_D, OP_LD_D_D8, OP_RLA,
         OP_JR_R8, OP_ADD_HL_DE, OP_LD_A_PDE, OP_DEC_DE, OP_INC_E, OP_DEC_E, OP_LD_E_D8, OP_RRA,
         OP_JR_NZ_R8, OP_LD_HL_D16, OP_LD_PHLI_A, OP_INC_HL, OP_INC_H, OP_DEC_H, OP_LD_H_D8, OP_DAA,
         OP_JR_Z_R8, OP_ADD_HL_HL, OP_LD_A_PHLI, OP_DEC_HL, OP_INC_L, OP_DEC_L, OP_LD_L_D8, OP_CPL,
         OP_JR_NC_R8, OP_LD_SP_D16, OP_LD_PHLD_A, OP_INC_SP, OP_INC_PHL, OP_DEC_PHL, OP_LD_PHL_D8, OP_LD_PHL_D8,
         OP_JR_C_R8, OP_ADD_HL_SP, OP_LD_A_PHLD, OP_DEC_SP, OP_INC_A, OP_DEC_A, OP_LD_A_D8, OP_CCF,
         OP_LD_B_B, OP_LD_B_C, OP_LD_B_D, OP_LD_B_E, OP_LD_B_H, OP_LD_B_L, OP_LD_B_PHL, OP_LD_B_A,
         OP_LD_C_B, OP_LD_C_C, OP_LD_C_D, OP_LD_C_E, OP_LD_C_H, OP_LD_C_L, OP_LD_C_PHL, OP_LD_C_A,
         OP_LD_D_B, OP_LD_D_C, OP_LD_D_D, OP_LD_D_E, OP_LD_D_H, OP_LD_D_L, OP_LD_D_PHL, OP_LD_D_A,
         OP_LD_E_B, OP_LD_E_C, OP_LD_E_D, OP_LD_E_E, OP_LD_E_H, OP_LD_E_L, OP_LD_E_PHL, OP_LD_E_A,
         OP_LD_H_B, OP_LD_H_C, OP_LD_H_D, OP_LD_H_E, OP_LD_H_H, OP_LD_H_L, OP_LD_H_PHL, OP_LD_H_A,
         OP_LD_L_B, OP_LD_L_C, OP_LD_L_D, OP_LD_L_E, OP_LD_L_H, OP_LD_L_L, OP_LD_L_PHL, OP_LD_L_A,
         OP_LD_PHL_B, OP_LD_PHL_C, OP_LD_PHL_D, OP_LD_PHL_E, OP_LD_PHL_H, OP_LD_PHL_L, OP_HALT, OP_LD_PHL_A,
         OP_LD_A_B, OP_LD_A_C, OP_LD_A_D, OP_LD_A_E, OP_LD_A_H, OP_LD_A_L, OP_LD_A_PHL, OP_LD_A_A,
         OP_ADD_A_B, OP_ADD_A_C, OP_ADD_A_D, OP_ADD_A_E, OP_ADD_A_H, OP_ADD_A_L, OP_ADD_A_PHL, OP_ADD_A_A,
         OP_ADC_A_B, OP_ADC_A_C, OP_ADC_A_D, OP_ADC_A_E, OP_ADC_A_H, OP_ADC_A_L, OP_ADC_A_PHL, OP_ADC_A_A,
         OP_SUB_A_B, OP_SUB_A_C, OP_SUB_A_D, OP_SUB_A_E, OP_SUB_A_H, OP_SUB_A_L, OP_SUB_A_PHL, OP_SUB_A_A,
         OP_SBC_A_B, OP_SBC_A_C, OP_SBC_A_D, OP_SBC_A_E, OP_SBC_A_H, OP_SBC_A_L, OP_SBC_A_PHL, OP_SBC_A_A,
         OP_AND_B, OP_AND_C, OP_AND_D, OP_AND_E, OP_AND_H, OP_AND_L, OP_AND_PHL, OP_AND_A,
         OP_XOR_B, OP_XOR_C, OP_XOR_D, OP_XOR_E, OP_XOR_H, OP_XOR_L, OP_XOR_PHL, OP_XOR_A,
         OP_OR_B, OP_OR_C, OP_OR_D, OP_OR_E, OP_OR_H, OP_OR_L, OP_OR_PHL, OP_OR_A,
         OP_CP_B, OP_CP_C, OP_CP_D, OP_CP_E, OP_CP_H, OP_CP_L, OP_CP_PHL, OP_CP_A,
         OP_RET_NZ, OP_POP_BC, OP_JP_NZ_A16, OP_JP_A16, OP_CALL_NZ_A16, OP_PUSH_BC, OP_ADD_A_D8, OP_RST_00,
         OP_RET_Z, OP_RET, OP_JP_Z_A16, OP_CB, OP_CALL_Z_A16, OP_CALL_A16, OP_ADC_A_D8, OP_RST_08,
         OP_RET_NC, OP_POP_DE, OP_JP_NC_A16, OP_ERROR_D3, OP_CALL_NC_A16, OP_PUSH_DE, OP_SUB_A_D8, OP_RST_10,
         OP_RET_C, OP_RETI, OP_JP_C_A16, OP_ERROR_DB, OP_CALL_C_A16, OP_ERROR_DD, OP_SBC_A_D8, OP_RST_18,
         OP_LDH_PA8_A, OP_POP_HL, OP_LD_OC_A, OP_ERROR_E3, OP_ERROR_E4, OP_PUSH_HL, OP_AND_D8, OP_RST_20,
         OP_ADD_SP_R8, OP_JP_PHL, OP_LD_A16_A, OP_ERROR_EB, OP_ERROR_EC, OP_ERROR_ED, OP_XOR_D8, OP_RST_28,
         OP_LDH_A_A8, OP_POP_AF, OP_LD_A_OC, OP_DI, OP_ERROR_F4, OP_PUSH_AF, OP_OR_D8, OP_RST_30,
         OP_LD_HL_SP_R8, OP_LD_SP_HL, OP_LD_A_A16, OP_EI, OP_ERROR_FC, OP_ERROR_FD, OP_CP_D8, OP_RST_38};

void (* exec_cb[0x100])(void) =
        {OP_RLC_B, OP_RLC_C, OP_RLC_D, OP_RLC_E, OP_RLC_H, OP_RLC_L, OP_RLC_PHL, OP_RLC_A,
         OP_RRC_B, OP_RRC_C, OP_RRC_D, OP_RRC_E, OP_RRC_H, OP_RRC_L, OP_RRC_PHL, OP_RRC_A,
         OP_RL_B, OP_RL_C, OP_RL_D, OP_RL_E, OP_RL_H, OP_RL_L, OP_RL_PHL, OP_RL_A,
         OP_RR_B, OP_RR_C, OP_RR_D, OP_RR_E, OP_RR_H, OP_RR_L, OP_RR_PHL, OP_RR_A,
         OP_SLA_B, OP_SLA_C, OP_SLA_D, OP_SLA_E, OP_SLA_H, OP_SLA_L, OP_SLA_PHL, OP_SLA_A,
         OP_SRA_B, OP_SRA_C, OP_SRA_D, OP_SRA_E, OP_SRA_H, OP_SRA_L, OP_SRA_PHL, OP_SRA_A,
         OP_SWAP_B, OP_SWAP_C, OP_SWAP_D, OP_SWAP_E, OP_SWAP_H, OP_SWAP_L, OP_SWAP_PHL, OP_SWAP_A,
         OP_SRL_B, OP_SRL_C, OP_SRL_D, OP_SRL_E, OP_SRL_H, OP_SRL_L, OP_SRL_PHL, OP_SRL_A,
         OP_BIT_0_B, OP_BIT_0_C, OP_BIT_0_D, OP_BIT_0_E, OP_BIT_0_H, OP_BIT_0_L, OP_BIT_0_PHL, OP_BIT_0_A,
         OP_BIT_1_B, OP_BIT_1_C, OP_BIT_1_D, OP_BIT_1_E, OP_BIT_1_H, OP_BIT_1_L, OP_BIT_1_PHL, OP_BIT_1_A,
         OP_BIT_2_B, OP_BIT_2_C, OP_BIT_2_D, OP_BIT_2_E, OP_BIT_2_H, OP_BIT_2_L, OP_BIT_2_PHL, OP_BIT_2_A,
         OP_BIT_3_B, OP_BIT_3_C, OP_BIT_3_D, OP_BIT_3_E, OP_BIT_3_H, OP_BIT_3_L, OP_BIT_3_PHL, OP_BIT_3_A,
         OP_BIT_4_B, OP_BIT_4_C, OP_BIT_4_D, OP_BIT_4_E, OP_BIT_4_H, OP_BIT_4_L, OP_BIT_4_PHL, OP_BIT_4_A,
         OP_BIT_5_B, OP_BIT_5_C, OP_BIT_5_D, OP_BIT_5_E, OP_BIT_5_H, OP_BIT_5_L, OP_BIT_5_PHL, OP_BIT_5_A,
         OP_BIT_6_B, OP_BIT_6_C, OP_BIT_6_D, OP_BIT_6_E, OP_BIT_6_H, OP_BIT_6_L, OP_BIT_6_PHL, OP_BIT_6_A,
         OP_BIT_7_B, OP_BIT_7_C, OP_BIT_7_D, OP_BIT_7_E, OP_BIT_7_H, OP_BIT_7_L, OP_BIT_7_PHL, OP_BIT_7_A,
         OP_RES_0_B, OP_RES_0_C, OP_RES_0_D, OP_RES_0_E, OP_RES_0_H, OP_RES_0_L, OP_RES_0_PHL, OP_RES_0_A,
         OP_RES_1_B, OP_RES_1_C, OP_RES_1_D, OP_RES_1_E, OP_RES_1_H, OP_RES_1_L, OP_RES_1_PHL, OP_RES_1_A,
         OP_RES_2_B, OP_RES_2_C, OP_RES_2_D, OP_RES_2_E, OP_RES_2_H, OP_RES_2_L, OP_RES_2_PHL, OP_RES_2_A,
         OP_RES_3_B, OP_RES_3_C, OP_RES_3_D, OP_RES_3_E, OP_RES_3_H, OP_RES_3_L, OP_RES_3_PHL, OP_RES_3_A,
         OP_RES_4_B, OP_RES_4_C, OP_RES_4_D, OP_RES_4_E, OP_RES_4_H, OP_RES_4_L, OP_RES_4_PHL, OP_RES_4_A,
         OP_RES_5_B, OP_RES_5_C, OP_RES_5_D, OP_RES_5_E, OP_RES_5_H, OP_RES_5_L, OP_RES_5_PHL, OP_RES_5_A,
         OP_RES_6_B, OP_RES_6_C, OP_RES_6_D, OP_RES_6_E, OP_RES_6_H, OP_RES_6_L, OP_RES_6_PHL, OP_RES_6_A,
         OP_RES_7_B, OP_RES_7_C, OP_RES_7_D, OP_RES_7_E, OP_RES_7_H, OP_RES_7_L, OP_RES_7_PHL, OP_RES_7_A,
         OP_SET_0_B, OP_SET_0_C, OP_SET_0_D, OP_SET_0_E, OP_SET_0_H, OP_SET_0_L, OP_SET_0_PHL, OP_SET_0_A,
         OP_SET_1_B, OP_SET_1_C, OP_SET_1_D, OP_SET_1_E, OP_SET_1_H, OP_SET_1_L, OP_SET_1_PHL, OP_SET_1_A,
         OP_SET_2_B, OP_SET_2_C, OP_SET_2_D, OP_SET_2_E, OP_SET_2_H, OP_SET_2_L, OP_SET_2_PHL, OP_SET_2_A,
         OP_SET_3_B, OP_SET_3_C, OP_SET_3_D, OP_SET_3_E, OP_SET_3_H, OP_SET_3_L, OP_SET_3_PHL, OP_SET_3_A,
         OP_SET_4_B, OP_SET_4_C, OP_SET_4_D, OP_SET_4_E, OP_SET_4_H, OP_SET_4_L, OP_SET_4_PHL, OP_SET_4_A,
         OP_SET_5_B, OP_SET_5_C, OP_SET_5_D, OP_SET_5_E, OP_SET_5_H, OP_SET_5_L, OP_SET_5_PHL, OP_SET_5_A,
         OP_SET_6_B, OP_SET_6_C, OP_SET_6_D, OP_SET_6_E, OP_SET_6_H, OP_SET_6_L, OP_SET_6_PHL, OP_SET_6_A,
         OP_SET_7_B, OP_SET_7_C, OP_SET_7_D, OP_SET_7_E, OP_SET_7_H, OP_SET_7_L, OP_SET_7_PHL, OP_SET_7_A};

int OPCODE_LENGTH[0x100] =
        {
                1, 3, 1, 1, 1, 1, 2, 1, 3, 1, 1, 1, 1, 1, 2, 1,
                0, 3, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1,
                2, 3, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1,
                2, 3, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 3, 3, 3, 1, 2, 1, 1, 1, 3, 2, 3, 3, 2, 1,
                1, 1, 3, 0, 3, 1, 2, 1, 1, 1, 3, 0, 3, 0, 2, 1,
                2, 1, 1, 0, 0, 1, 2, 1, 2, 1, 3, 0, 0, 0, 2, 1,
                2, 1, 1, 1, 0, 1, 2, 1, 2, 1, 3, 1, 0, 0, 2, 1
        };

int CYCLE_LENGTH[0x100] =
        {
                1, 3, 2, 2, 1, 1, 2, 1, 5, 2, 2, 2, 1, 1, 2, 1,
                0, 3, 2, 2, 1, 1, 2, 1, 3, 2, 2, 2, 1, 1, 2, 1,
                2, 3, 2, 2, 1, 1, 2, 1, 2, 2, 2, 2, 1, 1, 2, 1,
                2, 3, 2, 2, 3, 3, 3, 1, 2, 2, 2, 2, 1, 1, 2, 1,
                1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1,
                1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1,
                1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1,
                2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1,
                1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1,
                1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1,
                1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1,
                1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1,
                2, 3, 3, 4, 3, 4, 2, 4, 2, 4, 3, 0, 3, 6, 2, 4,
                2, 3, 3, 0, 3, 4, 2, 4, 2, 4, 3, 0, 3, 0, 2, 4,
                3, 3, 2, 0, 0, 4, 2, 4, 4, 1, 4, 0, 0, 0, 2, 4,
                3, 3, 2, 1, 0, 4, 2, 4, 3, 2, 4, 1, 0, 0, 2, 4
        };