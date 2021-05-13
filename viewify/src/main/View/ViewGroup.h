// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_
#define VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_

#include <SDL.h>
#include <vector>
#include <initializer_list>
#include "../Any/View.h"
#include "../Any/Enums.h"

using std::initializer_list;
using std::vector;

namespace ii887522::viewify {

// It is a special view that can contain other views (called children).
// Not Thread Safe: it must not be assigned to integer
// See also ../Any/View.h for more details
class ViewGroup : public View {
  // remove copy semantics
  ViewGroup(const ViewGroup&) = delete;
  ViewGroup& operator=(const ViewGroup&) = delete;

  // remove move semantics
  ViewGroup& operator=(ViewGroup&&) = delete;

  // See also ../Any/View.h for more details
  vector<View*> views;

 public:
  // Param renderer: it must not be assigned to nullptr or integer
  // See also ../Any/View.h for more details
  explicit ViewGroup(SDL_Renderer*const renderer, const Point<int>& position, const initializer_list<View*>& views);

  // See also ../Any/View.h for more details
  explicit ViewGroup(ViewGroup&& that) noexcept;

  void add(View*const);
  Action reactKeyDown(const SDL_KeyboardEvent& keyEvent) override;
  Action reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) override;
  Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) override;
  Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) override;
  Action reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) override;
  void show() final;
  void hide() final;
  void step(const unsigned int dt) override;
  void checkAndReactHits(const unsigned int dt) override;
  void render() override;
  Action postRender() override;
  ~ViewGroup();
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_
