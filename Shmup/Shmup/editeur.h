#pragma once
#ifndef EDITEUR_H
#define EDITEUR_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Editeur
{
public:

	RectangleShape fenetre;

	Sprite choixEnnemi;

	Texture base;
	Texture advanced;
	Texture expert1;
	Texture expert2;
	Texture boss1;
	Texture boss2;

	Texture selecteurD;
	Texture selecteurG;

	Text nom;

	int selectNb;

	void isClick();
	void setEditeur();
	void select();

};

#endif