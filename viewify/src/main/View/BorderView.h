// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_BORDERVIEW_H_
#define VIEWIFY_SRC_MAIN_VIEW_BORDERVIEW_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <cstddef>
#include "../Any/View.h"
#include "../Struct/Border.h"
#include "../Struct/Color.h"
#include "../Struct/Point.h"
#include "../Struct/Paint.h"
#include "../Any/Map.h"
#include "../Any/constants.h"

using std::nullptr_t;

namespace ii887522::viewify {

/// <summary>
///   <para>Not Thread Safe: it must only be used in main thread</para>
///   <para>See also ../Any/View.h for more details</para>
/// </summary>
template <typename T = nullptr_t> class BorderView final : public View {
  // remove copy semantics
  BorderView(const BorderView&) = delete;
  BorderView& operator=(const BorderView&) = delete;

  // remove move semantics
  BorderView(BorderView&&) = delete;
  BorderView& operator=(BorderView&&) = delete;

 public:
  /// <summary>Not Thread Safe</summary>
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    SDL_Renderer*const renderer;
    const Point<int> position;
    const Paint<int, unsigned int> paint;
    const int width;
    Map<T>* map;
    const T cellValue;

   public:
    /// <param name="renderer">It must not be assigned to nullptr or integer</param>
    explicit constexpr Builder(SDL_Renderer*const renderer, const Point<int>& position = Point{ 0, 0 },
      const Paint<int, unsigned int>& paint = Paint{ Size{ 3, 3 }, Color{ 0u, 0u, 0u, static_cast<unsigned int>(MAX_COLOR.a) } }, const int width = 1, const T& cellValue = nullptr) :
      renderer{ renderer }, position{ position }, paint{ paint }, width{ width }, map{ nullptr }, cellValue{ cellValue } { }

    constexpr Builder& setMap(Map<T>*const value) {
      map = value;
      return *this;
    }

    BorderView* build() {
      return new BorderView{ *this };
    }

    friend class BorderView;
  };

 private:
  const Border model;
  const Color<unsigned int> color;

  explicit BorderView(const Builder& builder) : View{ builder.renderer, builder.position }, model{ Rect{ builder.position, builder.paint.size }, builder.width },
    color{ builder.paint.color } {
    if (builder.map) setCells(builder.map, builder.cellValue);
  }

  /// <param name="map">It must not be assigned to nullptr or integer</param>
  constexpr void setTopCells(Map<T>*const map, const T& cellValue) const {
    for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.w / model.width); ++i) (*map)[Point{ i, 0u }] = cellValue;
  }

  /// <param name="map">It must not be assigned to nullptr or integer</param>
  constexpr void setRightCells(Map<T>*const map, const T& cellValue) const {
    for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.h / model.width); ++i) (*map)[Point{ model.rect.size.w / model.width - 1u, i }] = cellValue;
  }

  /// <param name="map">It must not be assigned to nullptr or integer</param>
  constexpr void setBottomCells(Map<T>*const map, const T& cellValue) const {
    for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.w / model.width); ++i) (*map)[Point{ i, model.rect.size.h / model.width - 1u }] = cellValue;
  }

  /// <param name="map">It must not be assigned to nullptr or integer</param>
  constexpr void setLeftCells(Map<T>*const map, const T& cellValue) const {
    for (auto i{ 0u }; i != static_cast<unsigned int>(model.rect.size.h / model.width); ++i) (*map)[Point{ 0u, i }] = cellValue;
  }

  /// <param name="map">It must not be assigned to nullptr or integer</param>
  constexpr void setCells(Map<T>*const map, const T& cellValue) const {
    setTopCells(map, cellValue);
    setRightCells(map, cellValue);
    setBottomCells(map, cellValue);
    setLeftCells(map, cellValue);
  }

 public:
  void render() override {
    SDL_SetRenderDrawColor(getRenderer(), static_cast<Uint8>(color.r), static_cast<Uint8>(color.g), static_cast<Uint8>(color.b), static_cast<Uint8>(color.a));
    const SDL_Rect rects[]{
      { getPosition().get().x, getPosition().get().y, model.width, model.width },
      { getPosition().get().x + model.width, getPosition().get().y, model.rect.size.w - (model.width << 1u)  /* which means model.rect.size.w - model.width * 2 */, model.width},
      { getPosition().get().x + model.rect.size.w - model.width, getPosition().get().y, model.width, model.width },
      {
        getPosition().get().x + model.rect.size.w - model.width, getPosition().get().y + model.width, model.width,
        model.rect.size.h - (model.width << 1u)  /* which means model.rect.size.h - model.width * 2 */
      },
      {
        getPosition().get().x + model.rect.size.w - model.width, getPosition().get().y + model.rect.size.h - model.width,
        model.width, model.width
      },
      {
        getPosition().get().x + model.width, getPosition().get().y + model.rect.size.h - model.width,
        model.rect.size.w - (model.width << 1u)  /* which means model.rect.size.w - model.width * 2 */, model.width
      },
      { getPosition().get().x, getPosition().get().y + model.rect.size.h - model.width, model.width, model.width },
      { getPosition().get().x, getPosition().get().y + model.width, model.width, model.rect.size.h - (model.width << 1u)  /* which means model.rect.size.h - model.width * 2 */}
    };
    for (auto i{ 0u }; i != sizeof rects / sizeof SDL_Rect; ++i) SDL_RenderFillRect(getRenderer(), rects + i);
  }
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEW_BORDERVIEW_H_
