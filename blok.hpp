#pragma once

#ifndef BLOK_HPP
#define BLOK_HPP

#include <SFML/Graphics.hpp>
#include "pilka.hpp"

class Blok {
private:
    sf::RectangleShape blok;
public:
    bool zniszczony;
    Blok(float x_in, float y_in, bool zniszczony);
    sf::RectangleShape getBlok() const { return blok; }
    sf::Vector2f getPos() const { return blok.getPosition(); }

};
void utworzSiatkeBlokow(float startX, float startY, int liczbaWierszy, int liczbaKolumn, float szerokoscBloku, float wysokoscBloku);
void rysujBloki(sf::RenderWindow& window);
void odbijanieBloki(pilka& p1, float&dx, float& dy, float zmianaPromienia);
#endif