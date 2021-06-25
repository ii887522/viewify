// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_FUNCTIONS_CONTROL_FLOW_H_
#define VIEWIFY_SRC_MAIN_FUNCTIONS_CONTROL_FLOW_H_

#ifndef CONSOLE_TEST

#include <nitro/nitro.h>
#include "../Any/App.h"
#include "../Any/Enums.h"

using ii887522::nitro::AnimationController;

namespace ii887522::viewify {

/// <summary>
///   <para>Not Thread Safe: it must only be called in main thread</para>
///   <para>See also ../Any/View.h for more details</para>
/// </summary>
/// <param name="animationController">It must not be assigned to nullptr or integer</param>
void eventLoop(App&&, AnimationController*const animationController, const EventLoopFlag = EventLoopFlag::NONE);

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_FUNCTIONS_CONTROL_FLOW_H_
