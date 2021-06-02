// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FUNCTIONS_SDL_EXT_H_
#define VIEWIFY_SRC_MAIN_FUNCTIONS_SDL_EXT_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <string>
#include "../Struct/Point.h"
#include "../Struct/Rect.h"

using std::string;

namespace ii887522::viewify {

/// <summary>Not Thread Safe: it must be called in main thread</summary>
Point<int> getMousePosition();

/// <summary>Not Thread Safe: it must be called in main thread</summary>
/// <param name="renderer">It must not be assigned to nullptr or integer</param>
void snapshot(SDL_Renderer*const renderer, const Rect<int>&, const string& filePath);

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_FUNCTIONS_SDL_EXT_H_
