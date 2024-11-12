#ifndef UI_H
#define UI_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Img {
	public:
		Img(SDL_Renderer* rend, char* file);
		SDL_Surface *surf;
		SDL_Texture *tex;
		void render(SDL_Renderer* rend, int x, int y, int w, int h);
};

class Button {
	public:
		Button(SDL_Renderer* rend, int x, int y);
		Img *sprite;
		int x;
		int y;
		void render(SDL_Renderer *rend, int scale);
		bool clicked(std::vector<SDL_Event> events);
};

#endif
