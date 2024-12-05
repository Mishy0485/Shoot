#pragma once
#ifndef ENNEMI_H
#define ENNEMI_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;


class Ennemi
{
private:
	int x, y;
	int type; // 1, 2 ou 3 : quel ennemi
	Sprite ennemiSprite;

	int vie;


public:
	Texture textureEnnemi;
	Ennemi(int x, int y, int t, int v); // avoir pour position

	void attaque(int degats);

	Sprite getsprite();
	// avoir s'ils se deplacent

	void tir();

	void degats();
	bool EstVivant();
};

#endif
