#ifndef CONVO_H
#define CONVO_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "scene.h"

class Convo;
class Option;

class Convo {
	public:
		Convo();
		std::string dialogue;
		void add_option(Option option);
		void render(SDL_Renderer rend);
		Convo input();
}

class Option {
	public:
		Option();
		std::string text
		Convo target;
}

#endif
