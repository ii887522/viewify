// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_
#define VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_

#ifndef TEST

#include <SDL.h>
#include <initializer_list>
#include "../Any/View.h"

using std::initializer_list;

namespace ii887522::viewify {

// It is a special view that can contain other views (called children).
// Not Thread Safe: it must not be assigned to integer
// See also ../Any/View.h for more details
template <unsigned int viewCount> class ViewGroup : public View {
  // remove copy semantics
  ViewGroup(const ViewGroup&) = delete;
  ViewGroup& operator=(const ViewGroup&) = delete;

  // remove move semantics
  ViewGroup& operator=(ViewGroup&&) = delete;

  // See also ../Any/View.h for more details
  View* views[viewCount];

 public:
  // Param renderer: it must not be assigned to integer
  // See also ../Any/View.h for more details
  explicit ViewGroup(SDL_Renderer*const renderer, const Point<int>& position, const initializer_list<View*>& views) :
    View{ renderer, position } {
    memcpy(this->views, views.begin(), viewCount * sizeof(View*));
    for (auto view : views) {
      view->getPosition().watch([view, position](const Point<int>& value, const int handlerI) {
        view->getPosition().set(value + position, handlerI);
      });
      view->getPosition().set(view->getPosition().get());
    }
  }

  // See also ../Any/View.h for more details
  explicit ViewGroup(ViewGroup&& that) : View{ that.getRenderer(), that.getPosition() } {
    memcpy(views, that.views, viewCount * sizeof(View*));
    memset(that.views, 0, viewCount * sizeof(View*));
  }

  void reactKeyDown(const SDL_KeyboardEvent& keyEvent) override {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->reactKeyDown(keyEvent);
  }

  void reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) override {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->reactMouseMotion(motionEvent);
  }

  void reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) override {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->reactLeftMouseButtonDown(buttonEvent);
  }

  void reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) override {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->reactLeftMouseButtonUp(buttonEvent);
  }

  void reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) override {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->reactMouseLeaveWindow(windowEvent);
  }

  void show() final {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->show();
  }

  void hide() final {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->hide();
  }

  void step(const unsigned int dt) override {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->step(dt);
  }

  void checkAndReactHits(const unsigned int dt) override {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->checkAndReactHits(dt);
  }

  void render() override {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->render();
  }

  ~ViewGroup() {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) delete views[i];
  }
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_
