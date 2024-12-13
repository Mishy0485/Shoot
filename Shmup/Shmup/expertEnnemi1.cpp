#include"expertEnnemi1.h"

ExpertEnnemi1::ExpertEnnemi1(int x, int y, int v, int t, int s) : Ennemi(x, y, v, 0, s)
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

void ExpertEnnemi1::tir(vector<Projectile*>& bulleta)
{
	{
		bulleta.push_back(new Projectile(eEnnemi1sprite.getPosition().x + 150, eEnnemi1sprite.getPosition().y + 100, 10, 0, false));
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