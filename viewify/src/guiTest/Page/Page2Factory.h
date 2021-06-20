// Copyright ii887522

#ifndef VIEWIFY_SRC_GUITEST_PAGE_PAGE2FACTORY_H_
#define VIEWIFY_SRC_GUITEST_PAGE_PAGE2FACTORY_H_

#ifdef GUI_TEST

#include <SDL.h>
#include <nitro/nitro.h>
#include "../../main/Factory/PageFactory.h"
#include "../Any/Enums.h"
#include "../../main/ViewGroup/Page.h"
#include "../../main/Struct/Size.h"
#include "../../main/Atlas/GlyphAtlas.h"

using ii887522::nitro::Reactive;

namespace ii887522::viewify {

/// <summary>Not Thread Safe: it must only be used in main thread</summary>
class Page2Factory final : public PageFactory<Path> {
  // remove copy semantics
  Page2Factory(const Page2Factory&) = delete;
  Page2Factory& operator=(const Page2Factory&) = delete;

  // remove move semantics
  Page2Factory(Page2Factory&&) = delete;
  Page2Factory& operator=(Page2Factory&&) = delete;

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
    GlyphAtlas* glyphAtlas;
    bool hasSetGlyphAtlas;
    SDL_Cursor* pointer;
    bool hasSetPointer;
    Reactive<Path>* currentPath;
    bool hasSetCurrentPath;

   public:
    explicit constexpr Builder() : renderer{ nullptr }, hasSetRenderer{ false }, glyphAtlas{ nullptr }, hasSetGlyphAtlas{ false }, pointer{ nullptr }, hasSetPointer{ false },
      currentPath{ nullptr }, hasSetCurrentPath{ false } { }

    /// <summary>It must be called at least 1 time before building Page2Factory object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setRenderer(SDL_Renderer*const value) {
      renderer = value;
      hasSetRenderer = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Page2Factory object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setGlyphAtlas(GlyphAtlas*const value) {
      glyphAtlas = value;
      hasSetGlyphAtlas = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Page2Factory object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setPointer(SDL_Cursor*const value) {
      pointer = value;
      hasSetPointer = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Page2Factory object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setCurrentPath(Reactive<Path>*const value) {
      currentPath = value;
      hasSetCurrentPath = true;
      return *this;
    }

    /// <summary>It must be called to build Page2Factory object.</summary>
    Page2Factory* build();

    friend class Page2Factory;
  };

 private:
  GlyphAtlas& glyphAtlas;

  Page2Factory(const Builder&);

 public:
  Page<Path>* make(const Size<int>&);
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_GUITEST_PAGE_PAGE2FACTORY_H_
