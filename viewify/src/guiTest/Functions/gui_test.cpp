// Copyright ii887522

#ifdef GUI_TEST

#define ALLOCATOR_IMPLEMENTATIONS
#include <nitro/nitro.h>

#include <SDL.h>
#include "../../main/Any/Subsystems.h"
#include "../ViewGroupFactory/ViewifyViewGroupFactory.h"
#include "../../main/Any/App.h"
#include "../../main/Functions/control_flow.h"
#include "../../main/Struct/Size.h"
#include "../../main/Struct/Color.h"
#include "../../main/Struct/Paint.h"

using ii887522::nitro::AnimationController;

namespace ii887522::viewify {

static int main(int, char**) {
  const Subsystems subsystems;
  AnimationController animationController;
  ViewifyViewGroupFactory viewifyViewGroupFactory{ &animationController };
  eventLoop(App::Builder{ "Test", Paint{ Size{ 1280, 992 }, Color{ 255u, 255u, 255u, 255u } } }.setSceneFactory(&viewifyViewGroupFactory).build(), &animationController);
  return EXIT_SUCCESS;
}

}  // namespace ii887522::viewify

int main(int argc, char** argv) {
  return ii887522::viewify::main(argc, argv);
}

#endif
