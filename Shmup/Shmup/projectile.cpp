#include "projectile.h"

Projectile::Projectile(int x, int y, int v, int t, bool s) : x(x), y(y), vitesse(v), type(t), playerSide(s)
{
	bullet.loadFromFile("bulleta.png");
	Bullety.setTexture(bullet);
	Bullety.setPosition(x, y);
	Bullety.setScale(0.02, 0.02);
	Bullety.rotate(180);
}

int Projectile::getPositionX() { return Bullety.getPosition().x; }
int Projectile::getPositionY() { return Bullety.getPosition().y; }

bool Projectile::getSepState() {
	return separated;
}

void Projectile::setSepState() {
	separated = true;
}

int Projectile::setPositionX(int n)
{
	x += n;
}

int Projectile::setPositionY(int n)
{
	y += n;
}

int Projectile::getType() {
	return type;
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

void Projectile::fuse1(bool up) {
	if (up)
		Bullety.move(vitesse, vitesse);
	else
		Bullety.move(-vitesse, vitesse);
}

void Projectile::separation(vector<Projectile*>& bulleta, Projectile bullet)
{
	bulleta.push_back(new Projectile(bullet.getPositionX() , bullet.getPositionY(), 20, 2, false));

	bulleta.push_back(new Projectile(bullet.getPositionX() , bullet.getPositionY(), 20, 3, false));
}