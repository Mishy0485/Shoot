#include"boss3.h"
#include"jeu.h"

Boss3::Boss3(int x, int y, int v, int t, int s) : Ennemi(x, y, v, 5, s)
{
	boss3.loadFromFile("princeAlienTropMimi.png");
	prince.setTexture(boss3);
	prince.setPosition(x, y);
}

void Boss3::tir(vector<Projectile*>& bulleta) {

	capsmpl2.loadFromFile(".png");
	bombeRetard.setTexture(capsmpl2);

	int coordx = rand() % 1900;
	int coordy = rand() % (1010 - 600 + 1);

	timeBomb = clockinette.getElapsedTime().asSeconds();
	
	while (nbBomb <= 5)
	{
		// appeler le constructeur
		nbBomb++;

		if (timeBomb >= 2)
		{
			boom.loadFromFile("tryExposion.png");
			explosion.setTexture(boom);
			explosion.setOrigin(Vector2f(bomb.getOrigin().x, bomb.getOrigin().y));
			explosion.setPosition(Vector2f(bomb.getPosition().x, bomb.getPosition().y));
			
			if ( explosion.getGlobalBounds().intersects(bomb.getGlobalBounds()) )
			{
				
			}

			// bomb.delete();
			// explosion.delete()

			clockinette.restart();
		}
	}

	// nb de bombes ?  5 ? good
	// spawn new des qu'une a explosée ? good
	// spawn une par une ou plusieurs en meme temps ? good
}

void Boss3::capaciteSpe()
{
	capspe2.loadFromFile(".png");
	bigBombe.setTexture(capspe2);
	Jeu::setBool(true);
	// spawn aleatoirement sur la map good
	// taille de la bombe? 300x300 ? good
}