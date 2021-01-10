#ifndef II887522_VIEWIFY_IMAGE_MODEL_H
#define II887522_VIEWIFY_IMAGE_MODEL_H

#include <Any/AnimatedAny.h>

using ii887522::nitro::AnimatedAny;

namespace ii887522::viewify
{
	// Not Thread Safe
	class ImageModel final
	{
		// remove copy semantics
		ImageModel(const ImageModel&) = delete;
		ImageModel& operator=(const ImageModel&) = delete;

		// remove move semantics
		ImageModel(ImageModel&&) = delete;
		ImageModel& operator=(ImageModel&&) = delete;

	public:
		// Not Thread Safe
		class Builder final
		{
			// remove copy semantics
			Builder(const Builder&) = delete;
			Builder& operator=(const Builder&) = delete;

			// remove move semantics
			Builder(Builder&&) = delete;
			Builder& operator=(Builder&&) = delete;

			const unsigned int a;
			unsigned int duration; // animation duration
			bool hasSetDuration; // has set animation duration

		public:
			explicit constexpr Builder(const unsigned int a = 255u) : a{ a }, duration{ 0u }, hasSetDuration{ false } { }

			// Animation Duration. It must be called at least 1 time before building ImageModel object.
			// Param value: it must not be assigned to 0
			constexpr Builder& setDuration(const unsigned int value)
			{
				duration = value;
				hasSetDuration = true;
				return *this;
			}

			// It must be called to build ImageModel object.
			ImageModel build();

			friend class ImageModel;
		};

	private:
		AnimatedAny<int> a;

		explicit ImageModel(const Builder&);

	public:
		constexpr unsigned int getA() const
		{
			return static_cast<unsigned int>(a.get());
		}

		constexpr void show()
		{
			a.set(255);
		}

		constexpr void hide()
		{
			a.teleport(0);
		}

		constexpr void step(const unsigned int dt)
		{
			a.step(dt);
		}
	};
}

#endif
