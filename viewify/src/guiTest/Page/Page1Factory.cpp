// Copyright ii887522

#ifdef GUI_TEST

#include "Page1Factory.h"
#include <iostream>
#include <stdexcept>
#include <SDL.h>
#include <vector>
#include <chrono>  // NOLINT(build/c++11)
#include "../../main/Factory/PageFactory.h"
#include "../../main/Any/View.h"
#include "../../main/View/ViewGroup.h"
#include "../../main/Struct/Size.h"
#include "../../main/Struct/Point.h"
#include "../../main/Struct/Rect.h"
#include "../../main/Struct/Color.h"
#include "../../main/View/Text.h"
#include "../../main/Text/Score.h"
#include "../../main/View/BorderView.h"
#include "../../main/Any/Enums.h"
#include "../Any/Enums.h"
#include "../../main/View/Button.h"
#include "../../main/View/Image.h"
#include "../../main/View/RectView.h"
#include "../../main/ViewGroup/Modal.h"
#include "../../main/ViewGroup/Page.h"
#include "../../main/Functions/sdl_ext.h"
#include "../Any/FontName.h"
#include "../Any/SpriteName.h"
#include "../Any/constants.h"

using std::cout;
using std::vector;
using std::chrono::high_resolution_clock;
using std::runtime_error;

namespace ii887522::viewify {

Page1Factory* Page1Factory::Builder::build() {
  if (!hasSetRenderer) throw runtime_error{ "Page1Factory renderer is required!" };
  if (!hasSetTextureAtlas) throw runtime_error{ "Page1Factory textureAtlas is required!" };
  if (!hasSetGlyphAtlas) throw runtime_error{ "Page1Factory glyphAtlas is required!" };
  if (!hasSetPointer) throw runtime_error{ "Page1Factory pointer is required!" };
  if (!hasSetCurrentPath) throw runtime_error{ "Page1Factory currentPath is required!" };
  return new Page1Factory{ *this };
}

Page1Factory::Page1Factory(const Builder& builder) : PageFactory{ PageFactory::Builder{ builder.renderer }.setPointer(builder.pointer).setCurrentPath(builder.currentPath) },
  canIncrementScore0{ false }, canResetScore0{ false }, canIncrementScore1{ false }, canResetScore1{ false }, isModal1Showing{ false }, isModal2Showing{ false }, isModal3Showing{ false }
  , isModal4Showing{ false }, isModal5Showing{ false }, isModal6Showing{ false }, isModal7Showing{ false }, isModal8Showing{ false }, map{ Size{ 8u, 8u } }, colorComponents{ 0u, 255u },
  randomEngine{ static_cast<unsigned int>(high_resolution_clock::now().time_since_epoch().count()) }, textureAtlas{ *builder.textureAtlas }, glyphAtlas{ *builder.glyphAtlas } { }

Page<Path>* Page1Factory::make(const Size<int>& size) {
  constexpr Size<int> MODAL_SIZE_1{ 512, 256 };
  constexpr Size<int> MODAL_SIZE_2{ 384, 192 };
  return Page<Path>::Builder{ getRenderer(), Point{ 0, 0 }, [=](ViewGroup*const self, SDL_Renderer*const p_renderer) {
    return vector<View*>{
      Text::Builder{ Point{ 16, 16 }, "Text" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
      Text::Builder{ Point{ 16, 64 }, "Body text 1" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Text::Builder{ Point{ 112, 64 }, "Body text 2" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Text::Builder{ Point{ 208, 64 }, "Red text" }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setColor(Color{ 192u, 0u, 0u, 255u })
        .build(),
      Text::Builder{ Point{ 280, 64 }, "Yellow text" }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setColor(Color{ 192u, 192u, 0u, 255u })
        .build(),
      Text::Builder{ Point{ 368, 64 }, "Gray text" }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setColor(Color{ 192u, 192u, 192u, 255u })
        .build(),
      Text::Builder{ Point{ 448, 64 }, "Semi-transparent text" }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setColor(Color{ 192u, 192u, 192u, 128u })
        .build(),
      Text::Builder{ Point{ 608, 64 }, "Animated text 1" }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setColor(Color{ 192u, 192u, 192u, 128u })
        .setA(0u)
        .setDuration(256u)
        .build(),
      Text::Builder{ Point{ 736, 64 }, "Animated text 2" }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setColor(Color{ 192u, 192u, 192u, 128u })
        .setA(0u)
        .setDuration(512u)
        .build(),
      Text::Builder{ Point{ 864, 64 }, "Animated text 3" }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_BELL))
        .setFontSize(18u)
        .setColor(Color{ 192u, 192u, 192u, 128u })
        .setA(0u)
        .setDuration(512u)
        .build(),
      Text::Builder{ Point{ 16, 112 }, "Score" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
      Score::Builder{ Point{ 76, 160 }, Color{ 0u, 0u, 0u, 255u } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(32u)
        .setMax(4u)
        .setCanIncrement(&canIncrementScore0)
        .setCanReset(&canResetScore0)
        .build(),
      Score::Builder{ Point{ 224, 160 }, Color{ 0u, 0u, 0u, 255u } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(32u)
        .setMax(4u)
        .setCanIncrement(&canIncrementScore0)
        .setCanReset(&canResetScore0)
        .build(),
      Score::Builder{ Point{ 336, 168 }, Color{ 0u, 0u, 0u, 255u } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setMax(4u)
        .setCanIncrement(&canIncrementScore0)
        .setCanReset(&canResetScore0)
        .build(),
      Score::Builder{ Point{ 416, 168 }, Color{ 192u, 0u, 0u, 255u } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setMax(4u)
        .setCanIncrement(&canIncrementScore0)
        .setCanReset(&canResetScore0)
        .build(),
      Score::Builder{ Point{ 496, 168 }, Color{ 192u, 192u, 0u, 255u } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setMax(4u)
        .setCanIncrement(&canIncrementScore0)
        .setCanReset(&canResetScore0)
        .build(),
      Score::Builder{ Point{ 576, 168 }, Color{ 192u, 192u, 192u, 255u } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setMax(4u)
        .setCanIncrement(&canIncrementScore0)
        .setCanReset(&canResetScore0)
        .build(),
      Score::Builder{ Point{ 656, 168 }, Color{ 192u, 192u, 192u, 128u } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setMax(4u)
        .setCanIncrement(&canIncrementScore0)
        .setCanReset(&canResetScore0)
        .build(),
      Score::Builder{ Point{ 736, 168 }, Color{ 192u, 192u, 192u, 128u } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setMax(8u)
        .setCanIncrement(&canIncrementScore0)
        .setCanReset(&canResetScore0)
        .build(),
      Score::Builder{ Point{ 816, 168 }, Color{ 192u, 192u, 192u, 128u }, []() {
        cout << "You win!\n";
      } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setMax(8u)
        .setCanIncrement(&canIncrementScore0)
        .setCanReset(&canResetScore0)
        .build(),
      Score::Builder{ Point{ 896, 168 }, Color{ 192u, 192u, 192u, 128u }, []() {
        cout << "You win!\n";
      } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setMax(8u)
        .setCanIncrement(&canIncrementScore1)
        .setCanReset(&canResetScore1)
        .build(),
      Score::Builder{ Point{ 976, 168 }, Color{ 192u, 192u, 192u, 128u }, []() {
        cout << "You win!\n";
      } }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_BELL))
        .setFontSize(16u)
        .setMax(8u)
        .setCanIncrement(&canIncrementScore1)
        .setCanReset(&canResetScore1)
        .build(),
      Text::Builder{ Point{ 16, 232 }, "BorderView" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
      BorderView<>::Builder{ p_renderer, Point{ 16, 280 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 255u } }, 2u }.build(),
      BorderView<>::Builder{ p_renderer, Point{ 48, 280 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 255u } }, 2u }.build(),
      BorderView<>::Builder{ p_renderer, Point{ 80, 280 }, Paint{ Size{ 32, 16 }, Color{ 0u, 0u, 0u, 255u } }, 2u }.build(),
      BorderView<>::Builder{ p_renderer, Point{ 128, 280 }, Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } }, 2u }.build(),
      BorderView<>::Builder{ p_renderer, Point{ 176, 280 }, Paint{ Size{ 32, 32 }, Color{ 192u, 0u, 0u, 255u } }, 2u }.build(),
      BorderView<>::Builder{ p_renderer, Point{ 224, 280 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 0u, 255u } }, 2u }.build(),
      BorderView<>::Builder{ p_renderer, Point{ 272, 280 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 255u } }, 2u }.build(),
      BorderView<>::Builder{ p_renderer, Point{ 320, 280 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 128u } }, 2u }.build(),
      BorderView<>::Builder{ p_renderer, Point{ 368, 280 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 128u } }, 4u }.build(),
      BorderView<CellType>::Builder{ p_renderer, Point{ 416, 280 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 128u } }, 4u, CellType::BACKGROUND }.setMap(&map).build(),
      Text::Builder{ Point{ 16, 344 }, "Button" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
      Button::Builder{ p_renderer, Point{ 16, 392 }, Paint{ Size{ 16, 16 }, Color{ 128u, 128u, 128u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([]() { })
        .setOnClick([]() { })
        .setOnMouseOut([]() { })
        .setOnMouseOver([]() { })
        .build(),
      Button::Builder{ p_renderer, Point{ 48, 392 }, Paint{ Size{ 16, 16 }, Color{ 128u, 128u, 128u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([]() { })
        .setOnClick([]() { })
        .setOnMouseOut([]() { })
        .setOnMouseOver([]() { })
        .build(),
      Button::Builder{ p_renderer, Point{ 80, 392 }, Paint{ Size{ 32, 16 }, Color{ 128u, 128u, 128u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([]() { })
        .setOnClick([]() { })
        .setOnMouseOut([]() { })
        .setOnMouseOver([]() { })
        .build(),
      Button::Builder{ p_renderer, Point{ 128, 392 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([]() { })
        .setOnClick([]() { })
        .setOnMouseOut([]() { })
        .setOnMouseOver([]() { })
        .build(),
      Button::Builder{ p_renderer, Point{ 176, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 128u, 128u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([]() { })
        .setOnClick([]() { })
        .setOnMouseOut([]() { })
        .setOnMouseOver([]() { })
        .build(),
      Button::Builder{ p_renderer, Point{ 224, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 128u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([]() { })
        .setOnClick([]() { })
        .setOnMouseOut([]() { })
        .setOnMouseOver([]() { })
        .build(),
      Button::Builder{ p_renderer, Point{ 272, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([]() { })
        .setOnClick([]() { })
        .setOnMouseOut([]() { })
        .setOnMouseOver([]() { })
        .build(),
      Button::Builder{ p_renderer, Point{ 320, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 128u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([]() { })
        .setOnClick([]() { })
        .setOnMouseOut([]() { })
        .setOnMouseOver([]() { })
        .build(),
      Button::Builder{ p_renderer, Point{ 368, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 128u } } }
        .setA(0u)
        .setADuration(256u)
        .setLightnessDuration(128u)
        .setOnMouseMove([]() { })
        .setOnClick([]() { })
        .setOnMouseOut([]() { })
        .setOnMouseOver([]() { })
        .build(),
      Button::Builder{ p_renderer, Point{ 416, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 128u } } }
        .setA(0u)
        .setADuration(256u)
        .setLightnessDuration(256u)
        .setOnMouseMove([]() { })
        .setOnClick([]() { })
        .setOnMouseOut([]() { })
        .setOnMouseOver([]() { })
        .build(),
      Button::Builder{ p_renderer, Point{ 464, 392 }, Paint{ Size{ 160, 48 }, Color{ 192u, 192u, 192u, 128u } } }
        .setA(0u)
        .setADuration(256u)
        .setLightnessDuration(256u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          canIncrementScore0.set(true);
          cout << "You clicked increment score 0 button\n";
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ 482, 406 }, "Increment score 0" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Button::Builder{ p_renderer, Point{ 640, 392 }, Paint{ Size{ 160, 48 }, Color{ 192u, 192u, 192u, 128u } } }
        .setA(0u)
        .setADuration(256u)
        .setLightnessDuration(256u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          canIncrementScore1.set(true);
          cout << "You clicked increment score 1 button\n";
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
          cout << "You moved the mouse out of the increment score 1 button\n";
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ 658, 406 }, "Increment score 1" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Button::Builder{ p_renderer, Point{ 816, 392 }, Paint{ Size{ 136, 48 }, Color{ 192u, 192u, 192u, 128u } } }
        .setA(0u)
        .setADuration(256u)
        .setLightnessDuration(256u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          canResetScore0.set(true);
          cout << "You clicked reset score 0 button\n";
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
          cout << "You moved the mouse out of the reset score 0 button\n";
        })
        .setOnMouseOver([]() {
          cout << "You moved the mouse to the reset score 0 button\n";
        })
        .build(),
      Text::Builder{ Point{ 834, 406 }, "Reset score 0" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Button::Builder{ p_renderer, Point{ 968, 392 }, Paint{ Size{ 136, 48 }, Color{ 192u, 192u, 192u, 128u } } }
        .setA(0u)
        .setADuration(256u)
        .setLightnessDuration(256u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
          cout << "You are moving the mouse in the reset score 1 button\n";
        })
        .setOnClick([this]() {
          canResetScore1.set(true);
          cout << "You clicked reset score 1 button\n";
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
          cout << "You moved the mouse out of the reset score 1 button\n";
        })
        .setOnMouseOver([]() {
          cout << "You moved the mouse to the reset score 1 button\n";
        })
        .build(),
      Text::Builder{ Point{ 986, 406 }, "Reset score 1" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Text::Builder{ Point{ 16, 456 }, "Image" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
      Image::Builder{ Point{ 16, 504 } }.setTextureAtlas(&textureAtlas).setName(static_cast<unsigned int>(SpriteName::_PLACEHOLDER1)).build(),
      Image::Builder{ Point{ 96, 504 } }.setTextureAtlas(&textureAtlas).setName(static_cast<unsigned int>(SpriteName::_PLACEHOLDER1)).build(),
      Image::Builder{ Point{ 176, 504 } }.setTextureAtlas(&textureAtlas).setName(static_cast<unsigned int>(SpriteName::_PLACEHOLDER2)).build(),
      Image::Builder{ Point{ 256, 504 } }.setTextureAtlas(&textureAtlas).setName(static_cast<unsigned int>(SpriteName::_PLACEHOLDER2)).setA(128u).setDuration(256u).build(),
      Image::Builder{ Point{ 336, 504 } }
        .setTextureAtlas(&textureAtlas)
        .setName(static_cast<unsigned int>(SpriteName::_PLACEHOLDER2))
        .setA(128u)
        .setDuration(256u)
        .setRotation(Rotation::QUARTER_CLOCKWISE)
        .build(),
      Image::Builder{ Point{ 416, 504 } }
        .setTextureAtlas(&textureAtlas)
        .setName(static_cast<unsigned int>(SpriteName::_PLACEHOLDER2))
        .setA(128u)
        .setDuration(256u)
        .setRotation(Rotation::HALF)
        .build(),
      Image::Builder{ Point{ 496, 504 } }
        .setTextureAtlas(&textureAtlas)
        .setName(static_cast<unsigned int>(SpriteName::_PLACEHOLDER2))
        .setA(128u)
        .setDuration(256u)
        .setRotation(Rotation::QUARTER_COUNTERCLOCKWISE)
        .build(),
      Text::Builder{ Point{ 16, 600 }, "RectView" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
      new RectView{ p_renderer, Point{ 16, 648 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 255u } } },
      new RectView{ p_renderer, Point{ 48, 648 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 128u } } },
      new RectView{ p_renderer, Point{ 80, 648 }, Paint{ Size{ 32, 16 }, Color{ 0u, 0u, 0u, 255u } } },
      new RectView{ p_renderer, Point{ 128, 648 }, Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } } },
      new RectView{ p_renderer, Point{ 176, 648 }, Paint{ Size{ 32, 32 }, Color{ 128u, 0u, 0u, 255u } } },
      new RectView{ p_renderer, Point{ 224, 648 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 0u, 255u } } },
      new RectView{ p_renderer, Point{ 272, 648 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u, 255u } } },
      new RectView{ p_renderer, Point{ 320, 648 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u, 128u } } },
      new RectView{ p_renderer, Point{ 368, 648 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u, 128u } }, [this](Rect<int>&, Color<unsigned int>& color) {
        color = Color{ colorComponents(randomEngine), colorComponents(randomEngine), colorComponents(randomEngine), colorComponents(randomEngine) };
        return Action::NONE;
      } },
      Text::Builder{ Point{ 16, 712 }, "ViewGroup" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
      new ViewGroup{ p_renderer, Point{ 16, 760 }, [this](ViewGroup*const, SDL_Renderer*const) {
        return vector<View*>{
          Text::Builder{ Point{ 0, 0 }, "Body text1" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
          Text::Builder{ Point{ 96, 0 }, "Body text2" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build()
        };
      } },
      new ViewGroup{ p_renderer, Point{ 240, 760 }, [this](ViewGroup*const, SDL_Renderer*const) {
        return vector<View*>{
          Text::Builder{ Point{ 0, 0 }, "Body text1" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
          Text::Builder{ Point{ 96, 0 }, "Body text2" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build()
        };
      } },
      new ViewGroup{ p_renderer, Point{ 464, 760 }, [](ViewGroup*const, SDL_Renderer*const p_renderer) {
        return vector<View*>{
          BorderView<>::Builder{ p_renderer, Point{ 0, 0 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 255u } }, 2u }.build(),
          BorderView<>::Builder{ p_renderer, Point{ 32, 0 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 255u } }, 2u }.build(),
          BorderView<>::Builder{ p_renderer, Point{ 64, 0 }, Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 128u } }, 2u }.build()
        };
      } },
      Text::Builder{ Point{ 16, 824 }, "Modal" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
      Button::Builder{ p_renderer, Point{ 16, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          isModal1Showing.set(true);
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ 34, 886 }, "Modal 1" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Button::Builder{ p_renderer, Point{ 128, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          isModal2Showing.set(true);
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ 146, 886 }, "Modal 2" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Button::Builder{ p_renderer, Point{ 240, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          isModal3Showing.set(true);
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ 258, 886 }, "Modal 3" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Button::Builder{ p_renderer, Point{ 352, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          isModal4Showing.set(true);
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ 370, 886 }, "Modal 4" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Button::Builder{ p_renderer, Point{ 464, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          isModal5Showing.set(true);
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ 482, 886 }, "Modal 5" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Button::Builder{ p_renderer, Point{ 576, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 128u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          isModal6Showing.set(true);
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ 594, 886 }, "Modal 6" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Button::Builder{ p_renderer, Point{ 688, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 128u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          isModal7Showing.set(true);
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ 710, 886 }, "Modal 7" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Button::Builder{ p_renderer, Point{ 800, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 128u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          isModal8Showing.set(true);
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ 822, 886 }, "Modal 8" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build(),
      Button::Builder{ p_renderer, Point{ (size.w - NAV_BUTTON_SIZE.w) >> 1u, size.h - NAV_BUTTON_SIZE.h - 16 }, Paint{ NAV_BUTTON_SIZE, Color{ 192u, 192u, 255u, 255u } } }
        .setLightnessDuration(128u)
        .setOnMouseMove([this]() {
          SDL_SetCursor(getPointer());
        })
        .setOnClick([this]() {
          getCurrentPath().set(Path::PAGE2);
        })
        .setOnMouseOut([]() {
          SDL_SetCursor(SDL_GetDefaultCursor());
        })
        .setOnMouseOver([]() { })
        .build(),
      Text::Builder{ Point{ size.w >> 1u, size.h - NAV_BUTTON_SIZE.h - 2 }, "Next page" }
        .setGlyphAtlas(&glyphAtlas)
        .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
        .setFontSize(16u)
        .setColor(Color{ 0u, 0u, 0u, 255u })
        .setAlign(Align::CENTER)
        .build(),
      Modal::Builder{
        Point{ (size.w - MODAL_SIZE_1.w) >> 1u, (size.h - MODAL_SIZE_1.h) >> 1u }, Paint{ MODAL_SIZE_1, Color{ 255u, 255u, 255u, 255u } },
        [this, self](ViewGroup*const, SDL_Renderer*const p_renderer) {
          return vector<View*>{
            Text::Builder{ Point{ 192, 48 }, "Modal 1" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
            Button::Builder{ p_renderer, Point{ 200, 160 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
              .setLightnessDuration(128u)
              .setOnMouseMove([this]() {
                SDL_SetCursor(getPointer());
              })
              .setOnClick([this, self]() {
                isModal1Showing.set(false);
                self->reactMouseMotion(SDL_MouseMotionEvent{ .x = getMousePosition().x, .y = getMousePosition().y });
              })
              .setOnMouseOut([]() {
                SDL_SetCursor(SDL_GetDefaultCursor());
              })
              .setOnMouseOver([]() { })
              .build(),
            Text::Builder{ Point{ 226, 174 }, "Close" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build()
          };
        }
      }.setRenderer(p_renderer).setSceneSize(size).setShowing(&isModal1Showing).setDuration(128u).build(),
      Modal::Builder{
        Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 255u, 255u, 255u, 255u } },
        [this, self](ViewGroup*const, SDL_Renderer*const p_renderer) {
          return vector<View*>{
            Text::Builder{ Point{ 132, 32 }, "Modal 2" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
            Button::Builder{ p_renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
              .setLightnessDuration(128u)
              .setOnMouseMove([this]() {
                SDL_SetCursor(getPointer());
              })
              .setOnClick([this, self]() {
                isModal2Showing.set(false);
                self->reactMouseMotion(SDL_MouseMotionEvent{ .x = getMousePosition().x, .y = getMousePosition().y });
              })
              .setOnMouseOut([]() {
                SDL_SetCursor(SDL_GetDefaultCursor());
              })
              .setOnMouseOver([]() { })
              .build(),
            Text::Builder{ Point{ 168, 134 }, "Close" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build()
          };
        }
      }.setRenderer(p_renderer).setSceneSize(size).setShowing(&isModal2Showing).setDuration(128u).build(),
      Modal::Builder{
        Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 255u, 255u, 0u, 255u } },
        [this, self](ViewGroup*const, SDL_Renderer*const p_renderer) {
          return vector<View*>{
            Text::Builder{ Point{ 132, 32 }, "Modal 3" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
            Button::Builder{ p_renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
              .setLightnessDuration(128u)
              .setOnMouseMove([this]() {
                SDL_SetCursor(getPointer());
              })
              .setOnClick([this, self]() {
                isModal3Showing.set(false);
                self->reactMouseMotion(SDL_MouseMotionEvent{ .x = getMousePosition().x, .y = getMousePosition().y });
              })
              .setOnMouseOut([]() {
                SDL_SetCursor(SDL_GetDefaultCursor());
              })
              .setOnMouseOver([]() { })
              .build(),
            Text::Builder{ Point{ 168, 134 }, "Close" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build()
          };
        }
      }.setRenderer(p_renderer).setSceneSize(size).setShowing(&isModal3Showing).setDuration(128u).build(),
      Modal::Builder{
        Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 255u, 0u, 0u, 255u } },
        [this, self](ViewGroup*const, SDL_Renderer*const p_renderer) {
          return vector<View*>{
            Text::Builder{ Point{ 132, 32 }, "Modal 4" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(32u).build(),
            Button::Builder{ p_renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
              .setLightnessDuration(128u)
              .setOnMouseMove([this]() {
                SDL_SetCursor(getPointer());
              })
              .setOnClick([this, self]() {
                isModal4Showing.set(false);
                self->reactMouseMotion(SDL_MouseMotionEvent{ .x = getMousePosition().x, .y = getMousePosition().y });
              })
              .setOnMouseOut([]() {
                SDL_SetCursor(SDL_GetDefaultCursor());
              })
              .setOnMouseOver([]() { })
              .build(),
            Text::Builder{ Point{ 168, 134 }, "Close" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build()
          };
        }
      }.setRenderer(p_renderer).setSceneSize(size).setShowing(&isModal4Showing).setDuration(128u).build(),
      Modal::Builder{
        Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 0u, 0u, 0u, 255u } },
        [this, self](ViewGroup*const, SDL_Renderer*const p_renderer) {
          return vector<View*>{
            Text::Builder{ Point{ 132, 32 }, "Modal 5" }
              .setGlyphAtlas(&glyphAtlas)
              .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
              .setFontSize(32u)
              .setColor(Color{ 255u, 255u, 255u, 255u })
              .build(),
            Button::Builder{ p_renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
              .setLightnessDuration(128u)
              .setOnMouseMove([this]() {
                SDL_SetCursor(getPointer());
              })
              .setOnClick([this, self]() {
                isModal5Showing.set(false);
                self->reactMouseMotion(SDL_MouseMotionEvent{ .x = getMousePosition().x, .y = getMousePosition().y });
              })
              .setOnMouseOut([]() {
                SDL_SetCursor(SDL_GetDefaultCursor());
              })
              .setOnMouseOver([]() { })
              .build(),
            Text::Builder{ Point{ 168, 134 }, "Close" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build()
          };
        }
      }.setRenderer(p_renderer).setSceneSize(size).setShowing(&isModal5Showing).setDuration(128u).build(),
      Modal::Builder{
        Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 0u, 0u, 0u, 128u } },
        [this, self](ViewGroup*const, SDL_Renderer*const p_renderer) {
          return vector<View*>{
            Text::Builder{ Point{ 132, 32 }, "Modal 6" }
              .setGlyphAtlas(&glyphAtlas)
              .setFontName(static_cast<unsigned int>(FontName::_ARIAL))
              .setFontSize(32u)
              .setColor(Color{ 255u, 255u, 255u, 255u })
              .build(),
            Button::Builder{ p_renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
              .setLightnessDuration(128u)
              .setOnMouseMove([this]() {
                SDL_SetCursor(getPointer());
              })
              .setOnClick([this, self]() {
                isModal6Showing.set(false);
                self->reactMouseMotion(SDL_MouseMotionEvent{.x = getMousePosition().x, .y = getMousePosition().y });
              })
              .setOnMouseOut([]() {
                SDL_SetCursor(SDL_GetDefaultCursor());
              })
              .setOnMouseOver([]() { })
              .build(),
            Text::Builder{ Point{ 168, 134 }, "Close" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build()
          };
        }
      }.setRenderer(p_renderer).setSceneSize(size).setShowing(&isModal6Showing).setDuration(128u).build(),
      Modal::Builder{
        Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 0u, 0u, 0u, 128u } },
        [this, self](ViewGroup*const, SDL_Renderer*const p_renderer) {
          return vector<View*>{
            Button::Builder{ p_renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
              .setLightnessDuration(128u)
              .setOnMouseMove([this]() {
                SDL_SetCursor(getPointer());
              })
              .setOnClick([this, self]() {
                isModal7Showing.set(false);
                self->reactMouseMotion(SDL_MouseMotionEvent{ .x = getMousePosition().x, .y = getMousePosition().y });
              })
              .setOnMouseOut([]() {
                SDL_SetCursor(SDL_GetDefaultCursor());
              })
              .setOnMouseOver([]() { })
              .build(),
            Text::Builder{ Point{ 168, 134 }, "Close" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build()
          };
        }
      }.setRenderer(p_renderer).setSceneSize(size).setShowing(&isModal7Showing).setDuration(128u).build(),
      Modal::Builder{
        Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 0u, 0u, 0u, 128u } },
        [this, self](ViewGroup*const, SDL_Renderer*const p_renderer) {
          return vector<View*>{
            Button::Builder{ p_renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
              .setLightnessDuration(128u)
              .setOnMouseMove([this]() {
                SDL_SetCursor(getPointer());
              })
              .setOnClick([this, self]() {
                isModal8Showing.set(false);
                self->reactMouseMotion(SDL_MouseMotionEvent{.x = getMousePosition().x, .y = getMousePosition().y });
              })
              .setOnMouseOut([]() {
                SDL_SetCursor(SDL_GetDefaultCursor());
              })
              .setOnMouseOver([]() { })
              .build(),
            Text::Builder{ Point{ 168, 134 }, "Close" }.setGlyphAtlas(&glyphAtlas).setFontName(static_cast<unsigned int>(FontName::_ARIAL)).setFontSize(16u).build()
          };
        }
      }.setRenderer(p_renderer).setSceneSize(size).setShowing(&isModal8Showing).setDuration(256u).build()
    };
  } }.setPath(Path::PAGE1).setCurrentPath(&getCurrentPath()).build();
}

}  // namespace ii887522::viewify

#endif
