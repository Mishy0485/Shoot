#pragma once
#ifndef BASEENNEMI_H
#define BASEENNEMI_H

#include <SFML/Graphics.hpp>
#include "ennemi.h"
using namespace sf;

class BaseEnnemi : public Ennemi {
private:
	Texture bEnnemiTexture;
	Texture bEnnemiTextureHit;
	Sprite bEnnemisprite;
public:

	Sprite getSprite() override;

	void textureChange() override;

	void mouvement() override;

	BaseEnnemi(int x, int y, int v, int t, int s);

	void tir(vector<Projectile*>& bulleta) override;

	Sprite getSpeSprite();

	void capaciteSpe();
};

#endif