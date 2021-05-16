// Copyright ii887522

#ifdef TEST

#ifndef VIEWIFY_SRC_TEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_
#define VIEWIFY_SRC_TEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_

#include <nitro/Any/Reactive.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <random>
#include "../../main/Factory/ViewGroupFactory.h"
#include "../../main/View/ViewGroup.h"
#include "../../main/Struct/Size.h"
#include "../../main/Any/Map.h"
#include "../Any/Enums.h"

using ii887522::nitro::Reactive;
using std::uniform_int_distribution;
using std::default_random_engine;

namespace ii887522::viewify {

// See also ../../main/View/ViewGroup.h for more details
class ViewifyViewGroupFactory final : public ViewGroupFactory {
  // remove copy semantics
  ViewifyViewGroupFactory(const ViewifyViewGroupFactory&) = delete;
  ViewifyViewGroupFactory& operator=(const ViewifyViewGroupFactory&) = delete;

  // remove move semantics
  ViewifyViewGroupFactory(ViewifyViewGroupFactory&&) = delete;
  ViewifyViewGroupFactory& operator=(ViewifyViewGroupFactory&&) = delete;

  const Size<int> modalSize1;
  const Size<int> modalSize2;
  const Size<int> navButtonSize;
  TTF_Font*const headFont;
  TTF_Font*const bodyFont;
  Reactive<bool> canIncrementScore0;
  Reactive<bool> canResetScore0;
  Reactive<bool> canIncrementScore1;
  Reactive<bool> canResetScore1;
  Reactive<bool> isModal1Showing;
  Reactive<bool> isModal2Showing;
  Reactive<bool> isModal3Showing;
  Reactive<bool> isModal4Showing;
  Reactive<bool> isModal5Showing;
  Reactive<bool> isModal6Showing;
  Reactive<Path> currentPath;
  Map<CellType> map;
  SDL_Cursor*const pointer;
  uniform_int_distribution<unsigned int> colorComponents;
  default_random_engine randomEngine;

 public:
  // See also ../../main/View/ViewGroup.h for more details
  ViewifyViewGroupFactory();

  // Param renderer: it must not be assigned to integer
  // See also ../View/ViewGroup.h for more details
  ViewGroup make(SDL_Renderer*const renderer, const Size<int>& size) override;

  ~ViewifyViewGroupFactory();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_TEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_
