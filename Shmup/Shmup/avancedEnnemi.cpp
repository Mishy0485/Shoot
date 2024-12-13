#include "AvancedEnnemi.h"

AvancedEnnemi::AvancedEnnemi(int x, int y, int v, int t, int s) : Ennemi(x, y , v, 0, s) 
{
	aEnnemiTexture.loadFromFile("ennemi2.PNG");
	aEnnemiTextureHit.loadFromFile("ennemi2_hit.png");
	aEnnemisprite.setTexture(aEnnemiTexture);
	aEnnemisprite.setScale(5, 5);
	aEnnemisprite.setPosition(x, y);
}

Sprite AvancedEnnemi::getSprite() {
	return aEnnemisprite;
}

void AvancedEnnemi::mouvement() 
{
	/*bool direction;
	
	if (direction)
	{
		aEnnemisprite.move(Vector2f(5, 0));
	}
	else
	{
		aEnnemisprite.move(Vector2f(-5, 0));
	}*/

	/*x = aEnnemisprite.getPosition().x;
	if (droite) {
		if (x >= 1700) {
			droite = false;
		}
		else {
			aEnnemisprite.move(Vector2f(5, 0));
		}
	}
	else if (droite == false) {
		if (x <= 50) {
			droite = true;
		}
		else {
			aEnnemisprite.move(Vector2f(-5, 0));
		}
	}*/
}

void AvancedEnnemi::tir(vector<Projectile*>& bulleta) 
{
	{
		bulleta.push_back(new Projectile(aEnnemisprite.getPosition().x + 150, aEnnemisprite.getPosition().y + 100, 10, 0, false));
		bulleta.push_back(new Projectile(aEnnemisprite.getPosition().x + 50, aEnnemisprite.getPosition().y + 100, 10, 0, false));
	}
}

void AvancedEnnemi::textureChange() 
{
	aEnnemisprite.setTexture(aEnnemiTextureHit);
}

void AvancedEnnemi::capaciteSpe() 
{
	return;
}

Sprite& AvancedEnnemi::getSpeSprite() 
{
	return aEnnemisprite;
}