#include "jukebox.h"

Jukebox::Jukebox(){}

void Jukebox::music_m() {
	if (!music_b.loadFromFile("music.wav")) {
		return;
	}
	music.setBuffer(music_b);
}

void Jukebox::spawn_m() {
	if (!spawn_b.loadFromFile("spawn_sound.wav")) {
		return;
	}
	spawns.setBuffer(spawn_b);
}

void Jukebox::explosion_m() {
	if (!explosion_b.loadFromFile("explosion_sound.wav")) {
		return;
	}
	explosion.setBuffer(explosion_b);
}

void Jukebox::start_m() {
	if (!start_b.loadFromFile("start_sound.wav")) {
		return;
	}
	starts.setBuffer(start_b);
}

void Jukebox::death_m() {
	if (!death_b.loadFromFile("death_sound.wav")) {
		return;
	}
	deaths.setBuffer(death_b);
}