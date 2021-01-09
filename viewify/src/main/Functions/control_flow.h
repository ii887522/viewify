#ifndef TEST

#ifndef II887522_VIEWIFY_CONTROL_FLOW_H
#define II887522_VIEWIFY_CONTROL_FLOW_H

#include "../Any/App.h"
#include <SDL.h>
#include "../Any/Enums.h"

namespace ii887522::viewify
{
	// Not Thread Safe: it must only be called in main thread
	// See also ../Any/View.h for more details
	template <unsigned int viewCount> void eventLoop(App<viewCount>&& app)
	{
		SDL_Event event;
		auto lastTime{ SDL_GetTicks() };
		while (true)
		{
			while (SDL_PollEvent(&event)) if (app.react(event) == Action::QUIT) return;
			const auto now{ SDL_GetTicks() };
			app.step(now - lastTime);
			app.checkAndReactHits(now - lastTime);
			lastTime = now;
			app.show();
			SDL_Delay(4u);
		}
	}
}

#endif
#endif
