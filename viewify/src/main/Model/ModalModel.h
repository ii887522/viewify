#ifndef II887522_VIEWIFY_MODAL_MODEL_H
#define II887522_VIEWIFY_MODAL_MODEL_H

#include <Any/AnimatedAny.h>

using ii887522::nitro::AnimatedAny;

namespace ii887522::viewify
{
	// Not Thread Safe
	class ModalModel final
	{
		// remove copy semantics
		ModalModel(const ModalModel&) = delete;
		ModalModel& operator=(const ModalModel&) = delete;

		// remove move semantics
		ModalModel(ModalModel&&) = delete;
		ModalModel& operator=(ModalModel&&) = delete;

		AnimatedAny<int> sceneCoverA;
		AnimatedAny<int> a;

	public:
		// Param duration: animation duration and it must not be assigned to 0
		explicit ModalModel(const unsigned int aDuration);

		constexpr unsigned int getSceneCoverA() const
		{
			return static_cast<unsigned int>(sceneCoverA.get());
		}

		constexpr unsigned int getA() const
		{
			return static_cast<unsigned int>(a.get());
		}

		constexpr void show()
		{
			sceneCoverA.set(128);
			a.set(255);
		}

		constexpr void hide()
		{
			sceneCoverA.teleport(0);
			a.teleport(0);
		}

		constexpr void step(const unsigned int dt)
		{
			sceneCoverA.step(dt);
			a.step(dt);
		}
	};
}

#endif
