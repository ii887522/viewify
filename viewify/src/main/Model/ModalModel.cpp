#include "ModalModel.h"
#include <Any/AnimatedAny.h>

using ii887522::nitro::AnimatedAny;

namespace ii887522::viewify
{
	ModalModel::ModalModel(const unsigned int aDuration) : sceneCoverA{ AnimatedAny<int>::Builder{ 0 }.setDuration(aDuration).build() },
		a{ AnimatedAny<int>::Builder{ 0 }.setDuration(aDuration).build() } { }
}
