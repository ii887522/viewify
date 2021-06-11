// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FUNCTIONS_MATH_EXT_H_
#define VIEWIFY_SRC_MAIN_FUNCTIONS_MATH_EXT_H_

#include <nitro/nitro.h>
#include "../Struct/Point.h"
#include "../Struct/Rect.h"

using ii887522::nitro::Range;
using ii887522::nitro::isOverlapX;
using ii887522::nitro::isOverlapY;

namespace ii887522::viewify {

template <typename T> constexpr bool isOverlap(const Point<T>& point, const Rect<T>& rect) {
  return isOverlapX(point.x, Range{ rect.position.x, rect.position.x + rect.size.w }) &&
    isOverlapY(point.y, Range{ rect.position.y, rect.position.y + rect.size.h });
}

template <typename T> constexpr bool isOverlap(const Rect<T>& self, const Rect<T>& that) {
  return self.position.x + self.size.w > that.position.x && self.position.x < that.position.x + that.size.w && self.position.y + self.size.h > that.position.y &&
    self.position.y < that.position.y + that.size.h;
}

constexpr int distanceSqr(const Point<int>& l, const Point<int>& r) {
  return (r.x - l.x) * (r.x - l.x) + (r.y - l.y) * (r.y - l.y);
}

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_FUNCTIONS_MATH_EXT_H_
