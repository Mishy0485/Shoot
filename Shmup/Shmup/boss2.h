#pragma once
#ifndef BOSS2_H
#define BOSS2_H

#include <SFML/Graphics.hpp>
#include "ennemi.h"
using namespace sf;

class Boss2 : public Ennemi
{
protected:
	Sprite general;
	Sprite laser_gen;

public:
	Texture boss2;
	Texture capsmpl1;
	Texture capspe1;

	Boss2(int x, int y, int v, int t, int s);
	 
	void tir(vector<Projectile*>& bulleta);

	void capaciteSpe();

	void deplacementLaser(Projectile Bullet);

	Sprite getSprite();

	void textureChange();

	void mouvement();
};
#endif