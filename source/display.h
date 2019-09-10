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
  int  windows_active();
  void display_init(int index, size_t width, size_t height, size_t scale);
  void display_set_window_title(int index, const char* title);
  void display_draw(int index, const uint32_t* pixels);
  void display_destroy(int index);
  uint8_t get_input();
#ifdef __cplusplus
}
#endif
