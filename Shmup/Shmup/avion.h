#pragma once
#ifndef avion_H
#define avion_H
#include "projectile.h"
#include <iostream>s
#include <SFML/Graphics.hpp>
using namespace sf;

class Plane
{
private:
	int x, y;

	int vie;
	int maxvie = 100;
	float vitesse;
	Sprite Avion;

public:

	int tir_n = 1;
	
	void setVitesse(float n);

	void setTir(int n);

	Texture piupiu;

	Plane(int posX, int posY, int v, float vit);
	
	void setMaxVie(int n);

	int getMaxVie();

	int getVie();
	Sprite getSprite() const;

	void deplacement();
	void tir(vector<Projectile*>& bulleta);

	void setVie(int degats);

};
#endif