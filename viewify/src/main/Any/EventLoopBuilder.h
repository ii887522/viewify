// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_EVENTLOOPBUILDER_H_
#define VIEWIFY_SRC_MAIN_ANY_EVENTLOOPBUILDER_H_

#ifndef CONSOLE_TEST

#include <nitro/nitro.h>
#include "Enums.h"
#include "App.h"

using ii887522::nitro::AnimationController;

namespace ii887522::viewify {

/// <summary>Not Thread Safe</summary>
class EventLoopBuilder final {
  // remove copy semantics
  EventLoopBuilder(const EventLoopBuilder&) = delete;
  EventLoopBuilder& operator=(const EventLoopBuilder&) = delete;

  // remove move semantics
  EventLoopBuilder(EventLoopBuilder&&) = delete;
  EventLoopBuilder& operator=(EventLoopBuilder&&) = delete;

  const EventLoopFlag flag;
  App* app;
  bool hasSetApp;
  AnimationController* animationController;
  bool hasSetAnimationController;

 public:
  explicit constexpr EventLoopBuilder(const EventLoopFlag flag = EventLoopFlag::NONE) : flag{ flag }, app{ nullptr }, hasSetApp{ false }, animationController{ nullptr },
    hasSetAnimationController{ false } { }

  /// <summary>It must be called at least 1 time before building event loop.</summary>
  /// <param name="value">It must not be assigned to nullptr or integer</param>
  constexpr EventLoopBuilder& setApp(App*const value) {
    app = value;
    hasSetApp = true;
    return *this;
  }

  /// <summary>It must be called at least 1 time before building event loop.</summary>
  /// <param name="value">It must not be assigned to nullptr or integer</param>
  constexpr EventLoopBuilder& setAnimationController(AnimationController*const value) {
    animationController = value;
    hasSetAnimationController = true;
    return *this;
  }

  /// <summary>It must be called to build event loop.</summary>
  void build();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_ANY_EVENTLOOPBUILDER_H_
