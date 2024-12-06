#include <SFML/Graphics.hpp>
#include "jeu.h"
#include "avion.h"
#include "projectile.h"
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;



int main() 
{
    Clock shootdelay;
    Texture backTexture;
    if (!backTexture.loadFromFile("C:\\Users\\sbrossard\\source\\repos\\Mishy0485\\Shoot\\Shmup\\Back.png"))
        return -1;

    RectangleShape background;
    background.setTexture(&backTexture);
    background.setPosition(0, 0);
    background.setSize(Vector2f(1920, 1080));

    Jeu jeu;
    Plane joueur(500, 500, 20, 10);
    srand(time(0));
    RenderWindow window(VideoMode(1920, 1080), "Fenêtre SFML");

    // Création d'un cercle
    CircleShape shape(50); // Rayon de 50 pixels
    shape.setFillColor(Color::Green);

    jeu.spawnEnnemi(6);

    window.setFramerateLimit(60);
    while (window.isOpen()) {
        int shootdelayint = shootdelay.getElapsedTime().asMilliseconds();

        Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed)
                window.close();
            
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) && shootdelayint >= 200) {
                    joueur.tir(jeu.bulleta);
                    cout << jeu.bulleta.size() << endl;
                    shootdelay.restart();
        }

        window.clear();
        window.draw(background);
        for (int i = 0; i < jeu.ennemis.size(); i++) {
            jeu.ennemis[i]->mouvement();
            if (jeu.ennemis[i]->EstMort()) {
                delete jeu.ennemis[i];
                jeu.ennemis.erase(jeu.ennemis.begin() + i);
            }
            window.draw(jeu.ennemis[i]->getsprite());
        }
        for (int i = 0; i < jeu.bulleta.size(); i++) {
            jeu.bulleta[i]->fuse(true);
            
            if (jeu.bulleta[i]->isOutOfScreen() or jeu.bulleta[i]->getHitValue()) {
                delete jeu.bulleta[i];
                jeu.bulleta.erase(jeu.bulleta.begin() + i);
            }
            for (int j = 0; j < jeu.ennemis.size(); j++) {
                jeu.collisionEnnemi(jeu.ennemis[j], jeu.bulleta[i]);
            }
            window.draw(jeu.bulleta[i]->getSprite());
        }
        joueur.deplacement();
        window.draw(joueur.getSprite());
        window.display();
    }

    return 0;
}