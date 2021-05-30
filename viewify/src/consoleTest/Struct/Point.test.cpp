// Copyright ii887522

#ifdef CONSOLE_TEST

#include "Point.test.h"
#include "../../main/Struct/Point.h"
#include <nitro/Struct/Vector.h>
#include "../../main/Struct/Size.h"

using ii887522::nitro::Vector;

namespace ii887522::viewify {

constexpr static void testPointAddition() {
  static_assert((Point{ 0u, 1u } + Point{ 1u, 2u }).x == 1u);
  static_assert((Point{ 3u, 4u } + Point{ 5u, 6u }).y == 10u);
}

constexpr static void testVectorAddition() {
  static_assert((Point{ 0u, 1u } + Vector{ 1u, 2u }).x == 1u);
  static_assert((Point{ 3u, 4u } + Vector{ 5u, 6u }).y == 10u);
}

constexpr static void testSizeAddition() {
  static_assert((Point{ 0u, 1u } + Size{ 1u, 2u }).x == 1u);
  static_assert((Point{ 3u, 4u } + Size{ 5u, 6u }).y == 10u);
}

constexpr static void testPointSubtraction() {
  static_assert((Point{ 5u, 6u } - Point{ 3u, 4u }).x == 2u);
  static_assert((Point{ 1u, 2u } - Point{ 0u, 1u }).y == 1u);
}

constexpr static void testVectorSubtraction() {
  static_assert((Point{ 5u, 6u } - Vector{ 3u, 4u }).x == 2u);
  static_assert((Point{ 1u, 2u } - Vector{ 0u, 1u }).y == 1u);
}

constexpr static void testSizeSubtraction() {
  static_assert((Point{ 5u, 6u } - Size{ 3u, 4u }).x == 2u);
  static_assert((Point{ 1u, 2u } - Size{ 0u, 1u }).y == 1u);
}

constexpr static void testMultiply() {
  static_assert((Point { 1u, 2u } * 0u).x == 0u);
  static_assert((Point { 3u, 4u } * 1u).y == 4u);
  static_assert((Point { 5u, 6u } * 2u).x == 10u);
  static_assert((Point { 7u, 8u } * 3u).y == 24u);
}

void testPoint() {
  testPointAddition();
  testVectorAddition();
  testSizeAddition();
  testPointSubtraction();
  testVectorSubtraction();
  testSizeSubtraction();
  testMultiply();
}

}  // namespace ii887522::viewify

#endif
