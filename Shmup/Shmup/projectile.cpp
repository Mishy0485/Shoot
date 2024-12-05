#include "projectile.h"

Projectile::Projectile(int x, int y, int v, int t) : x(x), y(y), vitesse(v), type(t) 
{
	bullet.loadFromFile("");
	Bullety.setTexture(bullet);
}

bool Projectile::isInCollision(Sprite& sprite1)
{
	if (Bullety.getGlobalBounds().intersects(sprite1.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

bool Projectile::isInCollision()
{
	if ( Bullety.getPosition().y > 1079)
	{
		return true;
	}
	return false;
}