// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_MODEL_IMAGEMODEL_H_
#define VIEWIFY_SRC_MAIN_MODEL_IMAGEMODEL_H_

#include <nitro/Any/AnimatedAny.h>
#include "../Any/constants.h"

using ii887522::nitro::AnimatedAny;

namespace ii887522::viewify {

/// <summary>Not Thread Safe</summary>
class ImageModel final {
  // remove copy semantics
  ImageModel(const ImageModel&) = delete;
  ImageModel& operator=(const ImageModel&) = delete;

  // remove move semantics
  ImageModel(ImageModel&&) = delete;
  ImageModel& operator=(ImageModel&&) = delete;

 public:
  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    const unsigned int a;

    /// <summary>Animation duration</summary>
    unsigned int duration;

    /// <summary>Has set animation duration</summary>
    bool hasSetDuration;

   public:
    explicit constexpr Builder(const unsigned int a = static_cast<unsigned int>(MAX_A)) : a{ a }, duration{ 0u }, hasSetDuration{ false } { }

    /// <summary>
    ///   <para>Animation Duration.</para>
    ///   <para>It must be called at least 1 time before building ImageModel object.</para>
    /// </summary>
    /// <param name="value">it must not be assigned to 0</param>
    constexpr Builder& setDuration(const unsigned int value) {
      duration = value;
      hasSetDuration = true;
      return *this;
    }

    /// <summary>It must be called to build ImageModel object.</summary>
    ImageModel build();

    friend class ImageModel;
  };

 private:
  AnimatedAny<int> a;

  explicit ImageModel(const Builder&);

 public:
  constexpr unsigned int getA() const {
    return static_cast<unsigned int>(a.get());
  }

  constexpr void show() {
    a.set(static_cast<int>(MAX_A));
  }

  constexpr void hide() {
    a.teleport(0);
  }

  constexpr void step(const unsigned int dt) {
    a.step(dt);
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_MODEL_IMAGEMODEL_H_
