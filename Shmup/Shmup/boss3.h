#pragma once
#ifndef BOSS3_H
#define BOSS3_H

#include <SFML/Graphics.hpp>
#include "ennemi.h"
using namespace sf;

class Boss3 : public Ennemi
{
protected:
	Sprite prince;

public:
	Texture boss3;

	Clock clockinette;

	int timeBomb;
	int nbBomb;

	Boss3(int x, int y, int v, int t, int s);

	void tir(vector<Projectile*>& bulleta) override;

	void capaciteSpe() override;

};

#endif