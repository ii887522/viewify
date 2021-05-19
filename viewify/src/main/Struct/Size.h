// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_STRUCT_SIZE_H_
#define VIEWIFY_SRC_MAIN_STRUCT_SIZE_H_

namespace ii887522::viewify {

template <typename T> struct Size final {
  T w;
  T h;

  explicit constexpr Size() { }
  explicit constexpr Size(const T& w, const T& h) : w{ w }, h{ h } { }

  template <typename U> explicit constexpr operator Size<U>() const {
    return Size{ static_cast<U>(w), static_cast<U>(h) };
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_STRUCT_SIZE_H_
