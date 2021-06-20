// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ATLAS_GLYPHATLAS_H_
#define VIEWIFY_SRC_MAIN_ATLAS_GLYPHATLAS_H_

#ifndef CONSOLE_TEST

#include <font-packer/font_packer.h>
#include <SDL.h>
#include <vector>
#include <string>
#include "../Any/Atlas.h"
#include "../Struct/Color.h"
#include "../Functions/math_ext.h"
#include "../Any/constants.h"

using std::vector;
using std::string;
using ii887522::fontPacker::Font;
using ii887522::fontPacker::Glyph;

namespace ii887522::viewify {

/// <summary>
///   <para>Atlas is an image that contains multiple glyphs.</para>
///   <para>Not Thread Safe: it must only be used in main thread</para>
///   <para>See also ii887522::fontPacker::Glyph for more details</para>
/// </summary>
class GlyphAtlas final : public Atlas {
  // remove copy semantics
  GlyphAtlas(const GlyphAtlas&) = delete;
  GlyphAtlas& operator=(const GlyphAtlas&) = delete;

  // remove move semantics
  GlyphAtlas(GlyphAtlas&&) = delete;
  GlyphAtlas& operator=(GlyphAtlas&&) = delete;

  vector<Font> fontMetadatas;

  /// <summary>See also ii887522::fontPacker::Glyph for more details</summary>
  vector<Glyph> glyphs;

  /// <summary>Kerning is the process of adjusting the glyph position to reduce spaces between characters to produce a nice looking text.</summary>
  vector<vector<int>> kerningSizes;

  /// <summary>
  ///   <para>Kerning is the process of adjusting the glyph position to reduce spaces between characters to produce a nice looking text.</para>
  ///   <para>Atlas is an image that contains multiple smaller glyphs. It must only be called 1 time.</para>
  ///   <para>See also ii887522::fontPacker::Glyph for more details</para>
  /// </summary>
  /// <param name="atlasDirPath">It must exists and ends with either '/' or '\\'</param>
  void addKerningSizes(const string& atlasDirPath);

 protected:
  /// <summary>
  ///   <para>Atlas is an image that contains multiple glyphs. It must only be called 1 time.</para>
  ///   <para>See also ii887522::fontPacker::Glyph for more details</para>
  /// </summary>
  /// <param name="atlasDirPath">It must exists and ends with either '/' or '\\'</param>
  void addSurfaces(const string& atlasDirPath) override;

 public:
  /// <summary>
  ///   <para>Atlas is an image that contains multiple glyphs.</para>
  ///   <para>See also ii887522::fontPacker::Glyph for more details</para>
  /// </summary>
  /// <param name="renderer">It must not be assigned to nullptr or integer</param>
  /// <param name="atlasDirPath">It must exists and ends with either '/' or '\\'</param>
  explicit GlyphAtlas(SDL_Renderer*const renderer, const string& atlasDirPath);

  /// <summary>See also ii887522::fontPacker::Glyph for more details</summary>
  /// <param name="fontName">FontName enum ordinal</param>
  constexpr int getGlyphUnrotatedW(const unsigned int fontName, const unsigned int fontSize, const char ch) const {
    return static_cast<int>(glyphs[getGlyphI(fontName, ch)].isRotated ?
      glyphs[getGlyphI(fontName, ch)].rect.size.h * fontSize / static_cast<float>(fontMetadatas[fontName].size) :
      glyphs[getGlyphI(fontName, ch)].rect.size.w * fontSize / static_cast<float>(fontMetadatas[fontName].size));
  }

  /// <param name="fontName">FontName enum ordinal</param>
  int getTextW(const unsigned int fontName, const unsigned int fontSize, const string& str) const;

  /// <summary>Not Thread Safe</summary>
  class CharRenderer final {
    // remove copy semantics
    CharRenderer(const CharRenderer&) = delete;
    CharRenderer& operator=(const CharRenderer&) = delete;

    // remove move semantics
    CharRenderer(CharRenderer&&) = delete;
    CharRenderer& operator=(CharRenderer&&) = delete;

    const unsigned int fontName;
    const unsigned int fontSize;
    const char ch;
    Point<int> position;
    Color<unsigned int> color;

   public:
    /// <param name="fontName">FontName enum ordinal</param>
    explicit constexpr CharRenderer(const unsigned int fontName, const unsigned int fontSize, const char ch) : fontName{ fontName }, fontSize{ fontSize }, ch{ ch }, position{ 0, 0 },
      color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) } { }

    constexpr CharRenderer& setPosition(const Point<int>& value) {
      position = value;
      return *this;
    }

    constexpr CharRenderer& setColor(const Color<unsigned int>& value) {
      color = value;
      return *this;
    }

    /// <summary>It must be called to render a character.</summary>
    /// <param name="self">It must not be assigned to nullptr or integer</param>
    void render(GlyphAtlas*const self);
  };

  /// <summary>Not Thread Safe</summary>
  class StringRenderer final {
    // remove copy semantics
    StringRenderer(const StringRenderer&) = delete;
    StringRenderer& operator=(const StringRenderer&) = delete;

    // remove move semantics
    StringRenderer(StringRenderer&&) = delete;
    StringRenderer& operator=(StringRenderer&&) = delete;

    const unsigned int fontName;
    const unsigned int fontSize;
    const string*const str;
    Point<int> position;
    Color<unsigned int> color;

   public:
    /// <param name="fontName">FontName enum ordinal</param>
    explicit constexpr StringRenderer(const unsigned int fontName, const unsigned int fontSize, const string& str) : fontName{ fontName }, fontSize{ fontSize }, str{ &str },
      position{ 0, 0 }, color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) } { }

    constexpr StringRenderer& setPosition(const Point<int>& value) {
      position = value;
      return *this;
    }

    constexpr StringRenderer& setColor(const Color<unsigned int>& value) {
      color = value;
      return *this;
    }

    /// <summary>It must be called to render a string.</summary>
    /// <param name="self">It must not be assigned to nullptr or integer</param>
    void render(GlyphAtlas*const self);
  };
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_ATLAS_GLYPHATLAS_H_
