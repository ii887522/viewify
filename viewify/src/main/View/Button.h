// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_BUTTON_H_
#define VIEWIFY_SRC_MAIN_VIEW_BUTTON_H_

#ifndef CONSOLE_TEST

#include <nitro/nitro.h>
#include <SDL.h>
#include <functional>
#include "../Any/View.h"
#include "../Struct/Point.h"
#include "../Model/ButtonModel.h"
#include "../Struct/Paint.h"
#include "../Struct/Size.h"
#include "../Struct/Color.h"
#include "../Any/constants.h"

using std::function;
using ii887522::nitro::AnimationController;
using ii887522::nitro::Action;

namespace ii887522::viewify {

/// <summary>
///   <para>Not Thread Safe: it must only be used in main thread</para>
///   <para>See also ../Any/View.h for more details</para>
/// </summary>
class Button final : public View {
  // remove copy semantics
  Button(const Button&) = delete;
  Button& operator=(const Button&) = delete;

  // remove move semantics
  Button(Button&&) = delete;
  Button& operator=(Button&&) = delete;

 public:
  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    AnimationController* animationController;
    bool hasSetAnimationController;
    SDL_Renderer* renderer;
    bool hasSetRenderer;
    const Point<int> position;
    const Paint<int, unsigned int> paint;
    unsigned int a;

    /// <summary>Alpha animation duration</summary>
    unsigned int aDuration;

    bool hasSetADuration;

    /// <summary>Lightness animation duration</summary>
    unsigned int lightnessDuration;

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
    explicit Builder(const Point<int>& position = Point{ 0, 0 }, const Paint<int, unsigned int>& = Paint{ Size{ 1, 1 }, Color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) } });

    /// <summary>It must be called at least 1 time before building Button object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setAnimationController(AnimationController*const value) {
      animationController = value;
      hasSetAnimationController = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Button object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setRenderer(SDL_Renderer*const value) {
      renderer = value;
      hasSetRenderer = true;
      return *this;
    }

    constexpr Builder& setA(const unsigned int value) {
      a = value;
      return *this;
    }

    /// <summary>Alpha animation duration.</summary>
    /// <param name="value">It must not be assigned to 0</param>
    constexpr Builder& setADuration(const unsigned int value) {
      aDuration = value;
      return *this;
    }

    /// <summary>
    ///   <para>Lightness animation duration.</para>
    ///   <para>It must be called at least 1 time before building Button object.</para>
    /// </summary>
    /// <param name="value">It must not be assigned to 0</param>
    constexpr Builder& setLightnessDuration(const unsigned int value) {
      lightnessDuration = value;
      hasSetLightnessDuration = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Button object.</summary>
    Builder& setOnMouseMove(const function<void()>&);

    /// <summary>It must be called at least 1 time before building Button object.</summary>
    Builder& setOnMouseOver(const function<void()>&);

    /// <summary>It must be called at least 1 time before building Button object.</summary>
    Builder& setOnMouseOut(const function<void()>&);

    /// <summary>It must be called at least 1 time before building Button object.</summary>
    Builder& setOnClick(const function<void()>&);

    /// <summary>It must be called to build Button object.</summary>
    Button* build();

    friend class Button;
  };

 private:
  ButtonModel model;
  const Color<unsigned int> color;

  explicit Button(const Builder&);

 public:
  Action reactMouseMotion(const SDL_MouseMotionEvent&) override;
  Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent&) override;
  Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent&) override;
  Action reactMouseLeaveWindow(const SDL_WindowEvent&) override;
  void show() override;
  void hide() override;
  void step(const unsigned int dt) override;
  void render() override;
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEW_BUTTON_H_
