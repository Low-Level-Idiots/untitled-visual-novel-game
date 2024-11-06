#include <iostream>
#include <vector>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "scene.h"

int main(int argc, char* argv[]){
//	SDL_Init(SDL_INIT_EVERYTHING);
//	IMG_Init(IMG_INIT_PNG);
	SDL_Window *win = SDL_CreateWindow("Untitled Visual Novel Game", 30, 10, 900, 600, 0);
	SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface *icon = IMG_Load("assets/test.png");

	SDL_Texture *test_tex = SDL_CreateTextureFromSurface(rend, icon);

	SDL_Rect test_ent {10, 10, 100, 100};

	SDL_SetWindowIcon(win, icon);
	SDL_FreeSurface(icon);
	scene = testScene1;

	bool running = true;
	while(running){
		Uint32 frame_start = SDL_GetTicks();
		SDL_Event event;
		std::vector<SDL_Event> events;
		while(SDL_PollEvent(&event)){
			events.push_back(event);
		}
		for(int i = 0; i < events.size(); i++){
			switch(events[i].type){
				case SDL_QUIT:
					running = false;
					break;
			}
		}
		Uint32 frame_time = SDL_GetTicks() - frame_start;
		if(frame_time < 60){
			SDL_Delay(60 - frame_time);
		}
		SDL_RenderClear(rend);

		scene(rend, events);

		SDL_RenderCopy(rend, test_tex, NULL, &test_ent);

		SDL_RenderPresent(rend);
	}
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
