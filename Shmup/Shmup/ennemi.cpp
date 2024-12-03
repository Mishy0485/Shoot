#include "ennemi.h"


	Ennemi::Ennemi(int t, Texture tex, int v) : type(t), texture(tex), vie(v) {} // avoir pour position

	void Ennemi::attaque(int degats)
	{

	}

	// avoir s'ils se deplacent

	void Ennemi::tir()
	{}

	void Ennemi::degats()
	{
		int degats;
		vie -= degats;
	}

	bool Ennemi::EstVivant()
	{
		return vie<=0;
	}
};
