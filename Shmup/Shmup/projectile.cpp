#include "projectile.h"

Projectile::Projectile(int x, int y, int v, int t) : x(x), y(y), vitesse(v), type(t) 
{
	bullet.loadFromFile("");
	Bullety.setTexture(bullet);
}

void Projectile::tir(Sprite& sprite2, Projectile* currentBulleta)
{
	bulleta.push_back(new Projectile (x, y, 200, 0)); // type a changer
	Bullety.move(Vector2f(0.1f, 0.f));
}

Sprite Projectile::getSprite() {
	return Bullety;
}