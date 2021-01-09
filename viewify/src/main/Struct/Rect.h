#ifndef II887522_VIEWIFY_RECT_H
#define II887522_VIEWIFY_RECT_H

#include "Point.h"
#include "Size.h"

namespace ii887522::viewify
{
	template <typename T> struct Rect final
	{
		Point<T> position;
		Size<T> size;

		explicit constexpr Rect() { }
		explicit constexpr Rect(const Point<T>& position, const Size<T>& size) : position{ position }, size{ size } { }
	};
}

#endif
