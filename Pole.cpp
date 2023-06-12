#include "Pole.h"

bool operator==(const Pole& pole1, const Pole& pole2) {
    return pole1.obecnyZnak == pole2.obecnyZnak;
}

bool operator==(const Pole& pole1, znak symbol) {
    return pole1.obecnyZnak == symbol;
}

Pole::Pole() :
    obecnyZnak(znak::Brak), kwadrat(sf::RectangleShape(sf::Vector2f(100.0f, 100.0f))) {
        this->kwadrat.setFillColor(sf::Color::White);

        this->figura = sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
}

void Pole::odswiez(sf::Texture* kolko, sf::Texture* krzyzyk){

    //sprawdz figure i ustaw teskture
    if(this->obecnyZnak == znak::Brak){
        this->figura.setSize(sf::Vector2f(0.0f, 0.0f));
    }
    else if(this->obecnyZnak == znak::Kolko){
        this->figura.setSize(sf::Vector2f(100.0f, 100.0f));
        this->figura.setTexture(kolko);
    }
    else{
        this->figura.setSize(sf::Vector2f(100.0f, 100.0f));
        this->figura.setTexture(krzyzyk);
    }
}
