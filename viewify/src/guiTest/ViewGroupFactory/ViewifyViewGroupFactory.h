// Copyright ii887522

#ifndef VIEWIFY_SRC_GUITEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_
#define VIEWIFY_SRC_GUITEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_

#ifdef GUI_TEST

#include <nitro/nitro.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <random>
#include "../../main/Factory/ViewGroupFactory.h"
#include "../../main/View/ViewGroup.h"
#include "../../main/Struct/Size.h"
#include "../../main/Any/Map.h"
#include "../Any/Enums.h"
#include "../../main/Atlas/TextureAtlas.h"
#include "../../main/Atlas/GlyphAtlas.h"

using ii887522::nitro::Reactive;
using std::uniform_int_distribution;
using std::default_random_engine;

namespace ii887522::viewify {

/// <summary>See also ../../main/View/ViewGroup.h for more details</summary>
class ViewifyViewGroupFactory final : public ViewGroupFactory {
  // remove copy semantics
  ViewifyViewGroupFactory(const ViewifyViewGroupFactory&) = delete;
  ViewifyViewGroupFactory& operator=(const ViewifyViewGroupFactory&) = delete;

  // remove move semantics
  ViewifyViewGroupFactory(ViewifyViewGroupFactory&&) = delete;
  ViewifyViewGroupFactory& operator=(ViewifyViewGroupFactory&&) = delete;

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
  TextureAtlas* textureAtlas;
  GlyphAtlas* glyphAtlas;

 public:
  /// <summary>See also ../../main/View/ViewGroup.h for more details</summary>
  ViewifyViewGroupFactory();

  /// <summary>See also ../View/ViewGroup.h for more details</summary>
  /// <param name="renderer">It must not be assigned to integer</param>
  ViewGroup make(SDL_Renderer*const renderer, const Size<int>& size) override;

  ~ViewifyViewGroupFactory();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_GUITEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_
