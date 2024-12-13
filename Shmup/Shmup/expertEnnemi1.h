#pragma once
#ifndef EXPERTENNEMI1_H
#define EXPERTENNEMI1_H

#include <SFML/Graphics.hpp>
#include "ennemi.h"
#include "vecteurEnnemi.h"
using namespace sf;

class ExpertEnnemi1 : public Ennemi {
private:
	Texture eEnnemi1Texture;
	Texture eEnnemi1TextureHit;
	Sprite eEnnemi1sprite;
public:

	Sprite getSprite() override;

	void textureChange() override;

	void mouvement() override;

	ExpertEnnemi1(int x, int y, int v, int t, int s);

	void tir(vector<Projectile*>& bulleta) override;

	Sprite& getSpeSprite();

	void capaciteSpe();
};

#endif