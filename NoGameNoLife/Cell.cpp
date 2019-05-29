#include "Cell.h"



Cell::Cell()
{
	alive = false;
	checked = false;
}
Cell::Cell(int x, int y, int h, int w){
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	alive = false;
	int2 i;
}
Cell::~Cell()
{
}

void Cell::render(SDL_Renderer *renderer)
{
	if (!alive) {
		SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
		SDL_RenderDrawRect(renderer, &r);
	}
	else {
		SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
		SDL_RenderFillRect(renderer, &r);
	}
	
}
