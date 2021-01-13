// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_MODEL_BUTTONMODEL_H_
#define VIEWIFY_SRC_MAIN_MODEL_BUTTONMODEL_H_

#include <Any/AnimatedAny.h>
#include <functional>
#include "../Struct/Point.h"
#include "../Struct/Rect.h"
#include "../Functions/math_ext.h"

using std::function;
using ii887522::nitro::AnimatedAny;

namespace ii887522::viewify {

constexpr auto initialLightness{ 1.f };
constexpr auto hoveredLightness{ .9f };
constexpr auto pressedLightness{ .8f };

// Not Thread Safe
class ButtonModel final {
  // remove copy semantics
  ButtonModel(const ButtonModel&) = delete;
  ButtonModel& operator=(const ButtonModel&) = delete;

  // remove move semantics
  ButtonModel(ButtonModel&&) = delete;
  ButtonModel& operator=(ButtonModel&&) = delete;

 public:
  enum class State : unsigned int {
    INITIAL, HOVERED, PRESSED
  };

  // Not Thread Safe
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    const Rect<int> rect;
    unsigned int a;
    unsigned int aDuration;  // alpha animation duration
    bool hasSetADuration;  // has set alpha animation duration
    unsigned int lightnessDuration;  // lightness animation duration
    bool hasSetLightnessDuration;  // has set lightness animation duration
    function<void()> onMouseOver;
    bool hasSetOnMouseOver;
    function<void()> onMouseOut;
    bool hasSetOnMouseOut;
    function<void()> onClick;
    bool hasSetOnClick;

   public:
    explicit Builder(const Rect<int>&);

    constexpr Builder& setA(const unsigned int value) {
      a = value;
      return *this;
    }

    // Alpha animation duration. It must be called at least 1 time before building ButtonModel object.
    // Param value: it must not be assigned to 0
    constexpr Builder& setADuration(const unsigned int value) {
      aDuration = value;
      hasSetADuration = true;
      return *this;
    }

    // Lightness animation duration. It must be called at least 1 time before building ButtonModel object.
    // Param value: it must not be assigned to 0
    constexpr Builder& setLightnessDuration(const unsigned int value) {
      lightnessDuration = value;
      hasSetLightnessDuration = true;
      return *this;
    }

    // It must be called at least 1 time before building ButtonModel object.
    Builder& setOnMouseOver(const function<void()>&);

    // It must be called at least 1 time before building ButtonModel object.
    Builder& setOnMouseOut(const function<void()>&);

    // It must be called at least 1 time before building ButtonModel object.
    Builder& setOnClick(const function<void()>&);

    // It must be called to build ButtonModel object.
    ButtonModel build();

    friend class ButtonModel;
  };

 private:
  Rect<int> rect;
  State state;
  AnimatedAny<float> lightness;
  AnimatedAny<int> a;
  const function<void()> onMouseOver;
  const function<void()> onMouseOut;
  const function<void()> onClick;

  explicit ButtonModel(const Builder&);

  constexpr void reactMouseMotionWhenInitial(const Point<int>& position) {
    if (!isOverlap(position, rect)) return;
    state = State::HOVERED;
    lightness.set(hoveredLightness);
    onMouseOver();
  }

  constexpr void reactMouseMotionWhenHovered(const Point<int>& position) {
    if (isOverlap(position, rect)) return;
    state = State::INITIAL;
    lightness.set(initialLightness);
    onMouseOut();
  }

  constexpr void reactMouseMotionWhenPressed(const Point<int>& position) {
    if (isOverlap(position, rect)) return;
    state = State::INITIAL;
    lightness.set(initialLightness);
    onMouseOut();
  }

 public:
  constexpr const Rect<int>& getRect() const {
    return rect;
  }

  constexpr void setPosition(const Point<int>& position) {
    rect.position = position;
  }

  constexpr float getLightness() const {
    return lightness.get();
  }

  constexpr float getEndLightness() const {
    return lightness.getEnd();
  }

  constexpr unsigned int getA() const {
    return a.get();
  }

  constexpr void reactMouseMotion(const Point<int>& position) {
    switch (state) {
      case State::INITIAL: reactMouseMotionWhenInitial(position);
        break;
      case State::HOVERED: reactMouseMotionWhenHovered(position);
        break;
      case State::PRESSED: reactMouseMotionWhenPressed(position);
    }
  }

  constexpr void reactLeftMouseButtonDown() {
    if (state != State::HOVERED) return;
    state = State::PRESSED;
    lightness.set(pressedLightness);
  }

  constexpr void reactLeftMouseButtonUp() {
    if (state != State::PRESSED) return;
    state = State::HOVERED;
    lightness.set(hoveredLightness);
    onClick();
  }

  constexpr void reactMouseLeaveWindow() {
    state = State::INITIAL;
    lightness.set(initialLightness);
  }

  constexpr void show() {
    a.set(255);
  }

  constexpr void hide() {
    state = State::INITIAL;
    lightness.teleport(initialLightness);
    a.teleport(0);
  }

  constexpr void step(const unsigned int dt) {
    lightness.step(dt);
    a.step(dt);
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_MODEL_BUTTONMODEL_H_
