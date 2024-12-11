#include"boss3.h"
#include"jeu.h"

Boss3::Boss3(int x, int y, int v) : Ennemi(x, y, vie)
{
	boss3.loadFromFile("princeAlienTropMimi.png");
	prince.setTexture(boss3);
	prince.setPosition(x, y);
}

void Boss3::tir(vector<Projectile*>& bulleta) {

	bulleta.push_back(new Projectile(prince.getPosition().x, prince.getPosition().y, 20, 0, false));
}

void Boss3::capaciteSimple(vector<Projectile*>& bulleta, Projectile Bullet)
{
	capsmpl2.loadFromFile(".png");
	bombeRetard.setTexture(capsmpl2);
	// sprite/texture pour explosion
	// explose plus que la bombe ou juste elle ? plus avec detonation ?
	// nb de bombes ?  5 ?
	// spawn new des qu'une a explosée ? 
	// temps avant explosion ? 2sec ?
	// spawn une par une ou plusieurs en meme temps ? pleusieurs ? genre 2 ?
	// spawn partout aleatoirement sur la map? good?
}

void Boss3::capaciteSpe(Jeu jeu)
{
	capspe2.loadFromFile(".png");
	bigBombe.setTexture(capspe2);
	// spawn aleatoirement sur la map 
	// taille de la bombe? 200x200 ? 300x300 ?
}