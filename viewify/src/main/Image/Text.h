#ifndef TEST

#ifndef II887522_VIEWIFY_TEXT_H
#define II887522_VIEWIFY_TEXT_H

#include "../View/Image.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "../Struct/Color.h"
#include "../Struct/Point.h"
#include "../Any/Enums.h"

using std::string;

namespace ii887522::viewify
{
	// Not Thread Safe: it must only be used in main thread
	class Text : public Image
	{
		// remove copy semantics
		Text(const Text&) = delete;
		Text& operator=(const Text&) = delete;

		// remove move semantics
		Text(Text&&) = delete;
		Text& operator=(Text&&) = delete;

	public:
		// Not Thread Safe
		class Builder final
		{
			// remove copy semantics
			Builder(const Builder&) = delete;
			Builder& operator=(const Builder&) = delete;

			// remove move semantics
			Builder(Builder&&) = delete;
			Builder& operator=(Builder&&) = delete;

			SDL_Renderer*const renderer;
			TTF_Font*const font;
			const Point<int>& position;
			const string value;
			const Color<unsigned int> color;
			unsigned int a;
			unsigned int duration; // animation duration
			bool hasSetDuration; // has set animation duration
			const Align align;

		public:
			// Param renderer: it must not be assigned to integer
			// Param font: it must not be assigned to integer
			explicit Builder(SDL_Renderer*const renderer, TTF_Font*const font, const Point<int>& position, const string& = " ",
				const Color<unsigned int>& = Color{ 0u, 0u, 0u }, const Align = Align::LEFT);
					// " " because TTF_Render*() needs a string with at least one character.

			constexpr Builder& setA(const unsigned int p_value)
			{
				a = p_value;
				return *this;
			}

			// Animation duration
			// Param p_value: it must not be assigned to 0
			// Must Call Time(s): At least 1
			constexpr Builder& setDuration(const unsigned int p_value)
			{
				duration = p_value;
				hasSetDuration = true;
				return *this;
			}

			// Must Call Time(s): At least 1
			Text* build();

			friend class Text;
		};

	private:
		TTF_Font*const font;
		const Color<unsigned int> color;

	protected:
		explicit Text(const Builder&);

	public:
		// Param str: it must not be assigned to ""
		void set(const string& str);// str must not be equal to "" because TTF_Render*() needs a string with at least one character.
	};
}

#endif
#endif
