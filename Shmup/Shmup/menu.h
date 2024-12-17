#pragma once
#ifndef MENU_H
#define MENU_H

#include"regles.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{
public:
	Texture fond_menu;

	Texture button1;
	Texture button2;
	Texture button3;
	Texture button4;

	Text titre;
	Font font;

	Text parametreAffichage;

	Text son;
	Text FX;

	Text onOffM;
	Text onOffS;

	Event event;

	RectangleShape Para;
	RectangleShape menu;
	RectangleShape play;
	RectangleShape regle;
	RectangleShape parametre;
	RectangleShape fenetrePara;
	RectangleShape Param;
	RectangleShape quitter;
	CircleShape control;
	
	Mouse mouse;

	void onOff(Text text, bool on);

	void setMenu();
	bool isClick();

	void createButton(int x, int y);

	bool pressButtonPlay(bool play);
	bool pressButtonRegle();
	bool pressButtonParametre();
	bool pressButtonQuitter();

	void actionMenu(bool play, bool close);
};

#endif