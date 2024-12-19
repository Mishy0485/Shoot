#include"editeur.h"

void Editeur::setEditeur()
{
	// fenetre
	
	fenetre.setSize(Vector2f(700, 700));
	fenetre.setPosition(Vector2f(610, 190));
	fenetre.setFillColor(Color::Yellow);

	// load texture 
	
	base.loadFromFile("ennemi1.png");
	advanced.loadFromFile("ennemi2.png");
	expert1.loadFromFile("ennemi3_1.png");
	expert2.loadFromFile("ennemi3_2.png");
	boss1.loadFromFile("boss1.png");
	boss2.loadFromFile("boss2.png");

	selecteurD.loadFromFile("selecteurD.png");
	selecteurG.loadFromFile("selecteur.png");

	// position du sprite
	choixEnnemi.setPosition(Vector2f(500, 400));
}

void Editeur::isClick()
{


}


void Editeur::select()
{
	switch (selectNb)
	{
		case 0:

			choixEnnemi.setTexture(base);
			//choixEnnemi.setScale(1,1);
			break;

		case 1:

			choixEnnemi.setTexture(advanced);
			choixEnnemi.setScale(-1,-1);
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
			choixEnnemi.setScale(-11,-11);
			break;

		case 5:

			choixEnnemi.setTexture(boss2);
			choixEnnemi.setScale(-11, -11);
			break;

		default:
			break;
	}
}