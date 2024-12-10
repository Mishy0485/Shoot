#pragma once
#ifndef avion_H
#define avion_H
#include "projectile.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Plane
{
private:
	int x, y;
	int vie;
	float vitesse;
	Sprite Avion;

public:

	Texture piupiu;

	Plane(int posX, int posY, int v, float vit);
	
	void setVie(int n);

	int getVie();
	Sprite getSprite() const;

	void deplacement();
	void tir(vector<Projectile*>& bulleta);

	void degat(int degats);

};
#endif