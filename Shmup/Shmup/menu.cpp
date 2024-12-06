#include "menu.h"

void Menu::setMenu()
{
	RectangleShape menu(Vector2f(1920.f, 1080.f));
	menu.setTexture(&fond_menu);

	RectangleShape titre(Vector2f(1920.f, 1080.f));
	titre.setTexture(&ecrito);
	titre.setPosition(Vector2f(860.f, 540.f));

	RectangleShape play(Vector2f(200.f, 80.f));
	play.setTexture(&button1);
	play.setPosition(Vector2f(860.f, 540.f));

	RectangleShape regle(Vector2f(200.f, 80.f));
	regle.setTexture(&button2);
	regle.setPosition(Vector2f(860.f, 653.f));

	RectangleShape parametre(Vector2f(200.f, 80.f));
	parametre.setTexture(&button3);
	parametre.setPosition(Vector2f(860.f, 766.f));

	RectangleShape quitter(Vector2f(200.f, 80.f));
	quitter.setTexture(&button4);
	quitter.setPosition(Vector2f(860.f, 879.f));
}

bool Menu::isClick()
{
	if (Event::MouseButtonPressed)
		if (event.mouseButton.button == Mouse::Left)
		{
			return true;
		}
		return false;
}
