// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_STRUCT_POINT_H_
#define VIEWIFY_SRC_MAIN_STRUCT_POINT_H_

#include <Struct/Vector.h>
#include "Size.h"

using ii887522::nitro::Vector;

namespace ii887522::viewify {

template <typename T> struct Point final {
  T x;
  T y;

  explicit constexpr Point() { }
  explicit constexpr Point(const T& x, const T& y) : x{ x }, y{ y } { }

  template <typename U> constexpr Point<T> operator+(const Point<U>& that) const {
    return Point{ x + that.x, y + that.y };
  }

  template <typename U> constexpr Point<T> operator+(const Vector<U>& speed) const {
    return Point{ x + speed.x, y + speed.y };
  }

  template <typename U> constexpr Point<T> operator+(const Size<U>& size) const {
    return Point{ x + size.w, y + size.h };
  }

  template <typename U> constexpr Point<T> operator-(const Point<U>& that) const {
    return Point{ x - that.x, y - that.y };
  }

  template <typename U> constexpr Point<T> operator-(const Vector<U>& speed) const {
    return Point{ x - speed.x, y - speed.y };
  }

  template <typename U> constexpr Point<T> operator-(const Size<U>& size) const {
    return Point{ x - size.w, y - size.h };
  }

  template <typename U> constexpr Point<T> operator*(const U& scale) const {
    return static_cast<Point<T>>(Point{ x * scale, y * scale });
  }

  template <typename U> explicit constexpr operator Point<U>() const {
    return Point<U>{ static_cast<U>(x), static_cast<U>(y) };
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_STRUCT_POINT_H_
