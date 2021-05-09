// Copyright ii887522

#ifndef VIEWIFY_SRC_TEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_
#define VIEWIFY_SRC_TEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_

#include <Any/Reactive.h>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "../../main/Factory/ViewGroupFactory.h"
#include "../../main/View/ViewGroup.h"
#include "../../main/Struct/Size.h"
#include "../../main/Struct/Point.h"
#include "../../main/Struct/Rect.h"
#include "../../main/Struct/Color.h"
#include "../../main/Image/Text.h"
#include "../../main/Text/Score.h"
#include "../../main/View/BorderView.h"
#include "../../main/Any/Map.h"
#include "../Any/Enums.h"
#include "../../main/View/Button.h"
#include "../../main/View/Image.h"
#include "../../main/View/RectView.h"
#include "../../main/ViewGroup/Modal.h"
#include "../../main/ViewGroup/Page.h"
#include <random>

using ii887522::nitro::Reactive;
using std::cout;
using std::uniform_int_distribution;
using std::default_random_engine;

namespace ii887522::viewify {

// See also ../../main/View/ViewGroup.h for more details
template <unsigned int viewCount> class ViewifyViewGroupFactory final : public ViewGroupFactory<viewCount> {
  // remove copy semantics
  ViewifyViewGroupFactory(const ViewifyViewGroupFactory&) = delete;
  ViewifyViewGroupFactory& operator=(const ViewifyViewGroupFactory&) = delete;

  // remove move semantics
  ViewifyViewGroupFactory(ViewifyViewGroupFactory&&) = delete;
  ViewifyViewGroupFactory& operator=(ViewifyViewGroupFactory&&) = delete;

  const Size<int> modalSize1;
  const Size<int> modalSize2;
  const Size<int> navButtonSize;
  TTF_Font*const headFont;
  TTF_Font*const bodyFont;
  Reactive<bool> canIncrementScore0;
  Reactive<bool> canResetScore0;
  Reactive<bool> canIncrementScore1;
  Reactive<bool> canResetScore1;
  Reactive<bool> isModal1Showing;
  Reactive<bool> isModal2Showing;
  Reactive<bool> isModal3Showing;
  Reactive<bool> isModal4Showing;
  Reactive<bool> isModal5Showing;
  Reactive<bool> isModal6Showing;
  Reactive<Path> currentPath;
  Map<CellType> map;
  SDL_Cursor*const pointer;
  uniform_int_distribution<unsigned int> colorComponents;
  default_random_engine randomEngine;

 public:
  // See also ../../main/View/ViewGroup.h for more details
  constexpr ViewifyViewGroupFactory() : ViewGroupFactory<viewCount>{ }, modalSize1{ 512, 256 }, modalSize2{ 384, 192 }, navButtonSize{ 128, 48 },
    headFont{ TTF_OpenFont("res/test/arial.ttf", 32) }, bodyFont{ TTF_OpenFont("res/test/arial.ttf", 16) }, canIncrementScore0{ false }, canResetScore0{ false }, canIncrementScore1{ false },
    canResetScore1{ false }, isModal1Showing{ false }, isModal2Showing{ false }, isModal3Showing{ false }, isModal4Showing{ false }, isModal5Showing{ false }, isModal6Showing{ false },
    currentPath{ Path::MAIN }, map{ Size{ 8u, 8u } }, pointer{ SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND) }, colorComponents{ 0u, 255u }, randomEngine{ } { }

  // Param renderer: it must not be assigned to integer
  // See also ../View/ViewGroup.h for more details
  ViewGroup<viewCount> make(SDL_Renderer*const renderer, const Size<int>& size) override {
    return ViewGroup<viewCount>{ renderer, Point{ 0, 0 }, {
      new Page<Path, 72>{ renderer, Point{ 0, 0 }, Path::MAIN, &currentPath, {
        Text::Builder{ renderer, headFont, Point{ 16, 16 }, "Text" }.setDuration(1u).build(),
        Text::Builder{ renderer, bodyFont, Point{ 16, 64 }, "Body text1" }.setDuration(1u).build(),
        Text::Builder{ renderer, bodyFont, Point{ 112, 64 }, "Body text2" }.setDuration(1u).build(),
        Text::Builder{ renderer, bodyFont, Point{ 208, 64 }, "Animated text" }.setA(128u).setDuration(256u).build(),
        Text::Builder{ renderer, headFont, Point{ 16, 112 }, "Score" }.setDuration(1u).build(),
        Score::Builder{ renderer, headFont, Point{ 76, 160 }, Color{ 0u, 0u, 0u }, 4u, []() {} }.setCanIncrement(&canIncrementScore0).setCanReset(&canResetScore0).build(),
        Score::Builder{ renderer, bodyFont, Point{ 192, 168 }, Color{ 0u, 0u, 0u }, 4u, []() {} }.setCanIncrement(&canIncrementScore0).setCanReset(&canResetScore0).build(),
        Score::Builder{ renderer, bodyFont, Point{ 272, 168 }, Color{ 0u, 0u, 0u }, 4u, []() {} }.setCanIncrement(&canIncrementScore0).setCanReset(&canResetScore0).build(),
        Score::Builder{ renderer, bodyFont, Point{ 352, 168 }, Color{ 128u, 128u, 128u }, 4u, []() {} }.setCanIncrement(&canIncrementScore0).setCanReset(&canResetScore0).build(),
        Score::Builder{ renderer, bodyFont, Point{ 432, 168 }, Color{ 128u, 128u, 128u }, 8u, []() {} }.setCanIncrement(&canIncrementScore0).setCanReset(&canResetScore0).build(),
        Score::Builder{ renderer, bodyFont, Point{ 512, 168 }, Color{ 128u, 128u, 128u }, 8u, []() {
          cout << "You win!\n";
        } }.setCanIncrement(&canIncrementScore0).setCanReset(&canResetScore0).build(),
        Score::Builder{ renderer, bodyFont, Point{ 592, 168 }, Color{ 128u, 128u, 128u }, 8u, []() {
          cout << "You win!\n";
        } }.setCanIncrement(&canIncrementScore0).setCanReset(&canResetScore0).build(),
        Score::Builder{ renderer, bodyFont, Point{ 672, 168 }, Color{ 128u, 128u, 128u }, 8u, []() {
          cout << "You win!\n";
        } }.setCanIncrement(&canIncrementScore1).setCanReset(&canResetScore1).build(),
        Text::Builder{ renderer, headFont, Point{ 16, 232 }, "BorderView" }.setDuration(1u).build(),
        new BorderView<>{ renderer, Point{ 16, 280 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u } }, 2u },
        new BorderView<>{ renderer, Point{ 48, 280 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u } }, 2u },
        new BorderView<>{ renderer, Point{ 80, 280 }, Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u } }, 2u },
        new BorderView<>{ renderer, Point{ 128, 280 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u } }, 2u },
        new BorderView<>{ renderer, Point{ 176, 280 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u } }, 4u },
        new BorderView<CellType>{ renderer, Point{ 224, 280 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u } }, 4u, &map, CellType::BACKGROUND },
        new BorderView<CellType>{ renderer, Point{ 272, 280 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u } }, 4u, &map, CellType::BORDER },
        Text::Builder{ renderer, headFont, Point{ 16, 344 }, "Button" }.setDuration(1u).build(),
        Button::Builder{ renderer, Point{ 16, 392 }, Paint{ Size{ 16, 16 }, Color{ 128u, 128u, 128u } } }
          .setADuration(1u)
          .setLightnessDuration(128u)
          .setOnMouseMove([]() {})
          .setOnClick([]() {})
          .setOnMouseOut([]() {})
          .setOnMouseOver([]() {})
          .build(),
        Button::Builder{ renderer, Point{ 48, 392 }, Paint{ Size{ 16, 16 }, Color{ 128u, 128u, 128u } } }
          .setADuration(1u)
          .setLightnessDuration(128u)
          .setOnMouseMove([]() {})
          .setOnClick([]() {})
          .setOnMouseOut([]() {})
          .setOnMouseOver([]() {})
          .build(),
        Button::Builder{ renderer, Point{ 80, 392 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u } } }
          .setADuration(1u)
          .setLightnessDuration(128u)
          .setOnMouseMove([]() {})
          .setOnClick([]() {})
          .setOnMouseOut([]() {})
          .setOnMouseOver([]() {})
          .build(),
        Button::Builder{ renderer, Point{ 128, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u } } }
          .setADuration(1u)
          .setLightnessDuration(128u)
          .setOnMouseMove([]() {})
          .setOnClick([]() {})
          .setOnMouseOut([]() {})
          .setOnMouseOver([]() {})
          .build(),
        Button::Builder{ renderer, Point{ 176, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u } } }
          .setADuration(255u)
          .setLightnessDuration(128u)
          .setOnMouseMove([]() {})
          .setOnClick([]() {})
          .setOnMouseOut([]() {})
          .setOnMouseOver([]() {})
          .build(),
        Button::Builder{ renderer, Point{ 224, 392 }, Paint{ Size{ 32, 32 }, Color{ 192u, 192u, 192u } } }
          .setADuration(255u)
          .setLightnessDuration(512u)
          .setOnMouseMove([]() {})
          .setOnClick([]() {})
          .setOnMouseOut([]() {})
          .setOnMouseOver([]() {})
          .build(),
        Button::Builder{ renderer, Point{ 272, 392 }, Paint{ Size{ 160, 48 }, Color{ 192u, 192u, 192u } } }
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
          .setOnMouseOver([]() {})
          .build(),
        Text::Builder{ renderer, bodyFont, Point{ 290, 406 }, "Increment score 0" }.setDuration(1u).build(),
        Button::Builder{ renderer, Point{ 448, 392 }, Paint{ Size{ 160, 48 }, Color{ 192u, 192u, 192u } } }
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
          .setOnMouseOver([]() {})
          .build(),
        Text::Builder{ renderer, bodyFont, Point{ 466, 406 }, "Increment score 1" }.setDuration(1u).build(),
        Button::Builder{ renderer, Point{ 624, 392 }, Paint{ Size{ 136, 48 }, Color{ 192u, 192u, 192u } } }
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
        Text::Builder{ renderer, bodyFont, Point{ 642, 406 }, "Reset score 0" }.setDuration(1u).build(),
        Button::Builder{ renderer, Point{ 774, 392 }, Paint{ Size{ 136, 48 }, Color{ 192u, 192u, 192u } } }
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
        Text::Builder{ renderer, bodyFont, Point{ 792, 406 }, "Reset score 1" }.setDuration(1u).build(),
        Text::Builder{ renderer, headFont, Point{ 16, 456 }, "Image" }.setDuration(1u).build(),
        Image::Builder{ renderer, IMG_Load("res/test/placeholder1.png"), Point{ 16, 504 } }.setDuration(1u).build(),
        Image::Builder{ renderer, IMG_Load("res/test/placeholder2.png"), Point{ 96, 504 } }.setDuration(1u).build(),
        Image::Builder{ renderer, IMG_Load("res/test/placeholder2.png"), Point{ 176, 504 } }.setDuration(1u).build(),
        Image::Builder{ renderer, IMG_Load("res/test/placeholder2.png"), Point{ 256, 504 } }.setA(128u).setDuration(1u).build(),
        Image::Builder{ renderer, IMG_Load("res/test/placeholder2.png"), Point{ 336, 504 } }.setA(128u).setDuration(256u).build(),
        Text::Builder{ renderer, headFont, Point{ 16, 600 }, "RectView" }.setDuration(1u).build(),
        new RectView{ renderer, Point{ 16, 648 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u } } },
        new RectView{ renderer, Point{ 48, 648 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u } } },
        new RectView{ renderer, Point{ 80, 648 }, Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u } } },
        new RectView{ renderer, Point{ 128, 648 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u } } },
        new RectView{ renderer, Point{ 176, 648 }, Paint{ Size{ 32, 32 }, Color{ 128u, 128u, 128u } }, [this](Rect<int>&, Color<unsigned int>& color) {
          color = { colorComponents(randomEngine), colorComponents(randomEngine), colorComponents(randomEngine) };
          return Action::NONE;
        } },
        Text::Builder{ renderer, headFont, Point{ 16, 712 }, "ViewGroup" }.setDuration(1u).build(),
        new ViewGroup<2u>{ renderer, Point{ 16, 760 }, {
          Text::Builder{ renderer, bodyFont, Point{ 0, 0 }, "Body text1" }.setDuration(1u).build(),
          Text::Builder{ renderer, bodyFont, Point{ 96, 0 }, "Body text2" }.setDuration(1u).build()
        } },
        new ViewGroup<3u>{ renderer, Point{ 240, 760 }, {
          new BorderView<>{ renderer, Point{ 0, 0 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u } }, 2u },
          new BorderView<>{ renderer, Point{ 32, 0 }, Paint{ Size{ 16, 16 }, Color{ 0u, 0u, 0u } }, 2u },
          new BorderView<>{ renderer, Point{ 64, 0 }, Paint{ Size{ 32, 32 }, Color{ 0u, 0u, 0u } }, 2u }
        } },
        Text::Builder{ renderer, headFont, Point{ 16, 824 }, "Modal" }.setDuration(1u).build(),
        Button::Builder{ renderer, Point{ 16, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
          .setA(255u)
          .setADuration(1u)
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
          .setOnMouseOver([]() {})
          .build(),
        Text::Builder{ renderer, bodyFont, Point{ 34, 886 }, "Modal 1" }.setDuration(1u).build(),
        Button::Builder{ renderer, Point{ 128, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
          .setA(255u)
          .setADuration(1u)
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
          .setOnMouseOver([]() {})
          .build(),
        Text::Builder{ renderer, bodyFont, Point{ 146, 886 }, "Modal 2" }.setDuration(1u).build(),
        Button::Builder{ renderer, Point{ 240, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
          .setA(255u)
          .setADuration(1u)
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
          .setOnMouseOver([]() {})
          .build(),
        Text::Builder{ renderer, bodyFont, Point{ 258, 886 }, "Modal 3" }.setDuration(1u).build(),
        Button::Builder{ renderer, Point{ 352, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
          .setA(255u)
          .setADuration(1u)
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
          .setOnMouseOver([]() {})
          .build(),
        Text::Builder{ renderer, bodyFont, Point{ 370, 886 }, "Modal 4" }.setDuration(1u).build(),
        Button::Builder{ renderer, Point{ 464, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
          .setA(255u)
          .setADuration(1u)
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
          .setOnMouseOver([]() {})
          .build(),
        Text::Builder{ renderer, bodyFont, Point{ 482, 886 }, "Modal 5" }.setDuration(1u).build(),
        Button::Builder{ renderer, Point{ 576, 872 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
          .setA(255u)
          .setADuration(1u)
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
          .setOnMouseOver([]() {})
          .build(),
        Text::Builder{ renderer, bodyFont, Point{ 594, 886 }, "Modal 6" }.setDuration(1u).build(),
        Button::Builder{ renderer, Point{ (size.w - navButtonSize.w) >> 1u, size.h - navButtonSize.h - 16 }, Paint{ navButtonSize, Color{ 192u, 192u, 255u } } }
          .setA(255u)
          .setADuration(1u)
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
          .setOnMouseOver([]() {})
          .build(),
        Text::Builder{ renderer, bodyFont, Point{ size.w >> 1u, size.h - navButtonSize.h - 2 }, "Next page", Color{ 0u, 0u, 0u }, Align::CENTER }.setDuration(1u).build(),
        new Modal<3u>{ renderer, size, Point{ (size.w - modalSize1.w) >> 1u, (size.h - modalSize1.h) >> 1u }, Paint{ modalSize1, Color{ 255u, 255u, 255u } }, &isModal1Showing, 128u, {
          Text::Builder{ renderer, headFont, Point{ 192, 48 }, "Modal 1" }.setDuration(1u).build(),
          Button::Builder{ renderer, Point{ 200, 160 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
            .setA(255u)
            .setADuration(1u)
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
            })
            .setOnClick([this]() {
              isModal1Showing.set(false);
            })
            .setOnMouseOut([]() {
              SDL_SetCursor(SDL_GetDefaultCursor());
            })
            .setOnMouseOver([]() {})
            .build(),
          Text::Builder{ renderer, bodyFont, Point{ 226, 174 }, "Close" }.setDuration(1u).build()
        } },
        new Modal<3u>{ renderer, size, Point{ (size.w - modalSize2.w) >> 1u, (size.h - modalSize2.h) >> 1u }, Paint{ modalSize2, Color{ 255u, 255u, 255u } }, &isModal2Showing, 128u, {
          Text::Builder{ renderer, headFont, Point{ 132, 32 }, "Modal 2" }.setDuration(1u).build(),
          Button::Builder{ renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
            .setA(255u)
            .setADuration(1u)
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
            })
            .setOnClick([this]() {
              isModal2Showing.set(false);
            })
            .setOnMouseOut([]() {
              SDL_SetCursor(SDL_GetDefaultCursor());
            })
            .setOnMouseOver([]() {})
            .build(),
          Text::Builder{ renderer, bodyFont, Point{ 168, 134 }, "Close" }.setDuration(1u).build()
        } },
        new Modal<3u>{ renderer, size, Point{ (size.w - modalSize2.w) >> 1u, (size.h - modalSize2.h) >> 1u }, Paint{ modalSize2, Color{ 255u, 0u, 0u } }, &isModal3Showing, 128u, {
          Text::Builder{ renderer, headFont, Point{ 132, 32 }, "Modal 3" }.setDuration(1u).build(),
          Button::Builder{ renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
            .setA(255u)
            .setADuration(1u)
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
            })
            .setOnClick([this]() {
              isModal3Showing.set(false);
            })
            .setOnMouseOut([]() {
              SDL_SetCursor(SDL_GetDefaultCursor());
            })
            .setOnMouseOver([]() {})
            .build(),
          Text::Builder{ renderer, bodyFont, Point{ 168, 134 }, "Close" }.setDuration(1u).build()
        } },
        new Modal<3u>{ renderer, size, Point{ (size.w - modalSize2.w) >> 1u, (size.h - modalSize2.h) >> 1u }, Paint{ modalSize2, Color{ 255u, 0u, 0u } }, &isModal4Showing, 128u, {
          Text::Builder{ renderer, headFont, Point{ 132, 32 }, "Modal 4" }.setDuration(1u).build(),
          Button::Builder{ renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
            .setA(255u)
            .setADuration(1u)
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
            })
            .setOnClick([this]() {
              isModal4Showing.set(false);
            })
            .setOnMouseOut([]() {
              SDL_SetCursor(SDL_GetDefaultCursor());
            })
            .setOnMouseOver([]() {})
            .build(),
          Text::Builder{ renderer, bodyFont, Point{ 168, 134 }, "Close" }.setDuration(1u).build()
        } },
        new Modal<3u>{ renderer, size, Point{ (size.w - modalSize2.w) >> 1u, (size.h - modalSize2.h) >> 1u }, Paint{ modalSize2, Color{ 255u, 0u, 0u } }, &isModal5Showing, 256u, {
          Text::Builder{ renderer, headFont, Point{ 132, 32 }, "Modal 5" }.setDuration(1u).build(),
          Button::Builder{ renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
            .setA(255u)
            .setADuration(1u)
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
            })
            .setOnClick([this]() {
              isModal5Showing.set(false);
            })
            .setOnMouseOut([]() {
              SDL_SetCursor(SDL_GetDefaultCursor());
            })
            .setOnMouseOver([]() {})
            .build(),
          Text::Builder{ renderer, bodyFont, Point{ 168, 134 }, "Close" }.setDuration(1u).build()
        } },
        new Modal<2u>{ renderer, size, Point{ (size.w - modalSize2.w) >> 1u, (size.h - modalSize2.h) >> 1u }, Paint{ modalSize2, Color{ 255u, 0u, 0u } }, &isModal6Showing, 256u, {
          Button::Builder{ renderer, Point{ 140, 120 }, Paint{ Size{ 96, 48 }, Color{ 192u, 192u, 192u } } }
            .setA(255u)
            .setADuration(1u)
            .setLightnessDuration(128u)
            .setOnMouseMove([this]() {
              SDL_SetCursor(pointer);
            })
            .setOnClick([this]() {
              isModal6Showing.set(false);
            })
            .setOnMouseOut([]() {
              SDL_SetCursor(SDL_GetDefaultCursor());
            })
            .setOnMouseOver([]() {})
            .build(),
          Text::Builder{ renderer, bodyFont, Point{ 168, 134 }, "Close" }.setDuration(1u).build()
        } }
      } },
      new Page<Path, 2u>{ renderer, Point{ 0, 0 }, Path::EMPTY, &currentPath, {
        Button::Builder{ renderer, Point{ (size.w - navButtonSize.w) >> 1u, size.h - navButtonSize.h - 16 }, Paint{ navButtonSize, Color{ 192u, 192u, 255u } } }
          .setA(255u)
          .setADuration(1u)
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
          .setOnMouseOver([]() {})
          .build(),
        Text::Builder{ renderer, bodyFont, Point{ size.w >> 1u, size.h - navButtonSize.h - 2 }, "Prev page", Color{ 0u, 0u, 0u }, Align::CENTER }.setDuration(1u).build(),
      } }
    } };
  }

  ~ViewifyViewGroupFactory() {
    SDL_FreeCursor(pointer);
    TTF_CloseFont(bodyFont);
    TTF_CloseFont(headFont);
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_TEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_
