#include "display.h"

#include <stdint.h>
#include <stdlib.h>

#include "exception.hpp"

static size_t height = 0;
static size_t width = 0;
static size_t scale = 0;
static SDL_Window *window = nullptr;
static SDL_Surface *screen = nullptr;

void display_init(size_t native_width, size_t native_height, size_t window_scale)
{
  height = native_height;
  width = native_width;
  scale = window_scale;
  
  if(SDL_Init(SDL_INIT_VIDEO) < 0) { throw RuntimeError(SDL_GetError()); }

  atexit(SDL_Quit);

  uint32_t flags = 0;

  window = SDL_CreateWindow("DMG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width*scale, height*scale, flags | SDL_WINDOW_RESIZABLE);

  if(window == nullptr) { throw RuntimeError(SDL_GetError()); }

  screen = SDL_GetWindowSurface(window);

  if(screen == nullptr) { throw RuntimeError(SDL_GetError()); }
}

void display_set_window_title(const char* name)
{
  SDL_SetWindowTitle(window, name);
  SDL_UpdateWindowSurface(window);
}

void display_draw(const uint32_t * pixels)
{
  //     SDL_Surface* SDL_CreateRGBSurfaceFrom(void*  pixels,
  //                     int  width,
  //                     int  height,
  //                     int  depth,
  //                     int  pitch,
  //                     Uint32 Rmask,
  //                     Uint32 Gmask,
  //                     Uint32 Bmask,
  //                     Uint32 Amask)
  Uint32 Rmask = 0x000000FF;
  Uint32 Gmask = 0x0000FF00;
  Uint32 Bmask = 0x00FF0000;
  Uint32 Amask = 0xFF000000;
  SDL_Surface* native_surface = SDL_CreateRGBSurfaceFrom((void*)pixels, (int)width, (int)height, 4*8, 4*(int)width, Rmask, Gmask, Bmask, Amask);
  SDL_BlitScaled(native_surface, nullptr, screen, nullptr);
  SDL_UpdateWindowSurface(window);
}
