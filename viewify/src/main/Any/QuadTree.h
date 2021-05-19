// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_QUAD_TREE_H_
#define VIEWIFY_SRC_MAIN_ANY_QUAD_TREE_H_

#include <vector>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Functions/math_ext.h"
#include <cstring>

using std::vector;

namespace ii887522::viewify {

constexpr auto TOP_LEFT_INDEX = 0u;
constexpr auto TOP_RIGHT_INDEX = 1u;
constexpr auto BOTTOM_LEFT_INDEX = 2u;
constexpr auto BOTTOM_RIGHT_INDEX = 3u;

// Not Thread Safe
class QuadTree final {
  // remove copy semantics
  QuadTree(const QuadTree&) = delete;
  QuadTree& operator=(const QuadTree&) = delete;

  // remove move semantics
  QuadTree(QuadTree&&) = delete;
  QuadTree& operator=(QuadTree&&) = delete;

  vector<Rect<float>> rects;
  Rect<float>* const parentRect;
  QuadTree* topLeft;
  QuadTree* topRight;
  QuadTree* bottomLeft;
  QuadTree* bottomRight;
  bool isParent;

  // Param rect: it is a rectangle pointed to by this quad tree
  explicit QuadTree(Rect<float>& rect);

  void becomeParent();
  void free();

public:
  // Param rect: it is a container rectangle that contains this quad tree
  explicit QuadTree(const Rect<float>& rect);

  void add(const Rect<float>& rect);
  void add(const vector<Rect<float>>& p_rects);
  void clear();
  bool isAnyRectHit(const Rect<float>& p_rect) const;
  ~QuadTree();
};

} // namespace ii887522::viewify

#endif
