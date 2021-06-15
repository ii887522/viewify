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
#if defined LINEAR_ALLOCATOR && defined SHORT_TERM_ALLOCATOR_SIZE
using ii887522::nitro::beginShortTermAlloc;
using ii887522::nitro::endShortTermAlloc;
#endif

namespace ii887522::viewify {

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

    /// <summary>See also ../Atlas/GlyphAtlas.h for more details.</summary>
    GlyphAtlas*const atlas;

    /// <summary>FontName enum ordinal</summary>
    const unsigned int fontName;

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
    /// <summary>See also ../Atlas/GlyphAtlas.h for more details</summary>
    /// <param name="fontName">FontName enum ordinal</param>
    explicit Builder(GlyphAtlas*const atlas, const unsigned int fontName, const Point<int>& position, const Color<unsigned int>& color, const function<void()>& onValueMax) : atlas{ atlas },
      fontName{ fontName }, position{ position }, color{ color }, canIncrement{ nullptr }, hasSetCanIncrement{ false }, canReset{ nullptr }, hasSetCanReset{ false }, max{ max },
      onValueMax{ onValueMax } { }

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

  explicit Score(const Builder& builder, const string& label = "Score") : Text{
      Text::Builder{ builder.atlas, builder.fontName, builder.position, label + ": 0", builder.color, Align::CENTER }
        .setFontSize(builder.fontSize)
        .setA(static_cast<unsigned int>(MAX_A))
        .setDuration(1u)
    }, value{ 0u } {
    builder.canIncrement->watch(
      [this, label, &canIncrement{ *builder.canIncrement }, onValueMax{ builder.onValueMax }, max{ builder.max }](const bool&, const bool& newValue, const int) {
      if (!newValue) return;
      ++value;
#if defined LINEAR_ALLOCATOR && defined SHORT_TERM_ALLOCATOR_SIZE
      beginShortTermAlloc();
#endif
      set(label + ": " + to_string(value));
#if defined LINEAR_ALLOCATOR && defined SHORT_TERM_ALLOCATOR_SIZE
      endShortTermAlloc();
#endif
      if (value == max) onValueMax();
      canIncrement.set(false);
    });
    builder.canReset->watch([this, label](const bool&, const bool& newValue, const int) {
      if (!newValue) return;
      value = 0u;
#if defined LINEAR_ALLOCATOR && defined SHORT_TERM_ALLOCATOR_SIZE
      beginShortTermAlloc();
#endif
      set(label + ": " + to_string(value));
#if defined LINEAR_ALLOCATOR && defined SHORT_TERM_ALLOCATOR_SIZE
      endShortTermAlloc();
#endif
    });
  }
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_TEXT_SCORE_H_
