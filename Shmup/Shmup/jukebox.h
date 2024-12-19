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

	SoundBuffer spawn_b;
	Sound spawns;

	SoundBuffer explosion_b;
	Sound explosion;

	SoundBuffer start_b;
	Sound starts;

	SoundBuffer death_b;
	Sound deaths;

	void music_m();
	void spawn_m();
	void explosion_m();
	void start_m();
	void death_m();

	Jukebox();



};

#endif
