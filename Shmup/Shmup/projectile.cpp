#include "projectile.h"

Projectile::Projectile(int x, int y, int v, int t) : x(x), y(y), vitesse(v), type(t) 
{
	bullet.loadFromFile("");
	Bullety.setTexture(bullet);
}

bool Projectile::isInCollision(Sprite& sprite1, Projectile* currentBulleta)
{
	if (Bullety.getGlobalBounds().intersects(sprite1.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

bool Projectile::isInCollision1(Projectile* currentBulleta)
{
	if ( Bullety.getPosition().y > 1079)    
	{
		return true;
	}
	return false;
}

//void Projectile::tir(Sprite& sprite2, Projectile* currentBulleta)
//{
//	bulleta.push_back(new Projectile (x, y, 200, 0)); // type a changer
//	Bullety.move(Vector2f(0.1f, 0.f));
//
//	if (currentBulleta->isInCollision(sprite2, currentBulleta))
//	{
//		// perde de la vie 
//		
//
//			// ou meurt
//		if ()
//		{
//
//		}
//
//		// bullet meurt
//		delete(currentBulleta);
//	}
//
//	else if (currentBulleta->isInCollision1(currentBulleta))
//	{
//		// bullet meurt 
//		delete(currentBulleta);
//	}
//}