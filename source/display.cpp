#include "display.h"

#include <cstdint>
#include <cstdlib>
#include <thread>

#include "sdl_io_handler.cpp"


extern "C"{

typedef struct {
  SDL_IO_Handler sdl_io_handler;
} SDL_IO_Handler_Wrapper;

static SDL_IO_Handler_Wrapper sdl_io_handler_wrapper;

void handle_events_async()
{
  sdl_io_handler_wrapper.sdl_io_handler.handle_SDL_events_async();
}

void handle_events_async_stop()
{
  sdl_io_handler_wrapper.sdl_io_handler.handle_SDL_events_async_stop();
}

int windows_active()
{
  return sdl_io_handler_wrapper.sdl_io_handler.windows_active();
}
  
void display_init(int index, size_t width, size_t height, size_t scale)
{
  sdl_io_handler_wrapper.sdl_io_handler.display_init(index, width, height, scale);
}

void display_set_window_title(int index, const char* title)
{
  sdl_io_handler_wrapper.sdl_io_handler.display_set_window_title(index, title);
}

void display_draw(int index, const uint32_t* pixels)
{
  sdl_io_handler_wrapper.sdl_io_handler.display_draw(index, pixels);
}

void display_destroy(int index)
{
  sdl_io_handler_wrapper.sdl_io_handler.display_destroy(index);
}

uint8_t get_input(int output)
{
  return sdl_io_handler_wrapper.sdl_io_handler.get_input(output);
}

}
