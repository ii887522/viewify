// Copyright ii887522

#ifdef CONSOLE_TEST

#include <nitro/nitro.h>
#include <catch.hpp>
#include "../../main/Struct/Point.h"
#include "../../main/Struct/Size.h"

using ii887522::nitro::Vector;

namespace ii887522::viewify {

TEST_CASE("test Point<T>::operator+(const Point<U>&) function") {
  REQUIRE((Point{ 0u, 1u } + Point{ 1u, 2u }).x == 1u);
  REQUIRE((Point{ 3u, 4u } + Point{ 5u, 6u }).y == 10u);
}

TEST_CASE("test Point<T>::operator+(const Vector<U>&) function") {
  REQUIRE((Point{ 0u, 1u } + Vector{ 1u, 2u }).x == 1u);
  REQUIRE((Point{ 3u, 4u } + Vector{ 5u, 6u }).y == 10u);
}

TEST_CASE("test Point<T>::operator+(const Size<U>&) function") {
  REQUIRE((Point{ 0u, 1u } + Size{ 1u, 2u }).x == 1u);
  REQUIRE((Point{ 3u, 4u } + Size{ 5u, 6u }).y == 10u);
}

TEST_CASE("test Point<T>::operator-(const Point<U>&) function") {
  REQUIRE((Point{ 5u, 6u } - Point{ 3u, 4u }).x == 2u);
  REQUIRE((Point{ 1u, 2u } - Point{ 0u, 1u }).y == 1u);
}

TEST_CASE("test Point<T>::operator-(const Vector<U>&) function") {
  REQUIRE((Point{ 5u, 6u } - Vector{ 3u, 4u }).x == 2u);
  REQUIRE((Point{ 1u, 2u } - Vector{ 0u, 1u }).y == 1u);
}

TEST_CASE("test Point<T>::operator-(const Size<U>&) function") {
  REQUIRE((Point{ 5u, 6u } - Size{ 3u, 4u }).x == 2u);
  REQUIRE((Point{ 1u, 2u } - Size{ 0u, 1u }).y == 1u);
}

TEST_CASE("test Point<T>::operator*(const Point<U>&) function") {
  REQUIRE((Point { 1u, 2u } * 0u).x == 0u);
  REQUIRE((Point { 3u, 4u } * 1u).y == 4u);
  REQUIRE((Point { 5u, 6u } * 2u).x == 10u);
  REQUIRE((Point { 7u, 8u } * 3u).y == 24u);
}

}  // namespace ii887522::viewify

#endif
