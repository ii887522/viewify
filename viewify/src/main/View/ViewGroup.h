// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_
#define VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_

#include <SDL.h>
#include <initializer_list>
#include "../Any/View.h"
#include "../Any/Enums.h"

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

  Action reactKeyDown(const SDL_KeyboardEvent& keyEvent) override {
    for (auto i{ static_cast<int>(sizeof views / sizeof(View*) - 1) }; i >= 0; --i) {
      if (views[i]->reactKeyDown(keyEvent) == Action::CONSUME_EVENT) break;
    }
    return Action::NONE;
  }

  Action reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) override {
    for (auto i{ static_cast<int>(sizeof views / sizeof(View*) - 1) }; i >= 0; --i) {
      if (views[i]->reactMouseMotion(motionEvent) == Action::CONSUME_EVENT) break;
    }
    return Action::NONE;
  }

  Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) override {
    for (auto i{ static_cast<int>(sizeof views / sizeof(View*) - 1) }; i >= 0; --i) {
      if (views[i]->reactLeftMouseButtonDown(buttonEvent) == Action::CONSUME_EVENT) break;
    }
    return Action::NONE;
  }

  Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) override {
    for (auto i{ static_cast<int>(sizeof views / sizeof(View*) - 1) }; i >= 0; --i) {
      if (views[i]->reactLeftMouseButtonUp(buttonEvent) == Action::CONSUME_EVENT) break;
    }
    return Action::NONE;
  }

  Action reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) override {
    for (auto i{ static_cast<int>(sizeof views / sizeof(View*) - 1) }; i >= 0; --i) {
      if (views[i]->reactMouseLeaveWindow(windowEvent) == Action::CONSUME_EVENT) break;
    }
    return Action::NONE;
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

  Action postRender() override {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) {
      if (views[i]->postRender() == Action::QUIT) return Action::QUIT;
    }
    return Action::NONE;
  }

  ~ViewGroup() {
    for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) delete views[i];
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_
