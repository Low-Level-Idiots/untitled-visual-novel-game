#ifndef CONVO_H
#define CONVO_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

class Convo;
class Option;

class Convo {
	public:
		Convo();
		std::string dialogue;
		void addOption(Option option);
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
