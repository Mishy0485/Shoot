#include <SFML/Graphics.hpp>
using namespace sf;

class Plane
{
private:
	int x, y;
	int vie;
	float vitesse;
	Sprite Avion;
	
public:

	Texture piupiu;

	Plane(int posX, int posY, int v, float vit) : x(posX), y(posY), vie(v), vitesse(vit) 
	{ 
		piupiu.loadFromFile("plane.png");
		Avion.setTexture(piupiu);
	}

	Sprite getTex() const { return Avion; }

	void deplacement()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			Avion.move(Vector2f(vitesse, 0.f));
			if (Avion.getPosition().x < 0)
			{
				Avion.setPosition(Vector2f(0.f, Avion.getPosition().y));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			Avion.move(Vector2f(vitesse, 0.f));
			if (Avion.getPosition().x > 1000) // ( si chgt de taille de fenetre changer la valeur)
			{
				Avion.setPosition(Vector2f(1000.f, Avion.getPosition().y));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			Avion.move(Vector2f(0.f, vitesse));
			if (Avion.getPosition().y > 1079)
			{
				Avion.setPosition(Vector2f(Avion.getPosition().x, 1079.f));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			Avion.move(Vector2f(0.f, vitesse));
			if (Avion.getPosition().y < 0)
			{
				Avion.setPosition(Vector2f(Avion.getPosition().x, 0.f));
			}
		}
	}

	//void tir()
	//{
	//	Projectile(x,y, 200, 0); // type a changer
	//}

	void degat(int degats)
	{
		vie -= degats;
	}
	
};