// Copyright ii887522

#include "ViewGroup.h"
#include <SDL.h>
#include <initializer_list>
#include <functional>
#include "../Any/View.h"
#include "../Any/Enums.h"

using std::initializer_list;
using std::function;

namespace ii887522::viewify {

ViewGroup::ViewGroup(SDL_Renderer*const renderer, const Point<int>& position, const initializer_list<View*>& views, const function<Action()>& onPostRender) : View{ renderer, position },
  onPostRender{ onPostRender } {
  for (auto view : views) add(view);
}

ViewGroup::ViewGroup(ViewGroup&& that) noexcept : View{ that.getRenderer(), that.getPosition().get() } {
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

void ViewGroup::render() {
  for (auto i{ 0u }; i != views.size(); ++i) views[i]->render();
}

Action ViewGroup::postRender() {
  for (auto i{ 0u }; i != views.size(); ++i) {
    if (views[i]->postRender() == Action::QUIT) return Action::QUIT;
  }
  return onPostRender();
}

ViewGroup::~ViewGroup() {
  for (auto i{ 0u }; i != views.size(); ++i) delete views[i];
}

}  // namespace ii887522::viewify
