#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "jeu.h"
#include "jukebox.h"
#include "menu.h"
#include <ctime>
#include <iostream>

using namespace sf;
using namespace std;
bool alldead = false;
bool play = false;
bool menu = true;
bool finish;
bool deathsound = false;

int main()
{
        srand(time(NULL));
        Clock scoring;
        Clock shootdelayPlayer;
        Clock shootdelayEnnemi;
        Clock spedelay;
        Clock rounddelay;
        Texture backTexture;
        Texture eartht;
        Texture marst;
        Texture moont;

        if (!backTexture.loadFromFile("seamless_background.jpg"))return -1;
        if (!eartht.loadFromFile("earth.png")) return -1;
        if (!marst.loadFromFile("mars.png")) return -1;
        if (!moont.loadFromFile("moon.png")) return -1;


        RectangleShape mask;
        mask.setSize(Vector2f(3000, 2000));
        mask.setPosition(-100, -100);
        mask.setFillColor(Color(0, 0, 0, 150));

        RectangleShape background;
        background.setTexture(&backTexture);
        background.setPosition(0, 0);
        background.setSize(Vector2f(1920, 4800));

        RectangleShape background2;
        background2.setTexture(&backTexture);
        background2.setPosition(0, -4800);
        background2.setSize(Vector2f(1920, 4800));

        RectangleShape barreDeVieOutline;
        barreDeVieOutline.setFillColor(Color::Transparent);
        Color color(107, 107, 107, 255);
        barreDeVieOutline.setOutlineColor(color);
        barreDeVieOutline.setOutlineThickness(10);
        barreDeVieOutline.setPosition(100, 900);

        Sprite earth;
        earth.setTexture(eartht);
        earth.setPosition(1600, -2500);
        earth.setScale(0.6, 0.6);

        Sprite mars;
        mars.setTexture(marst);
        mars.setPosition(200, -1000);
        mars.setScale(0.6, 0.6);

        Sprite moon;
        moon.setTexture(moont);
        moon.setPosition(1500, -2000);
        moon.setScale(0.3, 0.3);

        RectangleShape barreDeVie;
        barreDeVie.setFillColor(Color::Red);
        barreDeVie.setPosition(100, 900);


        Menu menuu;
        Jeu jeu;
        Editeur editeur;
        Jukebox jukebox;
        jukebox.music_m();
        jukebox.spawn_m();
        jukebox.explosion_m();
        jukebox.start_m();
        jukebox.death_m();
        jeu.police.loadFromFile("Daydream.ttf");
        jeu.congrats.setString(" FELICITATIONS ");
        jeu.congrats.setPosition(700, 400);
        jeu.congrats.setCharacterSize(100);
        Plane joueur(500, 500, 200, 10);

        RenderWindow window(VideoMode(1920, 1080), "Fen�tre SFML", Style::Default);


        window.setFramerateLimit(60);

        while (window.isOpen()) {
            barreDeVieOutline.setSize(Vector2f(joueur.getMaxVie() * 4, 50));
            int scoringint = scoring.getElapsedTime().asMilliseconds();
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

            window.clear();

            if (menu) {
                menuu.setMenu();
                menuu.actionMenu(play, window, editeur);
              

                window.draw(menuu.menutry);
                window.draw(menuu.titre);
                window.draw(menuu.play);
                window.draw(menuu.butPlay);
                window.draw(menuu.parametre);
                window.draw(menuu.butSet);
                window.draw(menuu.quitter);
                window.draw(menuu.butQuit);
                window.draw(menuu.editor);
                window.draw(menuu.butEditor);

                if (menuu.parametreb) 
                {
                    window.draw(menuu.fenetrePara);
                    window.draw(menuu.parametreAffichage);
                    window.draw(menuu.buttonPara1);
                    window.draw(menuu.buttonPara2);
                    window.draw(menuu.control1);
                    window.draw(menuu.control2);
                    window.draw(menuu.son);
                    window.draw(menuu.FX);
                }

                if (editeur.editeurb)
                {
                    editeur.setEditeur();
                    window.draw(editeur.fenetre);
                    window.draw(editeur.choixEnnemi);
                    window.draw(editeur.selecteurDr);
                    window.draw(editeur.selecteurDrnb);
                    window.draw(editeur.selecteurGch);
                    window.draw(editeur.selecteurGchnb);
                    window.draw(editeur.bimBamBoom);
                    window.draw(editeur.next);
                }
            }


            if (jukebox.music.getStatus() != Sound::Playing && !jeu.getGameOver()) {
                jukebox.music.play();
            }

            if (!menuu.music_on) {
                jukebox.music.setVolume(0);
            }
            else if (menuu.music_on) {
                jukebox.music.setVolume(100);
            }


            if (play)
            {
                menu = false;
                if (Keyboard::isKeyPressed(Keyboard::Space) && shootdelayint >= 200) {
                    joueur.tir(jeu.bulleta);
                    shootdelayPlayer.restart();
                }

                if (jeu.ennemis.size() == 0 && alldead == false) {
                    jeu.bulleta.clear();
                    if (jeu.nb_vagues == 5) {
                        jeu.setBonusScreen(true);
                        jeu.bonus_screen(0, window, joueur);
                    }
                    if (jeu.nb_vagues == 10) {
                        play = false;
                        finish = true;
                    }
                    if (!jeu.getBonusScreen() && jeu.nb_vagues != 10) {
                        alldead = true;
                        jeu.incrVague();
                        jeu.enTeteVague();
                        FloatRect textRect = jeu.vague.getLocalBounds();
                        jeu.vague.setOrigin(textRect.width / 2, textRect.height / 2);
                        jeu.vague.setPosition(sf::Vector2f(1920 / 2.0f, 1080 / 2.0f));
                        if (jeu.nb_vagues == 1 && menuu.sfx_on) {
                            jukebox.starts.play();
                            jukebox.music.setVolume(0);
                        }
                        if (jeu.nb_vagues != 1) {
                            if (scoringint >= 10000) scoringint = 10000;
                            jeu.score += 10000 - scoringint;
                        }
                        rounddelay.restart();
                    }
                }

                else if (alldead && rounddelayint >= 2000) {
                    scoring.restart();
                    jeu.manage_vague();
                    if (menuu.sfx_on)
                    jukebox.spawns.play();
                    jukebox.music.setVolume(100);
                    jeu.vague.setPosition(200, 50);
                    alldead = false;
                }


                window.clear();

                window.draw(background);
                window.draw(background2);
                window.draw(earth);
                window.draw(mars);
                window.draw(moon);
                window.draw(mask);

                if (jeu.getBonusScreen()) {
                    window.draw(jeu.powerup1);
                    window.draw(jeu.powerup2);
                    window.draw(jeu.powerup3);
                }

                if (!jeu.getGameOver() && !jeu.getBonusScreen()) {
                    for (int i = 0; i < jeu.ennemis.size(); ) {
                        jeu.ennemis[i]->mouvement();

                        if (shootdelayint2 >= jeu.ennemis[i]->getASpeed()) {
                            jeu.ennemis[i]->tir(jeu.bulleta);
                            shootdelayEnnemi.restart();
                        }

                        if (spedelayint >= 10000 && !jeu.ennemis[i]->spe) {
                            spedelay.restart();
                            jeu.ennemis[i]->capaciteSpe();
                            spedelayint = spedelay.getElapsedTime().asMilliseconds();
                            cout << jeu.ennemis[i]->getType() << endl;
                            if (jeu.ennemis[i]->getType() == 4) {
                                jeu.capaSpeBoss2(jeu.ennemis[i]->getSprite().getPosition().x, jeu.ennemis[i]->getSprite().getPosition().y, jeu.ennemis[i]);
                            }
                        }


                        if (jeu.ennemis[i]->EstMort()) {
                            jeu.score += jeu.ennemis[i]->getPoint();
                            if ( menuu.sfx_on)
                            jukebox.explosion.play();
                            delete jeu.ennemis[i];
                            jeu.ennemis.erase(jeu.ennemis.begin() + i);
                        }
                        else {
                            if (jeu.ennemis[i]->spe && jeu.ennemis[i]->getType() == 3) {
                                if (spedelayint >= 5000 && jeu.ennemis[i]->spe) {
                                    jeu.ennemis[i]->spe = false;
                                }
                                window.draw(jeu.ennemis[i]->getSpeSprite());
                                if (spedelayint >= 1500) {
                                    jeu.ennemis[i]->textureChange();
                                    if (joueur.getSprite().getGlobalBounds().intersects(jeu.ennemis[i]->getSpeSprite().getGlobalBounds())) {

                                        joueur.setVie(-1);
                                    }
                                }
                            }
                            window.draw(jeu.ennemis[i]->getSprite());
                            i++;
                        }
                    }

                    for (int i = 0; i < jeu.bulleta.size(); i++) {
                        jeu.collisionPlane(joueur, jeu.bulleta[i]);
                        if (jeu.bulleta[i]->getSide()) {
                            jeu.bulleta[i]->fuse(true);
                        }
                        else if (!jeu.bulleta[i]->getSide()){
                            if (jeu.bulleta[i]->getType() == 0) {
                            jeu.bulleta[i]->fuse(false);
                            }

                            else if (jeu.bulleta[i]->getType() == 1) {
                                if (jeu.bulleta[i]->getSprite().getPosition().y > 475 && !jeu.bulleta[i]->getSepState()) {
                                    jeu.bulleta[i]->separation(jeu.bulleta);
                                    jeu.bulleta[i]->setSepState();
                                }
                                jeu.bulleta[i]->fuse(false);
                            }
                            else if (jeu.bulleta[i]->getType() == 2) {
                                jeu.bulleta[i]->fuse1(true);
                            }
                            else if (jeu.bulleta[i]->getType() == 3) {
                                jeu.bulleta[i]->fuse1(false);
                            }

                            else if (jeu.bulleta[i]->getType() == 4) {
                                jeu.bulleta[i]->deplacementLaser();
                            }
                        }

                        if (jeu.bulleta[i]->isOutOfScreen() or jeu.bulleta[i]->getHitValue()) {
                            delete jeu.bulleta[i];
                            jeu.bulleta.erase(jeu.bulleta.begin() + i);
                        }
                        for (int j = 0; j < jeu.ennemis.size(); j++) {
                            jeu.collisionEnnemi(jeu.ennemis[j], jeu.bulleta[i]);
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
                    window.draw(jeu.score_aff);
                    barreDeVie.setSize(Vector2f(joueur.getVie() * 4, 50));
                    window.draw(barreDeVie);
                    window.draw(barreDeVieOutline);
                }
                background.move(0, 1);
                background2.move(0, 1);
                earth.move(0, 2);
                mars.move(0, 2);
                moon.move(0, 3);
            }
            if (jeu.getGameOver()) {
                background.move(0, 1);
                background2.move(0, 1);
                earth.move(0, 2);
                mars.move(0, 2);
                moon.move(0, 3);
                if (!deathsound && menuu.sfx_on) {
                    jukebox.deaths.play();
                    deathsound = true;
                }
                jukebox.music.stop();
                Texture fin;
                if (!fin.loadFromFile("game_over_final.png"))
                    return -1;


                jeu.end.setSize(Vector2f(600.f, 200.f));
                jeu.end.setTexture(&fin);


                jeu.end.setPosition(Vector2f(660.f, 440.f));

                window.draw(jeu.end);
            }
            if (finish) {
                window.draw(jeu.congrats);
                jeu.score_aff.setPosition(jeu.congrats.getPosition().x, jeu.congrats.getPosition().y + 300);
                window.draw(jeu.score_aff);
            }
            if (background.getPosition().y >= 1500) {
                background.setPosition(0, background2.getPosition().y - 4800);
            }
            if (background2.getPosition().y >= 1500) {
                background2.setPosition(0, background.getPosition().y - 4800);
            }
            if (earth.getPosition().y >= 1500) {
                earth.setPosition(earth.getPosition().x, -2000);
            }
            if (mars.getPosition().y >= 3500) {
                mars.setPosition(mars.getPosition().x, -2000);
            }
            if (moon.getPosition().y >= 1500) {
                moon.setPosition(moon.getPosition().x, -2500);
            }



            window.display();
            jeu.score_maj();
        }

    return 0;
}