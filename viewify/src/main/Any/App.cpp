// Copyright ii887522

#ifndef CONSOLE_TEST

#include "App.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdexcept>
#include "../Struct/Size.h"
#include "Enums.h"
#include "../Factory/ViewGroupFactory.h"
#include "../Struct/Color.h"
#include "../Struct/Paint.h"

using std::string;
using std::runtime_error;

namespace ii887522::viewify {

App::Builder::Builder(const string& title, const Paint<int, unsigned int>& paint, const unsigned int windowFlags) : title{ title }, paint{ paint }, sceneFactory{ nullptr },
  hasSetSceneFactory{ false }, windowFlags{ windowFlags } { }

App App::Builder::build() {
  if (!hasSetSceneFactory) throw runtime_error{ "App sceneFactory is required!" };
  return App{ *this };
}

App::App(const Builder& builder) :
  window{ SDL_CreateWindow(builder.title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, builder.paint.size.w, builder.paint.size.h, builder.windowFlags) },
  favicon{ IMG_Load("res/main/favicon.png") }, renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED) }, backgroundColor{ builder.paint.color },
  scene(builder.sceneFactory->make(renderer, builder.paint.size)) {
  SDL_SetWindowIcon(window, favicon);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void App::reactMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) {
  if (buttonEvent.button == SDL_BUTTON_LEFT) scene.reactLeftMouseButtonDown(buttonEvent);
}

void App::reactMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) {
  if (buttonEvent.button == SDL_BUTTON_LEFT) scene.reactLeftMouseButtonUp(buttonEvent);
}

void App::reactWindowEvent(const SDL_WindowEvent& windowEvent) {
  if (windowEvent.event == SDL_WINDOWEVENT_LEAVE) scene.reactMouseLeaveWindow(windowEvent);
}

Action App::react(const SDL_Event& event) {
  switch (event.type) {
  case SDL_QUIT: return Action::QUIT;
  case SDL_KEYDOWN: scene.reactKeyDown(event.key);
    break;
  case SDL_MOUSEMOTION: scene.reactMouseMotion(event.motion);
    break;
  case SDL_MOUSEBUTTONDOWN: reactMouseButtonDown(event.button);
    break;
  case SDL_MOUSEBUTTONUP: reactMouseButtonUp(event.button);
    break;
  case SDL_WINDOWEVENT: reactWindowEvent(event.window);
  }
  return Action::NONE;
}

void App::step(const unsigned int dt) {
  scene.step(dt);
}

void App::checkAndReactHits(const unsigned int dt) {
  scene.checkAndReactHits(dt);
}

void App::renderBackground() {
  SDL_SetRenderDrawColor(renderer, static_cast<Uint8>(backgroundColor.r), static_cast<Uint8>(backgroundColor.g), static_cast<Uint8>(backgroundColor.b), static_cast<Uint8>(backgroundColor.a));
  SDL_RenderClear(renderer);
}

Action App::preShow() {
  return scene.preRender();
}

void App::render() {
  renderBackground();
  scene.render();
}

void App::show() {
  render();
  SDL_RenderPresent(renderer);
}

Action App::postShow() {
  return scene.postRender();
}

App::~App() {
  SDL_DestroyRenderer(renderer);
  SDL_FreeSurface(favicon);
  SDL_DestroyWindow(window);
}

}  // namespace ii887522::viewify

#endif
