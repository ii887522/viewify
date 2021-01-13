// Copyright ii887522

#ifndef TEST

#include "sdl_ext.h"  // NOLINT(build/include_subdir)
#include <SDL.h>
#include "../Struct/Point.h"

namespace ii887522::viewify {

Point<int> getMousePosition() {
  Point<int> result;
  SDL_GetMouseState(&result.x, &result.y);
  return result;
}

}  // namespace ii887522::viewify

#endif
