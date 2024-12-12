#include "boss1.h"

Boss1::Boss1(int x, int y, int v, int t, int s) : Ennemi(x, y, v, 3, s)
{
	
	boss1.loadFromFile("boss1.png");
	colonel.setTexture(boss1);
	colonel.setPosition(x, y); 
	cout << "Création du boss avec vie: " << vie << endl;
	}


void Boss1::tir(vector<Projectile*>& bulleta) {

	bulleta.push_back(new Projectile(colonel.getPosition().x, colonel.getPosition().y, 20, 1, false));
}


Sprite Boss1::getSprite() {
	return colonel;
}


void Boss1::capaciteSpe()
{
	capspe.loadFromFile("laser.png");
	laser.setTexture(capspe);
	laser.setScale(3, 3);
	laser.setPosition(0, 0);
}

void Boss1::mouvement() {
	x = colonel.getPosition().x;
	if (droite) {
		if (x >= 1700) {
			droite = false;
		}
		else {
			colonel.move(Vector2f(3, 0));
		}
	}
	else if (droite == false) {
		if (x <= 50) {
			droite = true;
		}
		else {
			colonel.move(Vector2f(-3, 0));
		}
	}
}

void Boss1::textureChange() {
	cout << "A FAIRE";
}

Sprite Boss1::getSpeSprite() {
	return laser;
}