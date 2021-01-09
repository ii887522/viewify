#ifndef TEST

#ifndef II887522_VIEWIFY_BORDER_VIEW_H
#define II887522_VIEWIFY_BORDER_VIEW_H

#include "../Any/View.h"
#include <SDL.h>
#include "../Struct/Border.h"
#include "../Struct/Color.h"
#include "../Struct/Point.h"
#include "../Struct/Paint.h"
#include "../Any/Map.h"
#include <cstddef>

using std::nullptr_t;

namespace ii887522::viewify
{
	// Not Thread Safe: it must only be used in main thread
	// See also ../Any/View.h for more details
	template <typename T = nullptr_t> class BorderView final : public View
	{
		// remove copy semantics
		BorderView(const BorderView&) = delete;
		BorderView& operator=(const BorderView&) = delete;

		// remove move semantics
		BorderView(BorderView&&) = delete;
		BorderView& operator=(BorderView&&) = delete;

		const Border model;
		const Color<unsigned int> color;

		constexpr void setTopCells(Map<T>& map, const T& cellValue) const
		{
			for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.w / model.width); ++i)
				map.set(Point{ i, 0u }, cellValue);
		}
		
		constexpr void setRightCells(Map<T>& map, const T& cellValue) const
		{
			for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.h / model.width); ++i)
				map.set(Point{ model.rect.size.w / model.width - 1u, i }, cellValue);
		}

		constexpr void setBottomCells(Map<T>& map, const T& cellValue) const
		{
			for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.w / model.width); ++i)
				map.set(Point{ i, model.rect.size.h / model.width - 1u }, cellValue);
		}

		constexpr void setLeftCells(Map<T>& map, const T& cellValue) const
		{
			for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.h / model.width); ++i)
				map.set(Point{ 0u, i }, cellValue);
		}

		constexpr void setCells(Map<T>& map, const T& cellValue) const
		{
			setTopCells(map, cellValue);
			setRightCells(map, cellValue);
			setBottomCells(map, cellValue);
			setLeftCells(map, cellValue);
		}

	public:
		// Param renderer: it must not be assigned to integer
		explicit BorderView(SDL_Renderer*const renderer, const Point<int>& position, const Paint<int, unsigned int>& paint, const int width,
			Map<T>*const map = nullptr, const T& cellValue = nullptr) : View{ renderer, position }, model{ Rect{ position, paint.size }, width },
			color{ paint.color }
		{
			if (map) setCells(*map, cellValue);
		}

		virtual void render() override
		{
			SDL_SetRenderDrawColor(getRenderer(), static_cast<Uint8>(color.r), static_cast<Uint8>(color.g), static_cast<Uint8>(color.b), 255u);
			const SDL_Rect rects[]{
				{ getPosition().get().x, getPosition().get().y, model.width, model.width },
				{ getPosition().get().x + model.width, getPosition().get().y, model.rect.size.w - (model.width << 1u), model.width },
				{ getPosition().get().x + model.rect.size.w - model.width, getPosition().get().y, model.width, model.width },
				{
					getPosition().get().x + model.rect.size.w - model.width, getPosition().get().y + model.width, model.width,
					model.rect.size.h - (model.width << 1u)
				},
				{
					getPosition().get().x + model.rect.size.w - model.width, getPosition().get().y + model.rect.size.h - model.width,
					model.width, model.width
				},
				{
					getPosition().get().x + model.width, getPosition().get().y + model.rect.size.h - model.width,
					model.rect.size.w - (model.width << 1u), model.width
				},
				{ getPosition().get().x, getPosition().get().y + model.rect.size.h - model.width, model.width, model.width },
				{ getPosition().get().x, getPosition().get().y + model.width, model.width, model.rect.size.h - (model.width << 1u) }
			};
			for (auto i{ 0u }; i != sizeof rects / sizeof SDL_Rect; ++i) SDL_RenderFillRect(getRenderer(), rects + i);
		}
	};
}

#endif
#endif
