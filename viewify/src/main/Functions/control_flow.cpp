// Copyright ii887522

#include "control_flow.h"  // NOLINT(build/include_subdir)
#include <SDL.h>
#include "../Any/Enums.h"

namespace ii887522::viewify {

void eventLoop(App&& app) {
  SDL_Event event;
  auto lastTime{ SDL_GetTicks() };
  while (true) {
    while (SDL_PollEvent(&event)) if (app.react(event) == Action::QUIT) return;
    const auto now{ SDL_GetTicks() };
    app.step(now - lastTime);
    app.checkAndReactHits(now - lastTime);
    lastTime = now;
    if (app.preShow() == Action::QUIT) return;
    app.show();
    if (app.postShow() == Action::QUIT) return;
    SDL_Delay(4u);
  }
}

}  // namespace ii887522::viewify
