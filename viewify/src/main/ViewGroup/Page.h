#ifndef TEST

#ifndef II887522_VIEWIFY_PAGE_H
#define II887522_VIEWIFY_PAGE_H

#include "../View/ViewGroup.h"
#include <SDL.h>
#include "../Struct/Point.h"
#include <initializer_list>
#include "../Any/View.h"
#include <Any/Reactive.h>

using std::initializer_list;
using ii887522::nitro::Reactive;

namespace ii887522::viewify
{
	// Not Thread Safe: it must only be used in main thread
	// See also ../View/ViewGroup.h for more details
	template <typename T, unsigned int viewCount> class Page final : public ViewGroup<viewCount>
	{
		// remove copy semantics
		Page(const Page&) = delete;
		Page& operator=(const Page&) = delete;

		// remove move semantics
		Page(Page&&) = delete;
		Page& operator=(Page&&) = delete;

		bool isShowing;

	public:
		// Param renderer: it must not be assigned to integer
		explicit Page(SDL_Renderer*const renderer, const Point<int>& position, const T& path, Reactive<T>& currentPath,
			const initializer_list<View*>& views) : ViewGroup<viewCount>{ renderer, position, views }, isShowing{ false }
		{
			currentPath.watch([this, path](const T& value, const int) {
				const auto wasShowing{ isShowing };
				isShowing = value == path;
				if (!wasShowing && isShowing) this->show();
				else if (wasShowing && !isShowing) this->hide();
			});
			currentPath.set(currentPath.get());
		}

		virtual void reactKeyDown(const SDL_KeyboardEvent& keyEvent) override
		{
			if (isShowing) ViewGroup<viewCount>::reactKeyDown(keyEvent);
		}

		virtual void reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) override
		{
			if (isShowing) ViewGroup<viewCount>::reactMouseMotion(motionEvent);
		}

		virtual void reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) override
		{
			if (isShowing) ViewGroup<viewCount>::reactLeftMouseButtonDown(buttonEvent);
		}

		virtual void reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) override
		{
			if (isShowing) ViewGroup<viewCount>::reactLeftMouseButtonUp(buttonEvent);
		}

		virtual void reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) override
		{
			if (isShowing) ViewGroup<viewCount>::reactMouseLeaveWindow(windowEvent);
		}

		virtual void step(const unsigned int dt) override
		{
			if (isShowing) ViewGroup<viewCount>::step(dt);
		}

		virtual void render() override
		{
			if (isShowing) ViewGroup<viewCount>::render();
		}
	};
}

#endif
#endif
