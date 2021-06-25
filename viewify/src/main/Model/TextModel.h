// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_MODEL_TEXTMODEL_H_
#define VIEWIFY_SRC_MAIN_MODEL_TEXTMODEL_H_

#include <nitro/nitro.h>
#include "../Any/constants.h"

using ii887522::nitro::AnimatedAny;
using ii887522::nitro::AnimationController;

namespace ii887522::viewify {

/// <summary>Not Thread Safe</summary>
class TextModel final {
  // remove copy semantics
  TextModel(const TextModel&) = delete;
  TextModel& operator=(const TextModel&) = delete;

  // remove move semantics
  TextModel(TextModel&&) = delete;
  TextModel& operator=(TextModel&&) = delete;

 public:
  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    AnimationController*const animationController;
    const unsigned int a;

    /// <summary>Animation duration</summary>
    unsigned int duration;

    /// <summary>Has set animation duration</summary>
    bool hasSetDuration;

   public:
    explicit constexpr Builder(AnimationController*const animationController, const unsigned int a = static_cast<unsigned int>(MAX_COLOR.a)) :
      animationController{ animationController }, a{ a }, duration{ 0u }, hasSetDuration{ false } { }

    /// <summary>
    ///   <para>Animation Duration.</para>
    ///   <para>It must be called at least 1 time before building TextModel object.</para>
    /// </summary>
    /// <param name="value">It must not be assigned to 0</param>
    constexpr Builder& setDuration(const unsigned int value) {
      duration = value;
      hasSetDuration = true;
      return *this;
    }

    /// <summary>It must be called to build TextModel object.</summary>
    TextModel build();

    friend class TextModel;
  };

 private:
  AnimatedAny<int> a;

  explicit TextModel(const Builder&);

 public:
  constexpr unsigned int getA() const {
    return static_cast<unsigned int>(a.get());
  }

  constexpr void show() {
    a.set(static_cast<int>(MAX_COLOR.a));
  }

  constexpr void hide() {
    a.teleport(0);
  }

  constexpr void step(const unsigned int dt) {
    a.step(dt);
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_MODEL_TEXTMODEL_H_
