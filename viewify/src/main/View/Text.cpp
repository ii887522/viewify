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

Text::Builder::Builder(const Point<int>& position, const string& value) : animationController{ nullptr }, hasSetAnimationController{ false }, atlas{ nullptr }, hasSetAtlas{ false },
  fontName{ 0u }, hasSetFontName{ false }, fontSize{ 0u }, hasSetFontSize{ false }, position{ position }, value{ value }, color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) },
  a{ static_cast<unsigned int>(MAX_COLOR.a) }, duration{ 1u  /* See also Text::Builder::setDuration(const unsigned int) for more details */ }, align{ Align::LEFT } { }

Text* Text::Builder::build() {
  if (!hasSetAnimationController) throw runtime_error{ "Text animationController is required!" };
  if (!hasSetAtlas) throw runtime_error{ "Text atlas is required!" };
  if (!hasSetFontName) throw runtime_error{ "Text fontName is required!" };
  if (!hasSetFontSize) throw runtime_error{ "Text fontSize is required!" };
  return new Text{ *this };
}

Text::Text(const Builder& builder) : View{
  builder.atlas->getRenderer(),
  builder.position - (builder.align == Align::LEFT ?
    Size{ 0, 0 } :
    Size{
      builder.atlas->getTextW(builder.fontName, builder.fontSize, builder.value) >> 1u  /* which means builder.atlas->getTextW(builder.fontName, builder.fontSize, builder.value) / 2 */, 0 })
    }, atlas{ builder.atlas }, model{ TextModel::Builder{ builder.animationController, builder.a }.setDuration(builder.duration).build() }, fontName{ builder.fontName },
  fontSize{ builder.fontSize }, value{ builder.value }, color{ builder.color }, align{ builder.align } { }

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
  GlyphAtlas::StringRenderer{ fontName, fontSize, value }
    .setPosition(getPosition().get())
    .setColor(Color{ color.r, color.g, color.b, static_cast<unsigned int>(color.a * model.getA() / MAX_COLOR.a) })
    .render(atlas);
}

}  // namespace ii887522::viewify

#endif
