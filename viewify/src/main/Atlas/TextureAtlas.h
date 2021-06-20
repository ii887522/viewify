// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ATLAS_TEXTUREATLAS_H_
#define VIEWIFY_SRC_MAIN_ATLAS_TEXTUREATLAS_H_

#ifndef CONSOLE_TEST

#include <texture-packer/texture_packer.h>
#include <SDL.h>
#include <vector>
#include <string>
#include "../Any/Atlas.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Any/Enums.h"
#include "../Any/constants.h"

using std::vector;
using std::string;
using ii887522::texturePacker::Sprite;

namespace ii887522::viewify {

/// <summary>
///   <para>Atlas is an image that contains multiple smaller sprites.</para>
///   <para>Not Thread Safe: it must only be used in main thread</para>
///   <para>See also ii887522::texturePacker::Sprite for more details</para>
/// </summary>
class TextureAtlas final : public Atlas {
  // remove copy semantics
  TextureAtlas(const TextureAtlas&) = delete;
  TextureAtlas& operator=(const TextureAtlas&) = delete;

  // remove move semantics
  TextureAtlas(TextureAtlas&&) = delete;
  TextureAtlas& operator=(TextureAtlas&&) = delete;

  /// <summary>See also ii887522::texturePacker::Sprite for more details</summary>
  vector<Sprite> sprites;

 protected:
  /// <summary>
  ///   <para>Atlas is an image that contains multiple smaller sprites.</para>
  ///   <para>It must only be called 1 time.</para>
  ///   <para>See also ii887522::texturePacker::Sprite for more details</para>
  /// </summary>
  /// <param name="atlasDirPath">It must exists and ends with either '/' or '\\'</param>
  void addSurfaces(const string& atlasDirPath) override;

 public:
  /// <summary>
  ///   <para>Atlas is an image that contains multiple smaller sprites.</para>
  ///   <para>See also ii887522::texturePacker::Sprite for more details</para>
  /// </summary>
  /// <param name="renderer">It must not be assigned to nullptr or integer</param>
  /// <param name="atlasDirPath">It must exists and ends with either '/' or '\\'</param>
  explicit TextureAtlas(SDL_Renderer*const renderer, const string& atlasDirPath);

  /// <summary>See also ii887522::texturePacker::Sprite for more details</summary>
  /// <param name="name">SpriteName enum ordinal</param>
  constexpr Size<int> getSpriteUnrotatedSize(const unsigned int name) const {
    return sprites[name].isRotated ? Size{ sprites[name].rect.size.h, sprites[name].rect.size.w } : Size{ sprites[name].rect.size.w, sprites[name].rect.size.h };
  }

  /// <summary>Not Thread Safe</summary>
  class Renderer final {
    // remove copy semantics
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    // remove move semantics
    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;

    const unsigned int name;
    Point<int> position;
    unsigned int a;
    Rotation rotation;

   public:
    /// <summary>See also ii887522::texturePacker::Sprite for more details</summary>
    /// <param name="name">SpriteName enum ordinal</param>
    explicit constexpr Renderer(const unsigned int name) : name{ name }, position{ 0, 0 }, a{ static_cast<unsigned int>(MAX_COLOR.a) }, rotation{ Rotation::NONE } { }

    constexpr Renderer& setPosition(const Point<int>& value) {
      position = value;
      return *this;
    }

    constexpr Renderer& setA(const unsigned int value) {
      a = value;
      return *this;
    }

    constexpr Renderer& setRotation(const Rotation value) {
      rotation = value;
      return *this;
    }

    /// <summary>
    ///   <para>It must be called to render a sprite.</para>
    ///   <para>See also ii887522::texturePacker::Sprite for more details</para>
    /// </summary>
    /// <param name="self">It must not be assigned to nullptr or integer</param>
    void render(TextureAtlas*const self);
  };
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_ATLAS_TEXTUREATLAS_H_
