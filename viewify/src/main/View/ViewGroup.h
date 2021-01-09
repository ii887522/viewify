#ifndef TEST

#ifndef II887522_VIEWIFY_VIEW_GROUP_H
#define II887522_VIEWIFY_VIEW_GROUP_H

#include "../Any/View.h"
#include <SDL.h>
#include <initializer_list>

using std::initializer_list;

namespace ii887522::viewify
{
	// It is a special view that can contain other views (called children). 
	// Not Thread Safe: it must not be assigned to integer
	// See also ../Any/View.h for more details
	template <unsigned int viewCount> class ViewGroup : public View
	{
		// remove copy semantics
		ViewGroup(const ViewGroup&) = delete;
		ViewGroup& operator=(const ViewGroup&) = delete;

		// remove move semantics
		ViewGroup& operator=(ViewGroup&&) = delete;

		// See also ../Any/View.h for more details
		View* views[viewCount];

	public:
		// Param renderer: it must not be assigned to integer
		// See also ../Any/View.h for more details
		explicit ViewGroup(SDL_Renderer*const renderer, const Point<int>& position, const initializer_list<View*>& views) :
			View{ renderer, position }
		{
			memcpy(this->views, views.begin(), viewCount * sizeof(View*));
			for (auto view : views)
			{
				view->getPosition().watch([view, position](const Point<int>& value, const int handlerI) {
					view->getPosition().set(value + position, handlerI);
				});
				view->getPosition().set(view->getPosition().get());
			}
		}

		// See also ../Any/View.h for more details
		explicit ViewGroup(ViewGroup&& that) : View{ that.getRenderer(), that.getPosition() }
		{
			memcpy(views, that.views, viewCount * sizeof(View*));
			memset(that.views, 0, viewCount * sizeof(View*));
		}

		virtual void reactKeyDown(const SDL_KeyboardEvent& keyEvent) override
		{
			for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->reactKeyDown(keyEvent);
		}

		virtual void reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) override
		{
			for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->reactMouseMotion(motionEvent);
		}

		virtual void reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) override
		{
			for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->reactLeftMouseButtonDown(buttonEvent);
		}

		virtual void reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) override
		{
			for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->reactLeftMouseButtonUp(buttonEvent);
		}

		virtual void reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) override
		{
			for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->reactMouseLeaveWindow(windowEvent);
		}

		virtual void show() final override
		{
			for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->show();
		}

		virtual void hide() final override
		{
			for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->hide();
		}

		virtual void step(const unsigned int dt) override
		{
			for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->step(dt);
		}

		virtual void checkAndReactHits(const unsigned int dt) override
		{
			for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->checkAndReactHits(dt);
		}

		virtual void render() override
		{
			for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) views[i]->render();
		}

		~ViewGroup()
		{
			for (auto i{ 0u }; i != sizeof views / sizeof(View*); ++i) delete views[i];
		}
	};
}

#endif
#endif
