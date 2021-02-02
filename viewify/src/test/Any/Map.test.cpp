// Copyright ii887522

#include "Map.test.h"
#include <cassert>
#include "../../main/Any/Map.h"
#include "../../main/Struct/Size.h"
#include "../../main/Struct/Point.h"

namespace ii887522::viewify {

static void testSet() {
  {
    Map<unsigned int> map{ Size{ 3u, 3u } };
    map.set(Point{ 0u, 0u }, 1u);
    assert(map.get(Point{ 0u, 0u }) == 1u);
    map.set(Point{ 1u, 1u }, 1u);
    assert(map.get(Point{ 1u, 1u }) == 1u);
    map.set(Point{ 1u, 1u }, 2u);
    assert(map.get(Point{ 1u, 1u }) == 2u);
  }
  {
    Map<unsigned int> map{ Size{ 5u, 5u } };
    map.set(Point{ 0u, 0u }, 1u);
    assert(map.get(Point{ 0u, 0u }) == 1u);
    map.set(Point{ 1u, 1u }, 1u);
    assert(map.get(Point{ 1u, 1u }) == 1u);
    map.set(Point{ 1u, 1u }, 2u);
    assert(map.get(Point{ 1u, 1u }) == 2u);
  }
}

void testMap() {
  testSet();
}

}  // namespace ii887522::viewify
