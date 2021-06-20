// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_COMPONENTFACTORY_LISTITEMFACTORY_H_
#define VIEWIFY_SRC_MAIN_COMPONENTFACTORY_LISTITEMFACTORY_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <nitro/nitro.h>
#include <string>
#include "../Factory/ComponentFactory.h"
#include "../Atlas/GlyphAtlas.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Struct/Paint.h"
#include "../Struct/Color.h"
#include "../View/ViewGroup.h"
#include "../Any/constants.h"

using std::string;
using ii887522::nitro::Pair;

namespace ii887522::viewify {

/// <summary>Not Thread Safe: it must only be called in main thread</summary>
class ListItemFactory final : public ComponentFactory {
  // remove copy semantics
  ListItemFactory(const ListItemFactory&) = delete;
  ListItemFactory& operator=(const ListItemFactory&) = delete;

  // remove move semantics
  ListItemFactory(ListItemFactory&&) = delete;
  ListItemFactory& operator=(ListItemFactory&&) = delete;

  GlyphAtlas* glyphAtlas;
  bool hasSetGlyphAtlas;
  unsigned int fontName;
  bool hasSetFontName;
  unsigned int fontSize;
  bool hasSetFontSize;
  Size<int> keyMargin;
  Size<int> keyPadding;
  Paint<int, unsigned int> keyPaint;
  Pair<string, string> textPair;
  Pair<Color<unsigned int>, Color<unsigned int>> textColorPair;

 public:
  /// <param name="renderer">It must not be assigned to nullptr or integer</param>
  explicit constexpr ListItemFactory(SDL_Renderer*const renderer, const Point<int>& position = Point{ 0, 0 }) : ComponentFactory{ renderer, position }, glyphAtlas { nullptr },
    hasSetGlyphAtlas{ false }, fontName{ 0u }, hasSetFontName{ false }, fontSize{ 0u }, hasSetFontSize{ false }, keyMargin{ 1, 1 }, keyPadding{ 1, 1 },
    keyPaint{ Size{ 1, 1 }, Color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) } }, textPair{ " ", " " },
    textColorPair{ Color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) }, Color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) } } { }

  /// <summary>It must be called at least 1 time before making ListItem component.</summary>
  /// <param name="value">It must not be assigned to nullptr or integer</param>
  constexpr ListItemFactory& setGlyphAtlas(GlyphAtlas*const value) {
    glyphAtlas = value;
    hasSetGlyphAtlas = true;
    return *this;
  }

  /// <summary>It must be called at least 1 time before making ListItem component.</summary>
  constexpr ListItemFactory& setFontName(const unsigned int value) {
    fontName = value;
    hasSetFontName = true;
    return *this;
  }

  /// <summary>It must be called at least 1 time before making ListItem component.</summary>
  constexpr ListItemFactory& setFontSize(const unsigned int value) {
    fontSize = value;
    hasSetFontSize = true;
    return *this;
  }

  constexpr ListItemFactory& setKeyMargin(const Size<int>& value) {
    keyMargin = value;
    return *this;
  }

  constexpr ListItemFactory& setKeyPadding(const Size<int>& value) {
    keyPadding = value;
    return *this;
  }

  constexpr ListItemFactory& setKeyPaint(const Paint<int, unsigned int>& value) {
    keyPaint = value;
    return *this;
  }

  ListItemFactory& setTextPair(const Pair<string, string>& value);

  constexpr ListItemFactory& setTextColorPair(const Pair<Color<unsigned int>, Color<unsigned int>>& value) {
    textColorPair = value;
    return *this;
  }

  /// <summary>It must be called to make a ListItem component.</summary>
  ViewGroup* make() override;
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_COMPONENTFACTORY_LISTITEMFACTORY_H_
