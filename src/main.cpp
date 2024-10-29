#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *win = SDL_CreateWindow("Untitled Visual Novel Game", 30, 10, 900, 600, 0);
	SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	bool running = true;
	while(running){
		Uint32 frame_start = SDL_GetTicks();
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
					// key handling here
					break;
			}
		}
		Uint32 frame_time = SDL_GetTicks() - frame_start;
		if(frame_time < 60){
			SDL_Delay(60 - frame_time);
		}
		SDL_RenderClear(rend);

		SDL_SetRenderDrawColor(rend, 170, 170, 255, 255);
		SDL_RenderPresent(rend);
	}
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
