#pragma once
#ifndef EXPERTENNEMI2_H
#define EXPERTENNEMI2_H

#include <SFML/Graphics.hpp>
#include "ennemi.h"
using namespace sf;

class ExpertEnnemi2 : public Ennemi {
private:
	Texture eEnnemi2Texture;
	Texture eEnnemi2TextureHit;
	Sprite eEnnemi2sprite;
public:

	Sprite getSprite() override;

	void textureChange() override;

	void mouvement() override;

	ExpertEnnemi2(int x, int y, int v, int t, int s);

	void tir(vector<Projectile*>& bulleta) override;

	Sprite& getSpeSprite();

	void capaciteSpe();
};

#endif