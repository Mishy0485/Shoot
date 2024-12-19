/*#include"expertEnnemi1.h"



ExpertEnnemi1::ExpertEnnemi1(int x, int y, int v, int t, int s) : Ennemi(x, y, v, 0, s, 400)
{
	eEnnemi1Texture.loadFromFile("ennemi2.PNG");
	eEnnemi1TextureHit.loadFromFile("ennemi2_hit.png");
	eEnnemi1sprite.setTexture(eEnnemi1Texture);
	eEnnemi1sprite.setScale(5, 5);
	eEnnemi1sprite.setPosition(x, y);
}

Sprite ExpertEnnemi1::getSprite() {
	return eEnnemi1sprite;
}

void ExpertEnnemi1::tir(vector<Projectile*> bulleta, vector<Ennemi*> ennemis)
{
	bulleta.push_back(new Projectile(eEnnemi1sprite.getPosition().x + 100, eEnnemi1sprite.getPosition().y + 100, 10, 0, false));

int x = ennemis[0]->getX();
	int y = ennemis[0]->getY(); 

	for (int i = 0; i < ennemis.size(); i++)
	{
		if (ennemis[i]->getX() < x && ennemis[i]->getY() < y)
		{
			x = ennemis[i]->getX();
			y = ennemis[i]->getY();
		}
	}

	 //si le x < a x ennemi : + au x et - si inverse

	if (.getPositionX() < x)
	{
		.setPositionX(vitesse);
	}
	else
	{
		.setPositionX(-vitesse);
	}
	
	// pareil pour le y 

	if (.getPositionY() < y)
	{
		.setPositionY(vitesse);
	}
	else
	{
		.setPositiony(-vitesse);
	}
}

void ExpertEnnemi1::textureChange()
{
	eEnnemi1sprite.setTexture(eEnnemi1TextureHit);
}

void ExpertEnnemi1::capaciteSpe()
{
	return;
}

Sprite& ExpertEnnemi1::getSpeSprite()
{
	return eEnnemi1sprite;
}

*/