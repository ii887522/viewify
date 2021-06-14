// Copyright ii887522

#ifdef GUI_TEST

#include "ViewifyViewGroupFactory.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <chrono>  // NOLINT(build/c++11)
#include "../../main/Factory/ViewGroupFactory.h"
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
#include "../../main/Atlas/GlyphAtlas.h"
#include "../../main/Atlas/TextureAtlas.h"

using std::cout;
using std::vector;
using std::chrono::high_resolution_clock;

namespace ii887522::viewify {

ViewifyViewGroupFactory::ViewifyViewGroupFactory() : ViewGroupFactory{ }, canIncrementScore0{ false }, canResetScore0{ false }, canIncrementScore1{ false }, canResetScore1{ false },
  isModal1Showing{ false }, isModal2Showing{ false }, isModal3Showing{ false }, isModal4Showing{ false }, isModal5Showing{ false }, isModal6Showing{ false }, currentPath{ Path::MAIN },
  map{ Size{ 8u, 8u } }, pointer{ SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND) }, colorComponents{ 0u, 255u },
  randomEngine{ static_cast<unsigned int>(high_resolution_clock::now().time_since_epoch().count()) }, textureAtlas{ nullptr }, glyphAtlas{ nullptr } { }

ViewGroup ViewifyViewGroupFactory::make(SDL_Renderer*const renderer, const Size<int>& size) {
  textureAtlas = new TextureAtlas{ renderer, "res/test/images/" };
  glyphAtlas = new GlyphAtlas{ renderer, "res/test/fonts/" };
  constexpr Size<int> MODAL_SIZE_1{ 512, 256 };
  constexpr Size<int> MODAL_SIZE_2{ 384, 192 };
  constexpr Size<int> NAV_BUTTON_SIZE{ 128, 48 };
  return ViewGroup{ renderer, Point{ 0, 0 }, [this, size, &MODAL_SIZE_1, &MODAL_SIZE_2, &NAV_BUTTON_SIZE](ViewGroup*const, SDL_Renderer*const renderer) {
    return vector<View*>{
      new Page<Path>{ renderer, Point{ 0, 0 }, Path::MAIN, &currentPath, [this, size, &MODAL_SIZE_1, &MODAL_SIZE_2, &NAV_BUTTON_SIZE](ViewGroup*const self, SDL_Renderer*const renderer) {
        return vector<View*>{
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 16, 16 }, "Text" }.setFontSize(32u).build(),
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 16, 64 }, "Body text1" }.setFontSize(16u).build(),
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 112, 64 }, "Body text2" }.setFontSize(16u).build(),
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 208, 64 }, "Animated text" }.setFontSize(16u).setA(128u).setDuration(256u).build(),
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 16, 112 }, "Score" }.setFontSize(32u).build(),
          Score::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 76, 160 }, Color{ 0u, 0u, 0u, 255u }, []() { } }
            .setFontSize(32u)
            .setMax(4u)
            .setCanIncrement(&canIncrementScore0)
            .setCanReset(&canResetScore0)
            .build(),
          Score::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 192, 168 }, Color{ 0u, 0u, 0u, 255u }, []() { } }
            .setFontSize(16u)
            .setMax(4u)
            .setCanIncrement(&canIncrementScore0)
            .setCanReset(&canResetScore0)
            .build(),
          Score::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 272, 168 }, Color{ 0u, 0u, 0u, 255u }, []() { } }
            .setFontSize(16u)
            .setMax(4u)
            .setCanIncrement(&canIncrementScore0)
            .setCanReset(&canResetScore0)
            .build(),
          Score::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 352, 168 }, Color{ 128u, 128u, 128u, 255u }, []() { } }
            .setFontSize(16u)
            .setMax(4u)
            .setCanIncrement(&canIncrementScore0)
            .setCanReset(&canResetScore0)
            .build(),
          Score::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 432, 168 }, Color{ 128u, 128u, 128u, 255u }, []() { } }
            .setFontSize(16u)
            .setMax(8u)
            .setCanIncrement(&canIncrementScore0)
            .setCanReset(&canResetScore0)
            .build(),
          Score::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 512, 168 }, Color{ 128u, 128u, 128u, 255u }, []() {
            cout << "You win!\n";
          } }.setFontSize(16u).setMax(8u).setCanIncrement(&canIncrementScore0).setCanReset(&canResetScore0).build(),
          Score::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 592, 168 }, Color{ 128u, 128u, 128u, 255u }, []() {
            cout << "You win!\n";
          } }.setFontSize(16u).setMax(8u).setCanIncrement(&canIncrementScore0).setCanReset(&canResetScore0).build(),
          Score::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 672, 168 }, Color{ 128u, 128u, 128u, 128u }, []() {
            cout << "You win!\n";
          } }.setFontSize(16u).setMax(8u).setCanIncrement(&canIncrementScore1).setCanReset(&canResetScore1).build(),
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 16, 232 }, "BorderView" }.setFontSize(32u).build(),
          new BorderView<>{ renderer, Point{ 16, 280 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 255u } }, 2u },
          new BorderView<>{ renderer, Point{ 48, 280 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 255u } }, 2u },
          new BorderView<>{ renderer, Point{ 80, 280 }, Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } }, 2u },
          new BorderView<>{ renderer, Point{ 128, 280 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u, 255u } }, 2u },
          new BorderView<>{ renderer, Point{ 176, 280 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u, 255u } }, 4u },
          new BorderView<CellType>{ renderer, Point{ 224, 280 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u, 255u } }, 4u, &map, CellType::BACKGROUND },
          new BorderView<CellType>{ renderer, Point{ 272, 280 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u, 128u } }, 4u, &map, CellType::BORDER },
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 16, 344 }, "Button" }.setFontSize(32u).build(),
          Button::Builder{ renderer, Point{ 16, 392 }, Paint{ Size{ 16, 16 }, Color{ 128u, 128u, 128u, 255u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([]() { })
            .setOnClick([]() { })
            .setOnMouseOut([]() { })
            .setOnMouseOver([]() { })
            .build(),
          Button::Builder{ renderer, Point{ 48, 392 }, Paint{ Size{ 16, 16 }, Color{ 128u, 128u, 128u, 255u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([]() { })
            .setOnClick([]() { })
            .setOnMouseOut([]() { })
            .setOnMouseOver([]() { })
            .build(),
          Button::Builder{ renderer, Point{ 80, 392 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u, 255u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([]() { })
            .setOnClick([]() { })
            .setOnMouseOut([]() { })
            .setOnMouseOver([]() { })
            .build(),
          Button::Builder{ renderer, Point{ 128, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 255u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([]() { })
            .setOnClick([]() { })
            .setOnMouseOut([]() { })
            .setOnMouseOver([]() { })
            .build(),
          Button::Builder{ renderer, Point{ 176, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 255u } } }
            .setADuration(255u)
            .setLightnessDuration(128u)
            .setOnMouseMove([]() { })
            .setOnClick([]() { })
            .setOnMouseOut([]() { })
            .setOnMouseOver([]() { })
            .build(),
          Button::Builder{ renderer, Point{ 224, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u, 255u } } }
            .setADuration(255u)
            .setLightnessDuration(512u)
            .setOnMouseMove([]() { })
            .setOnClick([]() { })
            .setOnMouseOut([]() { })
            .setOnMouseOver([]() { })
            .build(),
          Button::Builder{ renderer, Point{ 272, 392 }, Paint{ Size{ 160, 48 }, Color{ 192u, 192u, 192u, 255u } } }
            .setADuration(255u)
            .setLightnessDuration(256u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
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
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 290, 406 }, "Increment score 0" }.setFontSize(16u).build(),
          Button::Builder{ renderer, Point{ 448, 392 }, Paint{ Size{ 160, 48 }, Color{ 192u, 192u, 192u, 255u } } }
            .setADuration(255u)
            .setLightnessDuration(256u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
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
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 466, 406 }, "Increment score 1" }.setFontSize(16u).build(),
          Button::Builder{ renderer, Point{ 624, 392 }, Paint{ Size{ 136, 48 }, Color{ 192u, 192u, 192u, 255u } } }
            .setADuration(255u)
            .setLightnessDuration(256u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
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
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 642, 406 }, "Reset score 0" }.setFontSize(16u).build(),
          Button::Builder{ renderer, Point{ 774, 392 }, Paint{ Size{ 136, 48 }, Color{ 192u, 192u, 192u, 128u } } }
            .setADuration(255u)
            .setLightnessDuration(256u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
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
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 792, 406 }, "Reset score 1" }.setFontSize(16u).build(),
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 16, 456 }, "Image" }.setFontSize(32u).build(),
          Image::Builder{ textureAtlas, static_cast<unsigned int>(SpriteName::_PLACEHOLDER1), Point{ 16, 504 } }.build(),
          Image::Builder{ textureAtlas, static_cast<unsigned int>(SpriteName::_PLACEHOLDER2), Point{ 96, 504 } }.build(),
          Image::Builder{ textureAtlas, static_cast<unsigned int>(SpriteName::_PLACEHOLDER2), Point{ 176, 504 } }.build(),
          Image::Builder{ textureAtlas, static_cast<unsigned int>(SpriteName::_PLACEHOLDER2), Point{ 256, 504 } }.setA(128u).build(),
          Image::Builder{ textureAtlas, static_cast<unsigned int>(SpriteName::_PLACEHOLDER2), Point{ 336, 504 } }.setA(128u).setDuration(256u).build(),
          Image::Builder{ textureAtlas, static_cast<unsigned int>(SpriteName::_PLACEHOLDER2), Point{ 416, 504 }, Align::LEFT, Rotation::QUARTER_CLOCKWISE }
            .setA(128u)
            .setDuration(256u)
            .build(),
          Image::Builder{ textureAtlas, static_cast<unsigned int>(SpriteName::_PLACEHOLDER2), Point{ 496, 504 }, Align::LEFT, Rotation::HALF }.setA(128u).setDuration(256u).build(),
          Image::Builder{ textureAtlas, static_cast<unsigned int>(SpriteName::_PLACEHOLDER2), Point{ 576, 504 }, Align::LEFT, Rotation::QUARTER_COUNTERCLOCKWISE }
            .setA(128u)
            .setDuration(256u)
            .build(),
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 16, 600 }, "RectView" }.setFontSize(32u).build(),
          new RectView{ renderer, Point{ 16, 648 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 255u } } },
          new RectView{ renderer, Point{ 48, 648 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 128u } } },
          new RectView{ renderer, Point{ 80, 648 }, Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 255u } } },
          new RectView{ renderer, Point{ 128, 648 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u, 255u } } },
          new RectView{ renderer, Point{ 176, 648 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u, 255u } }, [this](Rect<int>&, Color<unsigned int>& color) {
            color = Color{ colorComponents(randomEngine), colorComponents(randomEngine), colorComponents(randomEngine), colorComponents(randomEngine) };
            return Action::NONE;
          } },
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 16, 712 }, "ViewGroup" }.setFontSize(32u).build(),
          new ViewGroup{ renderer, Point{ 16, 760 }, [this](ViewGroup*const, SDL_Renderer*const) {
            return vector<View*>{
              Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 0, 0 }, "Body text1" }.setFontSize(16u).build(),
              Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 96, 0 }, "Body text2" }.setFontSize(16u).build()
            };
          } },
          new ViewGroup{ renderer, Point{ 240, 760 }, [](ViewGroup*const, SDL_Renderer*const renderer) {
            return vector<View*>{
              new BorderView<>{ renderer, Point{ 0, 0 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 255u } }, 2u },
              new BorderView<>{ renderer, Point{ 32, 0 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u, 255u } }, 2u },
              new BorderView<>{ renderer, Point{ 64, 0 }, Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u, 128u } }, 2u }
            };
          } },
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 16, 824 }, "Modal" }.setFontSize(32u).build(),
          Button::Builder{ renderer, Point{ 16, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
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
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 34, 886 }, "Modal 1" }.setFontSize(16u).build(),
          Button::Builder{ renderer, Point{ 128, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
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
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 146, 886 }, "Modal 2" }.setFontSize(16u).build(),
          Button::Builder{ renderer, Point{ 240, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
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
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 258, 886 }, "Modal 3" }.setFontSize(16u).build(),
          Button::Builder{ renderer, Point{ 352, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
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
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 370, 886 }, "Modal 4" }.setFontSize(16u).build(),
          Button::Builder{ renderer, Point{ 464, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
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
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 482, 886 }, "Modal 5" }.setFontSize(16u).build(),
          Button::Builder{ renderer, Point{ 576, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 128u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
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
          Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 594, 886 }, "Modal 6" }.setFontSize(16u).build(),
          Button::Builder{ renderer, Point{ (size.w - NAV_BUTTON_SIZE.w) >> 1u, size.h - NAV_BUTTON_SIZE.h - 16 }, Paint{ NAV_BUTTON_SIZE, Color{ 192u, 192u, 255u, 255u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
            })
            .setOnClick([this]() {
              currentPath.set(Path::EMPTY);
            })
            .setOnMouseOut([]() {
              SDL_SetCursor(SDL_GetDefaultCursor());
            })
            .setOnMouseOver([]() { })
            .build(),
          Text::Builder{
            glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ size.w >> 1u, size.h - NAV_BUTTON_SIZE.h - 2 }, "Next page", Color{ 0u, 0u, 0u, 255u }, Align::CENTER
          }.setFontSize(16u).build(),
          new Modal{
            renderer, size, Point{ (size.w - MODAL_SIZE_1.w) >> 1u, (size.h - MODAL_SIZE_1.h) >> 1u }, Paint{ MODAL_SIZE_1, Color{ 255u, 255u, 255u, 255u } }, &isModal1Showing, 128u,
            [this, self](ViewGroup*const, SDL_Renderer*const renderer) {
              return vector<View*>{
                Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 192, 48 }, "Modal 1" }.setFontSize(32u).build(),
                Button::Builder{ renderer, Point{ 200, 160 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
                  .setLightnessDuration(128u)
                  .setOnMouseMove([this]() {
                    SDL_SetCursor(pointer);
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
                Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 226, 174 }, "Close" }.setFontSize(16u).build()
              };
            }
          },
          new Modal{
            renderer, size, Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 255u, 255u, 255u, 255u } }, &isModal2Showing, 128u,
            [this, self](ViewGroup*const, SDL_Renderer*const renderer) {
              return vector<View*>{
                Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 132, 32 }, "Modal 2" }.setFontSize(32u).build(),
                Button::Builder{ renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
                  .setLightnessDuration(128u)
                  .setOnMouseMove([this]() {
                    SDL_SetCursor(pointer);
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
                Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 168, 134 }, "Close" }.setFontSize(16u).build()
              };
            }
          },
          new Modal{
            renderer, size, Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 255u, 0u, 0u, 255u } }, &isModal3Showing, 128u,
            [this, self](ViewGroup*const, SDL_Renderer*const renderer) {
              return vector<View*>{
                Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 132, 32 }, "Modal 3" }.setFontSize(32u).build(),
                Button::Builder{ renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
                  .setLightnessDuration(128u)
                  .setOnMouseMove([this]() {
                    SDL_SetCursor(pointer);
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
                Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 168, 134 }, "Close" }.setFontSize(16u).build()
              };
            }
          },
          new Modal{
            renderer, size, Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 255u, 0u, 0u, 255u } }, &isModal4Showing, 128u,
            [this, self](ViewGroup*const, SDL_Renderer*const renderer) {
              return vector<View*>{
                Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 132, 32 }, "Modal 4" }.setFontSize(32u).build(),
                Button::Builder{ renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
                  .setLightnessDuration(128u)
                  .setOnMouseMove([this]() {
                    SDL_SetCursor(pointer);
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
                Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 168, 134 }, "Close" }.setFontSize(16u).build()
              };
            }
          },
          new Modal{
            renderer, size, Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 255u, 0u, 0u, 255u } }, &isModal5Showing, 256u,
            [this, self](ViewGroup*const, SDL_Renderer*const renderer) {
              return vector<View*>{
                Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 132, 32 }, "Modal 5" }.setFontSize(32u).build(),
                Button::Builder{ renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
                  .setLightnessDuration(128u)
                  .setOnMouseMove([this]() {
                    SDL_SetCursor(pointer);
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
                Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 168, 134 }, "Close" }.setFontSize(16u).build()
              };
            }
          },
          new Modal{
            renderer, size, Point{ (size.w - MODAL_SIZE_2.w) >> 1u, (size.h - MODAL_SIZE_2.h) >> 1u }, Paint{ MODAL_SIZE_2, Color{ 255u, 0u, 0u, 255u } }, &isModal6Showing, 256u,
            [this, self](ViewGroup*const, SDL_Renderer*const renderer) {
              return vector<View*>{
                Button::Builder{ renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u, 255u } } }
                  .setLightnessDuration(128u)
                  .setOnMouseMove([this]() {
                    SDL_SetCursor(pointer);
                  })
                  .setOnClick([this, self]() {
                    isModal6Showing.set(false);
                    self->reactMouseMotion(SDL_MouseMotionEvent{ .x = getMousePosition().x, .y = getMousePosition().y });
                  })
                  .setOnMouseOut([]() {
                    SDL_SetCursor(SDL_GetDefaultCursor());
                  })
                  .setOnMouseOver([]() { })
                  .build(),
                Text::Builder{ glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ 168, 134 }, "Close" }.setFontSize(16u).build()
              };
            }
          }
        };
      } },
      new Page<Path>{ renderer, Point{ 0, 0 }, Path::EMPTY, &currentPath, [this, size, &NAV_BUTTON_SIZE](ViewGroup*const, SDL_Renderer*const renderer) {
        return vector<View*>{
          Button::Builder{ renderer, Point{ (size.w - NAV_BUTTON_SIZE.w) >> 1u, size.h - NAV_BUTTON_SIZE.h - 16 }, Paint{ NAV_BUTTON_SIZE, Color{ 192u, 192u, 255u, 255u } } }
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
            })
            .setOnClick([this]() {
              currentPath.set(Path::MAIN);
            })
            .setOnMouseOut([this]() {
              SDL_SetCursor(SDL_GetDefaultCursor());
            })
            .setOnMouseOver([]() { })
            .build(),
          Text::Builder{
            glyphAtlas, static_cast<unsigned int>(FontName::_ARIAL), Point{ size.w >> 1u, size.h - NAV_BUTTON_SIZE.h - 2 }, "Prev page", Color{ 0u, 0u, 0u, 255u }, Align::CENTER
          }.setFontSize(16u).build(),
        };
      } }
    };
  } };
}

ViewifyViewGroupFactory::~ViewifyViewGroupFactory() {
  delete glyphAtlas;
  delete textureAtlas;
  SDL_FreeCursor(pointer);
}

}  // namespace ii887522::viewify

#endif
