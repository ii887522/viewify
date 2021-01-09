#ifndef TEST

#ifndef II887522_VIEWIFY_APP_H
#define II887522_VIEWIFY_APP_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "../Struct/Size.h"
#include "Enums.h"
#include "../View/ViewGroup.h"
#include <initializer_list>
#include "../Factory/ViewGroupFactory.h"

using std::string;
using std::initializer_list;

namespace ii887522::viewify
{
	// Not Thread Safe: it must only be used in main thread
	// See also ./View.h for more details
	template <unsigned int viewCount> class App final
	{
		// remove copy semantics
		App(const App&) = delete;
		App& operator=(const App&) = delete;

		// remove move semantics
		App(App&&) = delete;
		App& operator=(App&&) = delete;

		SDL_Window*const window;
		SDL_Surface*const favicon;
		SDL_Renderer*const renderer;
		ViewGroup<viewCount> scene;

		constexpr void reactMouseButtonDown(const SDL_MouseButtonEvent& buttonEvent)
		{
			if (buttonEvent.button == SDL_BUTTON_LEFT) scene.reactLeftMouseButtonDown(buttonEvent);
		}

		constexpr void reactMouseButtonUp(const SDL_MouseButtonEvent& buttonEvent)
		{
			if (buttonEvent.button == SDL_BUTTON_LEFT) scene.reactLeftMouseButtonUp(buttonEvent);
		}

		constexpr void reactWindowEvent(const SDL_WindowEvent& windowEvent)
		{
			if (windowEvent.event == SDL_WINDOWEVENT_LEAVE) scene.reactMouseLeaveWindow(windowEvent);
		}

		void renderBackground()
		{
			SDL_SetRenderDrawColor(renderer, 0u, 0u, 0u, 255u);
			SDL_RenderClear(renderer);
		}

		void render()
		{
			renderBackground();
			scene.render();
		}

	public:
		explicit App(const string& title, const Size<int>& size, ViewGroupFactory<viewCount>& sceneFactory) :
			window{ SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.w, size.h, 0u) },
			favicon{ IMG_Load("res/main/favicon.png") }, renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED) },
			scene(sceneFactory.make(renderer, size))
		{
			SDL_SetWindowIcon(window, favicon);
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		}

		constexpr Action react(const SDL_Event& event)
		{
			switch (event.type)
			{
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

		constexpr void step(const unsigned int dt)
		{
			scene.step(dt);
		}

		constexpr void checkAndReactHits(const unsigned int dt)
		{
			scene.checkAndReactHits(dt);
		}

		void show()
		{
			render();
			SDL_RenderPresent(renderer);
		}

		~App()
		{
			SDL_DestroyRenderer(renderer);
			SDL_FreeSurface(favicon);
			SDL_DestroyWindow(window);
		}
	};
}

#endif
#endif
