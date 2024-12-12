#include"boss3.h"
#include"jeu.h"

Boss3::Boss3(int x, int y, int v, int t, int s) : Ennemi(x, y, v, 5, s)
{
	boss3.loadFromFile("princeAlienTropMimi.png");
	prince.setTexture(boss3);
	prince.setPosition(x, y);
}

void Boss3::tir(vector<Projectile*>& bulleta)
{

	while (nbBomb < 5)
	{
		// appeler le constructeur

		nbBomb++;

	}
	// spawn new des qu'une a explosée ? good
}

void Boss3::capaciteSpe()
{
	// spawn aleatoirement sur la map good
	// taille de la bombe? 300x300 ? good
}