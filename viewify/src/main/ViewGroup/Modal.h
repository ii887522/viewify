// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEWGROUP_MODAL_H_
#define VIEWIFY_SRC_MAIN_VIEWGROUP_MODAL_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <nitro/nitro.h>
#include <functional>
#include <vector>
#include "../Any/View.h"
#include "../View/ViewGroup.h"
#include "../Struct/Paint.h"
#include "../Struct/Size.h"
#include "../Struct/Point.h"
#include "../Model/ModalModel.h"
#include "../Any/Enums.h"
#include "../Any/typedefs.h"
#include "../Any/constants.h"

using std::function;
using std::vector;
using ii887522::nitro::Reactive;

namespace ii887522::viewify {

/// <summary>
///   <para>Not Thread Safe: it must only be used in main thread</para>
///   <para>See also ../View/ViewGroup.h for more details</para>
/// </summary>
class Modal final : public ViewGroup {
  // remove copy semantics
  Modal(const Modal&) = delete;
  Modal& operator=(const Modal&) = delete;

  // remove move semantics
  Modal(Modal&&) = delete;
  Modal& operator=(Modal&&) = delete;

 public:
  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    SDL_Renderer* renderer;
    bool hasSetRenderer;
    Size<int> sceneSize;
    bool hasSetSceneSize;
    const Point<int> position;
    const Paint<int, unsigned int> paint;
    Reactive<bool>* isShowing;
    bool hasSetShowing;
    unsigned int duration;
    const MakeViews makeViews;

   public:
    explicit Builder(const Point<int>& position = Point{ 0, 0 }, const Paint<int, unsigned int>& paint = Paint{ Size{ 1, 1 }, Color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) } },
      const MakeViews& = [](ViewGroup*const, SDL_Renderer*const) {
        return vector<View*>{ };
      });

    /// <summary>It must be called at least 1 time before building Modal object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setRenderer(SDL_Renderer*const value) {
      renderer = value;
      hasSetRenderer = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Modal object.</summary>
    constexpr Builder& setSceneSize(const Size<int>& value) {
      sceneSize = value;
      hasSetSceneSize = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Modal object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setShowing(Reactive<bool>*const value) {
      isShowing = value;
      hasSetShowing = true;
      return *this;
    }

    constexpr Builder& setDuration(const unsigned int value) {
      duration = value;
      return *this;
    }

    /// <summary>It must be called to build Modal object.</summary>
    Modal* build();

    friend class Modal;
  };

 private:
  const Size<int> sceneSize;
  const Paint<int, unsigned int> paint;
  Reactive<bool>& isShowing;
  ModalModel model;

  explicit Modal(const Builder&);
  void darkenScene();
  void renderBackground();

 public:
  Action reactKeyDown(const SDL_KeyboardEvent& keyEvent) override;
  Action reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) override;
  Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) override;
  Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) override;
  Action reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) override;
  void step(const unsigned int dt) override;
  Action preRender() override;
  void render() override;
  Action postRender() override;
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEWGROUP_MODAL_H_
