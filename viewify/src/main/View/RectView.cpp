// Copyright ii887522

#include "RectView.h"
#include <SDL.h>
#include <functional>
#include "../Any/View.h"
#include "../Struct/Rect.h"
#include "../Struct/Color.h"
#include "../Struct/Point.h"
#include "../Struct/Paint.h"
#include "../Any/Enums.h"

using std::function;

namespace ii887522::viewify {

RectView::RectView(SDL_Renderer*const renderer, const Point<int>& position, const Paint<int, unsigned int>& paint, const function<Action(Rect<int>&, Color<unsigned int>&)>& onPostRender) :
  View{ renderer, position }, model{ Rect{ position, paint.size } }, color{ paint.color }, onPostRender{ onPostRender } { }

void RectView::render() {
  SDL_SetRenderDrawColor(getRenderer(), static_cast<Uint8>(color.r), static_cast<Uint8>(color.g), static_cast<Uint8>(color.b), 255u);
  const SDL_Rect rect{ getPosition().get().x, getPosition().get().y, model.size.w, model.size.h };
  SDL_RenderFillRect(getRenderer(), &rect);
}

Action RectView::postRender() {
  const auto result{ onPostRender(model, color) };
  getPosition().set(model.position);
  return result;
}

}  // namespace ii887522::viewify
