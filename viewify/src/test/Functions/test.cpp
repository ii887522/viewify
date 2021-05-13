// Copyright ii887522

#ifdef TEST

#define ALLOCATOR_IMPLEMENTATIONS
#include <Any/allocator.h>

#include "../Struct/Point.test.h"
#include "../Functions/math_ext.test.h"
#include "../Model/ModalModel.test.h"
#include "../Model/ImageModel.test.h"
#include "../Model/ButtonModel.test.h"
#include "../Any/Map.test.h"
#include "../../main/Any/Subsystems.h"
#include "../../main/Any/App.h"
#include "../../main/Struct/Size.h"
#include "../ViewGroupFactory/ViewifyViewGroupFactory.h"
#include <SDL.h>
#include "../../main/Functions/control_flow.h"
#include "../../main/Struct/Color.h"

namespace ii887522::viewify {

static void consoleTest() {
  testPoint();
  testMathExt();
  testModalModel();
  testImageModel();
  testButtonModel();
  testMap();
}

static void guiTest() {
  const Subsystems subsystems;
  ViewifyViewGroupFactory viewifyViewGroupFactory;
  eventLoop(App{ "Test", Size{ 992, 992 }, Color{ 255u, 255u, 255u }, &viewifyViewGroupFactory });
}

static int main(int, char**) {
  consoleTest();
  guiTest();
  return 0;
}

}  // namespace ii887522::viewify

int main(int argc, char** argv) {
  return ii887522::viewify::main(argc, argv);
}

#endif
