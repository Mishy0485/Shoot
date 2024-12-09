#pragma once
#ifndef BOSS1_H
#define BOSS1_H

#include <SFML/Graphics.hpp>
#include "ennemi.h"
using namespace sf;

class Boss1 : public Ennemi {
public:
	Boss1();
	void tir(vector<Projectile*>& bulleta) override;
};

#endif