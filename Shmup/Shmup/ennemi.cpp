#include "ennemi.h"
#include <iostream>

	Ennemi::Ennemi(int x, int y, int v) : x(x), y(y), vie(v){}

	void Ennemi::degats(int degats)
	{
		vie -= degats;
	}

	bool Ennemi::EstMort()
	{
		return vie<=0;
	}

	int Ennemi::getX() {
		return x;
	}

	int Ennemi::getY() {
		return y;
	}
