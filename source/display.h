#pragma once

#include <SDL2/SDL.h>

#define BLACK      0xFF2D1B00
#define DARK_GREY  0xFF1E606E
#define LIGHT_GREY 0xFF5AB9A8
#define WHITE      0xFFC4f0C2

#ifdef __cplusplus
extern "C"{
#endif
  void handle_events_async();
  void handle_events_async_stop();
  void display_init(size_t width, size_t height, size_t scale);
  void display_set_window_title(const char*);
  void display_draw(const uint32_t* pixels);
#ifdef __cplusplus
}
#endif
