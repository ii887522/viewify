// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FUNCTIONS_SDL_EXT_H_
#define VIEWIFY_SRC_MAIN_FUNCTIONS_SDL_EXT_H_

#include "../Struct/Point.h"

namespace ii887522::viewify {

// Not Thread Safe: it must be called in main thread
Point<int> getMousePosition();

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_FUNCTIONS_SDL_EXT_H_
