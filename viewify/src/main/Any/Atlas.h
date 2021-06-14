// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_ANY_ATLAS_H_
#define VIEWIFY_SRC_MAIN_ANY_ATLAS_H_

#ifndef CONSOLE_TEST

#include <SDL.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace ii887522::viewify {

/// <summary>
///   <para>Atlas is an image that contains multiple smaller images.</para>
///   <para>Not Thread Safe: it must only be used in main thread</para>
/// </summary>
class Atlas {
  // remove copy semantics
  Atlas(const Atlas&) = delete;
  Atlas& operator=(const Atlas&) = delete;

  // remove move semantics
  Atlas(Atlas&&) = delete;
  Atlas& operator=(Atlas&&) = delete;

  SDL_Renderer*const renderer;
  vector<SDL_Surface*> surfaces;
  vector<SDL_Texture*> textures;

  /// <summary>It must only be called 1 time.</summary>
  void freeTextures();

  /// <summary>It must only be called 1 time.</summary>
  void freeSurfaces();

 protected:
  vector<SDL_Surface*>& getSurfaces();
  vector<SDL_Texture*>& getTextures();

  /// <summary>
  ///   <para>Atlas is an image that contains multiple smaller images.</para>
  ///   <para>It must only be called 1 time.</para>
  /// </summary>
  /// <param name="atlasDirPath">It must exists and ends with either '/' or '\\'</param>
  virtual void addSurfaces(const string& atlasDirPath) = 0;

  /// <summary>It must only be called 1 time.</summary>
  void addTextures();

  /// <summary>It must only be called 1 time.</summary>
  void enableAnisotropicFiltering();

 public:
  /// <param name="renderer">It must not be assigned to nullptr or integer</param>
  explicit Atlas(SDL_Renderer*const renderer);

  constexpr SDL_Renderer* getRenderer() const {
    return renderer;
  }

  virtual ~Atlas();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_ANY_ATLAS_H_
