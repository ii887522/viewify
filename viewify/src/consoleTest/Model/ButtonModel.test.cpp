// Copyright ii887522

#ifdef CONSOLE_TEST

#include <nitro/nitro.h>
#include <catch.hpp>
#include "../../main/Model/ButtonModel.h"
#include "../../main/Struct/Rect.h"
#include "../../main/Struct/Point.h"
#include "../../main/Struct/Size.h"
#include "../../main/Functions/math_ext.h"

using ii887522::nitro::Range;

namespace ii887522::viewify {

TEST_CASE("test ButtonModel::Builder::build() function") {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    REQUIRE(model.getA() == 255);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    REQUIRE(model.getA() == 255);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([]() {})
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
    REQUIRE(model.getA() == 255);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    auto q{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([&q]() {
          ++q;
        })
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
    REQUIRE(model.getA() == 255);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    auto q{ 0u };
    REQUIRE_THROWS(
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setOnMouseMove([&q]() {
          ++q;
        })
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([&p]() {
          ++p;
        })
        .setOnClick([&n]() {
          ++n;
        })
        .build());
  }
  {
    auto n{ 0u };
    auto p{ 0u };
    auto q{ 0u };
    REQUIRE_THROWS(
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([&q]() {
          ++q;
          })
        .setOnMouseOut([&p]() {
          ++p;
        })
        .setOnClick([&n]() {
          ++n;
        })
        .build());
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto q{ 0u };
    REQUIRE_THROWS(
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([&q]() {
          ++q;
        })
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnClick([&n]() {
          ++n;
        })
        .build());
  }
  {
    auto m{ 0u };
    auto p{ 0u };
    auto q{ 0u };
    REQUIRE_THROWS(
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([&q]() {
          ++q;
        })
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([&p]() {
          ++p;
        })
        .build());
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    REQUIRE_THROWS(
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
        .build());
  }
}

TEST_CASE("test ButtonModel::reactMouseMotion() function") {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    model.reactMouseMotion(Point{ 2, 2 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.reactMouseMotion(Point{ 2, 2 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    model.reactMouseMotion(Point{ 2, 2 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 2, 2 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 2u);
    REQUIRE(n == 0u);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    REQUIRE(m == 2u);
    REQUIRE(n == 0u);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 2u);
    REQUIRE(n == 0u);
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
        .setOnMouseMove([]() {})
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
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 2u);
    REQUIRE(n == 0u);
    REQUIRE(p == 1u);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    REQUIRE(m == 2u);
    REQUIRE(n == 0u);
    REQUIRE(p == 1u);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 2u);
    REQUIRE(n == 0u);
    REQUIRE(p == 2u);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    auto q{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([&q]() {
          ++q;
        })
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
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 0u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 2u);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 1u);
    REQUIRE(q == 2u);
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 2u);
    REQUIRE(n == 0u);
    REQUIRE(p == 1u);
    REQUIRE(q == 3u);
    model.reactLeftMouseButtonDown();
    model.reactMouseMotion(Point{ 4, 4 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    REQUIRE(m == 2u);
    REQUIRE(n == 0u);
    REQUIRE(p == 1u);
    REQUIRE(q == 4u);
    model.reactMouseMotion(Point{ 8, 8 });
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 2u);
    REQUIRE(n == 0u);
    REQUIRE(p == 2u);
    REQUIRE(q == 4u);
  }
}

TEST_CASE("test ButtonModel::reactLeftMouseButtonDown() function") {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 2, 2 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
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
        .setOnMouseMove([]() {})
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
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
  }

  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    auto q{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([&q]() {
          ++q;
        })
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
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 0u);
    model.reactLeftMouseButtonUp();
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == PRESSED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 1u);
  }
}

TEST_CASE("test ButtonModel::reactLeftMouseButtonUp() function") {
  {
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 1u);
    model.reactMouseMotion(Point{ 2, 2 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 2u);
  }
  {
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 2u);
  }
  {
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 2u);
  }
  {
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          --n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          --n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 0, 0 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto m{ 1u };
    auto n{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
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
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
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
        .setOnMouseMove([]() {})
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
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 1u);
    REQUIRE(p == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    REQUIRE(p == 1u);
  }
  {
    auto m{ 1u };
    auto n{ 1u };
    auto p{ 1u };
    auto q{ 1u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([&q]() {
          --q;
        })
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
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 1u);
    REQUIRE(p == 1u);
    REQUIRE(q == 1u);
    model.reactMouseMotion(Point{ 4, 4 });
    model.reactLeftMouseButtonDown();
    model.reactLeftMouseButtonUp();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    REQUIRE(p == 1u);
    REQUIRE(q == 0u);
  }
}

TEST_CASE("test ButtonModel::reactMouseLeaveWindow() function") {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseLeaveWindow();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseLeaveWindow();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseLeaveWindow();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseLeaveWindow();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseLeaveWindow();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseLeaveWindow();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
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
        .setOnMouseMove([]() {})
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
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    auto q{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([&q]() {
          ++q;
        })
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
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 0u);
  }
}

TEST_CASE("test ButtonModel::show() function") {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.show();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.show();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.show();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.show();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.show();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.show();
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
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
        .setOnMouseMove([]() {})
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
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    auto q{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([&q]() {
          ++q;
        })
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
    REQUIRE(model.getA() == 1);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 0u);
  }
}

TEST_CASE("test ButtonModel::hide() function") {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.hide();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.hide();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.hide();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.hide();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.hide();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.hide();
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
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
        .setOnMouseMove([]() {})
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
    REQUIRE(model.getA() == 0);
    REQUIRE(model.getLightness() == INITIAL_LIGHTNESS);
    REQUIRE(model.getEndLightness() == INITIAL_LIGHTNESS);
    REQUIRE(m == 0u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
  }
}

TEST_CASE("test ButtonModel::step() function") {
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 1, 1 }, Size{ 3, 3 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseMotion(Point{ 2, 2 });
    model.step(15u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(20u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(25u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(30u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(35u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(125u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseMotion(Point{ 4, 4 });
    model.step(15u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(20u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(25u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(30u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(35u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
  }
  {
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(250u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([]() {})
        .build()
    };
    model.reactMouseMotion(Point{ 4, 4 });
    model.step(30u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(40u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(50u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(60u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    model.step(70u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(0u)
        .setADuration(125u)
        .setLightnessDuration(250u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 4, 4 });
    model.step(30u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.step(40u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.step(50u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.step(60u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.step(70u);
    REQUIRE(model.getA() == 0);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(125u)
        .setLightnessDuration(250u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([]() {})
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 4, 4 });
    model.step(30u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.step(40u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.step(50u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.step(60u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
    model.step(70u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(n == 0u);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([]() {})
        .setOnMouseOver([&m]() {
          ++m;
        })
        .setOnMouseOut([]() {})
        .setOnClick([&n]() {
          ++n;
        })
        .build()
    };
    model.reactMouseMotion(Point{ 4, 4 });
    model.step(30u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    model.step(40u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    model.step(50u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    model.step(60u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    model.step(70u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
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
        .setOnMouseMove([]() {})
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
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    model.step(40u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    model.step(50u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    model.step(60u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    model.step(70u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
  }
  {
    auto m{ 0u };
    auto n{ 0u };
    auto p{ 0u };
    auto q{ 0u };
    ButtonModel model{
      ButtonModel::Builder{ Rect{ Point{ 2, 2 }, Size{ 5, 5 } } }
        .setA(1u)
        .setADuration(250u)
        .setLightnessDuration(250u)
        .setOnMouseMove([&q]() {
          ++q;
        })
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
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9879f, .9881f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 1u);
    model.step(40u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9719f, .9721f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 1u);
    model.step(50u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9519f, .9521f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 1u);
    model.step(60u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .9279f, .9281f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 1u);
    model.step(70u);
    REQUIRE(model.getA() == 1);
    REQUIRE(isOverlapX(model.getLightness(), Range{ .89f, .91f }));
    REQUIRE(model.getEndLightness() == HOVERED_LIGHTNESS);
    REQUIRE(m == 1u);
    REQUIRE(n == 0u);
    REQUIRE(p == 0u);
    REQUIRE(q == 1u);
  }
}

}  // namespace ii887522::viewify

#endif
