#include "stuff.h"

int main(int argc, char **argv)
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

    // create coredump folder, if not already existent
    struct stat st = {0};
    if(stat("./coredumps", &st) == -1)
    {
        mkdir("./coredumps", 0777);
    }

    // TEST
    FILE *coredump = fopen("Tetris.dump", "r");
    fread(MEM, 1, 65536, coredump);
    fclose(coredump);
    LY = 0;
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
    char *title = malloc(16 + strlen(GAME_NAME) + 1);
    strcpy(title, "Working Title - ");
    strcpy(title + 16, GAME_NAME);
    display_set_window_title(title);
    LOG_OUTPUT = fopen("log.log", "w");
    SDL_Event close_event;

    int x = 0;

    loop:

    if(ppu_cycle>cpu_cycle)     // CPU's turn
    {
        // todo: after opcodes are implemented, change this
        //opcode = MEM[PC];
        opcode = 0;

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
            t8p = (void *) MEM;
            t8p += 0x8000;
            t8p += t32[0];
            t8p += 2 * (LY % 8);
            for(uint8_t mask = 0x80; mask != 0; mask >>= 1u)
            {
                (((uint16_t *) (&fifo))[1]) |= (uint16_t) (t8p[1] & mask);
                (((uint16_t *) (&fifo))[1]) <<= 1u;
                (((uint16_t *) (&fifo))[1]) |= (uint16_t) (t8p[0] & mask);
            }
        }
        if(!(LX % 8))
        {
            t32[0] = (uint32_t) (16 * MEM[0x9800 + (LX / 8) + 1 + (LY / 8) * 32]);
            t8p = (void *) MEM;
            // todo: #6
            t8p += 0x8000;
            t8p += t32[0];
            t8p += 2 * (LY % 8);
            for(uint8_t mask = 0x80; mask != 0; mask >>= 1u)
            {
                (((uint16_t *) (&fifo))[0]) |= (uint16_t) (t8p[1] & mask);
                (((uint16_t *) (&fifo))[0]) <<= 1u;
                (((uint16_t *) (&fifo))[0]) |= (uint16_t) (t8p[0] & mask);
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
                    t8p = (void *) MEM;
                    // todo: #6
                    t8p += 0x8800;
                    t8p += t8[0];
                    t8p += 2 * (8 + LY - SPRITE_Y_COORDINATE(VISIBLE_SPRITE_ARRAY[i]));
                    // todo: #23: pixel mixing
                    // here we just copy the sprite in there
                    for(uint8_t mask = 0x80; mask != 0; mask >>= 1u)
                    {
                        (((uint16_t *) (&fifo))[0]) |= (uint16_t) (t8p[1] & mask);
                        (((uint16_t *) (&fifo))[0]) <<= 1u;
                        (((uint16_t *) (&fifo))[0]) |= (uint16_t) (t8p[0] & mask);
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

        fprintf(stderr, ".");
        if(++x == 60)
        {
            fprintf(stderr, "\n");
            x = 0;
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
        uint8_t *buf = malloc(sizeof(uint8_t) * 8);
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

void read_header(const uint8_t *buf)
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
    char *cartridgetype = "unreadable";
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

int readfff(uint8_t *buffer, const char *filename)
{
    int err;
    FILE *cartridge = fopen(filename, "r");
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
    FILE *coredump;
    char *path = malloc(sizeof(char) * 64);
    sprintf(path, "./coredumps/coredump%u.dmp", coredumpnum);
    coredump = fopen(path, "w");

    fwrite(reg_ptr, 2, 6, coredump);
    fwrite(MEM, 1, length, coredump);

    fclose(coredump);
    free(path);
}


void reset_coredump(uint32_t length, uint16_t coredumpnum)
{
    FILE *coredump;
    char *path = malloc(sizeof(char) * 64);
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
        char *name = malloc(sizeof(char) * 64);
        sprintf(name, "./coredumps/coredump%u.dmp", i);
        remove(name);
        free(name);
    }
}

void convert_tile(uint8_t *input_ptr, uint32_t *output_ptr)
{
    for(int i = 0; i < 8; i++)
    {
        convert_line(input_ptr + i * 2, output_ptr + BG_DBG_WINDOW_WIDTH * i);
    }

}

void convert_line(const uint8_t *input_ptr, uint32_t *output_ptr)
{
    for(int i = 0; i < 8; i++)
    {
        // note: since we have unsigned integers, the shift is logical
        output_ptr[i] = colour[input_ptr[1] >> (7 - i) & 0x1][input_ptr[0] >> (7 - i) & 0x1];
    }
}

void background_tiles()
{
    uint32_t *pixel = malloc(BG_DBG_WINDOW_HEIGHT * BG_DBG_WINDOW_WIDTH * sizeof(uint32_t));
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
        fprintf(stderr, "BANKS IS NULL!\n");
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
        fprintf(stderr, "TARGET BANK OUT OF BOUNDS!\n");
        exit(EXIT_FAILURE);
    }

    // if bank has not been initialised, malloc
    if(banks->BANK_ARRAY[banks->active] == NULL)
    {
        banks->BANK_ARRAY[banks->active] = malloc(sizeof(uint8_t)*banks->length);
        if(banks->BANK_ARRAY[banks->active] == NULL)
        {
            fprintf(stderr, "COULD NOT ALLOCATE MEMORY!\n");
            exit(EXIT_FAILURE);
        }
    }

    // copy currently active bank into the backup
    memcpy(banks->BANK_ARRAY[banks->active], MEM+banks->start_addr, banks->length);

    // check if target bank is NULL
    if(banks->BANK_ARRAY[target_bank] == NULL)
    {
        banks->BANK_ARRAY[target_bank] = malloc(sizeof(uint8_t)*banks->length);
        if(banks->BANK_ARRAY[target_bank] == NULL)
        {
            fprintf(stderr, "COULD NOT ALLOCATE MEMORY!\n");
            exit(EXIT_FAILURE);
        }
        // set the whole bank to NULLBYTES
        memset(banks->BANK_ARRAY[target_bank], '\0', banks->length);
    }

    // copy target bank into memory
    memcpy(MEM+banks->start_addr, banks->BANK_ARRAY[target_bank], banks->length);

}