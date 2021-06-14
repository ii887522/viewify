// Copyright ii887522

#ifndef CONSOLE_TEST

#include "Atlas.h"
#include <SDL.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace ii887522::viewify {

Atlas::Atlas(SDL_Renderer*const renderer) : renderer{ renderer } { }

vector<SDL_Surface*>& Atlas::getSurfaces() {
  return surfaces;
}

vector<SDL_Texture*>& Atlas::getTextures() {
  return textures;
}

void Atlas::addTextures() {
  for (const auto surface : surfaces) textures.push_back(SDL_CreateTextureFromSurface(renderer, surface));
}

void Atlas::enableAnisotropicFiltering() {
  for (const auto texture : textures) SDL_SetTextureScaleMode(texture, SDL_ScaleModeBest);
}

void Atlas::freeTextures() {
  for (const auto texture : textures) SDL_DestroyTexture(texture);
}

void Atlas::freeSurfaces() {
  for (const auto surface : surfaces) SDL_FreeSurface(surface);
}

Atlas::~Atlas() {
  freeTextures();
  freeSurfaces();
}

}  // namespace ii887522::viewify

#endif
