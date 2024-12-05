#pragma once
#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

#include "ennemi.h"

class Jeu 
{
public:

	vector<Ennemi*> ennemis;

	void spawnEnnemi(int n);
};

#endif