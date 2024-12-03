#include <SFML/Graphics.hpp>
#include "jeu.h"

class Plane;
using namespace sf;



int main() 
{
    // Création de la fenêtre
    RenderWindow window(VideoMode(800, 600), "Fenêtre SFML");

    // Création d'un cercle
    CircleShape shape(50); // Rayon de 50 pixels
    shape.setFillColor(Color::Green);

    // Boucle principale
    while (window.isOpen()) {


        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close(); // Fermer la fenêtre
        }

        // Effacer la fenêtre
        window.clear();
        // Dessiner la forme
        window.draw(shape);
        // Afficher le contenu
        window.display();
    }

    return 0;
}