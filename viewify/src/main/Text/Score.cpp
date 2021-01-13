// Copyright ii887522

#ifndef TEST

#include "Score.h"
#include <string>
#include <stdexcept>
#include <functional>
#include "../Image/Text.h"
#include "../Any/Enums.h"
#include <SDL.h>
#include <SDL_ttf.h>

using std::runtime_error;
using std::function;

namespace ii887522::viewify {

Score::Builder::Builder(SDL_Renderer*const renderer, TTF_Font*const font, const Point<int>& position, const unsigned int max,
  const function<void()>& onValueMax) : renderer{ renderer }, font{ font }, position{ position }, canIncrement{ nullptr },
  hasSetCanIncrement{ false }, canReset{ nullptr }, hasSetCanReset{ false }, max{ max }, onValueMax{ onValueMax } { }

Score* Score::Builder::build() {
  if (!hasSetCanIncrement) throw runtime_error{ "Score canIncrement is required!" };
  if (!hasSetCanReset) throw runtime_error{ "Score canReset is required!" };
  return new Score{ *this };
}

}  // namespace ii887522::viewify

#endif
