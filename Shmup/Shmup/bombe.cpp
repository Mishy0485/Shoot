#include"bombe.h"

int coordx = rand() % 1900;
int coordy = rand() % (1010 - 600 + 1);

Bombe::Bombe(int x, int y, int t, int v) : x(x), y(y), taille(t), vie(v)
{
	CircleShape bomb(40);
	bomb.setOrigin(Vector2f(40.f, 40.f));
	bomb.setPosition(Vector2f(coordx, coordy));
}

void Bombe::collisionRetard(Plane joueur)
{}

bool Bombe::collisionOver()
{}