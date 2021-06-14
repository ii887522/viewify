// Copyright ii887522

#ifndef CONSOLE_TEST

#include "Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdexcept>
#include "../Any/View.h"
#include "../Model/ImageModel.h"
#include "../Any/Enums.h"
#include "../Struct/Size.h"

using std::runtime_error;

namespace ii887522::viewify {

Image* Image::Builder::build() {
  return new Image{ *this };
}

Image::Image(const Builder& builder) : View{
  builder.atlas->getRenderer(),
  builder.position - (builder.align == Align::LEFT ?
    Size{ 0, 0 } : Size{ builder.atlas->getSpriteUnrotatedSize(builder.name).w >> 1u  /* which means builder.atlas->getSpriteUnrotatedSize(builder.name).w / 2 */, 0 }) },
  atlas{ builder.atlas }, model{ ImageModel::Builder{ builder.a }.setDuration(builder.duration).build() }, name{ builder.name }, align{ builder.align }, rotation{ builder.rotation } { }

void Image::set(const unsigned int p_name) {
  const auto centerPosition{ getPosition().get() + Size{ atlas->getSpriteUnrotatedSize(name).w >> 1u  /* which means atlas->getSpriteUnrotatedSize(name).w / 2 */, 0 } };
  name = p_name;
  if (align == Align::CENTER) getPosition().set(centerPosition - Size{ atlas->getSpriteUnrotatedSize(p_name).w >> 1u  /* which means atlas->getSpriteUnrotatedSize(p_name).w / 2 */, 0 });
}

void Image::show() {
  model.show();
}

void Image::hide() {
  model.hide();
}

void Image::step(const unsigned int dt) {
  model.step(dt);
}

void Image::render() {
  atlas->render(name, getPosition().get(), model.getA(), rotation);
}

}  // namespace ii887522::viewify

#endif
