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

	Sprite selecteurDr;
	Sprite selecteurGch;

	Sprite selecteurDrnb;
	Sprite selecteurGchnb;

	Texture base;
	Texture advanced;
	Texture expert1;
	Texture expert2;
	Texture boss1;
	Texture boss2;

	Texture selecteurD;
	Texture selecteurG;

	Texture selecteurDnb;
	Texture selecteurGnb;

	RectangleShape bimBamBoom;

	Font font;
	Text nom;
	Text next;

	int selectNb;
	int nbEnnemis;
	int nbVague;
	int tab[6];

	bool isClick();
	void nbVagues(RenderWindow& window);
	void choix(RenderWindow& window);
	void Next(RenderWindow& window);
	void setEditeur();
	void select();

};

#endif