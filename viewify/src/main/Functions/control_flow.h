// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FUNCTIONS_CONTROL_FLOW_H_
#define VIEWIFY_SRC_MAIN_FUNCTIONS_CONTROL_FLOW_H_

#ifndef TEST

#include "../Any/App.h"
#include <SDL.h>
#include "../Any/Enums.h"

namespace ii887522::viewify {

// Not Thread Safe: it must only be called in main thread
// See also ../Any/View.h for more details
template <unsigned int viewCount> void eventLoop(App<viewCount>&& app) {
  SDL_Event event;
  auto lastTime{ SDL_GetTicks() };
  while (true) {
    while (SDL_PollEvent(&event)) if (app.react(event) == Action::QUIT) return;
    const auto now{ SDL_GetTicks() };
    app.step(now - lastTime);
    app.checkAndReactHits(now - lastTime);
    lastTime = now;
    app.show();
    SDL_Delay(4u);
  }
}

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_FUNCTIONS_CONTROL_FLOW_H_
