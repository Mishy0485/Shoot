#pragma once
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Menu
{
public:
	Texture fond_menu;
	Texture ecrito;

	Texture button1;
	Texture button2;
	Texture button3;
	Texture button4;

	Event event;

	void setMenu();
	bool isClick();
};

#endif