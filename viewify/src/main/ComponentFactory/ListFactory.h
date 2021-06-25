// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_COMPONENTFACTORY_LISTFACTORY_H_
#define VIEWIFY_SRC_MAIN_COMPONENTFACTORY_LISTFACTORY_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <nitro/nitro.h>
#include <initializer_list>
#include <string>
#include <vector>
#include "../Factory/ComponentFactory.h"
#include "../Atlas/GlyphAtlas.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Struct/Paint.h"
#include "../Struct/Color.h"
#include "../View/ViewGroup.h"
#include "../Any/constants.h"

using ii887522::nitro::Pair;
using ii887522::nitro::AnimationController;
using std::initializer_list;
using std::string;
using std::vector;

namespace ii887522::viewify {

/// <summary>Not Thread Safe: it must only be called in main thread</summary>
class ListFactory final : public ComponentFactory {
  // remove copy semantics
  ListFactory(const ListFactory&) = delete;
  ListFactory& operator=(const ListFactory&) = delete;

  // remove move semantics
  ListFactory(ListFactory&&) = delete;
  ListFactory& operator=(ListFactory&&) = delete;

  AnimationController* animationController;
  bool hasSetAnimationController;
  GlyphAtlas* glyphAtlas;
  bool hasSetGlyphAtlas;
  unsigned int fontName;
  bool hasSetFontName;
  unsigned int fontSize;
  bool hasSetFontSize;
  Size<int> keyMargin;
  vector<Size<int>> keyPaddings;
  Paint<int, unsigned int> keyPaint;
  vector<Pair<string, string>> textPairs;
  Pair<Color<unsigned int>, Color<unsigned int>> textColorPair;

 public:
  /// <param name="renderer">It must not be assigned to nullptr or integer</param>
  explicit ListFactory(SDL_Renderer*const renderer, const Point<int>& position = Point{ 0, 0 });

  /// <summary>It must be called at least 1 time before making List component.</summary>
  /// <param name="value">It must not be assigned to nullptr or integer</param>
  constexpr ListFactory& setAnimationController(AnimationController*const value) {
    animationController = value;
    hasSetAnimationController = true;
    return *this;
  }

  /// <summary>It must be called at least 1 time before making List component.</summary>
  /// <param name="value">It must not be assigned to nullptr or integer</param>
  constexpr ListFactory& setGlyphAtlas(GlyphAtlas*const value) {
    glyphAtlas = value;
    hasSetGlyphAtlas = true;
    return *this;
  }

  /// <summary>It must be called at least 1 time before making List component.</summary>
  constexpr ListFactory& setFontName(const unsigned int value) {
    fontName = value;
    hasSetFontName = true;
    return *this;
  }

  /// <summary>It must be called at least 1 time before making List component.</summary>
  constexpr ListFactory& setFontSize(const unsigned int value) {
    fontSize = value;
    hasSetFontSize = true;
    return *this;
  }

  constexpr ListFactory& setKeyMargin(const Size<int>& value) {
    keyMargin = value;
    return *this;
  }

  ListFactory& setKeyPaddings(const initializer_list<Size<int>>& value);

  constexpr ListFactory& setKeyPaint(const Paint<int, unsigned int>& value) {
    keyPaint = value;
    return *this;
  }

  ListFactory& setTextPairs(const initializer_list<Pair<string, string>>& value);

  constexpr ListFactory& setTextColorPair(const Pair<Color<unsigned int>, Color<unsigned int>>& value) {
    textColorPair = value;
    return *this;
  }

  /// <summary>It must be called to make a List component.</summary>
  ViewGroup* make() override;
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_COMPONENTFACTORY_LISTFACTORY_H_
