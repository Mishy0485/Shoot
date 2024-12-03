#include <SFML/Graphics.hpp>
using namespace sf;

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
	{}

	void tir()
	{

	}

	void degat(int degats)
	{
		vie -= degats;
	}
	
};