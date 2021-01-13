// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_TEXT_SCORE_H_
#define VIEWIFY_SRC_MAIN_TEXT_SCORE_H_

#ifndef TEST

#include <SDL.h>
#include <SDL_ttf.h>
#include <Any/allocator.h>
#include <Any/Reactive.h>
#include <functional>
#include <string>
#include "../Image/Text.h"
#include "../Struct/Point.h"

using std::to_string;
using std::function;
#if defined LINEAR_ALLOCATOR && defined SHORT_TERM_ALLOCATOR_SIZE
using ii887522::nitro::beginShortTermAlloc;
using ii887522::nitro::endShortTermAlloc;
#endif

namespace ii887522::viewify {

// Not Thread Safe: it must only be used in main thread
struct Score final : public Text {
  // remove copy semantics
  Score(const Score&) = delete;
  Score& operator=(const Score&) = delete;

  // remove move semantics
  Score(Score&&) = delete;
  Score& operator=(Score&&) = delete;

  // Not Thread Safe
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    SDL_Renderer*const renderer;
    TTF_Font*const font;
    const Point<int> position;
    Reactive<bool>* canIncrement;
    bool hasSetCanIncrement;
    Reactive<bool>* canReset;
    bool hasSetCanReset;
    const unsigned int max;
    const function<void()> onValueMax;

   public:
    // Param renderer: it must not be assigned to integer
    // Param font: it must not be assigned to integer
    explicit Builder(SDL_Renderer*const renderer, TTF_Font*const font, const Point<int>& position, const unsigned int max,
      const function<void()>& onValueMax);

    // Param value: it must not be assigned to nullpter and integer
    // It must be called at least 1 time before building Score object.
    constexpr Builder& setCanIncrement(Reactive<bool>*const value) {
      canIncrement = value;
      hasSetCanIncrement = true;
      return *this;
    }

    // Param value: it must not be assigned to nullpter and integer
    // It must be called at least 1 time before building Score object.
    constexpr Builder& setCanReset(Reactive<bool>*const value) {
      canReset = value;
      hasSetCanReset = true;
      return *this;
    }

    // It must be called to build Score object.
    Score* build();

    friend struct Score;
  };

 private:
  unsigned int value;

  explicit Score(const Builder& builder) : Text{
    Text::Builder{ builder.renderer, builder.font, builder.position, "Score: 0", Color{ 255u, 255u, 255u }, Align::CENTER }
        .setA(255u)
        .setDuration(1u)
    }, value{ 0u } {
    builder.canIncrement->watch(
      [this, &canIncrement{ *builder.canIncrement }, onValueMax{ builder.onValueMax }, max{ builder.max }](const bool& p_value,
        const int) {
      if (!p_value) return;
      ++value;
#if defined LINEAR_ALLOCATOR && SHORT_TERM_ALLOCATOR_SIZE
      beginShortTermAlloc();
#endif
      set(string { "Score: " } + to_string(value));
#if defined LINEAR_ALLOCATOR && SHORT_TERM_ALLOCATOR_SIZE
      endShortTermAlloc();
#endif
      if (value == max) onValueMax();
      canIncrement.set(false);
    });
    builder.canReset->watch([this](const bool& p_value, const int) {
      if (!p_value) return;
      value = 0u;
#if defined LINEAR_ALLOCATOR && SHORT_TERM_ALLOCATOR_SIZE
      beginShortTermAlloc();
#endif
      set(string { "Score: " } + to_string(value));
#if defined LINEAR_ALLOCATOR && SHORT_TERM_ALLOCATOR_SIZE
      endShortTermAlloc();
#endif
    });
  }
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_TEXT_SCORE_H_
