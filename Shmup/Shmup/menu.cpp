#include "menu.h"

void Menu::setMenu()
{
	menu.setSize(Vector2f(1920.f, 1080.f));
	menu.setTexture(&fond_menu);

	font.loadFromFile("Daydream.ttf");

	titre.setString(" Space Auction ");
	titre.setFont(font);
	titre.setCharacterSize(100);
	titre.setFillColor(Color(211,211,211));

	play.setSize(Vector2f(200.f, 80.f));
	play.setTexture(&button1);
	play.setPosition(Vector2f(860.f, 540.f));

	regle.setSize(Vector2f(200.f, 80.f));
	regle.setTexture(&button2);
	regle.setPosition(Vector2f(860.f, 653.f));

	parametre.setSize(Vector2f(200.f, 80.f));
	parametre.setTexture(&button3);
	parametre.setPosition(Vector2f(860.f, 766.f));

	quitter.setSize(Vector2f(200.f, 80.f));
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
		
		// RectangleShape para(Vector2f(500,800));
		// para.setFillColor(Color::Black));
		
		// createButton(x, y);
		// createButton(x, y);
		
		// music de fond on/off (booleen)                                    ?? BAISSER LE SON GENERAL ( curseur ) ??
		
		// if ( isClick && < mouse.getPosition().x < && < mouse.getPosition().x < )
		// {
		//		onoff(onOffM, false);
		// }
		// 
		// son des explosions? on/off (booleen) 
		// 
		// if (isClick && < mouse.getPosition().x < && < mouse.getPosition().x < )
		// {
		//		onoff(onOffS, false);
		// }
	}
}

void createbutton(int x, int y)
{
	// buttonPara.loadfromFill("button-on-off");
	// buttonPara.setSize(Vector2f(50,20)); 
	// Para.settexture(&buttonPara);
	// button.setPosition(Vector2f(x, y));
	
	// CircleShape curseur(12);
	// curseur.setFillColor(Color::White)
	// curseur.setPosition(Vector2f(x + 26 , y + 26))
}

void Menu::onOff(Text text, bool on)
{
	if (on)
	{
		// musique ou son
		
		// text = on
		// text.setString("ON")
		// curseur.setPosition(Vector2f(?,?)
	}
	else
	{
		// pas musique ou son
		
		// text = off 
		// text.setString("OFF")
		// curseur.setPosition(Vector2f(?,?)
	}
}

void Menu::pressButtonQuitter()
{
	if (isClick && 860 < mouse.getPosition().x < 1060 && 875 < mouse.getPosition().y < 955)
	{
		// fermer la fenetre 
		// window.close()
	}
}