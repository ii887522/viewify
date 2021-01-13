// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_STRUCT_BORDER_H_
#define VIEWIFY_SRC_MAIN_STRUCT_BORDER_H_

#include "Rect.h"

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

  explicit constexpr Border(const Rect<int>& rect, const int width) : rect{ rect }, width{ width } { }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_STRUCT_BORDER_H_
