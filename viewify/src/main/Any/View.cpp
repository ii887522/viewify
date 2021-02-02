// Copyright ii887522

#include "View.h"
#include <SDL.h>
#include "../Struct/Point.h"
#include "../Any/Enums.h"

namespace ii887522::viewify {
  View::View(SDL_Renderer*const renderer, const Point<int>& position) : renderer{ renderer }, position{ position } { }

  Action View::reactKeyDown(const SDL_KeyboardEvent&) {
    return Action::NONE;
  }

  Action View::reactMouseMotion(const SDL_MouseMotionEvent&) {
    return Action::NONE;
  }

  Action View::reactLeftMouseButtonDown(const SDL_MouseButtonEvent&) {
    return Action::NONE;
  }

  Action View::reactLeftMouseButtonUp(const SDL_MouseButtonEvent&) {
    return Action::NONE;
  }

  Action View::reactMouseLeaveWindow(const SDL_WindowEvent&) {
    return Action::NONE;
  }

  void View::show() { }
  void View::hide() { }
  void View::step(const unsigned int) { }
  void View::checkAndReactHits(const unsigned int) { }
  View::~View() { }
}  // namespace ii887522::viewify
