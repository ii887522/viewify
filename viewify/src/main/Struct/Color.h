#ifndef II887522_VIEWIFY_COLOR_H
#define II887522_VIEWIFY_COLOR_H

namespace ii887522::viewify
{
	template <typename T> struct Color final
	{
		T r;
		T g;
		T b;

		explicit constexpr Color() { }
		explicit constexpr Color(const T& r, const T& g, const T& b) : r{ r }, g{ g }, b{ b } { }
	};
}

#endif
