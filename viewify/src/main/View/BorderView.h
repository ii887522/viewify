// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_BORDERVIEW_H_
#define VIEWIFY_SRC_MAIN_VIEW_BORDERVIEW_H_

#ifndef TEST

#include <SDL.h>
#include <cstddef>
#include "../Any/View.h"
#include "../Struct/Border.h"
#include "../Struct/Color.h"
#include "../Struct/Point.h"
#include "../Struct/Paint.h"
#include "../Any/Map.h"

using std::nullptr_t;

namespace ii887522::viewify {

// Not Thread Safe: it must only be used in main thread
// See also ../Any/View.h for more details
template <typename T = nullptr_t> class BorderView final : public View {
  // remove copy semantics
  BorderView(const BorderView&) = delete;
  BorderView& operator=(const BorderView&) = delete;

  // remove move semantics
  BorderView(BorderView&&) = delete;
  BorderView& operator=(BorderView&&) = delete;

  const Border model;
  const Color<unsigned int> color;

  // Param map: it must not be assigned to nullptr and integer
  constexpr void setTopCells(Map<T>*const map, const T& cellValue) const {
    for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.w / model.width); ++i)
      map->set(Point{ i, 0u }, cellValue);
  }

  // Param map: it must not be assigned to nullptr and integer
  constexpr void setRightCells(Map<T>*const map, const T& cellValue) const {
    for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.h / model.width); ++i)
      map->set(Point{ model.rect.size.w / model.width - 1u, i }, cellValue);
  }

  // Param map: it must not be assigned to nullptr and integer
  constexpr void setBottomCells(Map<T>*const map, const T& cellValue) const {
    for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.w / model.width); ++i)
      map->set(Point{ i, model.rect.size.h / model.width - 1u }, cellValue);
  }

  // Param map: it must not be assigned to nullptr and integer
  constexpr void setLeftCells(Map<T>*const map, const T& cellValue) const {
    for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.h / model.width); ++i)
      map->set(Point{ 0u, i }, cellValue);
  }

  // Param map: it must not be assigned to nullptr and integer
  constexpr void setCells(Map<T>*const map, const T& cellValue) const {
    setTopCells(map, cellValue);
    setRightCells(map, cellValue);
    setBottomCells(map, cellValue);
    setLeftCells(map, cellValue);
  }

 public:
  // Param renderer: it must not be assigned to integer
  explicit BorderView(SDL_Renderer*const renderer, const Point<int>& position, const Paint<int, unsigned int>& paint, const int width,
    Map<T>*const map = nullptr, const T& cellValue = nullptr) : View{ renderer, position }, model{ Rect{ position, paint.size }, width },
    color{ paint.color } {
    if (map) setCells(map, cellValue);
  }

  void render() override {
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

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEW_BORDERVIEW_H_
