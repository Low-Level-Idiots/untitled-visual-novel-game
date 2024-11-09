#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "scene.h"
#include "ui.h"
#include "convo.h"

Convo::Convo(SDL_Renderer *rend, std::string d){
	dialogue = d;
}

void Convo::render(SDL_Renderer *rend){}
