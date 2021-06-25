// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_ENUMS_H_
#define VIEWIFY_SRC_MAIN_ANY_ENUMS_H_

namespace ii887522::viewify {

enum class EventLoopFlag : unsigned int {
  NONE, ALWAYS_ANIMATE
};

enum class Align : unsigned int {
  LEFT, CENTER
};

enum class Rotation : unsigned int {
  NONE, QUARTER_CLOCKWISE, HALF, QUARTER_COUNTERCLOCKWISE
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_ANY_ENUMS_H_
