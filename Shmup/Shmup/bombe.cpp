//#include"bombe.h"
//
//int coordx = rand() % 1900;
//int coordy = rand() % (1010 - 600 + 1);
//
//Bombe::Bombe(int x, int y, int t, int v) : x(x), y(y), taille(t), vie(v) // taille : 40 ( petite ) ; taille : 300 ( grosse )
//{
//	CircleShape bombeRetard(taille);
//	bombeRetard.setOrigin(Vector2f(taille, taille));       // a revoir
//	bombeRetard.setPosition(Vector2f(coordx, coordy));
//}
//
//void Bombe::setBombe(vector<Bombe*>& bombeRetard)
//{
//	bombeRetard.push_back(new Bombe(x, y, 40, 0));
//}
//
//void Bombe::setExplosion(CircleShape bombeRetard)
//{
//	timeBomb = clockinette.getElapsedTime().asSeconds();
//
//	if (timeBomb >= 2)
//	{
//		boom.loadFromFile("princeAlienTropMimi.png");
//		explosion.setTexture(boom);
//		explosion.setOrigin(Vector2f(bombeRetard.getOrigin().x, bombeRetard.getOrigin().y));
//		explosion.setPosition(Vector2f(bombeRetard.getPosition().x, bombeRetard.getPosition().y));
//	}
//	clockinette.restart();
//}
//
//void Bombe::collisionRetard(Plane joueur)
//{
//	if (explosion.getGlobalBounds().intersects(joueur.getSprite().getGlobalBounds()))
//	{
//		joueur.setVie(-50);
//		delete(); // l'esplosion
//		delete(); // la bombe
//	}
//}
//
//bool Bombe::collisionOver(Plane joueur)
//{
//	if (explosion.getGlobalBounds().intersects(joueur.getSprite().getGlobalBounds()))
//	{
//		// arreter de draw + game over
//	}
//}