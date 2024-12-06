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
private:
	int x, y;
	int type; // 1, 2 ou 3 : quel ennemi
	Sprite ennemiSprite;
	bool droite = true;
	int vie;


public:
	Texture textureEnnemi;
	Ennemi(int x, int y, int t, int v); // avoir pour position

	void attaque(int degats);


	Sprite getsprite();
	// avoir s'ils se deplacent

	void mouvement();

	void tir(vector<Projectile*>& bulleta);
	
	void degats(int degats);
	bool EstMort();
};

#endif
