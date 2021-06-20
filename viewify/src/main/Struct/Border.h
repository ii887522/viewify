// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_STRUCT_BORDER_H_
#define VIEWIFY_SRC_MAIN_STRUCT_BORDER_H_

#include "Rect.h"
#include "Point.h"
#include "Size.h"

namespace ii887522::viewify {

struct Border final {
  // remove copy semantics
  Border(const Border&) = delete;
  Border& operator=(const Border&) = delete;

  // remove move semantics
  Border(Border&&) = delete;
  Border& operator=(Border&&) = delete;

  const Rect<int> rect;
  const int width;

  explicit constexpr Border(const Rect<int>& rect = Rect{ Point{ 0, 0 }, Size{ 3, 3 } }, const int width = 1) : rect{ rect }, width{ width } { }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_STRUCT_BORDER_H_
