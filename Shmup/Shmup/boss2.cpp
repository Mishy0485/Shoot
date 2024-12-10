#include"boss2.h"
#include"jeu.h"

Boss2::Boss2(int x, int y, int v) : Ennemi(x, y, vie)
{
	boss2.loadFromFile("boss2.png");
	general.setTexture(boss2);
	general.setPosition(x, y);
}

void Boss2::tir(vector<Projectile*>& bulleta) {

	bulleta.push_back(new Projectile(general.getPosition().x, general.getPosition().y, 20, 0, false));
}

void Boss2::capaciteSimple(vector<Projectile*>& bulleta, Projectile Bullet)
{
	capsmpl1.loadFromFile("laser_gen.png");
	laser_gen.setTexture(capsmpl1);
}

void Boss2::capaciteSpe(Jeu jeu)
{
	jeu.spawnEnnemi(2,1);
}