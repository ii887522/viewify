// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_VIEW_H_
#define VIEWIFY_SRC_MAIN_ANY_VIEW_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <nitro/nitro.h>
#include "../Struct/Point.h"

using ii887522::nitro::Reactive;
using ii887522::nitro::Action;

namespace ii887522::viewify {

/// <summary>
///   <para>
///     It represents the basic building block for user interface components. A view occupies a rectangular area on the screen and is responsible for drawing and event handling.
///   </para>
///   <para>Not Thread Safe: it must only be used in main thread</para>
/// </summary>
class View {
  // remove copy semantics
  View(const View&) = delete;
  View& operator=(const View&) = delete;

  // remove move semantics
  View(View&&) = delete;
  View& operator=(View&&) = delete;

  SDL_Renderer*const renderer;
  Reactive<Point<int>> position;

 public:
  /// <param name="renderer">It must not be assigned to integer</param>
  explicit View(SDL_Renderer*const renderer, const Point<int>& position = Point{ 0, 0 });

  constexpr SDL_Renderer* getRenderer() const {
    return renderer;
  }

  constexpr Reactive<Point<int>>& getPosition() {
    return position;
  }

  virtual Action reactKeyDown(const SDL_KeyboardEvent&);
  virtual Action reactMouseMotion(const SDL_MouseMotionEvent&);
  virtual Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent&);
  virtual Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent&);
  virtual Action reactMouseLeaveWindow(const SDL_WindowEvent&);
  virtual void show();
  virtual void hide();
  virtual void step(const unsigned int dt);
  virtual void checkAndReactHits(const unsigned int dt);
  virtual Action preRender();
  virtual void render() = 0;
  virtual Action postRender();
  virtual ~View();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_ANY_VIEW_H_
