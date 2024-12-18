#include "projectile.h"

Projectile::Projectile(int x, int y, int v, int t, bool s) : x(x), y(y), vitesse(v), type(t), playerSide(s)
{
	bullet.loadFromFile("bulleta.png");
	Bullety.setTexture(bullet);
	Bullety.setPosition(x, y);
	Bullety.setScale(0.02, 0.02);
	Bullety.rotate(180);
	if (type == 4) {
		bullet.loadFromFile("laser_gen_coupe.png");
		Bullety.setTexture(bullet);
	}
}

bool Projectile::getSepState() {
	return separated;
}

void Projectile::setSepState() {
	separated = true;
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

void Projectile::deplacementLaser() {
	// bouge aleatoirement gauche/droite ?
	int sens;
	sens = rand() % 2;

	if (sens == 0) fuse1(false); //  autre fuse pour les diags 
	else fuse1(true);

	// si touche cote gauche inverse
	if (Bullety.getPosition().x < 0)
	{
		fuse1(true);
	}

	// si touche cote droit devit vers gauche
	if (Bullety.getPosition().x > 1919)
	{
		fuse1(false);
	}
}

void Projectile::separation(vector<Projectile*>& bulleta)
{
	bulleta.push_back(new Projectile(Bullety.getPosition().x , Bullety.getPosition().y, 20, 2, false));

	bulleta.push_back(new Projectile(Bullety.getPosition().x , Bullety.getPosition().y, 20, 3, false));
}