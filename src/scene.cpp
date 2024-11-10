#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#include "scene.h"

void testScene1(SDL_Renderer *rend, std::vector<SDL_Event> events);
void testScene2(SDL_Renderer *rend, std::vector<SDL_Event> events);

std::function<void(SDL_Renderer*, std::vector<SDL_Event>)> scene;

void testScene1(SDL_Renderer *rend, std::vector<SDL_Event> events){
	// define a convo here
	// call a convo
	for(int i = 0; i < events.size(); i++){
		switch(events[i].type){
			case SDL_KEYDOWN:
				scene = testScene2;
				break;
		}
	}
	SDL_SetRenderDrawColor(rend, 170, 170, 255, 255);
}

void testScene2(SDL_Renderer *rend, std::vector<SDL_Event> events){
	for(int i = 0; i < events.size(); i++){
		switch(events[i].type){
			case SDL_KEYDOWN:
				scene = testScene1;
				break;
		}
	}
	SDL_SetRenderDrawColor(rend, 255, 170, 170, 255);
}

