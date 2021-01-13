// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_RECTVIEW_H_
#define VIEWIFY_SRC_MAIN_VIEW_RECTVIEW_H_

#ifndef TEST

#include "../Any/View.h"
#include <SDL.h>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Paint.h"
#include "../Struct/Color.h"

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

  const Rect<int> model;
  const Color<unsigned int> color;

 public:
  // Param renderer: it must not be assigned to integer
  explicit RectView(SDL_Renderer*const renderer, const Point<int>& position, const Paint<int, unsigned int>&);

  void render() override;
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEW_RECTVIEW_H_
