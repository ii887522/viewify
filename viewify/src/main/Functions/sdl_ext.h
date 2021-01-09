#ifndef TEST

#ifndef II887522_VIEWIFY_SDL_EXT_H
#define II887522_VIEWIFY_SDL_EXT_H

#include "../Struct/Point.h"

namespace ii887522::viewify
{
	// Not Thread Safe: it must be called in main thread
	Point<int> getMousePosition();
}

#endif
#endif
