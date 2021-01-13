// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_STRUCT_RECT_H_
#define VIEWIFY_SRC_MAIN_STRUCT_RECT_H_

#include "Point.h"
#include "Size.h"

namespace ii887522::viewify {

template <typename T> struct Rect final {
  Point<T> position;
  Size<T> size;

  explicit constexpr Rect() { }
  explicit constexpr Rect(const Point<T>& position, const Size<T>& size) : position{ position }, size{ size } { }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_STRUCT_RECT_H_
