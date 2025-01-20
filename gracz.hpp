#pragma once
#ifndef GRACZ_H
#define GRACZ_H

#include <SFML/Graphics.hpp>
#include <string>

struct Gracz {
    std::string imie;
    int punkty=0;
    float zycia=3.f;
    Gracz() {};

    Gracz(const std::string imie, int id, int& punkty);
    void nadaj_imie(sf::RenderWindow& window, sf::Keyboard::Key Enter, sf::Font font);
};

#endif
