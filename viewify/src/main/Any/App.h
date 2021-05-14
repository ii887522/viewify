// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_APP_H_
#define VIEWIFY_SRC_MAIN_ANY_APP_H_

#include <SDL.h>
#include <string>
#include "../Struct/Size.h"
#include "Enums.h"
#include "../View/ViewGroup.h"
#include "../Factory/ViewGroupFactory.h"
#include "../Struct/Color.h"

using std::string;

namespace ii887522::viewify {

// Not Thread Safe: it must only be used in main thread
// See also View.h for more details
class App final {
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
  ViewGroup scene;

  void reactMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent);
  void reactMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent);
  void reactWindowEvent(const SDL_WindowEvent& windowEvent);
  void renderBackground();
  void render();

 public:
  // Param sceneFactory: it must not be assigned to nullptr or integer
  explicit App(const string& title, const Size<int>& size, const Color<unsigned int>& backgroundColor, ViewGroupFactory*const sceneFactory, const unsigned int windowFlags = 0u);

  Action react(const SDL_Event& event);
  void step(const unsigned int dt);
  void checkAndReactHits(const unsigned int dt);
  Action preShow();
  void show();
  Action postShow();
  ~App();
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_ANY_APP_H_
