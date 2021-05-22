// Copyright ii887522

#ifndef TEST

#include "ttf_ext.h"
#include "../Struct/GlyphMetrics.h"
#include <SDL_ttf.h>

namespace ii887522::viewify {

GlyphMetrics getGlyphMetrics(TTF_Font*const font, const char ch) {
  GlyphMetrics metrics;
  TTF_GlyphMetrics(font, ch, &metrics.box.xRange.min, &metrics.box.xRange.max, &metrics.box.yRange.min, &metrics.box.yRange.max, &metrics.advance);
  return metrics;
}

}  // namespace ii887522::viewify

#endif
