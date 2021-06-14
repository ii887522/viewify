// Copyright ii887522

#ifdef CONSOLE_TEST

#include <nitro/nitro.h>
#include <catch.hpp>
#include "../../main/Functions/math_ext.h"
#include "../../main/Struct/Point.h"
#include "../../main/Struct/Size.h"
#include "../../main/Struct/Rect.h"
#include "../Any/FontName.h"

using ii887522::nitro::Range;

namespace ii887522::viewify {

TEST_CASE("test isPointAndRectOverlap() function") {
  REQUIRE_FALSE(isOverlap(Point{ 0u, 0u }, Rect{ Point{ 1u, 1u }, Size{ 3u, 3u } }));
  REQUIRE(isOverlap(Point{ 1u, 1u }, Rect{ Point{ 1u, 1u }, Size{ 3u, 3u } }));
  REQUIRE(isOverlap(Point{ 2u, 2u }, Rect{ Point{ 1u, 1u }, Size{ 3u, 3u } }));
  REQUIRE(isOverlap(Point{ 3u, 3u }, Rect{ Point{ 1u, 1u }, Size{ 3u, 3u } }));
  REQUIRE_FALSE(isOverlap(Point{ 4u, 4u }, Rect{ Point{ 1u, 1u }, Size{ 3u, 3u } }));
  REQUIRE_FALSE(isOverlap(Point{ 0u, 0u }, Rect{ Point{ 2u, 2u }, Size{ 5u, 5u } }));
  REQUIRE(isOverlap(Point{ 2u, 2u }, Rect{ Point{ 2u, 2u }, Size{ 5u, 5u } }));
  REQUIRE(isOverlap(Point{ 4u, 4u }, Rect{ Point{ 2u, 2u }, Size{ 5u, 5u } }));
  REQUIRE(isOverlap(Point{ 6u, 6u }, Rect{ Point{ 2u, 2u }, Size{ 5u, 5u } }));
  REQUIRE_FALSE(isOverlap(Point{ 8u, 8u }, Rect{ Point{ 2u, 2u }, Size{ 5u, 5u } }));
}

TEST_CASE("test isRectAndRectOverlap() function") {
  REQUIRE_FALSE(isOverlap(Rect{ Point{ 1, 1 }, Size{ 3, 3 } }, Rect{ Point{ 4, 4 }, Size{ 4, 4 } }));
  REQUIRE(isOverlap(Rect{ Point{ 4, 4 }, Size{ 5, 5 } }, Rect{ Point{ 3, 3 }, Size{ 3, 3 } }));
  REQUIRE(isOverlap(Rect{ Point{ 0, 4 }, Size{ 5, 5 } }, Rect{ Point{ 3, 3 }, Size{ 3, 3 } }));
  REQUIRE(isOverlap(Rect{ Point{ 0, 0 }, Size{ 5, 5 } }, Rect{ Point{ 3, 3 }, Size{ 3, 3 } }));
  REQUIRE(isOverlap(Rect{ Point{ 4, 0 }, Size{ 5, 5 } }, Rect{ Point{ 3, 3 }, Size{ 3, 3 } }));
}

TEST_CASE("test distanceSqr() function") {
  REQUIRE(distanceSqr(Point{ 0, 0 }, Point{ 0, 0 }) == 0);
  REQUIRE(distanceSqr(Point{ 1, 0 }, Point{ 0, 0 }) == 1);
  REQUIRE(distanceSqr(Point{ 1, 1 }, Point{ 0, 0 }) == 2);
  REQUIRE(distanceSqr(Point{ 1, 1 }, Point{ 1, 0 }) == 1);
  REQUIRE(distanceSqr(Point{ 1, 1 }, Point{ 1, 1 }) == 0);
}

TEST_CASE("test getGlyphI() function") {
  REQUIRE(getGlyphI(static_cast<unsigned int>(FontName::_ARIAL), ' ') == 0u);
  REQUIRE(getGlyphI(static_cast<unsigned int>(FontName::_ARIAL), '!') == 1u);
  REQUIRE(getGlyphI(static_cast<unsigned int>(FontName::_ARIAL), '"') == 2u);
  REQUIRE(getGlyphI(static_cast<unsigned int>(FontName::_BASKVILL), '"') == 97u);
  REQUIRE(getGlyphI(static_cast<unsigned int>(FontName::_BAUHS93), '"') == 192u);
}

TEST_CASE("test getKerningSizeI() function") {
  REQUIRE(getKerningSizeI(' ', ' ') == 0u);
  REQUIRE(getKerningSizeI(' ', '!') == 1u);
  REQUIRE(getKerningSizeI(' ', '"') == 2u);
  REQUIRE(getKerningSizeI('!', '"') == 97u);
  REQUIRE(getKerningSizeI('"', '"') == 192u);
}

}  // namespace ii887522::viewify

#endif
