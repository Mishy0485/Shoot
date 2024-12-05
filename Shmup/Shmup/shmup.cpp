#include <SFML/Graphics.hpp>
#include "jeu.h"
#include <ctime>
using namespace sf;
using namespace std;



int main() 
{
    Jeu jeu;
    srand(time(0));
    // Cr�ation de la fen�tre
    RenderWindow window(VideoMode(1920, 1080), "Fen�tre SFML");

    // Cr�ation d'un cercle
    CircleShape shape(50); // Rayon de 50 pixels
    shape.setFillColor(Color::Green);

    jeu.spawnEnnemi(6);

    window.setFramerateLimit(60);
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
        for (int i = 0; i < jeu.ennemis.size(); i++) {
            jeu.ennemis[i]->mouvement();
            window.draw(jeu.ennemis[i]->getsprite());
        }
        
        // Afficher le contenu
        window.display();
    }

    return 0;
}