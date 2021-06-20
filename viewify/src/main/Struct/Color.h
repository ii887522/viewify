// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_STRUCT_COLOR_H_
#define VIEWIFY_SRC_MAIN_STRUCT_COLOR_H_

namespace ii887522::viewify {

template <typename T> struct Color final {
  T r;
  T g;
  T b;
  T a;

  explicit constexpr Color() { }
  explicit constexpr Color(const T& r, const T& g, const T& b, const T& a) : r{ r }, g{ g }, b{ b }, a{ a } { }

  template <typename U> explicit constexpr operator Color<U>() const {
    return Color<U>{ static_cast<U>(r), static_cast<U>(g), static_cast<U>(b), static_cast<U>(a) };
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_STRUCT_COLOR_H_
