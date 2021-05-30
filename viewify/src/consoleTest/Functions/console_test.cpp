// Copyright ii887522

#ifdef CONSOLE_TEST

#define ALLOCATOR_IMPLEMENTATIONS
#include <nitro/Any/allocator.h>

#include "../Struct/Point.test.h"
#include "../Functions/math_ext.test.h"
#include "../Model/ModalModel.test.h"
#include "../Model/ImageModel.test.h"
#include "../Model/ButtonModel.test.h"
#include "../Any/Map.test.h"
#include "../Any/QuadTree.test.h"

namespace ii887522::viewify {

static int main(int, char**) {
  testPoint();
  testMathExt();
  testModalModel();
  testImageModel();
  testButtonModel();
  testMap();
  testQuadTree();
  return EXIT_SUCCESS;
}

}  // namespace ii887522::viewify

int main(int argc, char** argv) {
  return ii887522::viewify::main(argc, argv);
}

#endif
