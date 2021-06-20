// Copyright ii887522

#ifndef VIEWIFY_SRC_GUITEST_PAGE_PAGE1FACTORY_H_
#define VIEWIFY_SRC_GUITEST_PAGE_PAGE1FACTORY_H_

#ifdef GUI_TEST

#include <nitro/nitro.h>
#include <SDL.h>
#include <random>
#include "../../main/Factory/PageFactory.h"
#include "../../main/Struct/Size.h"
#include "../../main/Any/Map.h"
#include "../Any/Enums.h"
#include "../../main/Atlas/TextureAtlas.h"
#include "../../main/Atlas/GlyphAtlas.h"
#include "../../main/ViewGroup/Page.h"

using ii887522::nitro::Reactive;
using std::uniform_int_distribution;
using std::default_random_engine;

namespace ii887522::viewify {

/// <summary>Not Thread Safe: it must only be used in main thread</summary>
class Page1Factory final : public PageFactory<Path> {
  // remove copy semantics
  Page1Factory(const Page1Factory&) = delete;
  Page1Factory& operator=(const Page1Factory&) = delete;

  // remove move semantics
  Page1Factory(Page1Factory&&) = delete;
  Page1Factory& operator=(Page1Factory&&) = delete;

 public:
  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    SDL_Renderer* renderer;
    bool hasSetRenderer;
    TextureAtlas* textureAtlas;
    bool hasSetTextureAtlas;
    GlyphAtlas* glyphAtlas;
    bool hasSetGlyphAtlas;
    SDL_Cursor* pointer;
    bool hasSetPointer;
    Reactive<Path>* currentPath;
    bool hasSetCurrentPath;

   public:
    explicit constexpr Builder() : renderer{ nullptr }, hasSetRenderer{ false }, textureAtlas{ nullptr }, hasSetTextureAtlas{ false }, glyphAtlas{ nullptr }, hasSetGlyphAtlas{ false },
      pointer{ nullptr }, hasSetPointer{ false }, currentPath{ nullptr }, hasSetCurrentPath{ false } { }

    /// <summary>It must be called at least 1 time before building Page1Factory object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setRenderer(SDL_Renderer*const value) {
      renderer = value;
      hasSetRenderer = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Page1Factory object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setTextureAtlas(TextureAtlas*const value) {
      textureAtlas = value;
      hasSetTextureAtlas = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Page1Factory object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setGlyphAtlas(GlyphAtlas*const value) {
      glyphAtlas = value;
      hasSetGlyphAtlas = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Page1Factory object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setPointer(SDL_Cursor*const value) {
      pointer = value;
      hasSetPointer = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Page1Factory object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setCurrentPath(Reactive<Path>*const value) {
      currentPath = value;
      hasSetCurrentPath = true;
      return *this;
    }

    /// <summary>It must be called to build Page1Factory object.</summary>
    Page1Factory* build();

    friend class Page1Factory;
  };

 private:
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
  Reactive<bool> isModal7Showing;
  Reactive<bool> isModal8Showing;
  Map<CellType> map;
  uniform_int_distribution<unsigned int> colorComponents;
  default_random_engine randomEngine;
  TextureAtlas& textureAtlas;
  GlyphAtlas& glyphAtlas;

  Page1Factory(const Builder&);

 public:
  Page<Path>* make(const Size<int>&) override;
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_GUITEST_PAGE_PAGE1FACTORY_H_
