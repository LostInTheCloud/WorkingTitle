#include <stdio.h>
#include <stdint.h>

#include "display.h"

int main()
{
  size_t height = 144;
  size_t width = 160;
  uint32_t* pixel = malloc(height*width*sizeof(uint32_t));
  size_t i = 0;
  
  for (i = 0; i < height*width; ++i)
  {
    pixel[i+0] = WHITE;
  }
  
  // Hier male ich ein schwarzes N
  // Das N kennt ihr vielleicht vom booten
  for (i = 64; i <= 80; i++)
  {
    pixel[i*width + 32] = BLACK;
    pixel[i*width + 33] = BLACK;
    pixel[i*width + 34] = BLACK;
    pixel[i*width + 35] = BLACK;
    pixel[i*width + 42] = BLACK;
    pixel[i*width + 43] = BLACK;
    pixel[i*width + 44] = BLACK;
    pixel[i*width + 45] = BLACK;
  }
  for (i = 66; i <= 77; ++i)
  {
    pixel[i*width + 36 + 2*((i-66)/4)] = BLACK;
    pixel[i*width + 37 + 2*((i-66)/4)] = BLACK;
  }
  
  
  display_init(width,height,2);
  display_set_window_title("Working Title - Tile Viewer");
  display_draw(pixel);
  
  sleep(5);
  
  free(pixel);
  return 0;
}