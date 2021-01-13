// Copyright ii887522

#ifndef TEST

#include "View.h"
#include <SDL.h>
#include "../Struct/Point.h"

namespace ii887522::viewify {
  View::View(SDL_Renderer*const renderer, const Point<int>& position) : renderer{ renderer }, position{ position } { }
  void View::reactKeyDown(const SDL_KeyboardEvent&) { }
  void View::reactMouseMotion(const SDL_MouseMotionEvent&) { }
  void View::reactLeftMouseButtonDown(const SDL_MouseButtonEvent&) { }
  void View::reactLeftMouseButtonUp(const SDL_MouseButtonEvent&) { }
  void View::reactMouseLeaveWindow(const SDL_WindowEvent&) { }
  void View::show() { }
  void View::hide() { }
  void View::step(const unsigned int) { }
  void View::checkAndReactHits(const unsigned int) { }
  View::~View() { }
}  // namespace ii887522::viewify

#endif
