#include "boss1.h"

Boss1::Boss1(int x, int y, int v) : Ennemi(x, y, vie)
{
	boss1.loadFromFile("boss1.png");
	colonel.setTexture(boss1);
	colonel.setPosition(x, y);
}

void Boss1::tir(vector<Projectile*>& bulleta) {

	bulleta.push_back(new Projectile(colonel.getPosition().x, colonel.getPosition().y, 20, 0, false));
}

void Boss1::capaciteSimple(vector<Projectile*>& bulleta, Projectile Bullet)
{
	if (Bullet.getPositionY() > 375)
	{
		Bullet.separation(bulleta, Bullet);
	}
}

void Boss1::capaciteSpe()
{
	capspe.loadFromFile("laser.png");
	laser.setTexture(capspe);
}