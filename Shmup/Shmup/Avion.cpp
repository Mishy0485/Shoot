#include <SFML/Graphics.hpp>
using namespace sf;
#include"projectile.cpp"
#include"texture.cpp"
#include"shmup.cpp"

class Plane
{
private:
	int x, y;
	int vie;
	int vitesse;
	Texture piupiu;
	Sprite Avion;
	
public:

	Plane(int posX, int posY, int v, Texture tex, int vit) : x(posX), y(posY), piupiu(tex), vie(v), vitesse(vit) 
	{ 
		piupiu.loadFromFile("plane.png");
		Avion.setTexture(piupiu); 
	}

	Texture getTex() const { return piupiu; }
	void deplacement()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			Avion.move(Vector2f(-200.f, 0.f) * lastFrameTime);
			if (Avion.getPosition().x < 0)
			{
				Avion.setPosition(Vector2f(0.f, Avion.getPosition().y));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			Avion.move(Vector2f(200.f, 0.f) * lastFrameTime);
			if (Avion.getPosition().x > 849) // ( si chgt de taille de fenetre changer la valeur)
			{
				Avion.setPosition(Vector2f(849.f, Avion.getPosition().y));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			Avion.move(Vector2f(0.f, 200.f) * lastFrameTime);
			if (Avion.getPosition().y > 625)
			{
				Avion.setPosition(Vector2f(Avion.getPosition().x, 625.f));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			Avion.move(Vector2f(0.f, -200.f) * lastFrameTime);
			if (Avion.getPosition().y < 350)
			{
				Avion.setPosition(Vector2f(Avion.getPosition().x, 350.f));
			}
		}
	}

	void tir()
	{
		Projectile(x,y, 200, 0); // type a changer
	}

	void degat(int degats)
	{
		vie -= degats;
	}
	
};