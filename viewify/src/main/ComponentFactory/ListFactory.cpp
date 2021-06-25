// Copyright ii887522

#ifndef CONSOLE_TEST

#include "ListFactory.h"
#include <SDL.h>
#include <nitro/nitro.h>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include "../Factory/ComponentFactory.h"
#include "../View/ViewGroup.h"
#include "ListItemFactory.h"
#include "../Any/View.h"
#include "../Struct/Point.h"
#include "ListItemFactory.h"
#include "../Struct/Size.h"
#include "../Struct/Color.h"

using ii887522::nitro::Pair;
using std::vector;
using std::string;
using std::initializer_list;
using std::runtime_error;

namespace ii887522::viewify {

ListFactory::ListFactory(SDL_Renderer*const renderer, const Point<int>& position) : ComponentFactory{ renderer, position }, animationController{ nullptr },
  hasSetAnimationController{ false }, glyphAtlas{ nullptr }, hasSetGlyphAtlas{ false }, fontName{ 0u }, hasSetFontName{ false }, fontSize{ 0u }, hasSetFontSize{ false },
  keyMargin{ 1, 1 }, keyPaddings{ Size{ 1, 1 } }, keyPaint{ Size{ 1, 1 }, Color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) } }, textPairs{ Pair{ string{ " " }, string{ " " } } },
  textColorPair{ Color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) }, Color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) } } { }

ListFactory& ListFactory::setKeyPaddings(const initializer_list<Size<int>>& value) {
  keyPaddings = vector(value);
  return *this;
}

ListFactory& ListFactory::setTextPairs(const initializer_list<Pair<string, string>>& value) {
  textPairs = vector(value);
  return *this;
}

ViewGroup* ListFactory::make() {
  if (!hasSetAnimationController) throw runtime_error{ "ListFactory animationController is required!" };
  if (!hasSetGlyphAtlas) throw runtime_error{ "ListFactory glyphAtlas is required!" };
  if (!hasSetFontName) throw runtime_error{ "ListFactory fontName is required!" };
  if (!hasSetFontSize) throw runtime_error{ "ListFactory fontSize is required!" };
  return new ViewGroup{
    getRenderer(), getPosition(), [this](ViewGroup*const, SDL_Renderer*const p_renderer) {
      vector<View*> views(textPairs.size());
      auto y{ 0 };
      for (auto i{ 0u }; i != views.size(); ++i) {
        views[i] = ListItemFactory{ p_renderer, Point{ 0, y } }
          .setAnimationController(animationController)
          .setGlyphAtlas(glyphAtlas)
          .setFontName(fontName)
          .setFontSize(fontSize)
          .setKeyMargin(keyMargin)
          .setKeyPadding(keyPaddings.begin()[i])
          .setKeyPaint(keyPaint)
          .setTextPair(textPairs.begin()[i])
          .setTextColorPair(textColorPair)
          .make();
        y += keyPaint.size.h + keyMargin.h;
      }
      return views;
    }
  };
}

}  // namespace ii887522::viewify

#endif
