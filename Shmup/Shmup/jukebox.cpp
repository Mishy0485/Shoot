#include "jukebox.h"

Jukebox::Jukebox(){}

void Jukebox::music_m() {
	if (!music_b.loadFromFile("music.wav")) {
		return;
	}
	music.setBuffer(music_b);
}