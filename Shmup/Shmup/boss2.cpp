#include"boss2.h"

Boss2::Boss2(int x, int y, int v, int t, int s) : Ennemi(x, y, v, 4, s)
{
	boss2.loadFromFile("boss2.png");
	general.setTexture(boss2);
	general.setPosition(x, y);
	general.setScale(2, 2);
}

void Boss2::tir(vector<Projectile*>& bulleta) {
	for (int i = 6; i > 0; i--) {
		bulleta.push_back(new Projectile(general.getPosition().x + 50, general.getPosition().y + 150, 10, 4, false));
	}
}

void Boss2::capaciteSpe() {
	spe = true;
}

Sprite Boss2::getSprite() {
	return general;
}

void Boss2::textureChange() {
	return;
}

void Boss2::mouvement() {
	x = general.getPosition().x;
	if (droite) {
		if (x >= 1700) {
			droite = false;
		}
		else {
			general.move(Vector2f(3, 0));
		}
	}
	else if (droite == false) {
		if (x <= 50) {
			droite = true;
		}
		else {
			general.move(Vector2f(-3, 0));
		}
	}
}

Sprite& Boss2::getSpeSprite() {
	return general;
}