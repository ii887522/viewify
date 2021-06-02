// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_SUBSYSTEMS_H_
#define VIEWIFY_SRC_MAIN_ANY_SUBSYSTEMS_H_

#ifndef CONSOLE_TEST

namespace ii887522::viewify {

/// <summary>
///   <para>They are subsystems such as SDL, SDL_image, SDL_ttf and etc.</para>
///   <para>Not Thread Safe: it must only be used in main thread</para>
/// </summary>
struct Subsystems final {
  // remove copy semantics
  Subsystems(const Subsystems&) = delete;
  Subsystems& operator=(const Subsystems&) = delete;

  // remove move semantics
  Subsystems(Subsystems&&) = delete;
  Subsystems& operator=(Subsystems&&) = delete;

  explicit Subsystems();
  ~Subsystems();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_ANY_SUBSYSTEMS_H_
