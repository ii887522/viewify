#ifndef TEST

#include "sdl_ext.h"
#include "../Struct/Point.h"
#include <SDL.h>

namespace ii887522::viewify
{
	Point<int> getMousePosition()
	{
		Point<int> result;
		SDL_GetMouseState(&result.x, &result.y);
		return result;
	}
}

#endif
