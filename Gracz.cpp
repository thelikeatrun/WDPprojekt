#include "Gracz.h"
#include <SFML/Graphics.hpp>
#include <vector>

Gracz::Gracz(znak symbol) :symbol(symbol) {}


sf::Vector2u Gracz::najlepszyRuch(Plansza* plansza, short gracz) {

    Plansza temp = *plansza;
    short zajete_pola = 0;
    bool pierwszy_ruch = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (temp.pola[i][j].obecnyZnak != znak::Brak)
                zajete_pola++;
        }
    }
    if (zajete_pola == 1) pierwszy_ruch = true;
    if (pierwszy_ruch) {
        if (temp.pola[1][1] == znak::Krzyzyk)   //jesli pierwszy ruch byl na srodku
            return sf::Vector2u(0, 2);
        else
            return sf::Vector2u(1, 1);
    }
    else {
        short najwyzszyWynik = 10000, wynik;
        sf::Vector2u najlepszyRuch;
        std::vector<sf::Vector2u> ruchy = temp.wygenerujRuchy();
        for (auto i : ruchy) {
            temp.pola[i.x][i.y].obecnyZnak = znak::Kolko;
            wynik = minimax(&temp, 0, 1);
            temp.pola[i.x][i.y].obecnyZnak = znak::Brak;
            if (wynik < najwyzszyWynik) {
                najwyzszyWynik = wynik;
                najlepszyRuch = sf::Vector2u(i.x, i.y);
            }
        }

        //std::cout << najlepszyRuch.x << " " << najlepszyRuch.y << std::endl;
        return najlepszyRuch;
    }
}
int minimax(Plansza* plansza, short glebokosc, short gracz) {

    Plansza temp = *plansza;


    short wynik = temp.czyKoniec();
    if (wynik != 2)
        return wynik * (10 - glebokosc);

    if (gracz == 1) { //maximizer [krzyzyk]

        short najlepszyWynik = -10000;
        for (auto i : temp.wygenerujRuchy()) {
            temp.pola[i.x][i.y].obecnyZnak = znak::Krzyzyk;
            wynik = minimax(&temp, glebokosc + 1, 0);
            temp.pola[i.x][i.y].obecnyZnak = znak::Brak;
            if (wynik > najlepszyWynik)
                najlepszyWynik = wynik;;
        }
        return najlepszyWynik;
    }
    else {  //minimizer [kolko]

        short najlepszyWynik = 10000;
        for (auto i : temp.wygenerujRuchy()) {
            temp.pola[i.x][i.y].obecnyZnak = znak::Kolko;
            wynik = minimax(&temp, glebokosc + 1, 1);
            temp.pola[i.x][i.y].obecnyZnak = znak::Brak;
            if (wynik < najlepszyWynik)
                najlepszyWynik = wynik;
        }

        return najlepszyWynik;
    }
}