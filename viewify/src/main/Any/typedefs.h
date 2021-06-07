// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_TYPEDEFS_H_
#define VIEWIFY_SRC_MAIN_ANY_TYPEDEFS_H_

#ifndef CONSOLE_TEST

#include <functional>
#include <SDL.h>
#include <vector>
#include "View.h"

using std::function;
using std::vector;

namespace ii887522::viewify {

class ViewGroup;

/// <summary>
///   <para>Not Thread Safe: it must only be used in main thread</para>
///   <para>See also ViewGroup for more details</para>
/// </summary>
/// <param name="self">It must not be assigned to nullptr or integer</param>
/// <param name="renderer">It must not be assigned to nullptr or integer</param>
using MakeViews = function<vector<View*>(ViewGroup*const self, SDL_Renderer*const renderer)>;

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_ANY_TYPEDEFS_H_
