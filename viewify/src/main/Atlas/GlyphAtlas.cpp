// Copyright ii887522

#ifndef CONSOLE_TEST

#include "GlyphAtlas.h"
#include <nitro/nitro.h>
#include <font-packer/font_packer.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include <filesystem>
#include "../Any/Atlas.h"
#include "../Struct/Point.h"
#include "../Any/Enums.h"
#include "../Struct/Color.h"
#include "../Any/constants.h"
#include "../Functions/math_ext.h"

using std::string;
using ii887522::nitro::read;
using std::vector;
using std::filesystem::exists;
using std::to_string;
using ii887522::fontPacker::Glyph;
using ii887522::fontPacker::Font;

namespace ii887522::viewify {

GlyphAtlas::GlyphAtlas(SDL_Renderer*const renderer, const string& atlasDirPath) : Atlas{ renderer },
  fontMetadatas{ read<Font, vector>(atlasDirPath + "fonts" + BINARY_FILE_EXTENSION_NAME) }, glyphs{ read<Glyph, vector>(atlasDirPath + "glyphs" + BINARY_FILE_EXTENSION_NAME) } {
  addSurfaces(atlasDirPath);
  addTextures();
  enableAnisotropicFiltering();
  addKerningSizes(atlasDirPath);
}

void GlyphAtlas::addSurfaces(const string& atlasDirPath) {
  auto i{ 0u };
  while (exists(atlasDirPath + "glyphs_" + to_string(i) + IMAGE_EXTENSION_NAME)) {
    getSurfaces().push_back(IMG_Load((atlasDirPath + "glyphs_" + to_string(i) + IMAGE_EXTENSION_NAME).c_str()));
    ++i;
  }
}

void GlyphAtlas::addKerningSizes(const string& atlasDirPath) {
  kerningSizes.resize(fontMetadatas.size());
  for (auto i{ 0u }; i != kerningSizes.size(); ++i) {
    if (exists(atlasDirPath + "kernings_" + to_string(i) + BINARY_FILE_EXTENSION_NAME))
      kerningSizes[i] = read<int, vector>(atlasDirPath + "kernings_" + to_string(i) + BINARY_FILE_EXTENSION_NAME);
  }
}

int GlyphAtlas::getTextW(const unsigned int fontName, const unsigned int fontSize, const string& str) const {
  auto x{ glyphs[getGlyphI(fontName, str.front())].advance * fontSize / static_cast<float>(fontMetadatas[fontName].size) };
  for (auto i{ 1u }; i != str.size(); ++i)
    x += (glyphs[getGlyphI(fontName, str[i])].advance + (kerningSizes[fontName].empty() ? 0 : kerningSizes[fontName][getKerningSizeI(str[i - 1u], str[i])])) * fontSize /
      static_cast<float>(fontMetadatas[fontName].size);
  return static_cast<int>(x);
}

void GlyphAtlas::CharRenderer::render(GlyphAtlas*const self) {
  SDL_SetTextureColorMod(self->getTextures()[self->glyphs[getGlyphI(fontName, ch)].atlasI], static_cast<Uint8>(color.r), static_cast<Uint8>(color.g), static_cast<Uint8>(color.b));
  SDL_SetTextureAlphaMod(self->getTextures()[self->glyphs[getGlyphI(fontName, ch)].atlasI], static_cast<Uint8>(color.a));
  const SDL_Rect srcRect{
    self->glyphs[getGlyphI(fontName, ch)].rect.position.x, self->glyphs[getGlyphI(fontName, ch)].rect.position.y, self->glyphs[getGlyphI(fontName, ch)].rect.size.w,
    self->glyphs[getGlyphI(fontName, ch)].rect.size.h
  };
  SDL_FRect dstRect;
  dstRect.w = self->glyphs[getGlyphI(fontName, ch)].rect.size.w * fontSize / static_cast<float>(self->fontMetadatas[fontName].size);
  dstRect.h = self->glyphs[getGlyphI(fontName, ch)].rect.size.h * fontSize / static_cast<float>(self->fontMetadatas[fontName].size);
  if (self->glyphs[getGlyphI(fontName, ch)].isRotated) {
    dstRect.x = position.x - ((self->glyphs[getGlyphI(fontName, ch)].rect.size.w - self->glyphs[getGlyphI(fontName, ch)].rect.size.h) * .5f) * fontSize /
      static_cast<float>(self->fontMetadatas[fontName].size);
    dstRect.y = position.y + ((self->glyphs[getGlyphI(fontName, ch)].rect.size.w - self->glyphs[getGlyphI(fontName, ch)].rect.size.h) * .5f) * fontSize /
      static_cast<float>(self->fontMetadatas[fontName].size);
  } else {
    dstRect.x = position.x * fontSize / static_cast<float>(self->fontMetadatas[fontName].size);
    dstRect.y = position.y * fontSize / static_cast<float>(self->fontMetadatas[fontName].size);
  }
  SDL_RenderCopyExF(
    self->getRenderer(), self->getTextures()[self->glyphs[getGlyphI(fontName, ch)].atlasI], &srcRect, &dstRect,
    self->glyphs[getGlyphI(fontName, ch)].isRotated ? static_cast<double>(-RIGHT_ANGLE) : 0.0, nullptr, SDL_FLIP_NONE);
}

void GlyphAtlas::StringRenderer::render(GlyphAtlas*const self) {
  CharRenderer{ fontName, fontSize, str->front() }.setPosition(position).setColor(color).render(self);
  auto x{ static_cast<int>(
    position.x + (self->glyphs[getGlyphI(fontName, str->front())].advance + (str->size() == 1u || self->kerningSizes[fontName].empty() ? 0 :
    self->kerningSizes[fontName][getKerningSizeI(str->front(), (*str)[1u])])) * fontSize / static_cast<float>(self->fontMetadatas[fontName].size))
  };
  for (auto i{ 1u }; i != str->size(); ++i) {
    CharRenderer{ fontName, fontSize, (*str)[i] }.setPosition(Point{ x, position.y }).setColor(color).render(self);
    x += static_cast<int>((self->glyphs[getGlyphI(fontName, (*str)[i])].advance + (self->kerningSizes[fontName].empty() ? 0 :
      self->kerningSizes[fontName][getKerningSizeI((*str)[i], (*str)[i + 1u])])) * fontSize / static_cast<float>(self->fontMetadatas[fontName].size));
  }
}

}  // namespace ii887522::viewify

#endif
