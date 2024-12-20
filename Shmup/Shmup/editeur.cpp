#include"editeur.h"

void Editeur::setEditeur()
{

	// Font 
	
	font.loadFromFile("Daydream.ttf");

	// fenetre
	
	fenetre.setSize(Vector2f(700, 700));
	fenetre.setPosition(Vector2f(610, 190));
	fenetre.setFillColor(Color(211,211,211));

	// load texture ennemis
	
	base.loadFromFile("ennemi1.png");
	choixEnnemi.setTexture(base);

	advanced.loadFromFile("ennemi2.png");
	expert1.loadFromFile("ennemi3_1.png");
	expert2.loadFromFile("ennemi3_2.png");
	boss1.loadFromFile("boss1.png");
	boss2.loadFromFile("boss2.png");

	// load texture bouton selecteur

	selecteurD.loadFromFile("selecteurD.png");
	selecteurDr.setTexture(selecteurD);
	selecteurDr.setPosition(Vector2f(800, 600));

	selecteurG.loadFromFile("selecteur.png");
	selecteurGch.setTexture(selecteurG);
	selecteurGch.setPosition(Vector2f(800, 600));

	selecteurDnb.loadFromFile("selecteurD.png");
	selecteurDrnb.setTexture(selecteurDnb);
	selecteurDrnb.setPosition(Vector2f());

	selecteurGnb.loadFromFile("selecteur.png");
	selecteurGchnb.setTexture(selecteurGnb);
	selecteurGchnb.setPosition(Vector2f());

	bimBamBoom.setSize(Vector2f(500, 200));
	bimBamBoom.setFillColor(Color(111,111,111));
	bimBamBoom.setPosition(Vector2f(710, 600));

	next.setString(" A La Prochaine");
	next.setFont(font);
	next.setCharacterSize(50);
	next.setFillColor(Color(150,150,150));
	next.setPosition(Vector2f(750, 620));


	// position du sprite
	choixEnnemi.setPosition(Vector2f(500, 400));
}

bool Editeur::isClick()
{
	if (Mouse::isButtonPressed(Mouse::Left)) {
		return true;
	}
	return false;
}



void Editeur::choix(RenderWindow& window)
{
	if ( isClick() && selecteurDr.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
	{
		selectNb++;
	}

	else if ( isClick() &&  selecteurGch.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
	{
		selectNb--;
	}

	select();
}



void Editeur::nbVagues(RenderWindow& window)
{
	if (isClick() && selecteurDrnb.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
	{
		nbEnnemis++;
	}

	else if (isClick() && selecteurGchnb.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
	{
		nbEnnemis--;
	}
}




void Editeur::Next(RenderWindow& window)
{
	if ( isClick() && bimBamBoom.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
	{
		tab[nbVague] = (nbEnnemis, selectNb);
	}
	nbVague++;
}




void Editeur::select()
{
	switch (selectNb)
	{
		case 0:

			choixEnnemi.setTexture(base);
			choixEnnemi.setScale(5,5);
			break;

		case 1:

			choixEnnemi.setTexture(advanced);
			choixEnnemi.setScale(1,1);
			break;

		case 2:

			choixEnnemi.setTexture(expert1);
			//choixEnnemi.setScale(1,1);
			break;

		case 3:

			choixEnnemi.setTexture(expert2);
			//choixEnnemi.setScale(1,1);
			break;

		case 4:

			choixEnnemi.setTexture(boss1);
			choixEnnemi.setScale(3,3);
			break;

		case 5:

			choixEnnemi.setTexture(boss2);
			choixEnnemi.setScale(3, 3);
			break;

		default:
			break;
	}
}
