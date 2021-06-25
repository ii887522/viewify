// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_APP_H_
#define VIEWIFY_SRC_MAIN_ANY_APP_H_

#ifndef CONSOLE_TEST

#include <nitro/nitro.h>
#include <SDL.h>
#include <string>
#include "../Struct/Size.h"
#include "../View/ViewGroup.h"
#include "../Factory/ViewGroupFactory.h"
#include "../Struct/Paint.h"
#include "../Struct/Color.h"
#include "constants.h"  // NOLINT(build/include_subdir)

using std::string;
using ii887522::nitro::Action;

namespace ii887522::viewify {

/// <summary>
///   <para>Not Thread Safe: it must only be used in main thread</para>
///   <para>See also View.h for more details</para>
/// </summary>
class App final {
  // remove copy semantics
  App(const App&) = delete;
  App& operator=(const App&) = delete;

  // remove move semantics
  App(App&&) = delete;
  App& operator=(App&&) = delete;

 public:
  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    const string title;
    const Paint<int, unsigned int> paint;
    ViewGroupFactory* sceneFactory;
    bool hasSetSceneFactory;
    const unsigned int windowFlags;

   public:
    explicit Builder(const string& title = "", const Paint<int, unsigned int>& = Paint{ Size{ 1, 1 }, static_cast<Color<unsigned int>>(MAX_COLOR) },
      const unsigned int windowFlags = NO_FLAGS);

    /// <summary>It must be called at least 1 time before building ButtonModel object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setSceneFactory(ViewGroupFactory*const value) {
      sceneFactory = value;
      hasSetSceneFactory = true;
      return *this;
    }

    /// <summary>It must be called to build App object.</summary>
    App build();

    friend class App;
  };

 private:
  SDL_Window*const window;
  SDL_Surface*const favicon;
  SDL_Renderer*const renderer;
  const Color<unsigned int> backgroundColor;
  ViewGroup scene;

  explicit App(const Builder&);
  void reactMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent);
  void reactMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent);
  void reactWindowEvent(const SDL_WindowEvent& windowEvent);
  void renderBackground();
  void render();

 public:
  Action react(const SDL_Event& event);
  void step(const unsigned int dt);
  void checkAndReactHits(const unsigned int dt);
  Action preShow();
  void show();
  Action postShow();
  ~App();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_ANY_APP_H_
