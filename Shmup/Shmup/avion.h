#pragma once
#ifndef avion_H
#define avion_H

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
	
	int getVie() const;
	Sprite getSprite() const;

	void deplacement();
	

	void degat(int degats);


};




#endif