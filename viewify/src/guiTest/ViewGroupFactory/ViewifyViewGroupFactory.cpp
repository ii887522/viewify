// Copyright ii887522

#ifdef GUI_TEST

#include "ViewifyViewGroupFactory.h"
#include <nitro/nitro.h>
#include <SDL.h>
#include <vector>
#include "../../main/View/ViewGroup.h"
#include "../../main/Struct/Point.h"
#include "../../main/Struct/Size.h"
#include "../Any/Enums.h"
#include "../../main/Atlas/TextureAtlas.h"
#include "../../main/Atlas/GlyphAtlas.h"
#include "../../main/Any/View.h"
#include "../Page/Page1Factory.h"
#include "../Page/Page2Factory.h"

using std::vector;
using ii887522::nitro::AnimationController;

namespace ii887522::viewify {

ViewifyViewGroupFactory::ViewifyViewGroupFactory(AnimationController*const animationController) : animationController{ animationController }, currentPath{ Path::PAGE1 },
  pointer{ SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND) }, textureAtlas{ nullptr }, glyphAtlas{ nullptr } { }

ViewGroup ViewifyViewGroupFactory::make(SDL_Renderer*const renderer, const Size<int>& size) {
  textureAtlas = new TextureAtlas{ renderer, "res/test/images/" };
  glyphAtlas = new GlyphAtlas{ renderer, "res/test/fonts/" };
  pageFactories = {
    Page1Factory::Builder{ }
      .setAnimationController(animationController)
      .setRenderer(renderer)
      .setTextureAtlas(textureAtlas)
      .setGlyphAtlas(glyphAtlas)
      .setPointer(pointer)
      .setCurrentPath(&currentPath)
      .build(),
    Page2Factory::Builder{ }
      .setAnimationController(animationController)
      .setRenderer(renderer)
      .setGlyphAtlas(glyphAtlas)
      .setPointer(pointer)
      .setCurrentPath(&currentPath)
      .build()
  };
  return ViewGroup{ renderer, Point{ 0, 0 }, [this, size](ViewGroup*const, SDL_Renderer*const) {
    vector<View*> views(pageFactories.size());
    for (auto i{ 0u }; i != views.size(); ++i) views[i] = pageFactories[i]->make(size);
    return views;
  } };
}

void ViewifyViewGroupFactory::freePageFactories() {
  for (const auto pageFactory : pageFactories) delete pageFactory;
}

ViewifyViewGroupFactory::~ViewifyViewGroupFactory() {
  freePageFactories();
  delete glyphAtlas;
  delete textureAtlas;
  SDL_FreeCursor(pointer);
}

}  // namespace ii887522::viewify

#endif
