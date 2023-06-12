#include "Plansza.h"

Plansza::Plansza() : tura(0) {

    this->punktPoczatkowy = sf::Vector2f(75.0f, 75.0f);
    this->tlo = sf::RectangleShape(sf::Vector2f(310.0f, 310.0f));
    this->tlo.setFillColor(sf::Color::Black);
    this->tlo.setPosition(this->punktPoczatkowy);
    this->turaNapis = sf::Text();

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            this->pola[i][j] = Pole();
            auto org = sf::Vector2f(this->punktPoczatkowy.x + (j * 105.0f), this->punktPoczatkowy.y + (i * 105.0f));
            this->pola[i][j].kwadrat.setPosition(org);
            this->pola[i][j].figura.setPosition(org);
        }

    this->kolko = sf::Texture();
    this->krzyzyk = sf::Texture();
    if (!this->kolko.loadFromFile("res/kolo.png"))
        std::cout << "Nie udalo sie zaladowac tekstury kola." << std::endl;
    if (!this->krzyzyk.loadFromFile("res/krzyz.png"))
        std::cout << "Nie udalo sie zaladowac tekstury krzyzyka." << std::endl;

}

short Plansza::czyKoniec() { // -1 kolko, 1 krzyzyk, 0 remis, 2 gra trwa
    for (int i = 0; i < 3; i++) {  //wiersze
        if ((this->pola[i][0] == this->pola[i][1]) && (this->pola[i][1] == this->pola[i][2]) && !(this->pola[i][2] == znak::Brak)) {
            if (this->pola[i][2] == znak::Kolko)
                return -1;
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {  //kolumny
        if ((this->pola[0][i] == this->pola[1][i]) && (this->pola[1][i] == this->pola[2][i]) && !(this->pola[2][i] == znak::Brak)) {
            if (this->pola[2][i] == znak::Kolko)
                return -1;
            return 1;
        }
    }

    //przekatne
    if ((this->pola[0][0] == this->pola[1][1]) && (this->pola[1][1] == this->pola[2][2]) && !(this->pola[2][2] == znak::Brak)) {
        if (this->pola[2][2] == znak::Kolko)
            return -1;
        return 1;
    }
    if ((this->pola[0][2] == this->pola[1][1]) && (this->pola[1][1] == this->pola[2][0]) && !(this->pola[2][0] == znak::Brak)) {
        if (this->pola[2][0] == znak::Kolko)
            return -1;
        return 1;
    }
    //czy wszystkie zapelnione
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->pola[i][j] == znak::Brak)
                return 2;
        }
    }

    return 0;

}

sf::Vector2u Plansza::wspGlobalneDoPlanszy(sf::Vector2i wsp) {

    unsigned minX = 0;
    unsigned minY = 0;
    unsigned maxX = this->tlo.getSize().x;
    unsigned maxY = this->tlo.getSize().y;

    wsp.x -= this->punktPoczatkowy.x;
    wsp.y -= this->punktPoczatkowy.y;

    if (wsp.x > maxX || wsp.y > maxY || wsp.x < minX || wsp.y < minY)
        return sf::Vector2u(0, 0);
    return sf::Vector2u((wsp.y - (wsp.y % 105)) / 105.0f, (wsp.x - (wsp.x % 105)) / 105.0f);
}

bool Plansza::dodajZnak(znak znakDoDodania, sf::Vector2u wspolrzednePola) {

    if (this->pola[wspolrzednePola.x][wspolrzednePola.y].obecnyZnak != znak::Brak)
        return false;

    this->pola[wspolrzednePola.x][wspolrzednePola.y].obecnyZnak = znakDoDodania;
    return true;
}

std::vector<sf::Vector2u> Plansza::wygenerujRuchy() {

    std::vector<sf::Vector2u> ruchy;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (this->pola[i][j] == znak::Brak) ruchy.push_back(sf::Vector2u(i, j));

    return ruchy;

}

void Plansza::wyczysc() {

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            this->pola[i][j].obecnyZnak = znak::Brak;

}

void Plansza::aktualizujUI(sf::Font& font) {
    this->font = font;
    this->turaNapis.setFont(font);
    this->turaNapis.setString((this->tura) ? "Tura: Gracz O" : "Tura: Gracz X");
}
