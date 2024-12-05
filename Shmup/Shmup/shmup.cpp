#include <SFML/Graphics.hpp>
#include "jeu.h"
#include "Avion.cpp"
using namespace sf;


int main() 
{
    Plane plane(500, 540, 100, 0.2f); // a voir

    // Cr�ation de la fen�tre
    RenderWindow window(VideoMode(1920, 1080), "Fen�tre SFML");

    // Cr�ation d'un cercle
    CircleShape shape(50); // Rayon de 50 pixels
    shape.setFillColor(Color::Green);

    // Boucle principale
    while (window.isOpen()) {


        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close(); // Fermer la fen�tre
        }

        // Effacer la fen�tre
        window.clear();
        // Dessiner la forme
        window.draw(shape);
        // Afficher le contenu
        window.display();
    }

    return 0;
}