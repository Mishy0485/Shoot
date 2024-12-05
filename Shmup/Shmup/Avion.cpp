#include "avion.h"

	Plane::Plane(int posX, int posY, int v, float vit) : x(posX), y(posY), vie(v), vitesse(vit) 
	{ 
		piupiu.loadFromFile("C:\\Users\\sbrossard\\source\\repos\\Mishy0485\\Shoot\\Shmup\\plane.PNG");
		Avion.setTexture(piupiu);
		Avion.setPosition(x, y);
	}

	Sprite Plane::getSprite() const {
		return Avion; 
	}

	int Plane::getVie() const {
		return vie;
	}

	void Plane::deplacement()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			Avion.move(Vector2f(-vitesse, 0.f));
			if (Avion.getPosition().x < 0)
			{
				Avion.setPosition(Vector2f(0.f, Avion.getPosition().y));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			Avion.move(Vector2f(vitesse, 0.f));
			if (Avion.getPosition().x > 1820) // ( si chgt de taille de fenetre changer la valeur)
			{
				Avion.setPosition(Vector2f(1820.f, Avion.getPosition().y));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			Avion.move(Vector2f(0.f, vitesse));
			if (Avion.getPosition().y > 1000)
			{
				Avion.setPosition(Vector2f(Avion.getPosition().x, 1000.f));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			Avion.move(Vector2f(0.f, -vitesse));
			if (Avion.getPosition().y < 0)
			{
				Avion.setPosition(Vector2f(Avion.getPosition().x, 0.f));
			}
		}
	}

	void Plane::degat(int degats)
	{
		vie -= degats;
	}
