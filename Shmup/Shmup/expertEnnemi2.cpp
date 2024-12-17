#include"expertEnnemi2.h"

ExpertEnnemi2::ExpertEnnemi2(int x, int y, int v, int t, int s) : Ennemi(x, y, v, 0, s)
{
	eEnnemi2Texture.loadFromFile("ennemi2.PNG");
	eEnnemi2TextureHit.loadFromFile("ennemi2_hit.png");
	eEnnemi2sprite.setTexture(eEnnemi2Texture);
	eEnnemi2sprite.setScale(5, 5);
	eEnnemi2sprite.setPosition(x, y);
}

Sprite ExpertEnnemi2::getSprite() {
	return eEnnemi2sprite;
}

void ExpertEnnemi2::tir(vector<Projectile*> bulleta)
{
	{
		bulleta.push_back(new Projectile(eEnnemi2sprite.getPosition().x + 150, eEnnemi2sprite.getPosition().y + 100, 10, 0, false));
	}
}
void ExpertEnnemi2::textureChange()
{
	eEnnemi2sprite.setTexture(eEnnemi2TextureHit);
}

void ExpertEnnemi2::capaciteSpe()
{
	return;
}

Sprite& ExpertEnnemi2::getSpeSprite()
{
	return eEnnemi2sprite;
}