#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#include "include/scene.h"
#include "include/ui.h"

void testScene1(SDL_Renderer *rend, std::vector<SDL_Event> events, int mouse_x, int mouse_y);
void testScene2(SDL_Renderer *rend, std::vector<SDL_Event> events, int mouse_x, int mouse_y);

std::function<void(SDL_Renderer*, std::vector<SDL_Event>, int, int)> scene;

void testScene1(SDL_Renderer *rend, std::vector<SDL_Event> events, int mouse_x, int mouse_y){
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
	if(button.clicked(events, mouse_x, mouse_y)){
		std::cout << "clicked" << std::endl;
	}
}

void testScene2(SDL_Renderer *rend, std::vector<SDL_Event> events, int mouse_x, int mouse_y){
	for(int i = 0; i < events.size(); i++){
		switch(events[i].type){
			case SDL_KEYDOWN:
				scene = testScene1;
				break;
		}
	}
	SDL_SetRenderDrawColor(rend, 255, 170, 170, 255);
}

