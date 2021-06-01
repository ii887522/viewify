// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FUNCTIONS_CONTROL_FLOW_H_
#define VIEWIFY_SRC_MAIN_FUNCTIONS_CONTROL_FLOW_H_

#ifndef CONSOLE_TEST

#include "../Any/App.h"

namespace ii887522::viewify {

/// <summary>
///   <para>Not Thread Safe: it must only be called in main thread</para>
///   <para>See also ../Any/View.h for more details</para>
/// </summary>
void eventLoop(App&& app);

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_FUNCTIONS_CONTROL_FLOW_H_
