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
  
void display_init(size_t width, size_t height, size_t scale)
{
  sdl_io_handler_wrapper.sdl_io_handler.display_init(0, width, height, scale);
}

void display_set_window_title(const char* title)
{
  sdl_io_handler_wrapper.sdl_io_handler.display_set_window_title(0, title);
}

void display_draw(const uint32_t* pixels)
{
  sdl_io_handler_wrapper.sdl_io_handler.display_draw(0, pixels);
}

}
