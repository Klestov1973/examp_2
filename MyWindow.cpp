/*
 * MyWindow.cpp
 *
 *  Created on: 19 ���. 2020 �.
 *      Author: admin
 */

#include "MyWindow.h"
#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>

#include <SDL2/SDL.h>

static constexpr double Pi = acos(-1.);
#ifdef _WIN32
# include <SDL2/SDL_main.h>
#endif
#include "ExampleWindow.h"

constexpr int WIDTH=800, HEIGHT=600;
int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	auto win = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
						"Домик",
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
						WIDTH, HEIGHT,
						SDL_WINDOW_SHOWN),
			SDL_DestroyWindow);
	if (win == nullptr) {
		std::cerr << "При создании окна произошла ошибка: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	auto ren = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(win.get(), -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);
	if (ren == nullptr) {
		std::cerr << "При создании renderer-а произошла ошибка: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Event event;

	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) return 0;
		}

		SDL_SetRenderDrawColor(ren.get(), 0, 48, 64, 255);
		SDL_RenderClear(ren.get());
		SDL_SetRenderDrawColor(ren.get(), 255, 255, 255, 255);
			SDL_Rect rect = {200, 270, 400, 300};
		    SDL_RenderFillRect(ren.get(), &rect);
			SDL_RenderDrawLine(ren.get(), 200, 270, 400, 100);
			SDL_RenderDrawLine(ren.get(), 600, 270, 400, 100);
			SDL_RenderDrawLine(ren.get(), 250, 500, 250, 370);


		SDL_RenderPresent(ren.get());
	}


	return 0;
}



