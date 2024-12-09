#pragma once
#ifndef ENNEMI_H
#define ENNEMI_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "projectile.h"
using namespace sf;
using namespace std;


class Ennemi
{
protected:
	int x, y;
	Sprite sprite;
	bool droite = true;
	int vie;
	Texture texture;

public:

	Ennemi(int x, int y, int v); // à voir pour position

	 virtual Sprite getSprite() = 0;
	// à voir s'ils se deplacent

	 virtual void mouvement() = 0;

	virtual void tir(vector<Projectile*>& bulleta) = 0;
	
	void degats(int degats);
	bool EstMort();
};

#endif
