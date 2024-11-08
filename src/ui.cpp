#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ui.h"

Img::Img(SDL_Renderer* rend, char* file){
	surf = IMG_Load(file);
	tex = SDL_CreateTextureFromSurface(rend, surf);
}

void Img::render(SDL_Renderer* rend, int x, int y, int w, int h){
	SDL_Rect dest {x, y, w, h};
	SDL_RenderCopy(rend, tex, NULL, &dest);
}
