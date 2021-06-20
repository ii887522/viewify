// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_MODEL_BUTTONMODEL_H_
#define VIEWIFY_SRC_MAIN_MODEL_BUTTONMODEL_H_

#include <nitro/nitro.h>
#include <functional>
#include "../Struct/Size.h"
#include "../Struct/Point.h"
#include "../Struct/Rect.h"
#include "../Functions/math_ext.h"
#include "../Any/constants.h"

using std::function;
using ii887522::nitro::AnimatedAny;

namespace ii887522::viewify {

constexpr auto INITIAL_LIGHTNESS{ 1.f };
constexpr auto HOVERED_LIGHTNESS{ .9f };
constexpr auto PRESSED_LIGHTNESS{ .8f };

/// <summary>Not Thread Safe</summary>
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

  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    const Rect<int> rect;
    unsigned int a;

    /// <summary>Alpha animation duration</summary>
    unsigned int aDuration;

    /// <summary>Has set alpha animation duration</summary>
    bool hasSetADuration;

    /// <summary>Lightness animation duration</summary>
    unsigned int lightnessDuration;

    /// <summary>Has set lightness animation duration</summary>
    bool hasSetLightnessDuration;

    function<void()> onMouseMove;
    bool hasSetOnMouseMove;
    function<void()> onMouseOver;
    bool hasSetOnMouseOver;
    function<void()> onMouseOut;
    bool hasSetOnMouseOut;
    function<void()> onClick;
    bool hasSetOnClick;

   public:
    explicit Builder(const Rect<int>& = Rect{ Point{ 0, 0 }, Size{ 1, 1 } });

    constexpr Builder& setA(const unsigned int value) {
      a = value;
      return *this;
    }

    /// <summary>
    ///   <para>Alpha animation duration.</para>
    ///   <para>It must be called at least 1 time before building ButtonModel object.</para>
    /// </summary>
    /// <param name="value">It must not be assigned to 0</param>
    constexpr Builder& setADuration(const unsigned int value) {
      aDuration = value;
      hasSetADuration = true;
      return *this;
    }

    /// <summary>
    ///   <para>Lightness animation duration.</para>
    ///   <para>It must be called at least 1 time before building ButtonModel object.</para>
    /// </summary>
    /// <param name="value">It must not be assigned to 0</param>
    constexpr Builder& setLightnessDuration(const unsigned int value) {
      lightnessDuration = value;
      hasSetLightnessDuration = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building ButtonModel object.</summary>
    Builder& setOnMouseMove(const function<void()>&);

    /// <summary>It must be called at least 1 time before building ButtonModel object.</summary>
    Builder& setOnMouseOver(const function<void()>&);

    /// <summary>It must be called at least 1 time before building ButtonModel object.</summary>
    Builder& setOnMouseOut(const function<void()>&);

    /// <summary>It must be called at least 1 time before building ButtonModel object.</summary>
    Builder& setOnClick(const function<void()>&);

    /// <summary>It must be called to build ButtonModel object.</summary>
    ButtonModel build();

    friend class ButtonModel;
  };

 private:
  Rect<int> rect;
  State state;
  AnimatedAny<float> lightness;
  AnimatedAny<int> a;
  const function<void()> onMouseMove;
  const function<void()> onMouseOver;
  const function<void()> onMouseOut;
  const function<void()> onClick;

  explicit ButtonModel(const Builder&);

  constexpr void reactMouseMotionWhenInitial(const Point<int>& position) {
    if (!isOverlap(position, rect)) return;
    state = State::HOVERED;
    lightness.set(HOVERED_LIGHTNESS);
    onMouseMove();
    onMouseOver();
  }

  constexpr void reactMouseMotionWhenHovered(const Point<int>& position) {
    if (isOverlap(position, rect)) {
      onMouseMove();
      return;
    }
    state = State::INITIAL;
    lightness.set(INITIAL_LIGHTNESS);
    onMouseOut();
  }

  constexpr void reactMouseMotionWhenPressed(const Point<int>& position) {
    if (isOverlap(position, rect)) {
      onMouseMove();
      return;
    }
    state = State::INITIAL;
    lightness.set(INITIAL_LIGHTNESS);
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

  constexpr const function<void()>& getOnMouseOver() const {
    return onMouseOver;
  }

  constexpr const function<void()>& getOnMouseOut() const {
    return onMouseOut;
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
    lightness.set(PRESSED_LIGHTNESS);
  }

  constexpr void reactLeftMouseButtonUp() {
    if (state != State::PRESSED) return;
    state = State::HOVERED;
    lightness.set(HOVERED_LIGHTNESS);
    onClick();
  }

  constexpr void reactMouseLeaveWindow() {
    state = State::INITIAL;
    lightness.set(INITIAL_LIGHTNESS);
  }

  constexpr void show() {
    a.set(static_cast<int>(MAX_COLOR.a));
  }

  constexpr void hide() {
    state = State::INITIAL;
    lightness.teleport(INITIAL_LIGHTNESS);
    a.teleport(0);
  }

  constexpr void step(const unsigned int dt) {
    lightness.step(dt);
    a.step(dt);
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_MODEL_BUTTONMODEL_H_
