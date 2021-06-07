// Copyright ii887522

#ifndef CONSOLE_TEST

#include "ViewGroup.h"
#include <SDL.h>
#include <functional>
#include <vector>
#include "../Any/View.h"
#include "../Any/Enums.h"
#include "../Any/typedefs.h"

using std::function;
using std::vector;

namespace ii887522::viewify {

ViewGroup::ViewGroup(SDL_Renderer*const renderer, const Point<int>& position, const MakeViews& makeViews, const function<Action(ViewGroup*const self)>& onPreRender,
  const function<Action(ViewGroup*const self)>& onPostRender) : View{ renderer, position }, onPreRender{ onPreRender }, onPostRender{ onPostRender } {
  for (auto view : makeViews(this, renderer)) add(view);
}

ViewGroup::ViewGroup(ViewGroup&& that) noexcept : View{ that.getRenderer(), that.getPosition().get() }, onPreRender{ that.onPreRender }, onPostRender{ that.onPostRender } {
  views.resize(that.views.size());
  memcpy(views.data(), that.views.data(), that.views.size() * sizeof(View*));
  memset(that.views.data(), 0, that.views.size() * sizeof(View*));
}

void ViewGroup::add(View*const view) {
  views.push_back(view);
  view->getPosition().watch([this, view](const Point<int>& value, const int handlerI) {
    view->getPosition().set(value + getPosition().get(), handlerI);
  });
  view->getPosition().set(view->getPosition().get());
}

void ViewGroup::clear() {
  views.clear();
}

Action ViewGroup::reactKeyDown(const SDL_KeyboardEvent& keyEvent) {
  for (auto i{ static_cast<int>(views.size() - 1) }; i >= 0; --i) {
    if (views[i]->reactKeyDown(keyEvent) == Action::CONSUME_EVENT) break;
  }
  return Action::NONE;
}

Action ViewGroup::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) {
  for (auto i{ static_cast<int>(views.size() - 1) }; i >= 0; --i) {
    if (views[i]->reactMouseMotion(motionEvent) == Action::CONSUME_EVENT) break;
  }
  return Action::NONE;
}

Action ViewGroup::reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) {
  for (auto i{ static_cast<int>(views.size() - 1) }; i >= 0; --i) {
    if (views[i]->reactLeftMouseButtonDown(buttonEvent) == Action::CONSUME_EVENT) break;
  }
  return Action::NONE;
}

Action ViewGroup::reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) {
  for (auto i{ static_cast<int>(views.size() - 1) }; i >= 0; --i) {
    if (views[i]->reactLeftMouseButtonUp(buttonEvent) == Action::CONSUME_EVENT) break;
  }
  return Action::NONE;
}

Action ViewGroup::reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) {
  for (auto i{ static_cast<int>(views.size() - 1) }; i >= 0; --i) {
    if (views[i]->reactMouseLeaveWindow(windowEvent) == Action::CONSUME_EVENT) break;
  }
  return Action::NONE;
}

void ViewGroup::show() {
  for (auto i{ 0u }; i != views.size(); ++i) views[i]->show();
}

void ViewGroup::hide() {
  for (auto i{ 0u }; i != views.size(); ++i) views[i]->hide();
}

void ViewGroup::step(const unsigned int dt) {
  for (auto i{ 0u }; i != views.size(); ++i) views[i]->step(dt);
}

void ViewGroup::checkAndReactHits(const unsigned int dt) {
  for (auto i{ 0u }; i != views.size(); ++i) views[i]->checkAndReactHits(dt);
}

Action ViewGroup::preRender() {
  for (auto i{ 0u }; i != views.size(); ++i) {
    if (views[i]->preRender() == Action::QUIT) return Action::QUIT;
  }
  return onPreRender(*this);
}

void ViewGroup::render() {
  for (auto i{ 0u }; i != views.size(); ++i) views[i]->render();
}

Action ViewGroup::postRender() {
  for (auto i{ 0u }; i != views.size(); ++i) {
    if (views[i]->postRender() == Action::QUIT) return Action::QUIT;
  }
  return onPostRender(*this);
}

ViewGroup::~ViewGroup() {
  for (auto i{ 0u }; i != views.size(); ++i) delete views[i];
}

}  // namespace ii887522::viewify

#endif
