// Copyright ii887522

#ifndef CONSOLE_TEST

#include "Button.h"
#include <functional>
#include <SDL.h>
#include <stdexcept>
#include "../Any/View.h"
#include "../Struct/Point.h"
#include "../Struct/Paint.h"
#include "../Struct/Rect.h"
#include "../Model/ButtonModel.h"
#include "../Any/Enums.h"
#include "../Any/constants.h"

using std::function;
using std::runtime_error;

namespace ii887522::viewify {

Button::Builder::Builder(const Point<int>& position, const Paint<int, unsigned int>& paint) : animationController{ nullptr }, hasSetAnimationController{ false }, renderer{ nullptr },
  hasSetRenderer{ false }, position{ position }, paint{ paint }, onClick{ onClick }, a{ static_cast<unsigned int>(MAX_COLOR.a) },
  aDuration{ 1u  /* See also Button::Builder::setADuration(const unsigned int) for more details */ }, hasSetADuration{ false }, lightnessDuration{ 0u }, hasSetLightnessDuration{ false },
  hasSetOnMouseMove{ false }, hasSetOnMouseOver{ false }, hasSetOnMouseOut{ false }, hasSetOnClick{ false } { }

Button::Builder& Button::Builder::setOnMouseMove(const function<void()>& value) {
  onMouseMove = value;
  hasSetOnMouseMove = true;
  return *this;
}

Button::Builder& Button::Builder::setOnMouseOver(const function<void()>& value) {
  onMouseOver = value;
  hasSetOnMouseOver = true;
  return *this;
}

Button::Builder& Button::Builder::setOnMouseOut(const function<void()>& value) {
  onMouseOut = value;
  hasSetOnMouseOut = true;
  return *this;
}

Button::Builder& Button::Builder::setOnClick(const function<void()>& value) {
  onClick = value;
  hasSetOnClick = true;
  return *this;
}

Button* Button::Builder::build() {
  if (!hasSetAnimationController) throw runtime_error{ "Button animationController is required!" };
  if (!hasSetRenderer) throw runtime_error{ "Button renderer is required!" };
  if (!hasSetLightnessDuration) throw runtime_error{ "Button lightness duration is required!" };
  if (!hasSetOnMouseMove) throw runtime_error{ "Button onMouseMove is required!" };
  if (!hasSetOnMouseOver) throw runtime_error{ "Button onMouseOver is required!" };
  if (!hasSetOnMouseOut) throw runtime_error{ "Button onMouseOut is required!" };
  if (!hasSetOnClick) throw runtime_error{ "Button onClick is required!" };
  return new Button{ *this };
}

Button::Button(const Builder& builder) : View{ builder.renderer, builder.position }, model{
  ButtonModel::Builder{ builder.animationController, Rect{ builder.position, builder.paint.size } }
    .setA(builder.a)
    .setADuration(builder.aDuration)
    .setLightnessDuration(builder.lightnessDuration)
    .setOnMouseMove(builder.onMouseMove)
    .setOnMouseOver(builder.onMouseOver)
    .setOnMouseOut(builder.onMouseOut)
    .setOnClick(builder.onClick)
    .build()
  }, color{ builder.paint.color } {
  getPosition().watch([this](const Point<int>&, const Point<int>& newValue, const int) {
    model.setPosition(newValue);
  });
}

Action Button::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) {
  model.reactMouseMotion(Point{ motionEvent.x, motionEvent.y });
  return Action::NONE;
}

Action Button::reactLeftMouseButtonDown(const SDL_MouseButtonEvent&) {
  model.reactLeftMouseButtonDown();
  return Action::NONE;
}

Action Button::reactLeftMouseButtonUp(const SDL_MouseButtonEvent&) {
  model.reactLeftMouseButtonUp();
  return Action::NONE;
}

Action Button::reactMouseLeaveWindow(const SDL_WindowEvent&) {
  model.reactMouseLeaveWindow();
  return Action::NONE;
}

void Button::show() {
  model.show();
  model.getOnMouseOver()();
}

void Button::hide() {
  model.hide();
  model.getOnMouseOut()();
}

void Button::step(const unsigned int dt) {
  model.step(dt);
}

void Button::render() {
  SDL_SetRenderDrawColor(
    getRenderer(), static_cast<Uint8>(color.r * model.getLightness()), static_cast<Uint8>(color.g * model.getLightness()),
    static_cast<Uint8>(color.b * model.getLightness()), static_cast<Uint8>(color.a * model.getA() / MAX_COLOR.a));
  const SDL_Rect rect{ getPosition().get().x, getPosition().get().y, model.getRect().size.w, model.getRect().size.h };
  SDL_RenderFillRect(getRenderer(), &rect);
}

}  // namespace ii887522::viewify

#endif
