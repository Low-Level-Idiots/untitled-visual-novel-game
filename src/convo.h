#ifndef CONVO_H
#define CONVO_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "scene.h"
#include "ui.h"

class Convo;
class Option;

class Convo {
	public:
		Convo(SDL_Renderer *rend, std::string dialogue);
		std::string dialogue;
		void render(SDL_Renderer *rend);
};

#endif
