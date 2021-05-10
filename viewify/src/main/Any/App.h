// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_APP_H_
#define VIEWIFY_SRC_MAIN_ANY_APP_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <initializer_list>
#include "../Struct/Size.h"
#include "Enums.h"
#include "../View/ViewGroup.h"
#include "../Factory/ViewGroupFactory.h"
#include "../Struct/Color.h"

using std::string;
using std::initializer_list;

namespace ii887522::viewify {

// Not Thread Safe: it must only be used in main thread
// See also ./View.h for more details
template <unsigned int viewCount> class App final {
  // remove copy semantics
  App(const App&) = delete;
  App& operator=(const App&) = delete;

  // remove move semantics
  App(App&&) = delete;
  App& operator=(App&&) = delete;

  SDL_Window*const window;
  SDL_Surface*const favicon;
  SDL_Renderer*const renderer;
  const Color<unsigned int> backgroundColor;
  ViewGroup<viewCount> scene;

  constexpr void reactMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) {
    if (buttonEvent.button == SDL_BUTTON_LEFT) scene.reactLeftMouseButtonDown(buttonEvent);
  }

  constexpr void reactMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) {
    if (buttonEvent.button == SDL_BUTTON_LEFT) scene.reactLeftMouseButtonUp(buttonEvent);
  }

  constexpr void reactWindowEvent(const SDL_WindowEvent& windowEvent) {
    if (windowEvent.event == SDL_WINDOWEVENT_LEAVE) scene.reactMouseLeaveWindow(windowEvent);
  }

  void renderBackground() {
    SDL_SetRenderDrawColor(renderer, static_cast<Uint8>(backgroundColor.r), static_cast<Uint8>(backgroundColor.g), static_cast<Uint8>(backgroundColor.b), 255u);
    SDL_RenderClear(renderer);
  }

  void render() {
    renderBackground();
    scene.render();
  }

 public:
  // Param sceneFactory: it must not be assigned to nullptr or integer
  explicit App(const string& title, const Size<int>& size, const Color<unsigned int>& backgroundColor, ViewGroupFactory<viewCount>*const sceneFactory, const unsigned int windowFlags = 0u) :
    window{ SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.w, size.h, windowFlags) },
    favicon{ IMG_Load("res/main/favicon.png") }, renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED) }, backgroundColor{ backgroundColor },
    scene(sceneFactory->make(renderer, size)) {
    SDL_SetWindowIcon(window, favicon);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  }

  constexpr Action react(const SDL_Event& event) {
    switch (event.type) {
      case SDL_QUIT: return Action::QUIT;
      case SDL_KEYDOWN: scene.reactKeyDown(event.key);
        break;
      case SDL_MOUSEMOTION: scene.reactMouseMotion(event.motion);
        break;
      case SDL_MOUSEBUTTONDOWN: reactMouseButtonDown(event.button);
        break;
      case SDL_MOUSEBUTTONUP: reactMouseButtonUp(event.button);
        break;
      case SDL_WINDOWEVENT: reactWindowEvent(event.window);
    }
    return Action::NONE;
  }

  constexpr void step(const unsigned int dt) {
    scene.step(dt);
  }

  constexpr void checkAndReactHits(const unsigned int dt) {
    scene.checkAndReactHits(dt);
  }

  void show() {
    render();
    SDL_RenderPresent(renderer);
  }

  Action postShow() {
    return scene.postRender();
  }

  ~App() {
    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(favicon);
    SDL_DestroyWindow(window);
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_ANY_APP_H_
