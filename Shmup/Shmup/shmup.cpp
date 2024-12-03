#include <SFML/Graphics.hpp>
#include "jeu.h"

class Plane;
using namespace sf;

Clock clocky;

int main() 
{
    getTex().loadFromFile("plane.png");

    // Création de la fenêtre
    RenderWindow window(VideoMode(800, 600), "Fenêtre SFML");

    CircleShape rec(50); // Rayon de 50 pixels
    rec.setFillColor(Color::Green);

    // Boucle principale
    while (window.isOpen()) {

        float lastFrameTime = clocky.restart().asSeconds();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close(); // Fermer la fenêtre
        }

        // Effacer la fenêtre
        window.clear();
        // Dessiner la forme
        window.draw(rec);
        // Afficher le contenu
        window.display();
    }

    return 0;
}