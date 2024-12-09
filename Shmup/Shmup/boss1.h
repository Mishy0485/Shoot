#pragma once
#ifndef BOSS1_H
#define BOSS1_H

#include <SFML/Graphics.hpp>
#include "ennemi.h"
using namespace sf;

class Boss1 : public Ennemi 
{
protected:
	Sprite colonel;
	Sprite laser;

public:
	Texture boss1;
	Texture capsmpl;
	Texture capspe;

	Boss1(int x, int y, int v);

	void tir(vector<Projectile*>& bulleta) override;

	void capaciteSimple();
	void capaciteSpe();
};

#endif