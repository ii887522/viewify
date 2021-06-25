// Copyright ii887522

#ifndef CONSOLE_TEST

#include "control_flow.h"  // NOLINT(build/include_subdir)
#include <nitro/nitro.h>
#include <SDL.h>
#include "../Any/Enums.h"

using ii887522::nitro::AnimationController;
using ii887522::nitro::Action;

namespace ii887522::viewify {

void eventLoop(App&& app, AnimationController*const animationController, const EventLoopFlag flag) {
  while (true) {
    SDL_Event event;
    while (flag != EventLoopFlag::ALWAYS_ANIMATE && SDL_WaitEvent(&event)) {
      if (app.react(event) == Action::QUIT) return;
      if (animationController->nextAction() == Action::START_ANIMATION) break;
      if (app.preShow() == Action::QUIT) return;
      app.show();
      if (app.postShow() == Action::QUIT) return;
    }
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
      if (animationController->nextAction() == Action::STOP_ANIMATION) break;
      SDL_Delay(4u);
    }
  }
}

}  // namespace ii887522::viewify

#endif
