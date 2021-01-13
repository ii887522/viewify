// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_STRUCT_PAINT_H_
#define VIEWIFY_SRC_MAIN_STRUCT_PAINT_H_

#include "Size.h"
#include "Color.h"

namespace ii887522::viewify {

template <typename SIZE, typename COLOR> struct Paint final {
  Size<SIZE> size;
  Color<COLOR> color;

  explicit constexpr Paint() { }
  explicit constexpr Paint(const Size<SIZE>& size, const Color<COLOR>& color) : size{ size }, color{ color } { }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_STRUCT_PAINT_H_
