#pragma once
#include <vector>
#include <iostream>

#include "Cell.h"


static class GameOfLife
{
public:
	GameOfLife();
	~GameOfLife();
	void CreateGame(int w);
	void draw(SDL_Renderer* renderer);

private:
	struct int2 {
		int a[2];
	};
	float next;
	std::vector<Cell> Cells;
	Cell cells[96][96] = {};
	Cell cells2[96][96] = {};
	int h;
	void check(int i, int j, int indexInt2);
	void nextScene();
	std::vector<int2> vivos;

	
};

