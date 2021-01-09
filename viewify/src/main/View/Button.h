#ifndef TEST

#ifndef II887522_VIEWIFY_BUTTON_H
#define II887522_VIEWIFY_BUTTON_H

#include "../Any/View.h"
#include <SDL.h>
#include "../Struct/Point.h"
#include "../Model/ButtonModel.h"
#include "../Struct/Paint.h"
#include <functional>

using std::function;

namespace ii887522::viewify
{
	// Not Thread Safe: it must only be used in main thread
	// See also ../Any/View.h for more details
	class Button final : public View
	{
		// remove copy semantics
		Button(const Button&) = delete;
		Button& operator=(const Button&) = delete;

		// remove move semantics
		Button(Button&&) = delete;
		Button& operator=(Button&&) = delete;

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

			SDL_Renderer*const renderer;
			const Point<int> position;
			const Paint<int, unsigned int> paint;
			unsigned int a;
			unsigned int aDuration; // alpha animation duration
			bool hasSetADuration;
			unsigned int lightnessDuration; // lightness animation duration
			bool hasSetLightnessDuration;
			function<void()> onMouseOver;
			bool hasSetOnMouseOver;
			function<void()> onMouseOut;
			bool hasSetOnMouseOut;
			function<void()> onClick;
			bool hasSetOnClick;

		public:
			// Param renderer: it must not be assigned to integer
			explicit Builder(SDL_Renderer*const renderer, const Point<int>& position, const Paint<int, unsigned int>&);

			constexpr Builder& setA(const unsigned int value)
			{
				a = value;
				return *this;
			}

			// Alpha animation duration
			// Param value: it must not be assigned to 0
			// Must Call Time(s): At least 1
			constexpr Builder& setADuration(const unsigned int value)
			{
				aDuration = value;
				hasSetADuration = true;
				return *this;
			}

			// Lightness animation duration
			// Param value: it must not be assigned to 0
			// Must Call Time(s): At least 1
			constexpr Builder& setLightnessDuration(const unsigned int value)
			{
				lightnessDuration = value;
				hasSetLightnessDuration = true;
				return *this;
			}

			// Must Call Time(s): At least 1
			Builder& setOnMouseOver(const function<void()>&);

			// Must Call Time(s): At least 1
			Builder& setOnMouseOut(const function<void()>&);

			// Must Call Time(s): At least 1
			Builder& setOnClick(const function<void()>&);

			// Must Call Time(s): At least 1
			Button* build();

			friend class Button;
		};

	private:
		ButtonModel model;
		const Color<unsigned int> color;

		explicit Button(const Builder&);

	public:
		virtual void reactMouseMotion(const SDL_MouseMotionEvent&) override;
		virtual void reactLeftMouseButtonDown(const SDL_MouseButtonEvent&) override;
		virtual void reactLeftMouseButtonUp(const SDL_MouseButtonEvent&) override;
		virtual void reactMouseLeaveWindow(const SDL_WindowEvent&) override;
		virtual void show() override;
		virtual void hide() override;
		virtual void step(const unsigned int dt) override;
		virtual void render() override;
	};
}

#endif
#endif
