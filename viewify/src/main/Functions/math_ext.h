#ifndef II887522_VIEWIFY_MATH_EXT_H
#define II887522_VIEWIFY_MATH_EXT_H

#include <Struct/Range.h>
#include "../Struct/Point.h"
#include "../Struct/Rect.h"
#include <Functions/math_ext.h>

using ii887522::nitro::Range;
using ii887522::nitro::isOverlapX;
using ii887522::nitro::isOverlapY;

namespace ii887522::viewify
{
	template <typename T> constexpr bool isOverlap(const Point<T>& point, const Rect<T>& rect)
	{
		return isOverlapX(point.x, Range{ rect.position.x, rect.position.x + rect.size.w }) &&
			isOverlapY(point.y, Range{ rect.position.y, rect.position.y + rect.size.h });
	}

	template <typename T> constexpr bool isOverlap(const Rect<T>& self, const Rect<T>& that)
	{
		return isOverlap(self.position, that) || isOverlap(Point{ self.position.x + self.size.w - static_cast<T>(1), self.position.y }, that) ||
			isOverlap(Point{ self.position.x + self.size.w - static_cast<T>(1), self.position.y + self.size.h - static_cast<T>(1) }, that) ||
			isOverlap(Point{ self.position.x, self.position.y + self.size.h - static_cast<T>(1) }, that);
	}
}

#endif
