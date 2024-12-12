#include"boss3.h"
#include"jeu.h"

Boss3::Boss3(int x, int y, int v) : Ennemi(x, y, vie)
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

	CircleShape bomb(40);
	bomb.setOrigin(Vector2f(20.f, 20.f));
	bomb.setPosition(Vector2f(coordx, coordy));



	// sprite/texture pour explosion : A VOIR
	// explose plus que la bombe : sprite de l'explosion ? good
	// nb de bombes ?  5 ? good
	// spawn new des qu'une a explosée ? good
	// temps avant explosion ? 2sec ? good
	// spawn une par une ou plusieurs en meme temps ? good
	// spawn partout aleatoirement sur la map? good
}

void Boss3::capaciteSpe()
{
	capspe2.loadFromFile(".png");
	bigBombe.setTexture(capspe2);
	// spawn aleatoirement sur la map good
	// taille de la bombe? 300x300 ? good
}