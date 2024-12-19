#pragma once
#ifndef JUKEBOX_H
#define JUKEBOX_H
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;

class Jukebox {
public:

	SoundBuffer music_b;
	Sound music;

	void music_m();

	Jukebox();



};

#endif
