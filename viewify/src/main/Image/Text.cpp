#ifndef TEST

#include "Text.h"
#include "../View/Image.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "../Struct/Color.h"
#include "../Struct/Point.h"
#include <stdexcept>
#include "../Any/Enums.h"

using std::string;
using std::runtime_error;

namespace ii887522::viewify
{
	Text::Builder::Builder(SDL_Renderer*const renderer, TTF_Font*const font, const Point<int>& position, const string& value,
		const Color<unsigned int>& color, const Align align) : renderer{ renderer }, font{ font }, position{ position }, value{ value },
			color{ color }, a{ 255u }, duration{ 0u }, hasSetDuration{ false }, align{ align } { }

	Text* Text::Builder::build()
	{
		if (hasSetDuration) return new Text{ *this };
		throw runtime_error{ "Text duration is required!" };
	}

	Text::Text(const Builder& builder) : Image{ Image::Builder{ builder.renderer, TTF_RenderText_Blended(
			builder.font, builder.value.c_str(),
			SDL_Color{ static_cast<Uint8>(builder.color.r), static_cast<Uint8>(builder.color.g), static_cast<Uint8>(builder.color.b) }
		), builder.position, builder.align }.setA(builder.a).setDuration(builder.duration) }, font{ builder.font }, color{ builder.color } { }

	void Text::set(const string& value)
	{
		Image::set(TTF_RenderText_Blended(font, value.c_str(), SDL_Color{
			static_cast<Uint8>(color.r), static_cast<Uint8>(color.g), static_cast<Uint8>(color.b)
		}));
	}
}

#endif
