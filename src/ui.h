#ifndef UI_H
#define UI_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Img {
	public:
		Img(std::string filename);
		SDL_Surface *surf;
		void render(SDL_Renderer* rend, int x, int y, int w, int h);
};

class Button {
	public:
		Button(int x, int y);
		Img *sprite;
		int x;
		int y;
		void render(SDL_Renderer *rend, int scale);
		bool clicked(std::vector<SDL_Event> events, int mouse_x, int mouse_y);
};

#endif
