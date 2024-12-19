#pragma once
#ifndef MENU_H
#define MENU_H

#include"regles.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Menu
{
public:
	bool parametreb = false;

	Texture fond_menu;

	Texture button;
	Texture back_para;


	Text titre;
	Font font;

	Text butPlay;
	Text butRules;
	Text butSet;
	Text butEditor;
	Text butQuit;

	Text parametreAffichage;

	Text son;
	Text FX;

	bool music_on = true;
	bool sfx_on = true;

	Event event;

	CircleShape editor;
	RectangleShape buttonPara1;
	RectangleShape buttonPara2;
	RectangleShape menutry;
	RectangleShape play;
	RectangleShape regle;
	RectangleShape parametre;
	RectangleShape fenetrePara;
	RectangleShape quitter;
	CircleShape control1;
	CircleShape control2;
	
	Mouse mouse;

	void onOff(bool button, bool on);

	void setMenu();
	bool isClick(RenderWindow& window);

	void createButton(int x, int y);
	void affichage();

	bool pressButtonPlay(RenderWindow& window);
	bool pressButtonRegle(RenderWindow& window);
	bool pressButtonParametre(RenderWindow& window);
	bool pressButtonQuitter(RenderWindow& window);
	bool pressButtonEditor(RenderWindow& window);

	void actionMenu(bool& play, RenderWindow& window);
};

#endif