// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_IMAGE_H_
#define VIEWIFY_SRC_MAIN_VIEW_IMAGE_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include "../Any/View.h"
#include "../Struct/Point.h"
#include "../Model/ImageModel.h"
#include "../Any/Enums.h"
#include "../Atlas/TextureAtlas.h"
#include "../Any/constants.h"

namespace ii887522::viewify {

/// <summary>
///   <para>Not Thread Safe: it must only be used in main thread</para>
///   <para>See also ../Any/View.h for more details</para>
/// </summary>
class Image : public View {
  // remove copy semantics
  Image(const Image&) = delete;
  Image& operator=(const Image&) = delete;

  // remove move semantics
  Image(Image&&) = delete;
  Image& operator=(Image&&) = delete;

 public:
  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    /// <summary>See also ii887522::texturePacker::Sprite for more details</summary>
    TextureAtlas* atlas;

    /// <summary>See also ii887522::texturePacker::Sprite for more details</summary>
    bool hasSetAtlas;

    /// <summary>
    ///   <para>SpriteName enum ordinal</para>
    ///   <para>See also ii887522::texturePacker::Sprite for more details</para>
    /// </summary>
    unsigned int name;

    /// <summary>
    ///   <para>SpriteName enum ordinal</para>
    ///   <para>See also ii887522::texturePacker::Sprite for more details</para>
    /// </summary>
    bool hasSetName;

    const Point<int> position;
    unsigned int a;

    /// <summary>animation duration</summary>
    unsigned int duration;

    Align align;
    Rotation rotation;

   public:
     explicit constexpr Builder(const Point<int>& position = Point{ 0, 0 }) : atlas{ nullptr }, hasSetAtlas{ false }, name{ 0u }, hasSetName{ false }, position{ position },
      a{ static_cast<unsigned int>(MAX_COLOR.a) }, duration{ 1u }  /* See also setDuration(const unsigned int) for more details */, align{ Align::LEFT }, rotation{ Rotation::NONE } { }

    /// <summary>
    ///   <para>It must be called at least 1 time before building Image object.</para>
    ///   <para>See also ../Any/TextureAtlas.h for more details</para>
    /// </summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setTextureAtlas(TextureAtlas*const value) {
      atlas = value;
      hasSetAtlas = true;
      return *this;
    }

    /// <summary>
    ///   <para>SpriteName enum ordinal.</para>
    ///   <para>It must be called at least 1 time before building Image object.</para>
    ///   <para>See also ii887522::texturePacker::Sprite for more details</para>
    /// </summary>
    constexpr Builder& setName(const unsigned int value) {
      name = value;
      hasSetName = true;
      return *this;
    }

    constexpr Builder& setA(const unsigned int value) {
      a = value;
      return *this;
    }

    /// <summary>Animation duration.</summary>
    /// <param name="value">It must not be assigned to 0</param>
    constexpr Builder& setDuration(const unsigned int value) {
      duration = value;
      return *this;
    }

    constexpr Builder& setAlign(const Align value) {
      align = value;
      return *this;
    }

    constexpr Builder& setRotation(const Rotation value) {
      rotation = value;
      return *this;
    }

    /// <summary>It must be called to build Image object.</summary>
    Image* build();

    friend class Image;
  };

 private:
  /// <summary>See also ../Any/TextureAtlas.h for more details</summary>
  TextureAtlas*const atlas;

  ImageModel model;

  /// <summary>
  ///   <para>SpriteName enum ordinal</para>
  ///   <para>See also ii887522::texturePacker::Sprite for more details</para>
  /// </summary>
  unsigned int name;

  const Align align;
  const Rotation rotation;

 protected:
  explicit Image(const Builder&);

  /// <summary>See also ii887522::texturePacker::Sprite for more details</summary>
  /// <param name="name">SpriteName enum ordinal</param>
  void set(const unsigned int name);

 public:
  void show() override;
  void hide() override;
  void step(const unsigned int dt) override;
  void render() override;
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEW_IMAGE_H_
