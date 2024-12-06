#include "projectile.h"

Projectile::Projectile(int x, int y, int v, int t) : x(x), y(y), vitesse(v), type(t) 
{
	bullet.loadFromFile("C:\\Users\\sbrossard\\source\\repos\\Mishy0485\\Shoot\\Shmup\\bulleta.png");
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


bool Projectile::isOutOfScreen() {
	return Bullety.getPosition().y < 0;
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