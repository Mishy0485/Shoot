#include <SFML/Graphics.hpp>
using namespace sf;
#include"projectile.cpp"
#include"texture.cpp"

class Plane
{
private:
	int x, y;
	int vie;
	Texture texture;
	int vitesse;

public:

	Plane(int posX, int posY, int v, Texture tex, int vit) : x(posX), y(posY), vie(v), texture(tex), vitesse(vit) {}

	void deplacement()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			rec.move(Vector2f(-200.f, 0.f) * lastFrameTime);
			if (rec.getPosition().x < 0)
			{
				rec.setPosition(Vector2f(0.f, rec.getPosition().y));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			rec.move(Vector2f(200.f, 0.f) * lastFrameTime);
			if (rec.getPosition().x > 849) // ( si chgt de taille de fenetre changer la valeur)
			{
				rec.setPosition(Vector2f(849.f, rec.getPosition().y));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			rec.move(Vector2f(0.f, 200.f) * lastFrameTime);
			if (rec.getPosition().y > 625)
			{
				rec.setPosition(Vector2f(rec.getPosition().x, 625.f));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			rec.move(Vector2f(0.f, -200.f) * lastFrameTime);
			if (rec.getPosition().y < 350)
			{
				rec.setPosition(Vector2f(rec.getPosition().x, 350.f));
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