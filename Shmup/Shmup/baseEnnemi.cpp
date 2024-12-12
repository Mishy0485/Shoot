#include "baseEnnemi.h"

BaseEnnemi::BaseEnnemi(int x, int y, int v) : Ennemi(x, y , v) {
	bEnnemiTexture.loadFromFile("ennemi1.PNG");
	bEnnemiTextureHit.loadFromFile("ennemi1_hit.png");
	bEnnemisprite.setTexture(bEnnemiTexture);
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
		bulleta.push_back(new Projectile(bEnnemisprite.getPosition().x + 100, bEnnemisprite.getPosition().y + 100, 10, 0, false));
	}
}

void BaseEnnemi::textureChange() {
	bEnnemisprite.setTexture(bEnnemiTextureHit);
}

void BaseEnnemi::capaciteSimple(vector<Projectile*>& bulleta, Projectile bullet) {
	return;
}

void BaseEnnemi::capaciteSpe(Jeu jeu) {
	return;
}