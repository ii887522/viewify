// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FUNCTIONS_TTF_EXT_H_
#define VIEWIFY_SRC_MAIN_FUNCTIONS_TTF_EXT_H_

#ifndef TEST

#include "../Struct/GlyphMetrics.h"
#include <SDL_ttf.h>

namespace ii887522::viewify {

// Param font: it must not be assigned to nullptr or integer
// See also ../Struct/GlyphMetrics.h for more details
GlyphMetrics getGlyphMetrics(TTF_Font*const font, const char ch);

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_FUNCTIONS_TTF_EXT_H_
