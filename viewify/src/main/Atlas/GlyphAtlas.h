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
  constexpr int getGlyphUnrotatedW(const unsigned int fontName, const unsigned int fontSize, const char ch) {
    return static_cast<int>(glyphs[getGlyphI(fontName, ch)].isRotated ?
      glyphs[getGlyphI(fontName, ch)].rect.size.h * fontSize / static_cast<float>(fontMetadatas[fontName].size) :
      glyphs[getGlyphI(fontName, ch)].rect.size.w * fontSize / static_cast<float>(fontMetadatas[fontName].size));
  }

  /// <param name="fontName">FontName enum ordinal</param>
  int getTextW(const unsigned int fontName, const unsigned int fontSize, const string& str);

  /// <param name="fontName">FontName enum ordinal</param>
  void render(const unsigned int fontName, const unsigned int fontSize, const char ch, const Point<int>& position, const Color<unsigned int>& = Color{ 0u, 0u, 0u, 255u });

  /// <param name="fontName">FontName enum ordinal</param>
  void render(const unsigned int fontName, const unsigned int fontSize, const string& str, const Point<int>& position, const Color<unsigned int>& = Color{ 0u, 0u, 0u, 255u });
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_ATLAS_GLYPHATLAS_H_
