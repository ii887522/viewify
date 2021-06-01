// Copyright ii887522

#ifndef CONSOLE_TEST

#include "Modal.h"
#include <SDL.h>
#include <nitro/Any/Reactive.h>
#include <functional>
#include <vector>
#include "../Struct/Size.h"
#include "../Struct/Point.h"
#include "../Struct/Paint.h"
#include "../Any/View.h"
#include "../View/ViewGroup.h"
#include "../Any/Enums.h"
#include "../Functions/sdl_ext.h"
#include "../Any/typedefs.h"
#include "../Any/constants.h"

using ii887522::nitro::Reactive;
using std::function;
using std::vector;

namespace ii887522::viewify {

Modal::Modal(SDL_Renderer*const renderer, const Size<int>& sceneSize, const Point<int>& position, const Paint<int, unsigned int>& paint, Reactive<bool>*const isShowing,
  const unsigned int duration, const MakeViews& makeViews) : ViewGroup{ renderer, position, makeViews }, sceneSize{ sceneSize }, paint{ paint }, isShowing{ *isShowing }, model{ duration } {
  isShowing->watch([this](const bool& value, const int) {
    if (value) {
      model.show();
      ViewGroup::show();
      ViewGroup::reactMouseMotion(SDL_MouseMotionEvent{ .x = getMousePosition().x, .y = getMousePosition().y });
    } else {
      model.hide();
      ViewGroup::hide();
    }
  });
}

void Modal::darkenScene() {
  SDL_SetRenderDrawColor(View::getRenderer(), 0u, 0u, 0u, static_cast<Uint8>(model.getSceneCoverA()));
  const SDL_Rect rect{ 0, 0, sceneSize.w, sceneSize.h };
  SDL_RenderFillRect(View::getRenderer(), &rect);
}

void Modal::renderBackground() {
  SDL_SetRenderDrawColor(
    View::getRenderer(), static_cast<Uint8>(paint.color.r), static_cast<Uint8>(paint.color.g), static_cast<Uint8>(paint.color.b), static_cast<Uint8>(paint.color.a * model.getA() / MAX_A));
  const SDL_Rect rect{ View::getPosition().get().x, View::getPosition().get().y, paint.size.w, paint.size.h };
  SDL_RenderFillRect(View::getRenderer(), &rect);
}

Action Modal::reactKeyDown(const SDL_KeyboardEvent& keyEvent) {
  if (isShowing.get()) {
    ViewGroup::reactKeyDown(keyEvent);
    return Action::CONSUME_EVENT;
  }
  return Action::NONE;
}

Action Modal::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) {
  if (isShowing.get()) {
    ViewGroup::reactMouseMotion(motionEvent);
    return Action::CONSUME_EVENT;
  }
  return Action::NONE;
}

Action Modal::reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) {
  if (isShowing.get()) {
    ViewGroup::reactLeftMouseButtonDown(buttonEvent);
    return Action::CONSUME_EVENT;
  }
  return Action::NONE;
}

Action Modal::reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) {
  if (isShowing.get()) {
    ViewGroup::reactLeftMouseButtonUp(buttonEvent);
    return Action::CONSUME_EVENT;
  }
  return Action::NONE;
}

Action Modal::reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) {
  if (isShowing.get()) {
    ViewGroup::reactMouseLeaveWindow(windowEvent);
    return Action::CONSUME_EVENT;
  }
  return Action::NONE;
}

void Modal::step(const unsigned int dt) {
  if (!isShowing.get()) return;
  model.step(dt);
  ViewGroup::step(dt);
}

void Modal::render() {
  if (!isShowing.get()) return;
  darkenScene();
  renderBackground();
  ViewGroup::render();
}

}  // namespace ii887522::viewify

#endif
