#include <iostream>
#include <SDL.h>
#include "GameOfLife.h"


int main(int argc, char *argv[]) {
	SDL_Window* window = NULL;
	int w = 960;
	window = SDL_CreateWindow
	(
		"BRIUGET", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		w,
		w,
		SDL_WINDOW_SHOWN
	);

	// Setup renderer
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event windowEvent;

	GameOfLife game;

	game.CreateGame(w);

	while (true)
	{

		game.draw(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		
		if (SDL_PollEvent(&windowEvent))
		{
			if (windowEvent.type == SDL_QUIT)
			{
				break;
			}
		}

		SDL_RenderPresent(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}