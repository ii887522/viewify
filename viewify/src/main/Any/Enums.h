// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_ENUMS_H_
#define VIEWIFY_SRC_MAIN_ANY_ENUMS_H_

namespace ii887522::viewify {

enum class Action : unsigned int {
  NONE, QUIT, CONSUME_EVENT, RETURN_FROM_CALLER
};

enum class Align : unsigned int {
  LEFT, CENTER
};

enum class Rotation : unsigned int {
  NONE, QUARTER_CLOCKWISE, HALF, QUARTER_COUNTERCLOCKWISE
};

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_ANY_ENUMS_H_
