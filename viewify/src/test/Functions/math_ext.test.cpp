// Copyright ii887522

#ifdef TEST

#include "math_ext.test.h"  // NOLINT(build/include_subdir)
#include <nitro/Struct/Range.h>
#include <cassert>
#include "../../main/Functions/math_ext.h"
#include "../../main/Struct/Point.h"
#include "../../main/Struct/Size.h"
#include "../../main/Struct/Rect.h"

using ii887522::nitro::Range;

namespace ii887522::viewify {

constexpr static void testIsPointAndRectOverlap() {
  static_assert(!isOverlap(Point{ 0u, 0u }, Rect{ Point{ 1u, 1u }, Size{ 3u, 3u } }));
  static_assert(isOverlap(Point{ 1u, 1u }, Rect{ Point{ 1u, 1u }, Size{ 3u, 3u } }));
  static_assert(isOverlap(Point{ 2u, 2u }, Rect{ Point{ 1u, 1u }, Size{ 3u, 3u } }));
  static_assert(isOverlap(Point{ 3u, 3u }, Rect{ Point{ 1u, 1u }, Size{ 3u, 3u } }));
  static_assert(!isOverlap(Point{ 4u, 4u }, Rect{ Point{ 1u, 1u }, Size{ 3u, 3u } }));
  static_assert(!isOverlap(Point{ 0u, 0u }, Rect{ Point{ 2u, 2u }, Size{ 5u, 5u } }));
  static_assert(isOverlap(Point{ 2u, 2u }, Rect{ Point{ 2u, 2u }, Size{ 5u, 5u } }));
  static_assert(isOverlap(Point{ 4u, 4u }, Rect{ Point{ 2u, 2u }, Size{ 5u, 5u } }));
  static_assert(isOverlap(Point{ 6u, 6u }, Rect{ Point{ 2u, 2u }, Size{ 5u, 5u } }));
  static_assert(!isOverlap(Point{ 8u, 8u }, Rect{ Point{ 2u, 2u }, Size{ 5u, 5u } }));
}

constexpr static void testIsRectAndRectOverlap() {
  static_assert(!isOverlap(Rect{ Point{ 1, 1 }, Size{ 3, 3 } }, Rect{ Point{ 4, 4 }, Size{ 4, 4 } }));
  static_assert(isOverlap(Rect{ Point{ 4, 4 }, Size{ 5, 5 } }, Rect{ Point{ 3, 3 }, Size{ 3, 3 } }));
  static_assert(isOverlap(Rect{ Point{ 0, 4 }, Size{ 5, 5 } }, Rect{ Point{ 3, 3 }, Size{ 3, 3 } }));
  static_assert(isOverlap(Rect{ Point{ 0, 0 }, Size{ 5, 5 } }, Rect{ Point{ 3, 3 }, Size{ 3, 3 } }));
  static_assert(isOverlap(Rect{ Point{ 4, 0 }, Size{ 5, 5 } }, Rect{ Point{ 3, 3 }, Size{ 3, 3 } }));
}

void testMathExt() {
  testIsPointAndRectOverlap();
  testIsRectAndRectOverlap();
}

}  // namespace ii887522::viewify

#endif
