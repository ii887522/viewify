// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FUNCTIONS_SDL_EXT_H_
#define VIEWIFY_SRC_MAIN_FUNCTIONS_SDL_EXT_H_

#include "../Struct/Point.h"
#include "../Struct/Rect.h"
#include <SDL.h>
#include <string>

using std::string;

namespace ii887522::viewify {

// Not Thread Safe: it must be called in main thread
Point<int> getMousePosition();

// Param renderer: it must not be assigned to nullptr or integer
// Not Thread Safe: it must be called in main thread
void snapshot(SDL_Renderer*const renderer, const Rect<int>&, const string& fileName);

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_FUNCTIONS_SDL_EXT_H_
