#include <SFML/Graphics.hpp>
#include "klasy/Gracz.h"
#include "klasy/Plansza.h"
#include "klasy/Znak.h"
#include "klasy/Menu.h"

tryb trybGry = tryb::pauza;

short x, y;

int main() {

    sf::RenderWindow window(sf::VideoMode(450, 450), "TicTacToe", sf::Style::Default);

    Gracz* gracze = new Gracz[2];
    Menu menu;
    Plansza plansza;
    bool mozliwoscUstawienia = true;
    while (window.isOpen()) {

        if (((trybGry == tryb::vsAI) && (plansza.tura == 1))) {
            plansza.dodajZnak(znak::Kolko, gracze[1].najlepszyRuch(&plansza, 1));
            plansza.tura = (++plansza.tura) % 2;
            mozliwoscUstawienia = true;
        }

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }

            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    //wciśnięto przycisk
                    if (trybGry == tryb::pauza) {
                        mozliwoscUstawienia = true;
                        if (menu.przyciski[0]->wGranicach(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))) {
                            //1 gracz
                            trybGry = tryb::vsAI;
                            plansza.wyczysc();
                            plansza.tura = 0;
                        }
                        else if (menu.przyciski[1]->wGranicach(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))) {
                            //2 graczy
                            trybGry = tryb::vsGracz;
                            plansza.wyczysc();
                            plansza.tura = 0;
                        }
                        else if (menu.przyciski[2]->wGranicach(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))) {
                            //wyjscie
                            return 0;
                        }

                    }
                    else if(trybGry == tryb::Koniec){
                        trybGry = tryb::pauza;
                    }
                    else {
                        if ((trybGry == tryb::vsGracz) || ((trybGry == tryb::vsAI) && (plansza.tura == 0) && mozliwoscUstawienia)) {
                            auto wspPola = plansza.wspGlobalneDoPlanszy(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                            //std::cout << wspPola.x << " " << wspPola.y << std::endl;
                            if (plansza.dodajZnak(plansza.tura ? znak::Kolko : znak::Krzyzyk, wspPola)) {
                                mozliwoscUstawienia = false;
                                plansza.tura = (++plansza.tura) % 2;
                            };
                        }
                    }
                }
            }

        }

        auto status = plansza.czyKoniec();
        if ((status != 2) && (trybGry != tryb::Koniec) && (trybGry != tryb::pauza)) {
            trybGry = tryb::Koniec;
            if(!status)
                menu.statusPoprzedniejGry.setString("Remis");
            else if (status == -1)
                menu.statusPoprzedniejGry.setString("Wygralo Kolko");
            else
                menu.statusPoprzedniejGry.setString("Wygral Krzyzyk");
            menu.kliknij.setString("Kliknij aby kontynuowac...");
        }

        window.clear(sf::Color(255, 226, 145));
        if (trybGry == tryb::pauza) {
            //wyświetlanie menu
            window.draw(menu.glownyTekst);
            for (auto i : { 0, 1, 2 }) {
                window.draw(menu.przyciski[i]->tlo);
                window.draw(menu.przyciski[i]->napis);
            }
        }
        else {
            //wyświetlanie gry
            window.draw(plansza.tlo);
            plansza.aktualizujUI(menu.font);
            window.draw(plansza.turaNapis);
            for (auto i : { 0, 1, 2 }) {
                for (auto j : { 0, 1, 2 }) {
                    window.draw(plansza.pola[i][j].kwadrat);
                    //pole odswiez i narysuj teksture
                    plansza.pola[i][j].odswiez(&plansza.kolko, &plansza.krzyzyk);
                    window.draw(plansza.pola[i][j].figura);
                }
            }
            if(trybGry == tryb::Koniec){
                window.draw(menu.statusPoprzedniejGry);
                window.draw(menu.kliknij);
            }
        }
        window.display();

    }
    return 0;
}