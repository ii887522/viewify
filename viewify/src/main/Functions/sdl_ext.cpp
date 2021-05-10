// Copyright ii887522

#include "sdl_ext.h"  // NOLINT(build/include_subdir)
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "../Struct/Point.h"
#include "../Struct/Rect.h"

using std::string;

namespace ii887522::viewify {

Point<int> getMousePosition() {
  Point<int> result;
  SDL_GetMouseState(&result.x, &result.y);
  return result;
}

void snapshot(SDL_Renderer*const renderer, const Rect<int>& rect, const string& fileName) {
  SDL_Surface*const surface{ SDL_CreateRGBSurfaceWithFormat(0u, rect.size.w, rect.size.h, 32, SDL_PIXELFORMAT_RGBA32) };
  const SDL_Rect sdl_rect{ rect.position.x, rect.position.y, rect.size.w, rect.size.h };
  SDL_RenderReadPixels(renderer, &sdl_rect, SDL_PIXELFORMAT_RGBA32, surface->pixels, surface->pitch);
  IMG_SavePNG(surface, fileName.c_str());
  SDL_FreeSurface(surface);
}

}  // namespace ii887522::viewify
