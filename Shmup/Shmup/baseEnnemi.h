#pragma once
#ifndef BASEENNEMI_H
#define BASEENNEMI_H

#include <SFML/Graphics.hpp>
#include "ennemi.h"
using namespace sf;

class BaseEnnemi : public Ennemi {
private:
	Texture bEnnemitexture;
	Sprite bEnnemisprite;
public:

	Sprite getSprite() override;

	void mouvement() override;

	BaseEnnemi(int x, int y, int v);

	void tir(vector<Projectile*>& bulleta) override;
};

#endif