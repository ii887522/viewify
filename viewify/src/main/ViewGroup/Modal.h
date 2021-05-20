// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEWGROUP_MODAL_H_
#define VIEWIFY_SRC_MAIN_VIEWGROUP_MODAL_H_

#include <SDL.h>
#include <nitro/Any/Reactive.h>
#include <functional>
#include <vector>
#include "../Any/View.h"
#include "../View/ViewGroup.h"
#include "../Struct/Paint.h"
#include "../Struct/Size.h"
#include "../Struct/Point.h"
#include "../Model/ModalModel.h"
#include "../Any/Enums.h"

using std::function;
using std::vector;
using ii887522::nitro::Reactive;

namespace ii887522::viewify {

// Not Thread Safe: it must only be used in main thread
// See also ../View/ViewGroup.h for more details
class Modal final : public ViewGroup {
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

  void darkenScene();
  void renderBackground();

 public:
  // Param renderer: it must not be assigned to nullptr or integer
  // Param duration: animation duration and it must not be assigned to 0
  // Param isShowing: it must not be assigned to nullptr or integer
  // See also ../Any/View.h for more details
  explicit Modal(SDL_Renderer*const renderer, const Size<int>& sceneSize, const Point<int>& position, const Paint<int, unsigned int>& paint, Reactive<bool>*const isShowing,
    const unsigned int duration, const function<vector<View*>(ViewGroup&, SDL_Renderer*const)>& makeViews = [](ViewGroup&, SDL_Renderer*const) {
      return vector<View*>{ };
    });

  Action reactKeyDown(const SDL_KeyboardEvent& keyEvent) override;
  Action reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) override;
  Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) override;
  Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) override;
  Action reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) override;
  void step(const unsigned int dt) override;
  void render() override;
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_VIEWGROUP_MODAL_H_
