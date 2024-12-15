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

	// Texture buttonPara;

	Text titre;
	Font font;

	// Text onOffM;
	// Text onOffS;

	Event event;

	RectangleShape menu;
	RectangleShape play;
	RectangleShape regle;
	RectangleShape parametre;
	RectangleShape quitter;

	Mouse mouse;

	void onOff(Text text, bool on);

	void setMenu();
	bool isClick();

	void pressButtonPlay();
	void pressButtonRegle();
	void pressButtonParametre();
	void pressButtonQuitter();
};

#endif