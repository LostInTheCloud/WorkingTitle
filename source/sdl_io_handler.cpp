#include "sdl_io_handler.hpp"

#include "exception.hpp"


SDL_Display::SDL_Display(const size_t width, const size_t height, const size_t scale) :
  _width(width), _height(height), _scale(scale), _window(nullptr), _screen(nullptr)
{
  if (_width > 0 && _height > 0 && _scale > 0)
  {
    uint32_t flags = 0;
    _window = SDL_CreateWindow("DMG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, static_cast<int>(width * scale), static_cast<int>(height * scale), flags | SDL_WINDOW_RESIZABLE);

    if (_window == nullptr) { throw RuntimeError(SDL_GetError()); }

    _screen = SDL_GetWindowSurface(_window);

    if (_screen == nullptr) { throw RuntimeError(SDL_GetError()); }
  }
}

SDL_Display::~SDL_Display()
{
  SDL_DestroyWindow(_window);
}

void SDL_Display::display_init(const size_t width, const size_t height, const size_t scale)
{
  if (_window == nullptr && _screen == nullptr && width > 0 && height > 0 && scale > 0)
  {
    _width = width;
    _height = height;
    _scale = scale;
    
    uint32_t flags = 0;
    _window = SDL_CreateWindow("DMG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, static_cast<int>(width * scale), static_cast<int>(height * scale), flags | SDL_WINDOW_RESIZABLE);

    if(_window == nullptr) { throw RuntimeError(SDL_GetError()); }

    _screen = SDL_GetWindowSurface(_window);

    if(_screen == nullptr) { throw RuntimeError(SDL_GetError()); }
  }
}

void SDL_Display::display_destroy()
{
  _width = 0;
  _height = 0;
  _scale = 0;
  _screen = nullptr;
  SDL_DestroyWindow(_window);
  _window = nullptr;
}

SDL_Display::operator bool() const{
  return _width > 0 && _height > 0 && _scale > 0 && _window != nullptr && _screen != nullptr;
}

void SDL_Display::display_set_window_title(const char* name)
{
  if (*this == false) return;
    
  SDL_SetWindowTitle(_window, name);
  SDL_UpdateWindowSurface(_window);
}

void SDL_Display::display_draw(const uint32_t * pixels)
{
  if (*this == false) return;
  
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
  SDL_Surface* native_surface = SDL_CreateRGBSurfaceFrom((void*)pixels, (int)_width, (int)_height, 4*8, 4*(int)_width, Rmask, Gmask, Bmask, Amask);
  SDL_BlitScaled(native_surface, nullptr, _screen, nullptr);
  SDL_UpdateWindowSurface(_window);
}

bool SDL_Display::compare_window_id(Uint32 id) const
{
  return _window != nullptr && _window == SDL_GetWindowFromID(id);
}


SDL_IO_Handler::SDL_IO_Handler()
{
}

void SDL_IO_Handler::display_init(const size_t num, const size_t width, const size_t height, const size_t scale)
{
  std::lock_guard<std::mutex> guard(event_mutex);
  while (displays.size() <= num) { displays.emplace_back(); }
  
  displays[num].display_init(width, height, scale);
}

void SDL_IO_Handler::display_set_window_title(const size_t num, const char* title)
{
  std::lock_guard<std::mutex> guard(event_mutex);
  while (displays.size() <= num) { displays.emplace_back(); }
  
  displays[num].display_set_window_title(title);
}

void SDL_IO_Handler::display_draw(const size_t num, const uint32_t* pixels)
{
  std::lock_guard<std::mutex> guard(event_mutex);
  while (displays.size() <= num) { displays.emplace_back(); }
  
  displays[num].display_draw(pixels);
}

void SDL_IO_Handler::display_destroy(const size_t num)
{
  std::lock_guard<std::mutex> guard(event_mutex);
  while (displays.size() <= num) { displays.emplace_back(); }
  
  displays[num].display_destroy();
  
  // Remove all invalid displays
  while (displays.size() > 0 && displays.back() == false)
  {
    displays.pop_back();
  }
}

void SDL_IO_Handler::handle_SDL_events_async()
{
  stop_handle_SDL_events_async = false;
  worker_thread = std::thread([&, this] {
    while (!stop_handle_SDL_events_async)
    {
      while (!stop_handle_SDL_events_async && SDL_PollEvent(&current_event))
      {
        // Thread Safe Event handling
        std::lock_guard<std::mutex> guard(this->event_mutex);
        
        // Uncomment for debug purposes
        // SDL_DebugPrintEvent(&current_event);
        switch (current_event.type)
        {
        // Handle Window Events (e.g. closing)
        case SDL_WINDOWEVENT:
          // Determine display (if any)
          for (auto& display : this->displays)
          {
            if (display.compare_window_id(current_event.window.windowID))
            {
              // Handle event for this display
              switch (current_event.window.event)
              {
              case SDL_WINDOWEVENT_CLOSE:
                // Destroy current display
                display.display_destroy();
              }
            }
            break;
          }
          break;
        
        // Handle Input Device Events (e.g. Adding or removing controllers)
        case SDL_CONTROLLERDEVICEADDED:
        case SDL_CONTROLLERDEVICEREMOVED:
        case SDL_CONTROLLERDEVICEREMAPPED:
        case SDL_JOYDEVICEADDED:
        case SDL_JOYDEVICEREMOVED:
          
          break;
        // Handle Input Events
        case SDL_JOYAXISMOTION:
        case SDL_JOYBALLMOTION:
        case SDL_JOYHATMOTION:
        case SDL_JOYBUTTONDOWN:
        case SDL_JOYBUTTONUP:
          
          break;
        
        // Handle other events 
        default:
          
          break;
        }
      }
      
      // Handle the keyboard state.
      // Note: One should us SDL_PumpEvents() to update the state array.
      //       See https://wiki.libsdl.org/SDL_GetKeyboardState
      // Note: ... SDL_PollEvent() and SDL_WaitEvent() implicitly call SDL_PumpEvents().
      //       See https://wiki.libsdl.org/SDL_PumpEvents
      if (!stop_handle_SDL_events_async)
      {
        // Thread Safe Event handling
        std::lock_guard<std::mutex> guard(this->event_mutex);
        
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        current_input.right = state[SDL_SCANCODE_D] ? 0x01 : 0x00;
        current_input.left  = state[SDL_SCANCODE_A] ? 0x02 : 0x00;
        current_input.up    = state[SDL_SCANCODE_W] ? 0x04 : 0x00;
        current_input.down  = state[SDL_SCANCODE_S] ? 0x08 : 0x00;
        
        current_input.A      = state[SDL_SCANCODE_M] ? 0x01 : 0x00;
        current_input.B      = state[SDL_SCANCODE_N] ? 0x02 : 0x00;
        current_input.select = state[SDL_SCANCODE_J] ? 0x04 : 0x00;
        current_input.start  = state[SDL_SCANCODE_K] ? 0x08 : 0x00;
      }

      // Sleep till next iteration
      std::this_thread::sleep_for (std::chrono::milliseconds(20));
    }
  });
}


void SDL_IO_Handler::handle_SDL_events_async_stop()
{
  std::lock_guard<std::mutex> guard(event_mutex);
  stop_handle_SDL_events_async = true;
  if (worker_thread.joinable())
  {
    worker_thread.join();
  }
}


uint8_t SDL_IO_Handler::get_input(int output) const
{
  std::lock_guard<std::mutex> guard(event_mutex);
  uint8_t ret = 0;
  
  if (output == 0)
  {
    ret |= current_input.right;
    ret |= current_input.left;
    ret |= current_input.up;
    ret |= current_input.down;
  }
  else
  {
    ret |= current_input.A;
    ret |= current_input.B;
    ret |= current_input.select;
    ret |= current_input.start;
  }
  
  return ret;
}


// Borrowed from 'sdl_events.c'.
void SDL_DebugPrintEvent(const SDL_Event *event)
{
    fprintf(stderr, "SDL EVENT: ");

  if ((event->type >= SDL_USEREVENT) && (event->type <= SDL_LASTEVENT)) {
    fprintf(stderr, "SDL_USEREVENT");
    if (event->type > SDL_USEREVENT) {
      fprintf(stderr, "+%u", ((uint) event->type) - SDL_USEREVENT);
    }
    fprintf(stderr, " (timestamp=%u windowid=%u code=%d data1=%p data2=%p)",
        (uint) event->user.timestamp, (uint) event->user.windowID,
        (int) event->user.code, event->user.data1, event->user.data2);
    return;
  }

  switch (event->type) {
    #define SDL_EVENT_CASE(x) case x: fprintf(stderr, "%s", #x);
    SDL_EVENT_CASE(SDL_FIRSTEVENT) fprintf(stderr, "(THIS IS PROBABLY A BUG!)"); break;
    SDL_EVENT_CASE(SDL_QUIT) fprintf(stderr, "(timestamp=%u)", (uint) event->quit.timestamp); break;
    SDL_EVENT_CASE(SDL_APP_TERMINATING) break;
    SDL_EVENT_CASE(SDL_APP_LOWMEMORY) break;
    SDL_EVENT_CASE(SDL_APP_WILLENTERBACKGROUND) break;
    SDL_EVENT_CASE(SDL_APP_DIDENTERBACKGROUND) break;
    SDL_EVENT_CASE(SDL_APP_WILLENTERFOREGROUND) break;
    SDL_EVENT_CASE(SDL_APP_DIDENTERFOREGROUND) break;
    SDL_EVENT_CASE(SDL_KEYMAPCHANGED) break;
    SDL_EVENT_CASE(SDL_CLIPBOARDUPDATE) break;
    SDL_EVENT_CASE(SDL_RENDER_TARGETS_RESET) break;
    SDL_EVENT_CASE(SDL_RENDER_DEVICE_RESET) break;
    #undef SDL_EVENT_CASE

    #define SDL_EVENT_CASE(x) case x: fprintf(stderr, "%s ", #x);

    SDL_EVENT_CASE(SDL_WINDOWEVENT)
      fprintf(stderr, "(timestamp=%u windowid=%u event=", (uint) event->window.timestamp, (uint) event->window.windowID);
      switch(event->window.event) {
        case SDL_WINDOWEVENT_NONE: fprintf(stderr, "none(THIS IS PROBABLY A BUG!)"); break;
        #define SDL_WINDOWEVENT_CASE(x) case x: fprintf(stderr, "%s", #x); break
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_SHOWN);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_HIDDEN);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_EXPOSED);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_MOVED);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_RESIZED);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_SIZE_CHANGED);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_MINIMIZED);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_MAXIMIZED);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_RESTORED);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_ENTER);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_LEAVE);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_FOCUS_GAINED);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_FOCUS_LOST);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_CLOSE);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_TAKE_FOCUS);
        SDL_WINDOWEVENT_CASE(SDL_WINDOWEVENT_HIT_TEST);
        #undef SDL_WINDOWEVENT_CASE
        default: fprintf(stderr, "UNKNOWN(bug? fixme?)"); break;
      }
      fprintf(stderr, " data1=%d data2=%d)", (int) event->window.data1, (int) event->window.data2);
      break;

    SDL_EVENT_CASE(SDL_SYSWMEVENT)
      fprintf(stderr, "(timestamp=%u)", (uint) event->syswm.timestamp);
      /* We don't delve further at the moment. */
      break;

    #define PRINT_KEY_EVENT(event) \
      fprintf(stderr, "(timestamp=%u windowid=%u state=%s repeat=%s scancode=%u keycode=%u mod=%u)", \
        (uint) event->key.timestamp, (uint) event->key.windowID, \
        event->key.state == SDL_PRESSED ? "pressed" : "released", \
        event->key.repeat ? "true" : "false", \
        (uint) event->key.keysym.scancode, \
        (uint) event->key.keysym.sym, \
        (uint) event->key.keysym.mod)
    SDL_EVENT_CASE(SDL_KEYDOWN) PRINT_KEY_EVENT(event); break;
    SDL_EVENT_CASE(SDL_KEYUP) PRINT_KEY_EVENT(event); break;
    #undef PRINT_KEY_EVENT

    SDL_EVENT_CASE(SDL_TEXTEDITING)
      fprintf(stderr, "(timestamp=%u windowid=%u text='%s' start=%d length=%d)",
        (uint) event->edit.timestamp, (uint) event->edit.windowID,
        event->edit.text, (int) event->edit.start, (int) event->edit.length);
      break;

    SDL_EVENT_CASE(SDL_TEXTINPUT)
      fprintf(stderr, "(timestamp=%u windowid=%u text='%s')", (uint) event->text.timestamp, (uint) event->text.windowID, event->text.text);
      break;


    SDL_EVENT_CASE(SDL_MOUSEMOTION)
      fprintf(stderr, "(timestamp=%u windowid=%u which=%u state=%u x=%d y=%d xrel=%d yrel=%d)",
          (uint) event->motion.timestamp, (uint) event->motion.windowID,
          (uint) event->motion.which, (uint) event->motion.state,
          (int) event->motion.x, (int) event->motion.y,
          (int) event->motion.xrel, (int) event->motion.yrel);
      break;

    #define PRINT_MBUTTON_EVENT(event) \
      fprintf(stderr, "(timestamp=%u windowid=%u which=%u button=%u state=%s clicks=%u x=%d y=%d)", \
          (uint) event->button.timestamp, (uint) event->button.windowID, \
          (uint) event->button.which, (uint) event->button.button, \
          event->button.state == SDL_PRESSED ? "pressed" : "released", \
          (uint) event->button.clicks, (int) event->button.x, (int) event->button.y)
    SDL_EVENT_CASE(SDL_MOUSEBUTTONDOWN) PRINT_MBUTTON_EVENT(event); break;
    SDL_EVENT_CASE(SDL_MOUSEBUTTONUP) PRINT_MBUTTON_EVENT(event); break;
    #undef PRINT_MBUTTON_EVENT


    SDL_EVENT_CASE(SDL_MOUSEWHEEL)
      fprintf(stderr, "(timestamp=%u windowid=%u which=%u x=%d y=%d direction=%s)",
          (uint) event->wheel.timestamp, (uint) event->wheel.windowID,
          (uint) event->wheel.which, (int) event->wheel.x, (int) event->wheel.y,
          event->wheel.direction == SDL_MOUSEWHEEL_NORMAL ? "normal" : "flipped");
      break;

    SDL_EVENT_CASE(SDL_JOYAXISMOTION)
      fprintf(stderr, "(timestamp=%u which=%d axis=%u value=%d)",
        (uint) event->jaxis.timestamp, (int) event->jaxis.which,
        (uint) event->jaxis.axis, (int) event->jaxis.value);
      break;

    SDL_EVENT_CASE(SDL_JOYBALLMOTION)
      fprintf(stderr, "(timestamp=%u which=%d ball=%u xrel=%d yrel=%d)",
        (uint) event->jball.timestamp, (int) event->jball.which,
        (uint) event->jball.ball, (int) event->jball.xrel, (int) event->jball.yrel);
      break;

    SDL_EVENT_CASE(SDL_JOYHATMOTION)
      fprintf(stderr, "(timestamp=%u which=%d hat=%u value=%u)",
        (uint) event->jhat.timestamp, (int) event->jhat.which,
        (uint) event->jhat.hat, (uint) event->jhat.value);
      break;

    #define PRINT_JBUTTON_EVENT(event) \
      fprintf(stderr, "(timestamp=%u which=%d button=%u state=%s)", \
        (uint) event->jbutton.timestamp, (int) event->jbutton.which, \
        (uint) event->jbutton.button, event->jbutton.state == SDL_PRESSED ? "pressed" : "released")
    SDL_EVENT_CASE(SDL_JOYBUTTONDOWN) PRINT_JBUTTON_EVENT(event); break;
    SDL_EVENT_CASE(SDL_JOYBUTTONUP) PRINT_JBUTTON_EVENT(event); break;
    #undef PRINT_JBUTTON_EVENT

    #define PRINT_JOYDEV_EVENT(event) fprintf(stderr, "(timestamp=%u which=%d)", (uint) event->jdevice.timestamp, (int) event->jdevice.which)
    SDL_EVENT_CASE(SDL_JOYDEVICEADDED) PRINT_JOYDEV_EVENT(event); break;
    SDL_EVENT_CASE(SDL_JOYDEVICEREMOVED) PRINT_JOYDEV_EVENT(event); break;
    #undef PRINT_JOYDEV_EVENT

    SDL_EVENT_CASE(SDL_CONTROLLERAXISMOTION)
      fprintf(stderr, "(timestamp=%u which=%d axis=%u value=%d)",
        (uint) event->caxis.timestamp, (int) event->caxis.which,
        (uint) event->caxis.axis, (int) event->caxis.value);
      break;

    #define PRINT_CBUTTON_EVENT(event) \
      fprintf(stderr, "(timestamp=%u which=%d button=%u state=%s)", \
        (uint) event->cbutton.timestamp, (int) event->cbutton.which, \
        (uint) event->cbutton.button, event->cbutton.state == SDL_PRESSED ? "pressed" : "released")
    SDL_EVENT_CASE(SDL_CONTROLLERBUTTONDOWN) PRINT_CBUTTON_EVENT(event); break;
    SDL_EVENT_CASE(SDL_CONTROLLERBUTTONUP) PRINT_CBUTTON_EVENT(event); break;
    #undef PRINT_CBUTTON_EVENT

    #define PRINT_CONTROLLERDEV_EVENT(event) fprintf(stderr, "(timestamp=%u which=%d)", (uint) event->cdevice.timestamp, (int) event->cdevice.which)
    SDL_EVENT_CASE(SDL_CONTROLLERDEVICEADDED) PRINT_CONTROLLERDEV_EVENT(event); break;
    SDL_EVENT_CASE(SDL_CONTROLLERDEVICEREMOVED) PRINT_CONTROLLERDEV_EVENT(event); break;
    SDL_EVENT_CASE(SDL_CONTROLLERDEVICEREMAPPED) PRINT_CONTROLLERDEV_EVENT(event); break;
    #undef PRINT_CONTROLLERDEV_EVENT

    #define PRINT_FINGER_EVENT(event) \
      fprintf(stderr, "(timestamp=%u touchid=%lld fingerid=%lld x=%f y=%f dx=%f dy=%f pressure=%f)", \
        (uint) event->tfinger.timestamp, (long long) event->tfinger.touchId, \
        (long long) event->tfinger.fingerId, event->tfinger.x, event->tfinger.y, \
        event->tfinger.dx, event->tfinger.dy, event->tfinger.pressure)
    SDL_EVENT_CASE(SDL_FINGERDOWN) PRINT_FINGER_EVENT(event); break;
    SDL_EVENT_CASE(SDL_FINGERUP) PRINT_FINGER_EVENT(event); break;
    SDL_EVENT_CASE(SDL_FINGERMOTION) PRINT_FINGER_EVENT(event); break;
    #undef PRINT_FINGER_EVENT

    #define PRINT_DOLLAR_EVENT(event) \
      fprintf(stderr, "(timestamp=%u touchid=%lld gestureid=%lld numfingers=%u error=%f x=%f y=%f)", \
        (uint) event->dgesture.timestamp, (long long) event->dgesture.touchId, \
        (long long) event->dgesture.gestureId, (uint) event->dgesture.numFingers, \
        event->dgesture.error, event->dgesture.x, event->dgesture.y);
    SDL_EVENT_CASE(SDL_DOLLARGESTURE) PRINT_DOLLAR_EVENT(event); break;
    SDL_EVENT_CASE(SDL_DOLLARRECORD) PRINT_DOLLAR_EVENT(event); break;
    #undef PRINT_DOLLAR_EVENT

    SDL_EVENT_CASE(SDL_MULTIGESTURE)
      fprintf(stderr, "(timestamp=%u touchid=%lld dtheta=%f ddist=%f x=%f y=%f numfingers=%u)",
        (uint) event->mgesture.timestamp, (long long) event->mgesture.touchId,
        event->mgesture.dTheta, event->mgesture.dDist,
        event->mgesture.x, event->mgesture.y, (uint) event->mgesture.numFingers);
      break;

    #define PRINT_DROP_EVENT(event) fprintf(stderr, "(file='%s' timestamp=%u windowid=%u)", event->drop.file, (uint) event->drop.timestamp, (uint) event->drop.windowID)
    SDL_EVENT_CASE(SDL_DROPFILE) PRINT_DROP_EVENT(event); break;
    SDL_EVENT_CASE(SDL_DROPTEXT) PRINT_DROP_EVENT(event); break;
    SDL_EVENT_CASE(SDL_DROPBEGIN) PRINT_DROP_EVENT(event); break;
    SDL_EVENT_CASE(SDL_DROPCOMPLETE) PRINT_DROP_EVENT(event); break;
    #undef PRINT_DROP_EVENT

    #define PRINT_AUDIODEV_EVENT(event) fprintf(stderr, "(timestamp=%u which=%u iscapture=%s)", (uint) event->adevice.timestamp, (uint) event->adevice.which, event->adevice.iscapture ? "true" : "false");
    SDL_EVENT_CASE(SDL_AUDIODEVICEADDED) PRINT_AUDIODEV_EVENT(event); break;
    SDL_EVENT_CASE(SDL_AUDIODEVICEREMOVED) PRINT_AUDIODEV_EVENT(event); break;
    #undef PRINT_AUDIODEV_EVENT

    #undef SDL_EVENT_CASE

    default:
      fprintf(stderr, "UNKNOWN SDL EVENT #%u! (Bug? FIXME?)", (uint) event->type);
      break;
  }

  fprintf(stderr, "\n");
}
