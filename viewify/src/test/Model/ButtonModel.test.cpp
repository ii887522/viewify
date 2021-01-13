// Copyright ii887522

#ifdef TEST

#include "ButtonModel.test.h"
#include <Struct/Range.h>
#include <cassert>
#include "../../main/Model/ButtonModel.h"
#include "../../main/Struct/Rect.h"
#include "../../main/Struct/Point.h"
#include "../../main/Struct/Size.h"
#include "../../main/Functions/math_ext.h"

using ii887522::nitro::Range;

namespace ii887522::viewify {

static void testBuild() {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    assert(model.getA() == 255);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    assert(model.getA() == 255);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([&p]() {
          ++p;
        })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    assert(model.getA() == 255);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  try {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([&p]() {
          ++p;
        })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
  } catch (const runtime_error&) {
    try {
      auto n{ 0u };
      auto p{ 0u };
      ButtonModel model{
        ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
          .setADuration(250u)
          .setLightnessDuration(250u)
          .setOnMouseOut([&p]() {
            ++p;
          })
          .setOnClick([&n]() {
            ++n;
          })
          .build()
      };
    } catch (const runtime_error&) {
      try {
        auto m{ 0u };
        auto n{ 0u };
        ButtonModel model{
          ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
            .setADuration(250u)
            .setLightnessDuration(250u)
            .setOnMouseOver([&m]() {
              ++m;
            })
            .setOnClick([&n]() {
              ++n;
            })
            .build()
        };
      } catch (const runtime_error&) {
        try {
          auto m{ 0u };
          auto p{ 0u };
          ButtonModel model{
            ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
              .setADuration(250u)
              .setLightnessDuration(250u)
              .setOnMouseOver([&m]() {
                ++m;
              })
              .setOnMouseOut([&p]() {
                ++p;
              })
              .build()
          };
        } catch (const runtime_error&) {
          return;
        }
      }
    }
  }
  assert(false);
}

static void testReactMouseMotion() {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 2, 2 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 2, 2 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 2, 2 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 2, 2 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([&p]() {
          ++p;
        })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
    model.reactMouseMotion(Point{ 8, 8 });
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
}  // NOLINT(readability/fn_size)

static void testReactLeftMouseButtonDown() {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 2, 2 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
  }
  {
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
  }
  {
    auto m{ 1u };
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
  }
  {
    auto m{ 1u };
    auto n{ 1u };
    auto p{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([&p]() {
          ++p;
        })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == pressedLightness);
  }
}

static void testReactLeftMouseButtonUp() {
  {
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    assert(n == 1u);
    model.reactMouseMotion(Point{ 2, 2 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    assert(n == 2u);
  }
  {
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    assert(n == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    assert(n == 2u);
  }
  {
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    assert(n == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    assert(n == 2u);
  }
  {
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          --n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    assert(n == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    assert(n == 0u);
  }
  {
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          --n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    assert(n == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    assert(n == 0u);
  }
  {
    auto m{ 1u };
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseOver([&m]() {
          --m;
        })
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          --n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    assert(m == 1u);
    assert(n == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    assert(m == 0u);
    assert(n == 0u);
  }
  {
    auto m{ 1u };
    auto n{ 1u };
    auto p{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseOver([&m]() {
          --m;
        })
        .setOnMouseOut([&p]() {
          --p;
        })
        .setOnClick([&n]() {
          --n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
    assert(m == 1u);
    assert(n == 1u);
    assert(p == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == hoveredLightness);
    assert(m == 0u);
    assert(n == 0u);
    assert(p == 1u);
  }
}

static void testReactMouseLeaveWindow() {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseLeaveWindow();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseLeaveWindow();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseLeaveWindow();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseLeaveWindow();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseLeaveWindow();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseLeaveWindow();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([&p]() {
          ++p;
        })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseLeaveWindow();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
}

static void testShow() {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.show();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.show();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.show();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.show();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.show();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.show();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([&p]() {
          ++p;
        })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.show();
    assert(model.getA() == 1);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
}

static void testHide() {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.hide();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.hide();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.hide();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.hide();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.hide();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.hide();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([&p]() {
          ++p;
        })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.hide();
    assert(model.getA() == 0);
    assert(model.getLightness() == initialLightness);
    assert(model.getEndLightness() == initialLightness);
  }
}

static void testStep() {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseMotion(Point{ 2, 2 });
    model.step(15u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(20u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(25u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(30u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(35u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    assert(model.getEndLightness() == hoveredLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseMotion(Point{ 4, 4 });
    model.step(15u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(20u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(25u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(30u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(35u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    assert(model.getEndLightness() == hoveredLightness);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(250u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([]() { })
        .build()
    };
    model.reactMouseMotion(Point{ 4, 4 });
    model.step(30u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(40u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(50u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(60u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(70u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    assert(model.getEndLightness() == hoveredLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(250u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 4, 4 });
    model.step(30u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(40u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(50u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(60u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(70u);
    assert(model.getA() == 0);
    assert(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    assert(model.getEndLightness() == hoveredLightness);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(250u)
        .setOnMouseOver([]() { })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 4, 4 });
    model.step(30u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(40u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(50u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(60u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(70u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    assert(model.getEndLightness() == hoveredLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() { })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 4, 4 });
    model.step(30u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(40u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(50u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(60u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(70u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    assert(model.getEndLightness() == hoveredLightness);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([&p]() {
          ++p;
        })
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 4, 4 });
    model.step(30u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(40u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(50u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(60u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    assert(model.getEndLightness() == hoveredLightness);
    model.step(70u);
    assert(model.getA() == 1);
    assert(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    assert(model.getEndLightness() == hoveredLightness);
  }
}  // NOLINT(readability/fn_size)

void testButtonModel() {
  testBuild();
  testReactMouseMotion();
  testReactLeftMouseButtonDown();
  testReactLeftMouseButtonUp();
  testReactMouseLeaveWindow();
  testShow();
  testHide();
  testStep();
}

}  // namespace ii887522::viewify

#endif
