#include"boss2.h"
//#include"jeu.h"

Boss2::Boss2(int x, int y, int v, int t, int s) : Ennemi(x, y, v, 4, s)
{
	boss2.loadFromFile("boss2.png");
	general.setTexture(boss2);
	general.setPosition(x, y);
}

void Boss2::tir(vector<Projectile*>& bulleta) {

	capsmpl1.loadFromFile("laser_gen.png");
	laser_gen.setTexture(capsmpl1);
	bulleta.push_back(new Projectile(general.getPosition().x, general.getPosition().y, 20, 0, false));
}

void Boss2::deplacementLaser(Projectile Bullet)
{
	// bouge aleatoirement gauche/droite ?
	int sens;
	sens = rand() * 2;

	Bullet.fuse1(false); //  autre fuse pour les diags 

	// si touche cote gauche inverse
	if (Bullet.getPositionX() < 0)
	{
		Bullet.setPositionX(0);
	}

	// si touche cote droit devit vers gauche
	if (Bullet.getPositionX() > 1919)
	{
		Bullet.setPositionX(1919);
	}
}

void Boss2::capaciteSpe()
{
	//Jeu::spawnEnnemi(2,1);
}

Sprite Boss2::getSprite() {
	return general;
}

void Boss2::textureChange() {

}

void Boss2::mouvement() {

}