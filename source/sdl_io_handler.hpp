#pragma once

#include <cstdint>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <csignal>

#include <SDL2/SDL.h>

class SDL_Display
{
public:
  SDL_Display(const size_t width = 0, const size_t height = 0, const size_t scale = 0);
  SDL_Display(SDL_Display&& other);
  
  ~SDL_Display();
  
  operator bool() const;
  
  void display_init(const size_t width, const size_t height, const size_t scale);
  void display_destroy();
  void display_set_window_title(const char* title);
  void display_draw(const uint32_t* pixels);
  bool compare_window_id(Uint32 id) const;
  
  
protected:
  size_t _width;
  size_t _height;
  size_t _scale;
  SDL_Window  *_window;
  SDL_Surface *_screen;
};


typedef struct {
  uint8_t up;
  uint8_t down;
  uint8_t left;
  uint8_t right;
  uint8_t A;
  uint8_t B;
  uint8_t start;
  uint8_t select;
} DMG_Input;


class SDL_IO_Handler
{
public:
  SDL_IO_Handler();
  
  void handle_SDL_events_async();
  void handle_SDL_events_async_stop();
  
  void display_init(const size_t num, const size_t width, const size_t height, const size_t scale);
  void display_set_window_title(const size_t num, const char* title);
  void display_draw(const size_t num, const uint32_t* pixels);
  int windows_active() const;
  void display_destroy(const size_t num);
  
  uint8_t get_input() const;
  
protected:
  std::vector<SDL_Display> displays;
  SDL_Event current_event;
  bool stop_handle_SDL_events_async;
  std::thread worker_thread;
  mutable std::mutex event_mutex;
  DMG_Input current_input;
  
};

// Borrowed from 'sdl_events.c'.
void SDL_DebugPrintEvent(const SDL_Event *event);
