// Copyright ii887522

#ifndef VIEWIFY_SRC_GUITEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_
#define VIEWIFY_SRC_GUITEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_

#ifdef GUI_TEST

#include <nitro/nitro.h>
#include <SDL.h>
#include <vector>
#include "../../main/View/ViewGroup.h"
#include "../../main/Factory/ViewGroupFactory.h"
#include "../Any/Enums.h"
#include "../../main/Atlas/TextureAtlas.h"
#include "../../main/Atlas/GlyphAtlas.h"
#include "../../main/Struct/Size.h"
#include "../../main/Factory/PageFactory.h"

using ii887522::nitro::Reactive;
using ii887522::nitro::AnimationController;
using std::vector;

namespace ii887522::viewify {

/// <summary>See also ../../main/View/ViewGroup.h for more details</summary>
class ViewifyViewGroupFactory final : public ViewGroupFactory {
  // remove copy semantics
  ViewifyViewGroupFactory(const ViewifyViewGroupFactory&) = delete;
  ViewifyViewGroupFactory& operator=(const ViewifyViewGroupFactory&) = delete;

  // remove move semantics
  ViewifyViewGroupFactory(ViewifyViewGroupFactory&&) = delete;
  ViewifyViewGroupFactory& operator=(ViewifyViewGroupFactory&&) = delete;

  AnimationController*const animationController;
  Reactive<Path> currentPath;
  SDL_Cursor*const pointer;
  TextureAtlas* textureAtlas;
  GlyphAtlas* glyphAtlas;
  vector<PageFactory<Path>*> pageFactories;

  void freePageFactories();

 public:
  /// <param name="animationController">It must not be assigned to nullptr or integer</param>
  ViewifyViewGroupFactory(AnimationController*const animationController);

  /// <summary>See also ../View/ViewGroup.h for more details</summary>
  /// <param name="renderer">It must not be assigned to nullptr or integer</param>
  ViewGroup make(SDL_Renderer*const renderer, const Size<int>&) override;

  ~ViewifyViewGroupFactory();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_GUITEST_VIEWGROUPFACTORY_VIEWIFYVIEWGROUPFACTORY_H_
