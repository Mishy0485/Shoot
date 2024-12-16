#include "menu.h"

void Menu::setMenu()
{
	menu.setTexture(&fond_menu);
	menu.setSize(Vector2f(1920.f, 1080.f));

	font.loadFromFile("Daydream.ttf");

	titre.setString(" Space Auction ");
	titre.setFont(font);
	titre.setCharacterSize(100);
	titre.setFillColor(Color(211,211,211));

	play.setTexture(&button1);
	play.setSize(Vector2f(200.f, 80.f));
	play.setPosition(Vector2f(860.f, 540.f));

	regle.setTexture(&button2);
	regle.setSize(Vector2f(200.f, 80.f));
	regle.setPosition(Vector2f(860.f, 653.f));

	parametre.setTexture(&button3);
	parametre.setSize(Vector2f(200.f, 80.f));
	parametre.setPosition(Vector2f(860.f, 766.f));

	quitter.setTexture(&button4);
	quitter.setSize(Vector2f(200.f, 80.f));
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

void Menu::pressButtonPlay()
{
	if (isClick && 860 < mouse.getPosition().x < 1060 && 540 < mouse.getPosition().y < 620 )
	{
		// debut du jeu
		// bool jouer ou draw ?
	}
}

void Menu::pressButtonRegle()
{
	if (isClick && 860 < mouse.getPosition().x < 1060 && 653 < mouse.getPosition().y < 733)
	{
		// apparition des regles ( ajout d'un fichier )
		reglesDejeu();
	}
}

void Menu::pressButtonParametre()
{
	if (isClick && 860 < mouse.getPosition().x < 1060 && 766 < mouse.getPosition().y < 846)
	{
		// afficher les parametres 
		
		fenetrePara.setSize(Vector2f(500,800));
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
		
		if ( isClick && 780 < mouse.getPosition().x < 830 && 440 < mouse.getPosition().x < 460)
		{
			onOff(onOffM, false);
			// musique plus : ajout musique
		}
		 
		// son des explosions? on/off (booleen) 
		
		if (isClick && 780 < mouse.getPosition().x < 830 && 540 < mouse.getPosition().x < 560)
		{
			onOff(onOffS, false);
			// son plus : ajout effets
		}
	}
}

void Menu::createButton(int x, int y)
{
	Para.setSize(Vector2f(50,20));
	Para.setPosition(Vector2f(x, y));
	
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
		text.setPosition(Vector2f(850, Para.getSize().y - 20));
		control.setPosition(Vector2f(Para.getSize().x + 26, Para.getSize().y + 26));
	}
	else
	{
		// pas musique ou son
		
		text.setString("OFF");
		text.setPosition(Vector2f(850, Para.getSize().y - 20));
		control.setPosition(Vector2f(Para.getSize().x, Para.getSize().y));
	}
}

void Menu::pressButtonQuitter(RenderWindow window)
{
	if (isClick && 860 < mouse.getPosition().x < 1060 && 875 < mouse.getPosition().y < 955)
	{
		// fermer la fenetre
		
		window.close();
	}
}