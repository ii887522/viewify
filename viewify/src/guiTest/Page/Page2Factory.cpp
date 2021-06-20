// Copyright ii887522

#ifdef GUI_TEST

#include "Page2Factory.h"
#include <nitro/nitro.h>
#include <SDL.h>
#include <stdexcept>
#include <vector>
#include <string>
#include "../../main/Factory/PageFactory.h"
#include "../Any/Enums.h"
#include "../../main/Any/View.h"
#include "../../main/View/ViewGroup.h"
#include "../../main/ViewGroup/Page.h"
#include "../../main/Struct/Paint.h"
#include "../../main/Struct/Point.h"
#include "../../main/Struct/Size.h"
#include "../../main/Struct/Color.h"
#include "../Any/constants.h"
#include "../../main/View/Button.h"
#include "../../main/View/Text.h"
#include "../Any/FontName.h"
#include "../../main/ComponentFactory/ListFactory.h"

using ii887522::nitro::Pair;
using std::runtime_error;
using std::vector;
using std::string;

namespace ii887522::viewify {

Page2Factory* Page2Factory::Builder::build() {
  if (!hasSetRenderer) throw runtime_error{ "Page2Factory renderer is required!" };
  if (!hasSetGlyphAtlas) throw runtime_error{ "Page2Factory glyphAtlas is required!" };
  if (!hasSetPointer) throw runtime_error{ "Page2Factory pointer is required!" };
  if (!hasSetCurrentPath) throw runtime_error{ "Page2Factory currentPath is required!" };
  return new Page2Factory{ *this };
}

Page2Factory::Page2Factory(const Builder& builder) : PageFactory{ PageFactory::Builder{ builder.renderer }.setPointer(builder.pointer).setCurrentPath(builder.currentPath) },
  glyphAtlas{ *builder.glyphAtlas } { }

Page<Path>* Page2Factory::make(const Size<int>& size) {
  return Page<Path>::Builder{ getRenderer(), Point{ 0, 0 }, [=](ViewGroup*const, SDL_Renderer*const p_renderer) {
    return vector<View*>{
      Text::Builder{ Point{ 16, 16 }, "List" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
      ListFactory{ p_renderer, Point{ 16, 64 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(32u)
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ " " }, string{ "Item 1" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 192, 64 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(32u)
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ " " }, string{ "Item 1" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 368, 64 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyPaint(Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ " " }, string{ "Item 1" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 464, 64 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyPaint(Paint{ Size{ 16, 16 }, Color{ 192u, 0u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ " " }, string{ "Item 1" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 560, 64 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyPaint(Paint{ Size{ 16, 16 }, Color{ 192u, 192u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ " " }, string{ "Item 1" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 656, 64 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyPaint(Paint{ Size{ 16, 16 }, Color{ 192u, 192u, 192u, 255u } })
        .setTextPairs({ Pair{ string{ " " }, string{ "Item 1" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 752, 64 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyPaint(Paint{ Size{ 16, 16 }, Color{ 192u, 192u, 192u, 128u } })
        .setTextPairs({ Pair{ string{ " " }, string{ "Item 1" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 848, 64 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyPaddings({ Size{ 1, 1 }, Size{ 1, 1 } })
        .setKeyPaint(Paint{ Size{ 16, 16 }, Color{ 192u, 192u, 192u, 128u } })
        .setTextPairs({ Pair{ string{ " " }, string{ "Item 1" } }, Pair{ string{ " " }, string{ "Item 2" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 944, 64 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyPaddings({ Size{ 1, 1 }, Size{ 1, 1 }, Size{ 1, 1 } })
        .setKeyPaint(Paint{ Size{ 16, 16 }, Color{ 192u, 192u, 192u, 128u } })
        .setTextPairs({ Pair{ string{ " " }, string{ "Item 1" } }, Pair{ string{ " " }, string{ "Item 2" } }, Pair{ string{ " " }, string{ "Item 3" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 1040, 64 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyPaddings({ Size{ 1, 1 }, Size{ 1, 1 }, Size{ 1, 1 } })
        .setKeyPaint(Paint{ Size{ 16, 16 }, Color{ 192u, 192u, 192u, 128u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 1136, 64 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyPaddings({ Size{ 12, 8 }, Size{ 12, 8 }, Size{ 12, 8 } })
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 128u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 16, 192 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyMargin(Size{ 16, 16 })
        .setKeyPaddings({ Size{ 12, 8 }, Size{ 12, 8 }, Size{ 12, 8 } })
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 128u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .make(),
      ListFactory{ p_renderer, Point{ 144, 192 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyMargin(Size{ 16, 16 })
        .setKeyPaddings({ Size{ 12, 8 }, Size{ 12, 8 }, Size{ 12, 8 } })
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 128u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .setTextColorPair(Pair{ Color{ 255u, 0u, 0u, 255u }, Color{ 0u, 0u, 0u, 255u } })
        .make(),
      ListFactory{ p_renderer, Point{ 272, 192 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyMargin(Size{ 16, 16 })
        .setKeyPaddings({ Size{ 12, 8 }, Size{ 12, 8 }, Size{ 12, 8 } })
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .setTextColorPair(Pair{ Color{ 255u, 255u, 0u, 255u }, Color{ 0u, 0u, 0u, 255u } })
        .make(),
      ListFactory{ p_renderer, Point{ 400, 192 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyMargin(Size{ 16, 16 })
        .setKeyPaddings({ Size{ 12, 8 }, Size{ 12, 8 }, Size{ 12, 8 } })
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .setTextColorPair(Pair{ Color{ 255u, 255u, 255u, 255u }, Color{ 0u, 0u, 0u, 255u } })
        .make(),
      ListFactory{ p_renderer, Point{ 528, 192 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyMargin(Size{ 16, 16 })
        .setKeyPaddings({ Size{ 12, 8 }, Size{ 12, 8 }, Size{ 12, 8 } })
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .setTextColorPair(Pair{ Color{ 255u, 255u, 255u, 128u }, Color{ 0u, 0u, 0u, 255u } })
        .make(),
      ListFactory{ p_renderer, Point{ 656, 192 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyMargin(Size{ 16, 16 })
        .setKeyPaddings({ Size{ 12, 8 }, Size{ 12, 8 }, Size{ 12, 8 } })
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .setTextColorPair(Pair{ Color{ 255u, 255u, 255u, 128u }, Color{ 192u, 0u, 0u, 255u } })
        .make(),
      ListFactory{ p_renderer, Point{ 784, 192 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyMargin(Size{ 16, 16 })
        .setKeyPaddings({ Size{ 12, 8 }, Size{ 12, 8 }, Size{ 12, 8 } })
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .setTextColorPair(Pair{ Color{ 255u, 255u, 255u, 128u }, Color{ 192u, 192u, 0u, 255u } })
        .make(),
      ListFactory{ p_renderer, Point{ 912, 192 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyMargin(Size{ 16, 16 })
        .setKeyPaddings({ Size{ 12, 8 }, Size{ 12, 8 }, Size{ 12, 8 } })
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .setTextColorPair(Pair{ Color{ 255u, 255u, 255u, 128u }, Color{ 192u, 192u, 192u, 255u } })
        .make(),
      ListFactory{ p_renderer, Point{ 1040, 192 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setKeyMargin(Size{ 16, 16 })
        .setKeyPaddings({ Size{ 12, 8 }, Size{ 12, 8 }, Size{ 12, 8 } })
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .setTextColorPair(Pair{ Color{ 255u, 255u, 255u, 128u }, Color{ 192u, 192u, 192u, 128u } })
        .make(),
      ListFactory{ p_renderer, Point{ 1168, 192 } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_BELL))
        .setFontSize(16u)
        .setKeyMargin(Size{ 16, 16 })
        .setKeyPaddings({ Size{ 12, 8 }, Size{ 12, 8 }, Size{ 12, 8 } })
        .setKeyPaint(Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 255u } })
        .setTextPairs({ Pair{ string{ "1" }, string{ "Item 1" } }, Pair{ string{ "2" }, string{ "Item 2" } }, Pair{ string{ "3" }, string{ "Item 3" } } })
        .setTextColorPair(Pair{ Color{ 0u, 0u, 0u, 255u }, Color{ 192u, 192u, 192u, 128u } })
        .make(),
      Button::Builder{ p_renderer, Point{ (size.w - NAV_BUTTON_SIZE.w) >> 1u, size.h - NAV_BUTTON_SIZE.h - 16 }, Paint{ NAV_BUTTON_SIZE, Color{ 192u, 192u, 255u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          getCurrentPath().set(Path::PAGE1);
        })
        .setOnMouseOut([this]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ size.w >> 1u, size.h - NAV_BUTTON_SIZE.h - 2 }, "Prev page" }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setColor(Color{ 0u, 0u, 0u, 255u })
        .setAlign(Align::CENTER)
        .build(),
    };
  } }.setPath(Path::PAGE2).setCurrentPath(&getCurrentPath()).build();
}

}  // namespace ii887522::viewify

#endif
