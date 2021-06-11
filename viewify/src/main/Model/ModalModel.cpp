// Copyright ii887522

#include "ModalModel.h"
#include <nitro/nitro.h>

using ii887522::nitro::AnimatedAny;

namespace ii887522::viewify {
  ModalModel::ModalModel(const unsigned int aDuration) : sceneCoverA{ AnimatedAny<int>::Builder{ 0 }.setDuration(aDuration).build() },
    a{ AnimatedAny<int>::Builder{ 0 }.setDuration(aDuration).build() } { }
}
