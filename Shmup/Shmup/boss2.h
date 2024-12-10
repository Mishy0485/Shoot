#pragma once
#ifndef BOSS1_H
#define BOSS1_H

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

	Boss2(int x, int y, int v);

	void tir(vector<Projectile*>& bulleta) override;

	void capaciteSimple(vector<Projectile*>& bulleta, Projectile bullet) override;

	void capaciteSpe() override;
};
#endif