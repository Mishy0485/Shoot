#include "projectile.h"

Projectile::Projectile(int x, int y, int v, int t, bool s) : x(x), y(y), vitesse(v), type(t), playerSide(s)
{
	bullet.loadFromFile("bulleta.png");
	Bullety.setTexture(bullet);
	Bullety.setPosition(x, y);
	Bullety.setScale(0.02, 0.02);
	Bullety.rotate(180);
}

bool Projectile::getHitValue() {
	return hit;
}

void Projectile::setHitValue(bool b) {
	hit = b;
}

bool Projectile::getSide() {
	return playerSide;
}

void Projectile::setSide(bool b) {
	playerSide = b;
}

bool Projectile::isOutOfScreen() {
	if (playerSide)
		return Bullety.getPosition().y < 0;
	else
		return Bullety.getPosition().y > 1079;
}

Sprite Projectile::getSprite() {
	return Bullety;
}

void Projectile::fuse(bool up) {
	if (up)
		Bullety.move(0, -vitesse);
	else
		Bullety.move(0, vitesse);
}