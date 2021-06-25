// Copyright ii887522

#include "ModalModel.h"
#include <nitro/nitro.h>

using ii887522::nitro::AnimatedAny;
using ii887522::nitro::AnimationController;

namespace ii887522::viewify {
  ModalModel::ModalModel(AnimationController*const animationController, const unsigned int aDuration) :
    sceneCoverA{ AnimatedAny<int>::Builder{ animationController, 0 }.setDuration(aDuration).build() },
    a{ AnimatedAny<int>::Builder{ animationController, 0 }.setDuration(aDuration).build() } { }
}
