// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_QUADTREE_H_
#define VIEWIFY_SRC_MAIN_ANY_QUADTREE_H_

#include <vector>
#include <cstring>
#include "../Struct/Rect.h"
#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Functions/math_ext.h"

using std::vector;

namespace ii887522::viewify {

constexpr auto TOP_LEFT_I = 0u;
constexpr auto TOP_RIGHT_I = 1u;
constexpr auto BOTTOM_LEFT_I = 2u;
constexpr auto BOTTOM_RIGHT_I = 3u;

/// <summary>Not Thread Safe</summary>
class QuadTree final {
  // remove copy semantics
  QuadTree(const QuadTree&) = delete;
  QuadTree& operator=(const QuadTree&) = delete;

  // remove move semantics
  QuadTree(QuadTree&&) = delete;
  QuadTree& operator=(QuadTree&&) = delete;

  vector<Rect<float>> rects;
  Rect<float>*const parentRect;
  QuadTree* topLeft;
  QuadTree* topRight;
  QuadTree* bottomLeft;
  QuadTree* bottomRight;
  bool isParent;

  /// <param name="rect">It is a rectangle pointed to by this quad tree. It must not be assigned to integer or nullptr.</param>
  explicit QuadTree(Rect<float>*const rect);

  void becomeParent();
  void free();

 public:
  /// <param name="rect">It is a container rectangle that contains this quad tree</param>
  explicit QuadTree(const Rect<float>& rect = Rect{ Point{ 0.f, 0.f }, Size{ 2.f, 2.f } });

  void add(const Rect<float>& rect);
  void add(const vector<Rect<float>>& p_rects);
  void clear();
  bool isAnyRectHit(const Rect<float>& p_rect) const;
  ~QuadTree();
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_ANY_QUADTREE_H_
