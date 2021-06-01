// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_STRUCT_SPRITE_H_
#define VIEWIFY_SRC_MAIN_STRUCT_SPRITE_H_

#include "Rect.h"

namespace ii887522::viewify {

/// <summary>It is a single part of a texture atlas.</summary>
struct Sprite final {
  unsigned int atlasI;
  Rect<int> rect;
  bool isRotated;

  explicit constexpr Sprite() { }
  explicit constexpr Sprite(const unsigned int atlasI, const Rect<int>& rect, const bool isRotated = false) : atlasI{ atlasI }, rect{ rect }, isRotated{ isRotated } { }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_STRUCT_SPRITE_H_
