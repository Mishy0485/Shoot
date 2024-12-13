#include "avion.h"


	Plane::Plane(int posX, int posY, int v, float vit) : x(posX), y(posY), maxvie(v), vitesse(vit) 
	{ 
		piupiu.loadFromFile("plane.PNG");
		Avion.setTexture(piupiu);
		Avion.setPosition(x, y);
	}

	Sprite Plane::getSprite() const {
		return Avion; 
	}

	int Plane::getVie(){
		return vie;
	}

	int Plane::getMaxVie() {
		return maxvie;
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

	void Plane::setMaxVie(int n) {
		maxvie += n;
	}

	void Plane::setVie(int valeur)
	{
		vie += valeur;
	}

	void Plane::tir(vector<Projectile*>& bulleta)
	{
		bulleta.push_back(new Projectile(Avion.getPosition().x + 54, Avion.getPosition().y, 20, 0, true));
	}
