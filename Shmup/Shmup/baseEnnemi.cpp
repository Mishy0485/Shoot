#include "baseEnnemi.h"

BaseEnnemi::BaseEnnemi(int x, int y, int v) : Ennemi(x, y , v) {
	bEnnemitexture.loadFromFile("C:\\Users\\sbrossard\\source\\repos\\Mishy0485\\Shoot\\Shmup\\ennemi1.PNG");
	bEnnemisprite.setTexture(bEnnemitexture);
	bEnnemisprite.setScale(5, 5);
	bEnnemisprite.setPosition(x, y);
}

Sprite BaseEnnemi::getSprite() {
	return bEnnemisprite;
}

void BaseEnnemi::mouvement() {
	x = bEnnemisprite.getPosition().x;
	if (droite) {
		if (x >= 1700) {
			droite = false;
		}
		else {
			bEnnemisprite.move(Vector2f(5, 0));
		}
	}
	else if (droite == false) {
		if (x <= 50) {
			droite = true;
		}
		else {
			bEnnemisprite.move(Vector2f(-5, 0));
		}
	}
}

void BaseEnnemi::tir(vector<Projectile*>& bulleta) {
	{
		bulleta.push_back(new Projectile(bEnnemisprite.getPosition().x, bEnnemisprite.getPosition().y, 10, 0, false));
	}
}