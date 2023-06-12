#include "Menu.h"

Przycisk::Przycisk(sf::Font &font, std::string text): font(font), pkt1(sf::Vector2f(.0f, .0f)), rozmiar(sf::Vector2f(250.0f, 50.0f)){
    this->napis = sf::Text("test", this->font);
    this->napis.setString(text);
    this->napis.setPosition(sf::Vector2f(50.0f, 10.0f));
    
    this->tlo = sf::RectangleShape(this->rozmiar);
    this->tlo.setPosition(this->pkt1);
    this->tlo.setFillColor(sf::Color(186, 48, 53));
}

void Przycisk::odswiez(){

    this->tlo.setPosition(this->pkt1);
    this->napis.setPosition(this->pkt1);

}

bool Przycisk::wGranicach(sf::Vector2i wsp)
{
    return (wsp.x >= this->pkt1.x && wsp.x <= this->pkt1.x+this->rozmiar.x) && (wsp.y >= this->pkt1.y && wsp.y <= this->pkt1.y+this->rozmiar.y);
}

Menu::Menu(){
    this->font = sf::Font();
    if(!this->font.loadFromFile("res/Roboto_Mono/static/RobotoMono-Regular.ttf"))
        std::cout << "Nie udalo sie wczytac czcionki" << std::endl;

    this->glownyTekst = sf::Text("Kolko i Krzyzyk", this->font);
    this->glownyTekst.setFillColor(sf::Color::Black);
    this->statusPoprzedniejGry = sf::Text("", this->font);
    this->statusPoprzedniejGry.setPosition(sf::Vector2f(100.0f, 390.0f));
    this->statusPoprzedniejGry.setFillColor(sf::Color::Red);
    this->kliknij = sf::Text("", this->font);
    this->kliknij.setPosition(sf::Vector2f(100.0f, 425.0f));
    this->kliknij.setFillColor(sf::Color::Black);
    this->kliknij.setScale(sf::Vector2f(.45f, .45f));

    this->przyciski[0] = new Przycisk(this->font, "1 gracz(vs.AI)");
    this->przyciski[0]->pkt1 = sf::Vector2f(100.0f, 100.0f);
    this->przyciski[1] = new Przycisk(this->font, "2 graczy");
    this->przyciski[1]->pkt1 = sf::Vector2f(100.0f, 175.0f);
    this->przyciski[2] = new Przycisk(this->font, "wyjscie");
    this->przyciski[2]->pkt1 = sf::Vector2f(100.0f, 250.0f);

    for(auto i : {0, 1, 2})
        this->przyciski[i]->odswiez();

}
