#ifndef TEST

#ifndef II887522_VIEWIFY_RECT_VIEW_H
#define II887522_VIEWIFY_RECT_VIEW_H

#include "../Any/View.h"
#include <SDL.h>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Paint.h"
#include "../Struct/Color.h"

namespace ii887522::viewify
{
	// Not Thread Safe: it must not be assigned to integer
	// See also ../Any/View.h for more details
	class RectView final : public View
	{
		// remove copy semantics
		RectView(const RectView&) = delete;
		RectView& operator=(const RectView&) = delete;

		// remove move semantics
		RectView(RectView&&) = delete;
		RectView& operator=(RectView&&) = delete;

		const Rect<int> model;
		const Color<unsigned int> color;

	public:
		// Param renderer: it must not be assigned to integer
		explicit RectView(SDL_Renderer*const renderer, const Point<int>& position, const Paint<int, unsigned int>&);

		virtual void render() override;
	};
}

#endif
#endif
