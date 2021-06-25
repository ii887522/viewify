// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FUNCTIONS_VECTOR_EXT_H_
#define VIEWIFY_SRC_MAIN_FUNCTIONS_VECTOR_EXT_H_

#include <vector>

using std::vector;

namespace ii887522::viewify {

/// <param name="self">It must not be assigned to nullptr or integer</param>
template <typename T> T add(vector<T>*const self, const T& item) {
  self->push_back(item);
  return item;
}

}  // namespace ii887522::viewify

#endif  // VIEWIFY_SRC_MAIN_FUNCTIONS_VECTOR_EXT_H_
