#pragma once
#include <iostream>
#include <SDL.h>

class Cell
{
public:
	Cell();
	Cell(int x, int y, int h, int w);
	~Cell();
	bool alive;
	bool checked;
	void render(SDL_Renderer *render);
private:
	SDL_Rect r;
	struct int2 {
		int a[2];
	};
};

