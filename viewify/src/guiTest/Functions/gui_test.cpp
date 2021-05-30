// Copyright ii887522

#ifdef GUI_TEST

#define ALLOCATOR_IMPLEMENTATIONS
#include <nitro/Any/allocator.h>

#include <SDL.h>
#include "../../main/Any/Subsystems.h"
#include "../ViewGroupFactory/ViewifyViewGroupFactory.h"
#include "../../main/Any/App.h"
#include "../../main/Functions/control_flow.h"
#include "../../main/Struct/Size.h"
#include "../../main/Struct/Color.h"

namespace ii887522::viewify {

static int main(int, char**) {
  const Subsystems subsystems;
  ViewifyViewGroupFactory viewifyViewGroupFactory;
  eventLoop(App{ "Test", Size{ 992, 992 }, Color{ 255u, 255u, 255u, 255u }, &viewifyViewGroupFactory });
  return EXIT_SUCCESS;
}

}  // namespace ii887522::viewify

int main(int argc, char** argv) {
  return ii887522::viewify::main(argc, argv);
}

#endif
