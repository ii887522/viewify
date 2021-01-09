#ifndef II887522_VIEWIFY_MAP_H
#define II887522_VIEWIFY_MAP_H

#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include <cstring>

namespace ii887522::viewify
{
	// Not Thread Safe
	template <typename T> class Map final
	{
		// remove copy semantics
		Map(const Map&) = delete;
		Map& operator=(const Map&) = delete;

		// remove move semantics
		Map(Map&&) = delete;
		Map& operator=(Map&&) = delete;

		T*const cells;
		const unsigned int width;

	public:
		explicit constexpr Map(const Size<unsigned int>& size) : cells{ new T[size.w * size.h] }, width{ size.w }
		{
			memset(cells, 0, size.w * size.h * sizeof(T));
		}

		constexpr const T& get(const Point<unsigned int>& position) const
		{
			return cells[position.y * width + position.x];
		}

		constexpr void set(const Point<unsigned int>& position, const T& value)
		{
			cells[position.y * width + position.x] = value;
		}

		~Map()
		{
			delete[] cells;
		}
	};
}

#endif
