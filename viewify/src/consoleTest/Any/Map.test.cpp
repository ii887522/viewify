// Copyright ii887522

#ifdef CONSOLE_TEST

#include <catch.hpp>
#include "../../main/Any/Map.h"
#include "../../main/Struct/Size.h"
#include "../../main/Struct/Point.h"

namespace ii887522::viewify {

TEST_CASE("test Map<T>::operator[]() function") {
  {
    Map<unsigned int> map{ Size{ 3u, 3u } };
    map[Point{ 0u, 0u }] = 1u;
    REQUIRE(map[Point{ 0u, 0u }] == 1u);
    map[Point{ 1u, 1u }] = 1u;
    REQUIRE(map[Point{ 1u, 1u }] == 1u);
    map[Point{ 1u, 1u }] = 2u;
    REQUIRE(map[Point{ 1u, 1u }] == 2u);
  }
  {
    Map<unsigned int> map{ Size{ 5u, 5u } };
    map[Point{ 0u, 0u }] = 1u;
    REQUIRE(map[Point{ 0u, 0u }] == 1u);
    map[Point{ 1u, 1u }] = 1u;
    REQUIRE(map[Point{ 1u, 1u }] == 1u);
    map[Point{ 1u, 1u }] = 2u;
    REQUIRE(map[Point{ 1u, 1u }] == 2u);
  }
}

}  // namespace ii887522::viewify

#endif
