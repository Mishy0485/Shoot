#include"bombe.h"
#include"jeu.h"

int coordx = rand() % 1900;
int coordy = rand() % (1010 - 600 + 1);

Bombe::Bombe(int x, int y, int t, int v) : x(x), y(y), taille(t), vie(v) // taille : 40 ( petite ) ; taille : 300 ( grosse )
{
	CircleShape bombeRetard(taille);
	bombeRetard.setOrigin(Vector2f(taille, taille));       // a revoir
	bombeRetard.setPosition(Vector2f(coordx, coordy));
}

void Bombe::setBombe(vector<Bombe*>& bombeRetard, bool small)
{
	if (small)
	{
		bombeRetard.push_back(new Bombe(x, y, 40, 0));
	}
	else
	{
		bombeRetard.push_back(new Bombe(x, y, 300, 0));
	}
}

void Bombe::setExplosion(CircleShape bombeRetard)
{
	boom.loadFromFile("princeAlienTropMimi.png");
	explosion.setTexture(boom);
	explosion.setOrigin(Vector2f(bombeRetard.getOrigin().x, bombeRetard.getOrigin().y));
	explosion.setPosition(Vector2f(bombeRetard.getPosition().x, bombeRetard.getPosition().y));
}

void Bombe::spawnBombeRetard()
{
	timeBomb = clockinette.getElapsedTime().asSeconds();

	while (nbBomb < 5)
	{
		if (timeBomb >= 2)
		{ 
			setBombe(bombeRetard, true); 
		}
		nbBomb++;
		clockinette.restart();
	}
}

void Bombe::sapwnBigBombe()
{
	timeBomb = clockinette.getElapsedTime().asSeconds();

	if (timeBomb >= 15) 
	{
		setBombe(bombeRetard, false);
	}
	clockinette.restart();
}

bool Bombe::collisionRetard(Plane joueur)
{
	if (explosion.getGlobalBounds().intersects(joueur.getSprite().getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Bombe::collisionOver(Plane joueur)
{
	if (explosion.getGlobalBounds().intersects(joueur.getSprite().getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false; 
	}
}