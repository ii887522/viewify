// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_STRUCT_COLOR_H_
#define VIEWIFY_SRC_MAIN_STRUCT_COLOR_H_

namespace ii887522::viewify {

template <typename T> struct Color final {
  T r;
  T g;
  T b;

  explicit constexpr Color() { }
  explicit constexpr Color(const T& r, const T& g, const T& b) : r{ r }, g{ g }, b{ b } { }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_STRUCT_COLOR_H_
