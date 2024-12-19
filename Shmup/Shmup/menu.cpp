#include "menu.h"

void Menu::setMenu()
{
		if (!fond_menu.loadFromFile("back.png")) {}

		menutry.setFillColor(Color::Red);
		menutry.setTexture(&fond_menu);
		menutry.setSize(Vector2f(1920.f, 1080.f));

		font.loadFromFile("Daydream.ttf");

		titre.setString(" Space Auction ");
		titre.setFont(font);
		titre.setCharacterSize(100);
		titre.setFillColor(Color(211, 211, 211));
		titre.setPosition(Vector2f(290, 150));


		// Initialisation des titres de boutons
		
		butPlay.setString("Play");
		butPlay.setFont(font);
		butPlay.setFillColor(Color::Black);
		butPlay.setCharacterSize(50);
		butPlay.setPosition(Vector2f(850, 450));

		butRules.setString("Regles");
		butRules.setFont(font);
		butRules.setFillColor(Color::Black);
		butRules.setCharacterSize(50);
		butRules.setPosition(Vector2f(800, 600));

		butSet.setString("Parametres");
		butSet.setFont(font);
		butSet.setFillColor(Color::Black);
		butSet.setCharacterSize(50);
		butSet.setPosition(Vector2f(680, 750));

		butQuit.setString("Quitter");
		butQuit.setFont(font);
		butQuit.setFillColor(Color::Black);
		butQuit.setCharacterSize(50);
		butQuit.setPosition(Vector2f(770, 900));


		// Initialisation des boutons

		play.setTexture(&button1);
		play.setFillColor(Color(211, 211, 211));
		play.setSize(Vector2f(600.f, 100.f));
		play.setPosition(Vector2f(660.f, 440.f));

		regle.setTexture(&button2);
		regle.setFillColor(Color(211, 211, 211));
		regle.setSize(Vector2f(600.f, 100.f));
		regle.setPosition(Vector2f(660.f, 590.f));

		parametre.setTexture(&button3);
		parametre.setFillColor(Color(211, 211, 211));
		parametre.setSize(Vector2f(600.f, 100.f));
		parametre.setPosition(Vector2f(660.f, 740.f));

		quitter.setTexture(&button4);
		quitter.setFillColor(Color(211, 211, 211));
		quitter.setSize(Vector2f(600.f, 100.f));
		quitter.setPosition(Vector2f(660.f, 890.f));
}




bool Menu::isClick(RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			return true;
		}
	}
	return false;
}




bool Menu::pressButtonPlay(RenderWindow& window)
{
	if (isClick(window)) {
		if (play.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y)) {
			return true;
		}
	}
	return false;
}



bool Menu::pressButtonRegle(RenderWindow& window)
{
	if (isClick(window)) {
		if (regle.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y)) {
			return true;
		}
	}
	return false;
}


bool Menu::pressButtonParametre(RenderWindow& window)
{
	if (isClick(window)) {
		if (parametre.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y)) {
			return true;
		}
	}
	return false;
}


bool Menu::pressButtonQuitter(RenderWindow& window)
{
	if (isClick(window)) {
		if (quitter.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y)) {
			return true;
		}
	}
	return false;
}


void Menu::createButton(int x, int y)
{
	buttonPara.setSize(Vector2f(50,20));
	buttonPara.setPosition(Vector2f(x, y));
	
	control.setRadius(12);
	control.setFillColor(Color::White);
	control.setPosition(Vector2f(x + 26, y + 26));
}




void Menu::onOff(Text text, bool on)
{
	if (on)
	{
		// musique ou son

		text.setString("ON");
		text.setPosition(Vector2f(850, buttonPara.getSize().y - 20));
		control.setPosition(Vector2f(buttonPara.getSize().x + 26, buttonPara.getSize().y + 26));
	}
	else
	{
		// pas musique ou son

		text.setString("OFF");
		text.setPosition(Vector2f(850, buttonPara.getSize().y - 20));
		control.setPosition(Vector2f(buttonPara.getSize().x, buttonPara.getSize().y));
	}
}


void Menu::affichage(RenderWindow& window)
{
	// afficher les parametres 

	fenetrePara.setSize(Vector2f(500, 800));
	fenetrePara.setFillColor(Color::Black);
	fenetrePara.setPosition(710, 140);

	parametreAffichage.setString(" Parametre ");
	parametreAffichage.setPosition(Vector2f(876, 190));

	son.setString(" SON ");
	son.setPosition(Vector2f(720, 435));

	FX.setString(" FX ");
	FX.setPosition(Vector2f(720, 535));

	createButton(780, 440);
	createButton(780, 540);

	// music de fond on/off (booleen)

	if (isClick(window) && 780 < mouse.getPosition().x < 830 && 440 < mouse.getPosition().x < 460)
	{
		onOff(onOffM, false);
		// musique plus : ajout musique
	}

	// son des explosions? on/off (booleen) 

	if (isClick(window) && 780 < mouse.getPosition().x < 830 && 540 < mouse.getPosition().x < 560)
	{
		onOff(onOffS, false);
		// son plus : ajout effets
	}
}



void Menu::actionMenu(bool& play, bool& close, RenderWindow& window)
{
	if (pressButtonPlay(window))
	{
		// debut du jeu
		play = true;
	}

	if (pressButtonRegle(window))
	{
		// apparition des regles ( ajout d'un fichier )
		reglesDejeu();
	}

	if (pressButtonParametre(window))
	{
		affichage(window);
	}

	if (pressButtonQuitter(window))
	{
		// fermer la fenetre
		close = true;
	}
}