#ifndef TEST

#ifndef II887522_VIEWIFY_VIEW_H
#define II887522_VIEWIFY_VIEW_H

#include <SDL.h>
#include "../Struct/Point.h"
#include <Any/Reactive.h>

using ii887522::nitro::Reactive;

namespace ii887522::viewify
{
	// It represents the basic building block for user interface components. A view occupies a rectangular area on the screen
	// and is responsible for drawing and event handling.
	// 
	// Not Thread Safe: it must only be used in main thread
	class View
	{
		// remove copy semantics
		View(const View&) = delete;
		View& operator=(const View&) = delete;

		// remove move semantics
		View(View&&) = delete;
		View& operator=(View&&) = delete;

		SDL_Renderer*const renderer;
		Reactive<Point<int>> position;

	public:
		// Param renderer: it must not be assigned to integer
		explicit View(SDL_Renderer*const renderer, const Point<int>& position = Point{ 0, 0 });

		constexpr SDL_Renderer* getRenderer() const
		{
			return renderer;
		}

		constexpr Reactive<Point<int>>& getPosition()
		{
			return position;
		}

		virtual void reactKeyDown(const SDL_KeyboardEvent&);
		virtual void reactMouseMotion(const SDL_MouseMotionEvent&);
		virtual void reactLeftMouseButtonDown(const SDL_MouseButtonEvent&);
		virtual void reactLeftMouseButtonUp(const SDL_MouseButtonEvent&);
		virtual void reactMouseLeaveWindow(const SDL_WindowEvent&);
		virtual void show();
		virtual void hide();
		virtual void step(const unsigned int dt);
		virtual void checkAndReactHits(const unsigned int dt);
		virtual void render() = 0;
		virtual ~View();
	};
}

#endif
#endif
