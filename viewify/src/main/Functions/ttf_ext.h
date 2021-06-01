// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FUNCTIONS_TTF_EXT_H_
#define VIEWIFY_SRC_MAIN_FUNCTIONS_TTF_EXT_H_

#ifndef CONSOLE_TEST

#include "../Struct/GlyphMetrics.h"
#include <SDL_ttf.h>

namespace ii887522::viewify {

/// <summary>See also ../Struct/GlyphMetrics.h for more details</summary>
/// <param name="font">It must not be assigned to nullptr or integer</param>
GlyphMetrics getGlyphMetrics(TTF_Font*const font, const char ch);

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_FUNCTIONS_TTF_EXT_H_
