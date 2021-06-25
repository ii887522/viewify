// Copyright ii887522

#ifndef CONSOLE_TEST

#include "ListItemFactory.h"
#include <stdexcept>
#include <vector>
#include "../View/ViewGroup.h"
#include "../View/RectView.h"
#include "../View/Text.h"

using std::runtime_error;
using std::vector;

namespace ii887522::viewify {

ListItemFactory& ListItemFactory::setTextPair(const Pair<string, string>& value) {
  textPair = value;
  return *this;
}

ViewGroup* ListItemFactory::make() {
  if (!hasSetAnimationController) throw runtime_error{ "ListItemFactory animationController is required!" };
  if (!hasSetGlyphAtlas) throw runtime_error{ "ListItemFactory glyphAtlas is required!" };
  if (!hasSetFontName) throw runtime_error{ "ListItemFactory fontName is required!" };
  if (!hasSetFontSize) throw runtime_error{ "ListItemFactory fontSize is required!" };
  return new ViewGroup{
    getRenderer(), getPosition(), [this](ViewGroup*const, SDL_Renderer*const p_renderer) {
      return vector<View*>{
        new RectView{ p_renderer, Point{ 0, 0 }, keyPaint },
        Text::Builder{ Point { 0, 0 } + keyPadding, textPair.key }
          .setAnimationController(animationController)
          .setGlyphAtlas(glyphAtlas)
          .setFontName(fontName)
          .setFontSize(fontSize)
          .setColor(textColorPair.key)
          .build(),
        Text::Builder{ Point{ keyPaint.size.w + keyMargin.w, keyPadding.h }, textPair.value }
          .setAnimationController(animationController)
          .setGlyphAtlas(glyphAtlas)
          .setFontName(fontName)
          .setFontSize(fontSize)
          .setColor(textColorPair.value)
          .build()
      };
  } };
}

}  // namespace ii887522::viewify

#endif
