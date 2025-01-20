#pragma once
#ifndef NIEREGULARNY_HPP
#define NIEREGULARNY_HPP
#include <SFML/Graphics.hpp>
#include "pilka.hpp"
class Nieregularny {
private:
    sf::ConvexShape nieregularny;
    bool czy_spadl;
public:
    Nieregularny(float x_in, float y_in);
    sf::ConvexShape getNiereg() { return nieregularny; }
    sf::Vector2f getPos() const { return nieregularny.getPosition(); }
    sf::FloatRect getSize() const { return nieregularny.getGlobalBounds(); }
    bool czySpadl() const { return czy_spadl; }
    void spadanie();
    void generuj(pilka& p1);
    void zmienPos(float x, float y);
};
#endif