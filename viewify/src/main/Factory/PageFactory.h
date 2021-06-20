// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FACTORY_PAGEFACTORY_H_
#define VIEWIFY_SRC_MAIN_FACTORY_PAGEFACTORY_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <nitro/nitro.h>
#include <stdexcept>
#include "../ViewGroup/Page.h"

using ii887522::nitro::Reactive;
using std::runtime_error;

namespace ii887522::viewify {

/// <summary>Not Thread Safe: it must only be used in main thread</summary>
template <typename T> class PageFactory {
  // remove copy semantics
  PageFactory(const PageFactory&) = delete;
  PageFactory& operator=(const PageFactory&) = delete;

  // remove move semantics
  PageFactory(PageFactory&&) = delete;
  PageFactory& operator=(PageFactory&&) = delete;

  SDL_Renderer*const renderer;
  SDL_Cursor*const pointer;
  Reactive<T>& currentPath;

 protected:
  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    SDL_Renderer*const renderer;
    SDL_Cursor* pointer;
    bool hasSetPointer;
    Reactive<T>* currentPath;
    bool hasSetCurrentPath;

   public:
    /// <param name="renderer">It must not be assigned to nullptr or integer</param>
    explicit constexpr Builder(SDL_Renderer*const renderer) : renderer{ renderer }, pointer{ nullptr }, hasSetPointer{ false }, currentPath{ nullptr }, hasSetCurrentPath{ false } { }

    /// <summary>It must be called at least 1 time before building PageFactory object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setPointer(SDL_Cursor*const value) {
      pointer = value;
      hasSetPointer = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building PageFactory object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setCurrentPath(Reactive<T>*const value) {
      currentPath = value;
      hasSetCurrentPath = true;
      return *this;
    }

    /// <summary>It must be called to build PageFactory object.</summary>
    PageFactory* build() {
      if (!hasSetPointer) throw runtime_error{ "PageFactory pointer is required!" };
      if (!hasSetCurrentPath) throw runtime_error{ "PageFactory currentPath is required!" };
      return new PageFactory{ *this };
    }

    friend class PageFactory;
  };

  explicit constexpr PageFactory(const Builder& builder) : renderer{ builder.renderer }, pointer{ builder.pointer }, currentPath{ *builder.currentPath } { }

  constexpr SDL_Renderer* getRenderer() const {
    return renderer;
  }

  constexpr SDL_Cursor* getPointer() const {
    return pointer;
  }

  constexpr Reactive<T>& getCurrentPath() const {
    return currentPath;
  }

 public:
  virtual Page<T>* make(const Size<int>&) = 0;

  virtual ~PageFactory() { }
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_FACTORY_PAGEFACTORY_H_
