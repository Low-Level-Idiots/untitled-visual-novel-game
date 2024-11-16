#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ui.h"

Img::Img(std::string filename){
	surf = IMG_Load(filename.c_str());
}

void Img::render(SDL_Renderer *rend, int x, int y, int w, int h){
	SDL_Rect dest {x, y, w, h};
	SDL_RenderCopy(rend, SDL_CreateTextureFromSurface(rend, surf), NULL, &dest);
}

Button::Button(int x_pos, int y_pos){
	Img temp_sprite = Img("assets/test_button.png");
	sprite = &temp_sprite;                                                     // part 1 of the pointer ping pong solution
	x = x_pos;
	y = y_pos;
}

void Button::render(SDL_Renderer *rend, int scale){
	Img temp_sprite = *sprite;                                                 // part 2 of the pointer ping pong solution
	temp_sprite.render(rend, x, y, 75 * scale, 25 * scale);
}

bool Button::clicked(std::vector<SDL_Event> events, int mouse_x, int mouse_y){
	if(mouse_x >= x &&
		mouse_x <= x + 75 &&
		mouse_y >= y && 
		mouse_y <= y + 25){
		for(int i = 0; i < events.size(); i++){
			switch(events[i].type){
				case SDL_MOUSEBUTTONDOWN:
					switch(events[i].button.button){
						case SDL_BUTTON_LEFT:
							return true;
							break;
					}
					break;
			}
		}
	}
	return false;
}
