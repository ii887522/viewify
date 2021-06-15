// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEWGROUP_PAGE_H_
#define VIEWIFY_SRC_MAIN_VIEWGROUP_PAGE_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <nitro/nitro.h>
#include <functional>
#include <vector>
#include "../View/ViewGroup.h"
#include "../Struct/Point.h"
#include "../Any/View.h"
#include "../Functions/sdl_ext.h"
#include "../Any/Enums.h"
#include "../Any/typedefs.h"

using ii887522::nitro::Reactive;
using std::function;
using std::vector;

namespace ii887522::viewify {

/// <summary>
///   <para>Not Thread Safe: it must only be used in main thread</para>
///   <para>See also ../View/ViewGroup.h for more details</para>
/// </summary>
template <typename T> class Page final : public ViewGroup {
  // remove copy semantics
  Page(const Page&) = delete;
  Page& operator=(const Page&) = delete;

  // remove move semantics
  Page(Page&&) = delete;
  Page& operator=(Page&&) = delete;

  bool isShowing;

 public:
  /// <summary>See also MakeViews for more details</summary>
  /// <param name="self>It must not be assigned to nullptr or integer</param>
  /// <param name="renderer">It must not be assigned to nullptr or integer</param>
  explicit Page(SDL_Renderer*const renderer, const Point<int>& position, const T& path, Reactive<T>*const currentPath,
    const MakeViews& makeViews = [](ViewGroup*const self, SDL_Renderer*const renderer) {
      return vector<View*>{ };
    }) : ViewGroup{ renderer, position, makeViews }, isShowing{ false } {
    currentPath->watch([this, path](const T&, const T& newValue, const int) {
      const auto wasShowing{ isShowing };
      isShowing = newValue == path;
      if (!wasShowing && isShowing) this->show();
      else if (wasShowing && !isShowing) this->hide();
      ViewGroup::reactMouseMotion(SDL_MouseMotionEvent{ .x = getMousePosition().x, .y = getMousePosition().y });
    });
    currentPath->set(currentPath->get());
  }

  Action reactKeyDown(const SDL_KeyboardEvent& keyEvent) override {
    if (isShowing) ViewGroup::reactKeyDown(keyEvent);
    return Action::NONE;
  }

  Action reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) override {
    if (isShowing) ViewGroup::reactMouseMotion(motionEvent);
    return Action::NONE;
  }

  Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) override {
    if (isShowing) ViewGroup::reactLeftMouseButtonDown(buttonEvent);
    return Action::NONE;
  }

  Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) override {
    if (isShowing) ViewGroup::reactLeftMouseButtonUp(buttonEvent);
    return Action::NONE;
  }

  Action reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) override {
    if (isShowing) ViewGroup::reactMouseLeaveWindow(windowEvent);
    return Action::NONE;
  }

  void step(const unsigned int dt) override {
    if (isShowing) ViewGroup::step(dt);
  }

  void render() override {
    if (isShowing) ViewGroup::render();
  }
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEWGROUP_PAGE_H_
