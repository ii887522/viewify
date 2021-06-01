// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FACTORY_VIEWGROUPFACTORY_H_
#define VIEWIFY_SRC_MAIN_FACTORY_VIEWGROUPFACTORY_H_

#ifndef CONSOLE_TEST

#include "../View/ViewGroup.h"
#include <SDL.h>
#include "../Struct/Size.h"

namespace ii887522::viewify {

/// <summary>See also ../View/ViewGroup.h for more details</summary>
struct ViewGroupFactory {
  // remove copy semantics
  ViewGroupFactory(const ViewGroupFactory&) = delete;
  ViewGroupFactory& operator=(const ViewGroupFactory&) = delete;

  // remove move semantics
  ViewGroupFactory(ViewGroupFactory&&) = delete;
  ViewGroupFactory& operator=(ViewGroupFactory&&) = delete;

  /// <summary>See also ../View/ViewGroup.h for more details</summary>
  constexpr ViewGroupFactory() { }

  /// <summary>See also ../View/ViewGroup.h for more details</summary>
  /// <param name="renderer">It must not be assigned to nullptr or integer</param>
  virtual ViewGroup make(SDL_Renderer*const renderer, const Size<int>&) = 0;

  virtual ~ViewGroupFactory();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_FACTORY_VIEWGROUPFACTORY_H_
