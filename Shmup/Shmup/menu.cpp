#include "menu.h"



void Menu::setMenu()
{
	if (!button.loadFromFile("button.png")) { return; }
	if (!fond_menu.loadFromFile("back.png")) { return; }
	if (!back_para.loadFromFile("backpara.png")) { return; }

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

		butEditor.setString("Editor");
		butEditor.setFont(font);
		butEditor.setFillColor(Color::Black);
		butEditor.setCharacterSize(50);
		butEditor.setPosition(Vector2f(800, 600));

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

		play.setFillColor(Color(211, 211, 211));
		play.setSize(Vector2f(600.f, 100.f));
		play.setPosition(Vector2f(660.f, 440.f));

		editor.setFillColor(Color(211, 211, 211));
		editor.setSize(Vector2f(600.f, 100.f));
		editor.setPosition(Vector2f(660.f, 590.f));

		parametre.setFillColor(Color(211, 211, 211));
		parametre.setSize(Vector2f(600.f, 100.f));
		parametre.setPosition(Vector2f(660.f, 740.f));

		quitter.setFillColor(Color(211, 211, 211));
		quitter.setSize(Vector2f(600.f, 100.f));
		quitter.setPosition(Vector2f(660.f, 890.f));

}




bool Menu::isClick(RenderWindow& window)
{
		if (Mouse::isButtonPressed(Mouse::Left)) {
			return true;
		}
	return false;
}




bool Menu::pressButtonPlay(RenderWindow& window)
{
	if (isClick(window)) {
		if (play.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y + 40)) {
			return true;
		}
	}
	return false;
}



bool Menu::pressButtonEditer(RenderWindow& window)
{
	if (isClick(window)) {
		if (editor.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y +40)) {
			cout << "close" << endl;
			return true;
		}
	}
	return false;
}


bool Menu::pressButtonParametre(RenderWindow& window)
{
	if (isClick(window)) {
		if (parametre.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y +40)) {
			return true;
		}
	}
	return false;
}


bool Menu::pressButtonQuitter(RenderWindow& window)
{
	if (isClick(window)) {
		if (quitter.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y +40)) {
			cout << "close" << endl;
			return true;
		}
	}

	return false;
}


void Menu::createButton(int x, int y)
{
	buttonPara1.setSize(Vector2f(50,15));
	buttonPara1.setPosition(Vector2f(x, y));
	buttonPara1.setFillColor(Color::Green);
	buttonPara2.setSize(Vector2f(50, 15));
	buttonPara2.setPosition(Vector2f(x, y + 100));
	buttonPara2.setFillColor(Color::Green);
	
	Color color(107, 107, 107, 255);

	control1.setRadius(14);
	control1.setFillColor(color);
	control1.setPosition(Vector2f(x + 26, y - 5));
	if (!music_on) control1.setPosition(Vector2f(x, y - 5));
	control2.setRadius(14);
	control2.setFillColor(color);
	control2.setPosition(Vector2f(x + 26, y + 97));
	if (!sfx_on) control2.setPosition(Vector2f(x, y + 97));
}




void Menu::onOff(bool button, bool on)
{
	if (button) {
		if (on)
		{
			// musique ou son

			music_on = true;
			control1.move(30, 0);
			buttonPara1.setFillColor(Color::Green);
		}
		else
		{
			music_on = false;
			control1.move(-30, 0);
			buttonPara1.setFillColor(Color::Red);
		}
	}
	else {
		if (on)
		{
			// musique ou son

			sfx_on = true;
			control2.move(30, 0);
			buttonPara2.setFillColor(Color::Green);
		}
		else
		{
			// pas musique ou son

			sfx_on = false;
			control2.move(-30, 0);
			buttonPara2.setFillColor(Color::Red);
		}
	}
}


void Menu::affichage()
{
	parametreb = true;
	fenetrePara.setSize(Vector2f(500, 650));
	fenetrePara.setTexture(&back_para);
	fenetrePara.setPosition(710, 140);

	parametreAffichage.setString(" Parametres ");
	parametreAffichage.setFont(font);
	parametreAffichage.setPosition(Vector2f(730, 190));
	parametreAffichage.setFillColor(Color::White);
	parametreAffichage.setCharacterSize(40);

	son.setString(" MUSIQUE ");
	son.setFont(font);
	son.setPosition(Vector2f(720, 435));

	FX.setString(" FX ");
	FX.setFont(font);
	FX.setPosition(Vector2f(720, 535));

	createButton(780, 500);

	// music de fond on/off (booleen)

	// son des explosions? on/off (booleen) 


}



void Menu::actionMenu(bool& play, RenderWindow& window, Editeur editeur)
{
	if (pressButtonPlay(window) && !parametreb && !editeur.editeurb)
	{
		// debut du jeu
		play = true;
	}

	if (pressButtonParametre(window) && !parametreb && !editeur.editeurb)
	{
		affichage();
	}

	if (parametreb){
		if (isClick(window) && control1.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y +40))
		{
			if (music_on) {
				onOff(true, false);

			}
			else {
				onOff(true, true);
			}
			cout << "clique" << endl;
		}

		if (isClick(window) && control2.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y + 40))
		{
			if (sfx_on){
			onOff(false, false);}
			else {
				onOff(false, true);
			}
			cout << "clac" << endl;
		}
		if (isClick(window) && !fenetrePara.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y + 40)) {
			parametreb = false;
		}
	}

	if (pressButtonEditer(window) && !parametreb && editeur.editeurb)
	{
		editeur.levelEdit(window);
	}

	if (pressButtonQuitter(window) && !parametreb && !editeur.editeurb)
	{
		window.close();
	}
}