#include "GameOfLife.h"



GameOfLife::GameOfLife()
{
	float next = 1;
}


GameOfLife::~GameOfLife()
{
}

void GameOfLife::CreateGame(int w)
{
	h = w / 10;
	
	for (size_t i = 0; i != h; i++)
	{
		for (size_t j = 0; j != h; j++)
		{
			Cell c(j*10, i*10, 10, 10);
			c.checked = false;
			cells2[j][i] = c;
		}
	}
	cells2[1][0].alive = true;
	cells2[2][1].alive = true;
	cells2[2][2].alive = true;
	cells2[1][2].alive = true;
	cells2[0][2].alive = true;
	for (size_t i = 0; i != h; i++)
	{
		for (size_t j = 0; j != h; j++)
		{
			cells[j][i] = cells2[j][i];
		}
	}
	int2 i;
	i.a[0] = 1;
	i.a[1] = 0;
	vivos.push_back(i);
	i.a[0] = 2;
	i.a[1] = 1;
	vivos.push_back(i);
	i.a[0] = 2;
	i.a[1] = 2;
	vivos.push_back(i);
	i.a[0] = 1;
	i.a[1] = 2;
	vivos.push_back(i);
	i.a[0] = 0;
	i.a[1] = 2;
	vivos.push_back(i);
}

void GameOfLife::draw(SDL_Renderer* renderer)
{
	for (size_t i = 0; i != h; i++)
	{
		for (size_t j = 0; j != h; j++)
		{
			cells[j][i] = cells2[j][i];
			cells[j][i].render(renderer);
		}
	}
	next -= 0.07f;
	if (next < 0) {
		nextScene();
		next = 1;
	}

}

void GameOfLife::nextScene() {

	for (size_t i = 0; i != h; i++)
	{
		for (size_t j = 0; j != h; j++)
		{
			check(j, i, 0);
		}
	}
}

void GameOfLife::check(int i, int j, int indexInt2) {
	if (!cells[i][j].checked) {

		bool kb = false;
		bool lb = false;
		int alive = 0;
		int buf, buf2;
		for (int k = i - 1; k != i + 2; k++) {
			for (int l = j - 1; l != j + 2; l++) {
				if (k == i && l == j)
					continue;
				if (k == -1) {
					buf = k;
					k = h - 1;
					kb = true;
				}
				if (l == -1) {
					buf = l;
					l = h - 1;
					lb = true;
				}
				if (l == -1 && k == -1) {
					buf = l;
					l = h - 1;
					buf2 = k;
					k = h - 1;
					lb = true;
					kb = true;
				}
				if (cells[k][l].alive)
					alive++;

				if (kb) {
					k = buf;
					kb = false;
				}
				if (lb) {
					l = buf;
					lb = false;
				}
				if (kb && lb) {
					kb = false;
					lb = false;
					l = buf;
					k = buf2;
				}
			}
		}
		if (!cells[i][j].alive && alive == 3) {
			cells2[i][j].alive = true;
			int2 x;
			x.a[0] = i;
			x.a[1] = j;
			vivos.push_back(x);
		}
		else if ((alive == 3 && cells[i][j].alive) || (alive == 2 && cells[i][j].alive)) {

		}
		else {
			cells2[i][j].alive = false;
		}

		cells[i][j].checked = true;
	}
	
}