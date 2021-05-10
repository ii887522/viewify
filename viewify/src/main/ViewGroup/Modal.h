// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEWGROUP_MODAL_H_
#define VIEWIFY_SRC_MAIN_VIEWGROUP_MODAL_H_

#include <SDL.h>
#include <Any/Reactive.h>
#include <initializer_list>
#include "../View/ViewGroup.h"
#include "../Any/View.h"
#include "../Struct/Paint.h"
#include "../Struct/Size.h"
#include "../Struct/Point.h"
#include "../Model/ModalModel.h"
#include "../Any/Enums.h"
#include "../Functions/sdl_ext.h"

using std::initializer_list;
using ii887522::nitro::Reactive;

namespace ii887522::viewify {

// Not Thread Safe: it must only be used in main thread
// See also ../View/ViewGroup.h for more details
template <unsigned int viewCount> class Modal final : public ViewGroup<viewCount> {
  // remove copy semantics
  Modal(const Modal&) = delete;
  Modal& operator=(const Modal&) = delete;

  // remove move semantics
  Modal(Modal&&) = delete;
  Modal& operator=(Modal&&) = delete;

  const Size<int> sceneSize;
  const Paint<int, unsigned int> paint;
  Reactive<bool>& isShowing;
  ModalModel model;

  void darkenScene() {
    SDL_SetRenderDrawColor(View::getRenderer(), 0u, 0u, 0u, static_cast<Uint8>(model.getSceneCoverA()));
    const SDL_Rect rect{ 0, 0, sceneSize.w, sceneSize.h };
    SDL_RenderFillRect(View::getRenderer(), &rect);
  }

  void renderBackground() {
    SDL_SetRenderDrawColor(
      View::getRenderer(), static_cast<Uint8>(paint.color.r), static_cast<Uint8>(paint.color.g), static_cast<Uint8>(paint.color.b),
      static_cast<Uint8>(model.getA()));
    const SDL_Rect rect{ View::getPosition().get().x, View::getPosition().get().y, paint.size.w, paint.size.h };
    SDL_RenderFillRect(View::getRenderer(), &rect);
  }

 public:
  // Param renderer: it must not be assigned to nullptr or integer
  // Param duration: animation duration and it must not be assigned to 0
  // Param isShowing: it must not be assigned to nullptr or integer
  explicit Modal(SDL_Renderer*const renderer, const Size<int>& sceneSize, const Point<int>& position,
    const Paint<int, unsigned int>& paint, Reactive<bool>*const isShowing, const unsigned int duration, const initializer_list<View*>& views)
      : ViewGroup<viewCount>{ renderer, position, views }, sceneSize{ sceneSize }, paint{ paint }, isShowing{ *isShowing },
        model{ duration } {
    isShowing->watch([this](const bool& value, const int) {
      if (value) {
        model.show();
        ViewGroup<viewCount>::show();
        ViewGroup<viewCount>::reactMouseMotion(SDL_MouseMotionEvent{ .x = getMousePosition().x, .y = getMousePosition().y });
      } else {
        model.hide();
        ViewGroup<viewCount>::hide();
      }
    });
  }

  Action reactKeyDown(const SDL_KeyboardEvent& keyEvent) override {
    if (isShowing.get()) {
      ViewGroup<viewCount>::reactKeyDown(keyEvent);
      return Action::CONSUME_EVENT;
    }
    return Action::NONE;
  }

  Action reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) override {
    if (isShowing.get()) {
      ViewGroup<viewCount>::reactMouseMotion(motionEvent);
      return Action::CONSUME_EVENT;
    }
    return Action::NONE;
  }

  Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) override {
    if (isShowing.get()) {
      ViewGroup<viewCount>::reactLeftMouseButtonDown(buttonEvent);
      return Action::CONSUME_EVENT;
    }
    return Action::NONE;
  }

  Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) override {
    if (isShowing.get()) {
      ViewGroup<viewCount>::reactLeftMouseButtonUp(buttonEvent);
      return Action::CONSUME_EVENT;
    }
    return Action::NONE;
  }

  Action reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) override {
    if (isShowing.get()) {
      ViewGroup<viewCount>::reactMouseLeaveWindow(windowEvent);
      return Action::CONSUME_EVENT;
    }
    return Action::NONE;
  }

  void step(const unsigned int dt) override {
    if (!isShowing.get()) return;
    model.step(dt);
    ViewGroup<viewCount>::step(dt);
  }

  void render() override {
    if (!isShowing.get()) return;
    darkenScene();
    renderBackground();
    ViewGroup<viewCount>::render();
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_VIEWGROUP_MODAL_H_
