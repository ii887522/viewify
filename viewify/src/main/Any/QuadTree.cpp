// Copyright ii887522

#include "QuadTree.h"
#include <vector>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"

using std::vector;

namespace ii887522::viewify {

QuadTree::QuadTree(const Rect<float>& rect) : rects{
    Rect{ rect.position, Size{ rect.size.w * .5f, rect.size.h * .5f } },
    Rect{ Point{ rect.position.x + rect.size.w * .5f, rect.position.y }, Size{ rect.size.w * .5f, rect.size.h * .5f } },
    Rect{ Point{ rect.position.x, rect.position.y + rect.size.h * .5f }, Size{ rect.size.w * .5f, rect.size.h * .5f } },
    Rect{ Point{ rect.position.x + rect.size.w * .5f, rect.position.y + rect.size.h * .5f }, Size{ rect.size.w * .5f, rect.size.h * .5f } }
  }, parentRect{ nullptr }, topLeft{ new QuadTree{ &rects[TOP_LEFT_INDEX] } }, topRight{ new QuadTree{ &rects[TOP_RIGHT_INDEX] } }, bottomLeft{ new QuadTree{ &rects[BOTTOM_LEFT_INDEX] } },
  bottomRight{ new QuadTree{ &rects[BOTTOM_RIGHT_INDEX] } }, isParent{ true } { }

QuadTree::QuadTree(Rect<float>*const rect) : parentRect{ rect }, topLeft{ nullptr }, topRight{ nullptr }, bottomLeft{ nullptr }, bottomRight{ nullptr }, isParent{ false } { }

void QuadTree::becomeParent() {
  rects.clear();
  rects.push_back(Rect{ parentRect->position, Size{ parentRect->size.w * .5f, parentRect->size.h * .5f } });
  rects.push_back(Rect{ Point{ parentRect->position.x + parentRect->size.w * .5f, parentRect->position.y }, Size{ parentRect->size.w * .5f, parentRect->size.h * .5f } });
  rects.push_back(Rect{ Point{ parentRect->position.x, parentRect->position.y + parentRect->size.h * .5f }, Size{ parentRect->size.w * .5f, parentRect->size.h * .5f } });
  rects.push_back(
    Rect{ Point{ parentRect->position.x + parentRect->size.w * .5f, parentRect->position.y + parentRect->size.h * .5f }, Size{ parentRect->size.w * .5f, parentRect->size.h * .5f } });
  topLeft = new QuadTree{ &rects[TOP_LEFT_INDEX] };
  topRight = new QuadTree{ &rects[TOP_RIGHT_INDEX] };
  bottomLeft = new QuadTree{ &rects[BOTTOM_LEFT_INDEX] };
  bottomRight = new QuadTree{ &rects[BOTTOM_RIGHT_INDEX] };
  isParent = true;
}

void QuadTree::add(const vector<Rect<float>>& p_rects) {
  for (const auto& rect : p_rects) add(rect);
}

void QuadTree::add(const Rect<float>& rect) {
  constexpr auto maxRectsSize{ 16u };
  if (isParent) {
    if (isOverlap(rects[TOP_LEFT_INDEX], rect)) topLeft->add(rect);
    if (isOverlap(rects[TOP_RIGHT_INDEX], rect)) topRight->add(rect);
    if (isOverlap(rects[BOTTOM_LEFT_INDEX], rect)) bottomLeft->add(rect);
    if (isOverlap(rects[BOTTOM_RIGHT_INDEX], rect)) bottomRight->add(rect);
  } else if (rects.size() == maxRectsSize) {
    vector<Rect<float>> aux(maxRectsSize);
    memcpy(aux.data(), rects.data(), maxRectsSize * sizeof Rect<float>);
    becomeParent();
    add(aux);
    add(rect);
  } else {
    rects.push_back(rect);
  }
}

bool QuadTree::isAnyRectHit(const Rect<float>& p_rect) const {
  if (isParent)
    return isOverlap(rects[TOP_LEFT_INDEX], p_rect) && topLeft->isAnyRectHit(p_rect) || isOverlap(rects[TOP_RIGHT_INDEX], p_rect) && topRight->isAnyRectHit(p_rect) ||
    isOverlap(rects[BOTTOM_LEFT_INDEX], p_rect) && bottomLeft->isAnyRectHit(p_rect) || isOverlap(rects[BOTTOM_RIGHT_INDEX], p_rect) && bottomRight->isAnyRectHit(p_rect);
  for (const auto& rect : rects) {
    if (isOverlap(rect, p_rect)) return true;
  }
  return false;
}

void QuadTree::clear() {
  free();
  topLeft = new QuadTree{ &rects[TOP_LEFT_INDEX] };
  topRight = new QuadTree{ &rects[TOP_RIGHT_INDEX] };
  bottomLeft = new QuadTree{ &rects[BOTTOM_LEFT_INDEX] };
  bottomRight = new QuadTree{ &rects[BOTTOM_RIGHT_INDEX] };
}

void QuadTree::free() {
  delete bottomRight;
  delete bottomLeft;
  delete topRight;
  delete topLeft;
}

QuadTree::~QuadTree() {
  free();
}

}  // namespace ii887522::viewify
