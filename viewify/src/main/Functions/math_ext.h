// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FUNCTIONS_MATH_EXT_H_
#define VIEWIFY_SRC_MAIN_FUNCTIONS_MATH_EXT_H_

#include <nitro/Struct/Range.h>
#include <nitro/Functions/math_ext.h>
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
  return isOverlap(self.position, that) || isOverlap(Point{ self.position.x + self.size.w - static_cast<T>(1), self.position.y }, that) ||
    isOverlap(Point{ self.position.x + self.size.w - static_cast<T>(1), self.position.y + self.size.h - static_cast<T>(1) }, that) ||
    isOverlap(Point{ self.position.x, self.position.y + self.size.h - static_cast<T>(1) }, that);
}

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_FUNCTIONS_MATH_EXT_H_
