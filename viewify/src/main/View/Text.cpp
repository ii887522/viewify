// Copyright ii887522

#ifndef CONSOLE_TEST

#include "Text.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <stdexcept>
#include "../Any/View.h"
#include "../Struct/Color.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Any/Enums.h"
#include "../Atlas/GlyphAtlas.h"
#include "../Any/constants.h"
#include "../Model/TextModel.h"

using std::string;
using std::runtime_error;

namespace ii887522::viewify {

Text::Builder::Builder(GlyphAtlas*const atlas, const unsigned int fontName, const Point<int>& position, const string& value, const Color<unsigned int>& color, const Align align) :
  atlas{ atlas }, fontName{ fontName }, position{ position }, value{ value }, color{ color }, fontSize{ 0u }, hasSetFontSize{ false }, a{ static_cast<unsigned int>(MAX_A) },
  duration{ 1u  /* See also Text::Builder::setDuration(const unsigned int) for more details */ }, align{ align } { }

Text* Text::Builder::build() {
  if (!hasSetFontSize) throw runtime_error{ "Text fontSize is required!" };
  return new Text{ *this };
}

Text::Text(const Builder& builder) : View{
  builder.atlas->getRenderer(),
  builder.position - (builder.align == Align::LEFT ?
    Size{ 0, 0 } :
    Size{
      builder.atlas->getTextW(builder.fontName, builder.fontSize, builder.value) >> 1u  /* which means builder.atlas->getTextW(builder.fontName, builder.fontSize, builder.value) / 2 */, 0 })
    }, atlas{ builder.atlas }, model{ TextModel::Builder{ builder.a }.setDuration(builder.duration).build() }, fontName{ builder.fontName }, fontSize{ builder.fontSize },
  value{ builder.value }, color{ builder.color }, align{ builder.align } { }

void Text::set(const string& p_value) {
  const auto centerPosition{ getPosition().get() + Size{ atlas->getTextW(fontName, fontSize, value) >> 1u  /* which means atlas->getTextW(fontName, fontSize, value) / 2 */, 0 } };
  value = p_value;
  if (align == Align::CENTER)
    getPosition().set(centerPosition - Size{ atlas->getTextW(fontName, fontSize, p_value) >> 1u  /* which means atlas->getTextW(fontName, fontSize, p_value) / 2 */, 0 });
}

void Text::show() {
  model.show();
}

void Text::hide() {
  model.hide();
}

void Text::step(const unsigned int dt) {
  model.step(dt);
}

void Text::render() {
  atlas->render(fontName, fontSize, value, getPosition().get(), Color{ color.r, color.g, color.b, static_cast<unsigned int>(color.a * model.getA() / MAX_A) });
}

}  // namespace ii887522::viewify

#endif
