#include "ennemi.h"
#include <iostream>

	Ennemi::Ennemi(int x, int y, int v, int t, int s, int p) : x(x), y(y), vie(v), type(t), attackspeed(s), point (p){}

	void Ennemi::degats(int degats)
	{
		vie -= degats;
	}

	int Ennemi::getASpeed() {
		return attackspeed;
	}

	bool Ennemi::EstMort()
	{
		return vie <= 0;
	}

	int Ennemi::getX() {
		return x;
	}

	int Ennemi::getY() {
		return y;
	}

	int Ennemi::getType() {
		return type;
	}

	int Ennemi::getPoint() {
		return point;
	}
