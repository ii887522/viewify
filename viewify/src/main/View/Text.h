// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_TEXT_H_
#define VIEWIFY_SRC_MAIN_VIEW_TEXT_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "../Any/View.h"
#include "../Struct/Color.h"
#include "../Struct/Point.h"
#include "../Any/Enums.h"
#include "../Any/constants.h"
#include "../Model/TextModel.h"
#include "../Atlas/GlyphAtlas.h"

using std::string;

namespace ii887522::viewify {

/// <summary>Not Thread Safe: it must only be used in main thread</summary>
class Text : public View {
  // remove copy semantics
  Text(const Text&) = delete;
  Text& operator=(const Text&) = delete;

  // remove move semantics
  Text(Text&&) = delete;
  Text& operator=(Text&&) = delete;

 public:
  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    /// <summary>See also ../Atlas/GlyphAtlas.h for more details</summary>
    GlyphAtlas*const atlas;

    /// <summary>FontName enum ordinal</summary>
    const unsigned int fontName;

    const Point<int> position;
    const string value;
    const Color<unsigned int> color;
    unsigned int fontSize;
    bool hasSetFontSize;
    unsigned int a;

    /// <summary>Animation duration</summary>
    unsigned int duration;

    const Align align;

   public:
    /// <summary>See also ../Atlas/GlyphAtlas.h for more details</summary>
    /// <param name="atlas">It must not be assigned to integer or nullptr</param>
    /// <param name="fontName">FontName enum ordinal</param>
    /// <param name="value">It must not be assigned to ""</param>
    explicit Builder(GlyphAtlas*const atlas, const unsigned int fontName, const Point<int>& position, const string& value = " ",
      const Color<unsigned int>& = Color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_A) }, const Align = Align::LEFT);

    /// <summary>It must be called at least 1 time before building Text object.</summary>
    constexpr Builder& setFontSize(const unsigned int p_value) {
      fontSize = p_value;
      hasSetFontSize = true;
      return *this;
    }

    constexpr Builder& setA(const unsigned int p_value) {
      a = p_value;
      return *this;
    }

    /// <summary>Animation duration.</summary>
    /// <param name="p_value">It must not be assigned to 0</param>
    constexpr Builder& setDuration(const unsigned int p_value) {
      duration = p_value;
      return *this;
    }

    /// <summary>It must be called to build Text object.</summary>
    Text* build();

    friend class Text;
  };

 private:
  /// <summary>See also ../Any/GlyphAtlas.h for more details</summary>
  GlyphAtlas*const atlas;

  TextModel model;

  /// <summary>FontName enum ordinal</summary>
  const unsigned int fontName;

  const unsigned int fontSize;
  string value;
  const Color<unsigned int> color;
  const Align align;

 protected:
  explicit Text(const Builder&);

 public:
  /// <param name="value">It must not be assigned to ""</param>
  void set(const string& value);

  void show() override;
  void hide() override;
  void step(const unsigned int dt) override;
  void render() override;
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEW_TEXT_H_
