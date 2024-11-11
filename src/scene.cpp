#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#include "include/scene.h"
#include "include/ui.h"

void testScene1(SDL_Renderer *rend, std::vector<SDL_Event> events);
void testScene2(SDL_Renderer *rend, std::vector<SDL_Event> events);

std::function<void(SDL_Renderer*, std::vector<SDL_Event>)> scene;

void testScene1(SDL_Renderer *rend, std::vector<SDL_Event> events){
	Img button(rend, "assets/test_button.png");
	for(int i = 0; i < events.size(); i++){
		switch(events[i].type){
			case SDL_KEYDOWN:
				scene = testScene2;
				break;
		}
	}
	SDL_SetRenderDrawColor(rend, 170, 170, 255, 255);
	button.render(rend, 30, 30, 75, 25);
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

