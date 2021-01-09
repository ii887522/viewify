#ifndef TEST

#include "Image.h"
#include "../Any/View.h"
#include <SDL.h>
#include <SDL_image.h>
#include "../Model/ImageModel.h"
#include <stdexcept>
#include "../Any/Enums.h"
#include "../Struct/Size.h"

using std::runtime_error;

namespace ii887522::viewify
{
	Image* Image::Builder::build()
	{
		if (hasSetDuration) return new Image{ *this };
		throw runtime_error{ "Image duration is required!" };
	}

	Image::Image(const Builder& builder) :
		View{ builder.renderer, builder.position - (builder.align == Align::LEFT ? Size{ 0, 0 } : Size{ builder.surface->w >> 1u, 0 }) },
		model{ ImageModel::Builder{ builder.a }.setDuration(builder.duration).build() }, surface{ builder.surface },
		texture{ SDL_CreateTextureFromSurface(builder.renderer, surface) }, align{ builder.align } { }

	void Image::free()
	{
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(surface);
	}

	void Image::set(SDL_Surface*const p_surface)
	{
		const Point centerPosition{ getPosition().get() + Size{ surface->w >> 1u, 0 } };
		free();
		surface = p_surface;
		texture = SDL_CreateTextureFromSurface(getRenderer(), surface);
		if (align == Align::CENTER) getPosition().set(centerPosition - Size{ surface->w >> 1u, 0 });
	}

	void Image::show()
	{
		model.show();
	}

	void Image::hide()
	{
		model.hide();
	}

	void Image::step(const unsigned int dt)
	{
		model.step(dt);
	}

	void Image::render()
	{
		SDL_SetTextureAlphaMod(texture, static_cast<Uint8>(model.getA()));
		const SDL_Rect rect{ getPosition().get().x, getPosition().get().y, surface->w, surface->h };
		SDL_RenderCopy(getRenderer(), texture, nullptr, &rect);
	}

	Image::~Image()
	{
		free();
	}
}

#endif
