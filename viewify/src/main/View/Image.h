// Copyright ii887522

#ifndef VIEWIFY_SRC_MAIN_VIEW_IMAGE_H_
#define VIEWIFY_SRC_MAIN_VIEW_IMAGE_H_

#ifndef TEST

#include <SDL.h>
#include "../Any/View.h"
#include "../Struct/Point.h"
#include "../Model/ImageModel.h"
#include "../Any/Enums.h"

namespace ii887522::viewify {

// Not Thread Safe: it must only be used in main thread
// See also ../Any/View.h for more details
class Image : public View {
  // remove copy semantics
  Image(const Image&) = delete;
  Image& operator=(const Image&) = delete;

  // remove move semantics
  Image(Image&&) = delete;
  Image& operator=(Image&&) = delete;

 public:
  // Not Thread Safe
  class Builder final {
    // remove copy semantics
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    // remove move semantics
    Builder(Builder&&) = delete;
    Builder& operator=(Builder&&) = delete;

    SDL_Renderer*const renderer;
    SDL_Surface*const surface;
    const Point<int> position;
    unsigned int a;
    unsigned int duration;  // animation duration
    bool hasSetDuration;  // has set animation duration
    const Align align;

   public:
    // Param renderer: it must not be assigned to integer
    // Param surface: it must not be assigned to integer
    explicit constexpr Builder(SDL_Renderer*const renderer, SDL_Surface*const surface, const Point<int>& position,
      const Align align = Align::LEFT) : renderer{ renderer }, surface{ surface }, position{ position }, a{ 255u }, duration{ 0u },
      hasSetDuration{ false }, align{ align } { }

    constexpr Builder& setA(const unsigned int value) {
      a = value;
      return *this;
    }

    // Animation duration. It must be called at least 1 time before building Image object.
    // Param value: it must not be assigned to 0
    constexpr Builder& setDuration(const unsigned int value) {
      duration = value;
      hasSetDuration = true;
      return *this;
    }

    // It must be called to build Image object.
    Image* build();

    friend class Image;
  };

 private:
  ImageModel model;
  SDL_Surface* surface;
  SDL_Texture* texture;
  const Align align;

  void free();

 protected:
  explicit Image(const Builder&);

  // Param p_surface: it must not be assigned to integer
  void set(SDL_Surface*const p_surface);

 public:
  void show() override;
  void hide() override;
  void step(const unsigned int dt) override;
  void render() override;
  ~Image();
};

}  // namespace ii887522::viewify

#endif
#endif  // VIEWIFY_SRC_MAIN_VIEW_IMAGE_H_
