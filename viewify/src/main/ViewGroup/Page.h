// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEWGROUP_PAGE_H_
#define VIEWIFY_SRC_MAIN_VIEWGROUP_PAGE_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <nitro/nitro.h>
#include <functional>
#include <vector>
#include <stdexcept>
#include "../View/ViewGroup.h"
#include "../Struct/Point.h"
#include "../Any/View.h"
#include "../Functions/sdl_ext.h"
#include "../Any/typedefs.h"

using ii887522::nitro::Reactive;
using ii887522::nitro::Action;
using std::function;
using std::vector;
using std::runtime_error;

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

 public:
  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    SDL_Renderer*const renderer;
    const Point<int> position;
    const MakeViews makeViews;
    T path;
    bool hasSetPath;
    Reactive<T>* currentPath;
    bool hasSetCurrentPath;

   public:
    /// <summary>See also MakeViews for more details</summary>
    /// <param name="renderer">It must not be assigned to nullptr or integer</param>
    explicit constexpr Builder(SDL_Renderer*const renderer, const Point<int>& position = Point{ 0, 0 },
      const MakeViews& makeViews = [](ViewGroup*const self, SDL_Renderer*const renderer) {
        return vector<View*>{ };
      }) : renderer{ renderer }, position{ position }, makeViews{ makeViews }, hasSetPath{ false }, currentPath{ nullptr }, hasSetCurrentPath{ false } { }

    /// <summary>It must be called at least 1 time before building Page object.</summary>
    constexpr Builder& setPath(const T& value) {
      path = value;
      hasSetPath = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Page object.</summary>
    /// <param name="value">It must not be assigned nullptr or integer</param>
    constexpr Builder& setCurrentPath(Reactive<T>*const value) {
      currentPath = value;
      hasSetCurrentPath = true;
      return *this;
    }

    Page* build() {
      if (!hasSetPath) throw runtime_error{ "Page path is required!" };
      if (!hasSetCurrentPath) throw runtime_error{ "Page currentPath is required!" };
      return new Page{ *this };
    }

    friend class Page;
  };

 private:
  bool isShowing;

  explicit Page(const Builder& builder) : ViewGroup{ builder.renderer, builder.position, builder.makeViews }, isShowing{ false } {
    builder.currentPath->watch([this, path{ builder.path }](const T&, const T& newValue, const int) {
      const auto wasShowing{ isShowing };
      isShowing = newValue == path;
      if (!wasShowing && isShowing) this->show();
      else if (wasShowing && !isShowing) this->hide();
      ViewGroup::reactMouseMotion(SDL_MouseMotionEvent{ .x = getMousePosition().x, .y = getMousePosition().y });
    });
    builder.currentPath->set(builder.currentPath->get());
  }

 public:
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
    ViewGroup::step(dt);
  }

  Action preRender() override {
    if (isShowing) ViewGroup::preRender();
    return Action::NONE;
  }

  void render() override {
    if (isShowing) ViewGroup::render();
  }

  Action postRender() override {
    if (isShowing) ViewGroup::postRender();
    return Action::NONE;
  }
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEWGROUP_PAGE_H_
