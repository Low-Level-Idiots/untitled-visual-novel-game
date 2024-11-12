#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#include "include/scene.h"
#include "include/ui.h"

void testScene1(SDL_Renderer *rend, std::vector<SDL_Event> events);
void testScene2(SDL_Renderer *rend, std::vector<SDL_Event> events);

std::function<void(SDL_Renderer*, std::vector<SDL_Event>)> scene;

void testScene1(SDL_Renderer *rend, std::vector<SDL_Event> events){
	Button button(rend, 50, 50);
	for(int i = 0; i < events.size(); i++){
		switch(events[i].type){
			case SDL_KEYDOWN:
				scene = testScene2;
				break;
		}
	}
	SDL_SetRenderDrawColor(rend, 170, 170, 255, 255);
	button.render(rend, 1);
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

