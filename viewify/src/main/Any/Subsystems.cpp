// Copyright ii887522

#include "Subsystems.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace ii887522::viewify {

Subsystems::Subsystems() {
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();
}

Subsystems::~Subsystems() {
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}

}  // namespace ii887522::viewify
