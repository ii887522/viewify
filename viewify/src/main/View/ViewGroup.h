// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_
#define VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_

#ifndef CONSOLE_TEST

#include <nitro/nitro.h>
#include <SDL.h>
#include <vector>
#include <functional>
#include "../Any/View.h"
#include "../Any/typedefs.h"

using std::vector;
using std::function;
using ii887522::nitro::Action;

namespace ii887522::viewify {

/// <summary>
///   <para>It is a special view that can contain other views (called children).</para>
///   <para>Not Thread Safe: it must only be used in main thread</para>
///   <para>See also ../Any/View.h for more details</para>
/// </summary>
class ViewGroup : public View {
  /// <summary>See also ../Any/View.h for more details</summary>
  vector<View*> views;

  const function<Action(ViewGroup*const self)> onPreRender;
  const function<Action(ViewGroup*const self)> onPostRender;

 public:
  /// <summary>
  ///   <para>See also ../Any/View.h for more details</para>
  ///   <para>See also MakeViews for more details</para>
  /// </summary>
  /// <param name="renderer">It must not be assigned to nullptr or integer</param>
  explicit ViewGroup(SDL_Renderer*const renderer, const Point<int>& position = Point{ 0, 0 }, const MakeViews& = [](ViewGroup*const, SDL_Renderer*const) {
    return vector<View*>{ };
  }, const function<Action(ViewGroup*const self)>& onPreRender = [](ViewGroup*const) {
    return Action::NONE;
  }, const function<Action(ViewGroup*const self)>& onPostRender = [](ViewGroup*const) {
    return Action::NONE;
  });

  /// <summary>See also ../Any/View.h for more details</summary>
  explicit ViewGroup(ViewGroup&& that) noexcept;

  void add(const vector<View*>&);

  /// <param name="view">It must not be assigned to nullptr or integer</param>
  void add(View*const view);

  void clear();
  Action reactKeyDown(const SDL_KeyboardEvent& keyEvent) override;
  Action reactMouseMotion(const SDL_MouseMotionEvent& motionEvent) override;
  Action reactLeftMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent) override;
  Action reactLeftMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent) override;
  Action reactMouseLeaveWindow(const SDL_WindowEvent& windowEvent) override;
  void show() final;
  void hide() final;
  void step(const unsigned int dt) override;
  void checkAndReactHits(const unsigned int dt) override;
  Action preRender() override;
  void render() override;
  Action postRender() override;
  ~ViewGroup();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEW_VIEWGROUP_H_
