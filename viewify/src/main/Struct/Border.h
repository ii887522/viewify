#ifndef II887522_VIEWIFY_BORDER_H
#define II887522_VIEWIFY_BORDER_H

#include "Rect.h"

namespace ii887522::viewify
{
	struct Border final
	{
		// remove copy semantics
		Border(const Border&) = delete;
		Border& operator=(const Border&) = delete;

		// remove move semantics
		Border(Border&&) = delete;
		Border& operator=(Border&&) = delete;

		const Rect<int> rect;
		const int width;

		explicit constexpr Border(const Rect<int>& rect, const int width) : rect{ rect }, width{ width } { }
	};
}

#endif
