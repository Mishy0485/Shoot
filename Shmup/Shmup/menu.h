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

	Text butPlay;
	Text butRules;
	Text butSet;
	Text butQuit;

	Text parametreAffichage;

	Text son;
	Text FX;

	Text onOffM;
	Text onOffS;

	Event event;

	RectangleShape buttonPara;
	RectangleShape menutry;
	RectangleShape play;
	RectangleShape regle;
	RectangleShape parametre;
	RectangleShape fenetrePara;
	RectangleShape quitter;
	CircleShape control;
	
	Mouse mouse;

	void onOff(Text text, bool on);

	void setMenu();
	bool isClick(RenderWindow& window);

	void createButton(int x, int y);
	void affichage(RenderWindow& window);

	bool pressButtonPlay(RenderWindow& window);
	bool pressButtonRegle(RenderWindow& window);
	bool pressButtonParametre(RenderWindow& window);
	bool pressButtonQuitter(RenderWindow& window);

	void actionMenu(bool& play, bool& close, RenderWindow& window);
};

#endif