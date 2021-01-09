#ifndef II887522_VIEWIFY_PAINT_H
#define II887522_VIEWIFY_PAINT_H

#include "Size.h"
#include "Color.h"

namespace ii887522::viewify
{
	template <typename SIZE, typename COLOR> struct Paint final
	{
		Size<SIZE> size;
		Color<COLOR> color;

		explicit constexpr Paint() { }
		explicit constexpr Paint(const Size<SIZE>& size, const Color<COLOR>& color) : size{ size }, color{ color } { }
	};
}

#endif
