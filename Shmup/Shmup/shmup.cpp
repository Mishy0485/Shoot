#include <SFML/Graphics.hpp>
#include "jeu.h"
#include "avion.h"
#include "projectile.h"
#include <ctime>
#include <iostream>

using namespace sf;
using namespace std;
bool alldead = false;

int main()
{
    Clock shootdelayPlayer;
    Clock shootdelayEnnemi;
    Clock spedelay;
    Clock rounddelay;
    Texture backTexture;
    if (!backTexture.loadFromFile("Back.png"))
        return -1;
    RectangleShape background;
    background.setTexture(&backTexture);
    background.setPosition(0, 0);
    background.setSize(Vector2f(1920, 1080));

    RectangleShape barreDeVieOutline;
    barreDeVieOutline.setFillColor(Color::Transparent);
    barreDeVieOutline.setOutlineColor(Color::Black);
    barreDeVieOutline.setOutlineThickness(10);
    barreDeVieOutline.setPosition(100, 900);
    

    RectangleShape barreDeVie;
    barreDeVie.setFillColor(Color::Red);
    barreDeVie.setPosition(100, 900);
    


    Jeu jeu;
    jeu.police.loadFromFile("Daydream.ttf");
    Plane joueur(500, 500, 10000, 10);
    barreDeVieOutline.setSize(Vector2f(joueur.getMaxVie() * 4, 50));
    RenderWindow window(VideoMode(1920, 1080), "Fenêtre SFML", Style::Default);

    window.setFramerateLimit(60);
    while (window.isOpen()) {
        int shootdelayint = shootdelayPlayer.getElapsedTime().asMilliseconds();
        int shootdelayint2 = shootdelayEnnemi.getElapsedTime().asSeconds();
        int rounddelayint = rounddelay.getElapsedTime().asMilliseconds();
        int spedelayint = spedelay.getElapsedTime().asMilliseconds();
       

        Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed)
                window.close();
            
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Space) && shootdelayint >= 200) {
                    joueur.tir(jeu.bulleta);
                    shootdelayPlayer.restart();
        }

        if (ennemis.size() == 0 && alldead == false) {
            if (jeu.nb_vagues == 3) {
                jeu.setBonusScreen(true);
                jeu.bonus_screen(0, window, joueur);
            }
            if (!jeu.getBonusScreen()) {
                alldead = true;
                jeu.incrVague();
                jeu.enTeteVague();
                FloatRect textRect = jeu.vague.getLocalBounds();
                jeu.vague.setOrigin(textRect.width / 2, textRect.height / 2);
                jeu.vague.setPosition(sf::Vector2f(1920 / 2.0f, 1080 / 2.0f));
                rounddelay.restart();
            }
        }
        else if (alldead && rounddelayint >= 2000) {
            if (jeu.nb_vagues == 3) {
                jeu.spawnEnnemi(1, 3);
            }
            else {
                jeu.spawnEnnemi(6, 0);
            }
            jeu.vague.setPosition(200, 50);
            alldead = false;
        }


        window.clear();
        window.draw(background);

        if (jeu.getBonusScreen()) {
            window.draw(jeu.powerup1);
            window.draw(jeu.powerup2);
            window.draw(jeu.powerup3);
        }
        if (!jeu.getGameOver() && !jeu.getBonusScreen()){
            for (int i = 0; i < ennemis.size(); ) {
                ennemis[i]->mouvement();

                if (shootdelayint2 >= ennemis[i]->getASpeed()) {
                    ennemis[i]->tir(jeu.bulleta);
                    shootdelayEnnemi.restart();
                }

                if (ennemis[i]->getType() == 3 && spedelayint >= 10000 && !ennemis[i]->spe) {
                    spedelay.restart();
                    ennemis[i]->capaciteSpe();
                    spedelayint = spedelay.getElapsedTime().asMilliseconds();
                }


                if (ennemis[i]->EstMort()) {
                    delete ennemis[i];
                    ennemis.erase(ennemis.begin() + i);
                }
                else {
                    if (ennemis[i]->spe && ennemis[i]->getType() == 3){
                        if (spedelayint >= 5000 && ennemis[i]->spe) {
                            ennemis[i]->spe = false;
                        }
                        window.draw(ennemis[i]->getSpeSprite());
                        cout << ennemis[i]->getSpeSprite().getPosition().x << endl;
                        if (spedelayint>=1500){
                            ennemis[i]->textureChange();
                            if (joueur.getSprite().getGlobalBounds().intersects(ennemis[i]->getSpeSprite().getGlobalBounds())){
                        
                                joueur.setVie(-1);
                            }
                        }
                    }
                    window.draw(ennemis[i]->getSprite());
                    i++;
                }
            }

            for (int i = 0; i < jeu.bulleta.size(); i++) {
                jeu.collisionPlane(joueur, jeu.bulleta[i]);
                if (jeu.bulleta[i]->getSide()) {
                    jeu.bulleta[i]->fuse(true);
                }
                else if (!jeu.bulleta[i]->getSide() && jeu.bulleta[i]->getType()==0) {
                    jeu.bulleta[i]->fuse(false);
                }

                else if (!jeu.bulleta[i]->getSide() && jeu.bulleta[i]->getType() == 1) {
                    if (jeu.bulleta[i]->getPositionY() > 475 && !jeu.bulleta[i]->getSepState()) {
                        jeu.bulleta[i]->separation(jeu.bulleta, *jeu.bulleta[i]);
                        jeu.bulleta[i]->setSepState();
                    }
                    jeu.bulleta[i]->fuse(false);
                }
                else if (!jeu.bulleta[i]->getSide() && jeu.bulleta[i]->getType() == 2) {
                    jeu.bulleta[i]->fuse1(true);
                }
                else if (!jeu.bulleta[i]->getSide() && jeu.bulleta[i]->getType() == 3) {
                    jeu.bulleta[i]->fuse1(false);
                }
            
                if (jeu.bulleta[i]->isOutOfScreen() or jeu.bulleta[i]->getHitValue()) {
                    delete jeu.bulleta[i];
                    jeu.bulleta.erase(jeu.bulleta.begin() + i);
                }
                for (int j = 0; j < ennemis.size(); j++) {
                    jeu.collisionEnnemi(ennemis[j], jeu.bulleta[i]);
                }
                window.draw(jeu.bulleta[i]->getSprite());
            }

            if (joueur.getVie() < 1)
            {
                jeu.setGameOver(true);
                cout << "mort" << endl;
            }
            joueur.deplacement();

            window.draw(joueur.getSprite());
            window.draw(jeu.vague);
            barreDeVie.setSize(Vector2f(joueur.getVie() * 4, 50));
            window.draw(barreDeVie);
            window.draw(barreDeVieOutline);
        }
        
        if (jeu.getGameOver()) {

            Texture fin;
            if (!fin.loadFromFile("game_over_final.png"))
                return -1;


            jeu.end.setSize(Vector2f(600.f, 200.f));
            jeu.end.setTexture(&fin);


            jeu.end.setPosition(Vector2f(660.f, 440.f));

            window.draw(jeu.end);
        }

        window.display();
        cout << jeu.nb_vagues << endl;
    }

    return 0;
}