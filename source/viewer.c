#include <stdio.h>
#include <stdint.h>

#include "display.h"

void convert_tile(uint8_t* input_ptr, uint32_t* output_ptr);
void convert_line(uint8_t* input_ptr, uint32_t* output_ptr);

int counter = 0;

uint32_t colour[2][2] = {{WHITE, LIGHT_GREY},{DARK_GREY, BLACK}};

size_t height = 128;
size_t width = 192;

int main( )
{
    uint32_t* pixel = malloc(height*width*sizeof(uint32_t));
    size_t i = 0;
  
    for (i = 0; i < height*width; ++i)
    {
        pixel[i+0] = WHITE;
    }

    uint8_t* MEM = malloc(sizeof(uint8_t) * 65536);
    if(!MEM)
    {
        fprintf(stderr, "ERROR: could not allocate memory!\n");
        return EXIT_FAILURE;
    }

    void* reg_ptr[12];

    uint8_t coredumpnum = 6;
    FILE* coredump;
	char* path = malloc(sizeof(char)*64);
	sprintf(path,"./coredumps/coredump%u.dmp",coredumpnum);
	coredump = fopen(path,"r");
    fread(reg_ptr, 2, 6, coredump);
    fread(MEM, 1, 65536, coredump);
    fclose(coredump);

    convert_tile((MEM+0x8000), pixel);

    display_init(width, height, 6);
    display_set_window_title("Working Title - Tile Viewer");
    display_draw(pixel);

    sleep(10);

    free(pixel);
    return 0;
}

void convert_tile(uint8_t* input_ptr, uint32_t* output_ptr)
{
    for(int i = 0; i < 8; i++)
    {
        convert_line(input_ptr+i*2, output_ptr+width*i);
    }

}

void convert_line(uint8_t* input_ptr, uint32_t* output_ptr)
{
    for(int i = 0; i < 8; i++)
    {
        // note: since we have unsigned integers, the shift is logical
        output_ptr[i] = colour[(input_ptr[1]>>(7-i))&0x1][(input_ptr[0]>>(7-i))&0x1];
    }
}