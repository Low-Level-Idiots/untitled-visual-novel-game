#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#include "scene.h"
#include "ui.h"

void testScene1(SDL_Renderer *rend, std::vector<SDL_Event> events, int mouse_x, int mouse_y);
void testScene2(SDL_Renderer *rend, std::vector<SDL_Event> events, int mouse_x, int mouse_y);

std::function<void(SDL_Renderer*, std::vector<SDL_Event>, int, int)> scene;
SDL_Color clr = {255, 255, 255};

void testScene1(SDL_Renderer *rend, std::vector<SDL_Event> events, int mouse_x, int mouse_y){
	Button button(50, 50);
	Text txt("test", 20, clr);
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
	txt.render(rend, 10, 10, 200, 100);
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
