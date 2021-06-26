// Copyright ii887522

#ifndef CONSOLE_TEST

#include "EventLoopBuilder.h"
#include <SDL.h>
#include "App.h"

namespace ii887522::viewify {

void EventLoopBuilder::build() {
  while (true) {
    SDL_Event event;
    while (flag != EventLoopFlag::ALWAYS_ANIMATE && SDL_WaitEvent(&event)) {
      if (app->react(event) == Action::QUIT) return;
      if (animationController->nextAction() == Action::START_ANIMATION) break;
      if (app->preShow() == Action::QUIT) return;
      app->show();
      if (app->postShow() == Action::QUIT) return;
    }
    auto lastTime{ SDL_GetTicks() };
    while (true) {
      auto isWindowMinimized{ false };
      while (isWindowMinimized && SDL_WaitEvent(&event) || SDL_PollEvent(&event)) {
        const auto action{ app->react(event) };
        if (action == Action::QUIT) {
          return;
        } else if (action == Action::WINDOW_MINIMIZED) {
          isWindowMinimized = true;
          continue;
        } else if (action == Action::WINDOW_RESTORED) {
          isWindowMinimized = false;
          continue;
        }
      }
      const auto now{ SDL_GetTicks() };
      app->step(now - lastTime);
      app->checkAndReactHits(now - lastTime);
      lastTime = now;
      if (app->preShow() == Action::QUIT) return;
      app->show();
      if (app->postShow() == Action::QUIT) return;
      if (animationController->nextAction() == Action::STOP_ANIMATION) break;
      SDL_Delay(4u);
    }
  }
}

}  // namespace ii887522::viewify

#endif
