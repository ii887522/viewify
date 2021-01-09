#ifndef TEST

#ifndef II887522_VIEWIFY_VIEW_GROUP_FACTORY_H
#define II887522_VIEWIFY_VIEW_GROUP_FACTORY_H

#include "../View/ViewGroup.h"
#include <SDL.h>
#include "../Struct/Size.h"

namespace ii887522::viewify
{
	// See also ../View/ViewGroup.h for more details
	template <unsigned int viewCount> struct ViewGroupFactory
	{
		// remove copy semantics
		ViewGroupFactory(const ViewGroupFactory&) = delete;
		ViewGroupFactory& operator=(const ViewGroupFactory&) = delete;

		// remove move semantics
		ViewGroupFactory(ViewGroupFactory&&) = delete;
		ViewGroupFactory& operator=(ViewGroupFactory&&) = delete;

		// See also ../View/ViewGroup.h for more details
		explicit constexpr ViewGroupFactory() { }

		// Param renderer: it must not be assigned to integer
		// See also ../View/ViewGroup.h for more details
		virtual ViewGroup<viewCount> make(SDL_Renderer*const renderer, const Size<int>&) = 0;

		virtual ~ViewGroupFactory() { }
	};
}

#endif
#endif
