#include <SFML/Graphics.hpp>
#include "jeu.h"
#include "avion.h"
#include <ctime>
using namespace sf;
using namespace std;



int main() 
{
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
    RenderWindow window(VideoMode(1920, 1080), "Fen�tre SFML");

    // Cr�ation d'un cercle
    CircleShape shape(50); // Rayon de 50 pixels
    shape.setFillColor(Color::Green);

    jeu.spawnEnnemi(6);

    window.setFramerateLimit(60);
    while (window.isOpen()) {


        Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        for (int i = 0; i < jeu.ennemis.size(); i++) {
            jeu.ennemis[i]->mouvement();
            window.draw(jeu.ennemis[i]->getsprite());
        }
        joueur.deplacement();
        window.draw(joueur.getSprite());
        window.display();
    }

    return 0;
}