#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;


class Ennemi
{
private:
	int x, y;
	int type; // 1, 2 ou 3 : quel ennemi
	Texture texture;
	int vie;
	
public:

	Ennemi(int t, Texture tex, int v) : type(t), texture(tex), vie(v) {} // avoir pour position

	void attaque(int degats)
	{

	}

	// avoir s'ils se deplacent

	void tir()
	{}

	void degats()
	{
		int degats;
		vie -= degats;
	}

	bool EstVivant()
	{
		return vie<=0;
	}
};
