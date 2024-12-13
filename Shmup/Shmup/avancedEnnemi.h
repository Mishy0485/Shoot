#pragma once
#ifndef AVANCEDENNEMI_H
#define AVANCEDENNEMI_H

#include <SFML/Graphics.hpp>
#include "ennemi.h"
using namespace sf;

class AvancedEnnemi : public Ennemi {
private:
	Texture aEnnemiTexture;
	Texture aEnnemiTextureHit;
	Sprite aEnnemisprite;
public:

	Sprite getSprite() override;

	void textureChange() override;

	void mouvement() override;

	AvancedEnnemi(int x, int y, int v, int t, int s);

	void tir(vector<Projectile*>& bulleta) override;

	Sprite& getSpeSprite();

	void capaciteSpe();
};

#endif
