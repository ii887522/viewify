// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_BUTTON_H_
#define VIEWIFY_SRC_MAIN_VIEW_BUTTON_H_

#include <SDL.h>
#include <functional>
#include "../Any/View.h"
#include "../Struct/Point.h"
#include "../Model/ButtonModel.h"
#include "../Struct/Paint.h"
#include "../Any/Enums.h"

using std::function;

namespace ii887522::viewify {

// Not Thread Safe: it must only be used in main thread
// See also ../Any/View.h for more details
class Button final : public View {
  // remove copy semantics
  Button(const Button&) = delete;
  Button& operator=(const Button&) = delete;

  // remove move semantics
  Button(Button&&) = delete;
  Button& operator=(Button&&) = delete;

 public:
  // Not Thread Safe
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    SDL_Renderer*const renderer;
    const Point<int> position;
    const Paint<int, unsigned int> paint;
    unsigned int a;
    unsigned int aDuration;  // alpha animation duration
    bool hasSetADuration;
    unsigned int lightnessDuration;  // lightness animation duration
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
    // Param renderer: it must not be assigned to integer
    explicit Builder(SDL_Renderer*const renderer, const Point<int>& position, const Paint<int, unsigned int>&);

    constexpr Builder& setA(const unsigned int value) {
      a = value;
      return *this;
    }

    // Alpha animation duration. It must be called at least 1 time before building Button object.
    // Param value: it must not be assigned to 0
    constexpr Builder& setADuration(const unsigned int value) {
      aDuration = value;
      hasSetADuration = true;
      return *this;
    }

    // Lightness animation duration. It must be called at least 1 time before building Button object.
    // Param value: it must not be assigned to 0
    constexpr Builder& setLightnessDuration(const unsigned int value) {
      lightnessDuration = value;
      hasSetLightnessDuration = true;
      return *this;
    }

    // It must be called at least 1 time before building Button object.
    Builder& setOnMouseMove(const function<void()>&);

    // It must be called at least 1 time before building Button object.
    Builder& setOnMouseOver(const function<void()>&);

    // It must be called at least 1 time before building Button object.
    Builder& setOnMouseOut(const function<void()>&);

    // It must be called at least 1 time before building Button object.
    Builder& setOnClick(const function<void()>&);

    // It must be called to build Button object.
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

#endif  // VIEWIFY_SRC_MAIN_VIEW_BUTTON_H_
