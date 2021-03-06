// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_STRUCT_BOUNDINGBOX_H_
#define VIEWIFY_SRC_MAIN_STRUCT_BOUNDINGBOX_H_

#include <nitro/nitro.h>

using ii887522::nitro::Range;

namespace ii887522::viewify {

template <typename T> struct BoundingBox final {
  Range<T> xRange;
  Range<T> yRange;

  explicit constexpr BoundingBox() { }
  explicit constexpr BoundingBox(const Range<T>& xRange, const Range<T>& yRange) : xRange{ xRange }, yRange{ yRange } { }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_STRUCT_BOUNDINGBOX_H_
