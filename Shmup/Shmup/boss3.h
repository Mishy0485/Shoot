#pragma once
#ifndef BOSS2_H
#define BOSS2_H

#include <SFML/Graphics.hpp>
#include "ennemi.h"
using namespace sf;

class Boss3 : public Ennemi
{
protected:
	Sprite prince;
	Sprite bombeRetard;
	Sprite bigBombe;

public:
	Texture boss3;
	Texture capsmpl2;
	Texture capspe2;

	Boss3(int x, int y, int v);

	void tir(vector<Projectile*>& bulleta) override;

	void capaciteSimple(vector<Projectile*>& bulleta, Projectile bullet) override;

	void capaciteSpe(Jeu jeu) override;

};

#endif