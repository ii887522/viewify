// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_STRUCT_GLYPHMETRICS_H_
#define VIEWIFY_SRC_MAIN_STRUCT_GLYPHMETRICS_H_

#include "BoundingBox.h"

namespace ii887522::viewify {

/// <summary>Glyph is a single part of a texture atlas.</summary>
struct GlyphMetrics final {
  BoundingBox<int> box;
  int advance;

  explicit constexpr GlyphMetrics() { }
  explicit constexpr GlyphMetrics(const BoundingBox<int>& box, const int advance) : box{ box }, advance{ advance } { }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_STRUCT_GLYPHMETRICS_H_
