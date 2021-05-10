// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_RECTVIEW_H_
#define VIEWIFY_SRC_MAIN_VIEW_RECTVIEW_H_

#include <SDL.h>
#include <functional>
#include "../Any/View.h"
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Paint.h"
#include "../Struct/Color.h"
#include "../Any/Enums.h"

using std::function;

namespace ii887522::viewify {

// Not Thread Safe: it must not be assigned to integer
// See also ../Any/View.h for more details
class RectView final : public View {
  // remove copy semantics
  RectView(const RectView&) = delete;
  RectView& operator=(const RectView&) = delete;

  // remove move semantics
  RectView(RectView&&) = delete;
  RectView& operator=(RectView&&) = delete;

  Rect<int> model;
  Color<unsigned int> color;
  const function<Action(Rect<int>&, Color<unsigned int>&)> onPostRender;

 public:
  // Param renderer: it must not be assigned to nullptr or integer
  explicit RectView(SDL_Renderer*const renderer, const Point<int>& position, const Paint<int, unsigned int>&,
    const function<Action(Rect<int>&, Color<unsigned int>&)>& onPostRender = [](Rect<int>&, Color<unsigned int>&) {
      return Action::NONE;
    });

  void render() override;
  Action postRender() override;
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_VIEW_RECTVIEW_H_
