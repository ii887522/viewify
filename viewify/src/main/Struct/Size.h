#ifndef II887522_VIEWIFY_SIZE_H
#define II887522_VIEWIFY_SIZE_H

namespace ii887522::viewify
{
	template <typename T> struct Size final
	{
		T w;
		T h;

		explicit constexpr Size() { }
		explicit constexpr Size(const T& w, const T& h) : w{ w }, h{ h } { }
	};
}

#endif
