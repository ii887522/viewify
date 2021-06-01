// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_MODEL_MODALMODEL_H_
#define VIEWIFY_SRC_MAIN_MODEL_MODALMODEL_H_

#include <nitro/Any/AnimatedAny.h>
#include "../Any/constants.h"

using ii887522::nitro::AnimatedAny;

namespace ii887522::viewify {

/// <summary>Not Thread Safe</summary>
class ModalModel final {
  // remove copy semantics
  ModalModel(const ModalModel&) = delete;
  ModalModel& operator=(const ModalModel&) = delete;

  // remove move semantics
  ModalModel(ModalModel&&) = delete;
  ModalModel& operator=(ModalModel&&) = delete;

  AnimatedAny<int> sceneCoverA;
  AnimatedAny<int> a;

 public:
  /// <param name="duration">Animation duration and it must not be assigned to 0</param>
  explicit ModalModel(const unsigned int aDuration);

  constexpr unsigned int getSceneCoverA() const {
    return static_cast<unsigned int>(sceneCoverA.get());
  }

  constexpr unsigned int getA() const {
    return static_cast<unsigned int>(a.get());
  }

  constexpr void show() {
    sceneCoverA.set(128);
    a.set(static_cast<int>(MAX_A));
  }

  constexpr void hide() {
    sceneCoverA.teleport(0);
    a.teleport(0);
  }

  constexpr void step(const unsigned int dt) {
    sceneCoverA.step(dt);
    a.step(dt);
  }
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_MODEL_MODALMODEL_H_
