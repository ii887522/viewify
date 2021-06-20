// Copyright ii887522

#ifndef CONSOLE_TEST

#include "TextureAtlas.h"
#include <nitro/nitro.h>
#include <texture-packer/texture_packer.h>
#include <SDL.h>
#include <SDL_image.h>
#include <filesystem>
#include <string>
#include <vector>
#include "../Any/Atlas.h"
#include "../Any/Enums.h"
#include "../Struct/Point.h"
#include "../Any/constants.h"

using std::filesystem::exists;
using std::string;
using std::to_string;
using std::vector;
using ii887522::nitro::read;
using ii887522::texturePacker::Sprite;

namespace ii887522::viewify {

TextureAtlas::TextureAtlas(SDL_Renderer*const renderer, const string& atlasDirPath) : Atlas{ renderer }, sprites{ read<Sprite, vector>(atlasDirPath + "atlas.dat") } {
  addSurfaces(atlasDirPath);
  addTextures();
}

void TextureAtlas::addSurfaces(const string& atlasDirPath) {
  auto i{ 0u };
  while (exists(atlasDirPath + "atlas_" + to_string(i) + IMAGE_EXTENSION_NAME)) {
    getSurfaces().push_back(IMG_Load((atlasDirPath + "atlas_" + to_string(i) + IMAGE_EXTENSION_NAME).c_str()));
    ++i;
  }
}

void TextureAtlas::Renderer::render(TextureAtlas*const self) {
  SDL_SetTextureAlphaMod(self->getTextures()[self->sprites[name].atlasI], static_cast<Uint8>(a));
  const SDL_Rect srcRect{ self->sprites[name].rect.position.x, self->sprites[name].rect.position.y, self->sprites[name].rect.size.w, self->sprites[name].rect.size.h };
  SDL_FRect dstRect;
  dstRect.w = static_cast<float>(self->sprites[name].rect.size.w);
  dstRect.h = static_cast<float>(self->sprites[name].rect.size.h);
  if (
    self->sprites[name].isRotated && (rotation == Rotation::NONE || rotation == Rotation::HALF) || rotation == Rotation::QUARTER_CLOCKWISE ||
    rotation == Rotation::QUARTER_COUNTERCLOCKWISE) {
    dstRect.x = position.x - (self->sprites[name].rect.size.w - self->sprites[name].rect.size.h) * .5f;
    dstRect.y = position.y + (self->sprites[name].rect.size.w - self->sprites[name].rect.size.h) * .5f;
  } else {
    dstRect.x = static_cast<float>(position.x);
    dstRect.y = static_cast<float>(position.y);
  }
  SDL_RenderCopyExF(
    self->getRenderer(), self->getTextures()[self->sprites[name].atlasI], &srcRect, &dstRect,
    static_cast<double>((self->sprites[name].isRotated ? -RIGHT_ANGLE : 0) + static_cast<int>(rotation) * RIGHT_ANGLE), nullptr, SDL_FLIP_NONE);
}

}  // namespace ii887522::viewify

#endif
