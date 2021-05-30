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
  if (hasSetDuration) return new Image{ *this };
  throw runtime_error{ "Image duration is required!" };
}

Image::Image(const Builder& builder) :
  View{ builder.renderer, builder.position - (builder.align == Align::LEFT ? Size{ 0, 0 } : Size{ builder.surface->w >> 1u, 0 }) },
  model{ ImageModel::Builder{ builder.a }.setDuration(builder.duration).build() }, surface{ builder.surface },
  texture{ SDL_CreateTextureFromSurface(builder.renderer, surface) }, align{ builder.align }, rotation{ builder.rotation } { }

void Image::free() {
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);
}

void Image::set(SDL_Surface*const p_surface) {
  const Point centerPosition{ getPosition().get() + Size{ surface->w >> 1u, 0 } };
  free();
  surface = p_surface;
  texture = SDL_CreateTextureFromSurface(getRenderer(), surface);
  if (align == Align::CENTER) getPosition().set(centerPosition - Size{ surface->w >> 1u, 0 });
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
  SDL_SetTextureAlphaMod(texture, static_cast<Uint8>(model.getA()));
  SDL_FRect rect;
  rect.w = static_cast<float>(surface->w);
  rect.h = static_cast<float>(surface->h);
  switch (rotation) {
  case Rotation::NONE: case Rotation::HALF:
    rect.x = static_cast<float>(getPosition().get().x);
    rect.y = static_cast<float>(getPosition().get().y);
    break;
  case Rotation::QUARTER_CLOCKWISE: case Rotation::QUARTER_COUNTERCLOCKWISE:
    rect.x = getPosition().get().x - ((rect.w - rect.h) * .5f);
    rect.y = getPosition().get().y + ((rect.w - rect.h) * .5f);
  }
  SDL_RenderCopyExF(getRenderer(), texture, nullptr, &rect, static_cast<double>(static_cast<unsigned int>(rotation) * 90u), nullptr, SDL_FLIP_NONE);
}

Image::~Image() {
  free();
}

}  // namespace ii887522::viewify

#endif
