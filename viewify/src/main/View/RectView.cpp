// Copyright ii887522

#include "RectView.h"
#include "../Any/View.h"
#include <SDL.h>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Paint.h"

namespace ii887522::viewify {

RectView::RectView(SDL_Renderer*const renderer, const Point<int>& position, const Paint<int, unsigned int>& paint) :
  View{ renderer, position }, model{ Rect{ position, paint.size } }, color{ paint.color } { }

void RectView::render() {
  SDL_SetRenderDrawColor(getRenderer(), static_cast<Uint8>(color.r), static_cast<Uint8>(color.g), static_cast<Uint8>(color.b), 255u);
  const SDL_Rect rect{ getPosition().get().x, getPosition().get().y, model.size.w, model.size.h };
  SDL_RenderFillRect(getRenderer(), &rect);
}

}  // namespace ii887522::viewify
