// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_TEXT_SCORE_H_
#define VIEWIFY_SRC_MAIN_TEXT_SCORE_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <SDL_ttf.h>
#include <nitro/nitro.h>
#include <functional>
#include <string>
#include <stdexcept>
#include "../View/Text.h"
#include "../Struct/Point.h"
#include "../Struct/Color.h"
#include "../Atlas/GlyphAtlas.h"
#include "../Any/constants.h"

using std::to_string;
using std::function;
using std::runtime_error;
using std::string;
using ii887522::nitro::AnimationController;
#if defined LINEAR_ALLOCATOR && defined SHORT_TERM_ALLOCATOR_SIZE
using ii887522::nitro::beginShortTermAlloc;
using ii887522::nitro::endShortTermAlloc;
#endif

namespace ii887522::viewify {

constexpr auto LABEL{ "Score:" };

/// <summary>Not Thread Safe: it must only be used in main thread</summary>
struct Score final : public Text {
  // remove copy semantics
  Score(const Score&) = delete;
  Score& operator=(const Score&) = delete;

  // remove move semantics
  Score(Score&&) = delete;
  Score& operator=(Score&&) = delete;

  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    AnimationController* animationController;
    bool hasSetAnimationController;

    /// <summary>See also ../Atlas/GlyphAtlas.h for more details.</summary>
    GlyphAtlas* atlas;

    /// <summary>See also ../Atlas/GlyphAtlas.h for more details.</summary>
    bool hasSetAtlas;

    /// <summary>FontName enum ordinal</summary>
    unsigned int fontName;

    /// <summary>FontName enum ordinal</summary>
    bool hasSetFontName;

    unsigned int fontSize;
    bool hasSetFontSize;
    const Point<int> position;
    const Color<unsigned int> color;
    Reactive<bool>* canIncrement;
    bool hasSetCanIncrement;
    Reactive<bool>* canReset;
    bool hasSetCanReset;
    unsigned int max;
    bool hasSetMax;
    const function<void()> onValueMax;

   public:
    explicit Builder(const Point<int>& position = Point{ 0, 0 }, const Color<unsigned int>& color = Color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) },
      const function<void()>& onValueMax = []() { }) : animationController{ nullptr }, hasSetAnimationController{ false }, atlas{ nullptr }, hasSetAtlas{ false }, fontName{ 0u },
      hasSetFontName{ false }, fontSize{ 0u }, hasSetFontSize{ false }, position{ position }, color{ color }, canIncrement{ nullptr }, hasSetCanIncrement{ false }, canReset{ nullptr },
      hasSetCanReset{ false }, max{ 0u }, hasSetMax{ false }, onValueMax{ onValueMax } { }

    /// <summary>It must be called at least 1 time before building Score object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setAnimationController(AnimationController*const value) {
      animationController = value;
      hasSetAnimationController = true;
      return *this;
    }

    /// <summary>
    ///   <para>It must be called at least 1 time before building Score object.</para>
    ///   <para>See also ../Atlas/GlyphAtlas.h for more details</para>
    /// </summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setGlyphAtlas(GlyphAtlas*const value) {
      atlas = value;
      hasSetAtlas = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Score object.</summary>
    /// <param name="fontName">FontName enum ordinal</param>
    constexpr Builder& setFontName(const unsigned int value) {
      fontName = value;
      hasSetFontName = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Score object.</summary>
    constexpr Builder& setFontSize(const unsigned int value) {
      fontSize = value;
      hasSetFontSize = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Score object.</summary>
    constexpr Builder& setMax(const unsigned int value) {
      max = value;
      hasSetMax = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Score object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setCanIncrement(Reactive<bool>*const value) {
      canIncrement = value;
      hasSetCanIncrement = true;
      return *this;
    }

    /// <summary>It must be called at least 1 time before building Score object.</summary>
    /// <param name="value">It must not be assigned to nullptr or integer</param>
    constexpr Builder& setCanReset(Reactive<bool>*const value) {
      canReset = value;
      hasSetCanReset = true;
      return *this;
    }

    /// <summary>It must be called to build Score object.</summary>
    Score* build() {
      if (!hasSetAnimationController) throw runtime_error{ "Score animationController is required!" };
      if (!hasSetAtlas) throw runtime_error{ "Score atlas is required!" };
      if (!hasSetFontName) throw runtime_error{ "Score fontName is required!" };
      if (!hasSetFontSize) throw runtime_error{ "Score fontSize is required!" };
      if (!hasSetMax) throw runtime_error{ "Score max is required!" };
      if (!hasSetCanIncrement) throw runtime_error{ "Score canIncrement is required!" };
      if (!hasSetCanReset) throw runtime_error{ "Score canReset is required!" };
      return new Score{ *this };
    }

    friend struct Score;
  };

 private:
  unsigned int value;

  explicit Score(const Builder& builder) : Text{
      Text::Builder{ builder.position, string { LABEL } + " 0" }
        .setAnimationController(builder.animationController)
        .setGlyphAtlas(builder.atlas)
        .setFontName(builder.fontName)
        .setFontSize(builder.fontSize)
        .setA(static_cast<unsigned int>(MAX_COLOR.a))
        .setDuration(1u)
        .setColor(builder.color)
        .setAlign(Align::CENTER)
    }, value{ 0u } {
    builder.canIncrement->watch(
      [this, &canIncrement{ *builder.canIncrement }, onValueMax{ builder.onValueMax }, max{ builder.max }](const bool&, const bool& newValue, const int) {
      if (!newValue) return;
      if (value != max) ++value;
#if defined LINEAR_ALLOCATOR && defined SHORT_TERM_ALLOCATOR_SIZE
      beginShortTermAlloc();
#endif
      set(string { LABEL } + " " + to_string(value));
#if defined LINEAR_ALLOCATOR && defined SHORT_TERM_ALLOCATOR_SIZE
      endShortTermAlloc();
#endif
      if (value == max) onValueMax();
      canIncrement.set(false);
    });
    builder.canReset->watch([this](const bool&, const bool& newValue, const int) {
      if (!newValue) return;
      value = 0u;
#if defined LINEAR_ALLOCATOR && defined SHORT_TERM_ALLOCATOR_SIZE
      beginShortTermAlloc();
#endif
      set(string { LABEL } + " " + to_string(value));
#if defined LINEAR_ALLOCATOR && defined SHORT_TERM_ALLOCATOR_SIZE
      endShortTermAlloc();
#endif
    });
  }
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_TEXT_SCORE_H_
