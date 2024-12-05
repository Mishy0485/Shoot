#include "ennemi.h"
#include <iostream>


	Ennemi::Ennemi(int x, int y, int t, int v) : x(x), y(y), type(t), vie(v)
	{
		textureEnnemi.loadFromFile("C:\\Users\\sbrossard\\source\\repos\\Mishy0485\\Shoot\\Shmup\\ennemi1.PNG");
		ennemiSprite.setTexture(textureEnnemi);
		ennemiSprite.setScale(5, 5);
		ennemiSprite.setPosition(x, y);
	}

	void Ennemi::attaque(int degats)
	{

	}

	Sprite Ennemi::getsprite() {
		return ennemiSprite;
	}
	// avoir s'ils se deplacent

	void Ennemi::tir()
	{}

	void Ennemi::mouvement() {
		x = ennemiSprite.getPosition().x;
		if (droite) {
			if (x >= 1700) {
				droite = false;
			}
			else {
				ennemiSprite.move(Vector2f(5, 0));
			}
		}
		else if (droite == false){
			if (x <= 50) {
				droite = true;
			}
			else {
				ennemiSprite.move(Vector2f(-5, 0));
			}
		}
	}

	void Ennemi::degats()
	{
		int degats;
		vie -= degats;
	}

	bool Ennemi::EstVivant()
	{
		return vie<=0;
	}

