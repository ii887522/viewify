// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FACTORY_COMPONENTFACTORY_H_
#define VIEWIFY_SRC_MAIN_FACTORY_COMPONENTFACTORY_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include "../Struct/Point.h"
#include "../View/ViewGroup.h"

namespace ii887522::viewify {

/// <summary>Not Thread Safe: it must only be used in main thread</summary>
class ComponentFactory {
  // remove copy semantics
  ComponentFactory(const ComponentFactory&) = delete;
  ComponentFactory& operator=(const ComponentFactory&) = delete;

  // remove move semantics
  ComponentFactory(ComponentFactory&&) = delete;
  ComponentFactory& operator=(ComponentFactory&&) = delete;

  SDL_Renderer*const renderer;
  const Point<int> position;

 protected:
  /// <param name="renderer">It must not be assigned to nullptr or integer</param>
  explicit constexpr ComponentFactory(SDL_Renderer*const renderer, const Point<int>& position) : renderer{ renderer }, position{ position } { }

  constexpr SDL_Renderer* getRenderer() const {
    return renderer;
  }

  constexpr const Point<int>& getPosition() const {
    return position;
  }

 public:
  /// <summary>It must be called to make a component.</summary>
  virtual ViewGroup* make() = 0;

  virtual ~ComponentFactory();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_FACTORY_COMPONENTFACTORY_H_
