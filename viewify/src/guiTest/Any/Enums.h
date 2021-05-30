// Copyright ii887522

#ifndef VIEWIFY_SRC_GUITEST_ANY_ENUMS_H_
#define VIEWIFY_SRC_GUITEST_ANY_ENUMS_H_

#ifdef GUI_TEST

namespace ii887522::viewify {

enum class CellType : unsigned int {
  BACKGROUND, BORDER
};

enum class Path : unsigned int {
  MAIN, EMPTY
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_GUITEST_ANY_ENUMS_H_
