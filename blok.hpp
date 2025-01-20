#pragma once

#ifndef BLOK_HPP
#define BLOK_HPP

#include <SFML/Graphics.hpp>
#include "pilka.hpp"
#include "gracz.hpp"

class Blok {
private:
    sf::RectangleShape blok;
    sf::Texture tekstura;
public:
    bool zniszczony;
    Blok(float x_in, float y_in, bool zniszczony, const sf::Texture& tekstura);
    sf::RectangleShape getBlok() const { return blok; }
    sf::Vector2f getPos() const { return blok.getPosition(); }

};
void utworzSiatkeBlokow(float startX, float startY, int liczbaWierszy, int liczbaKolumn, float szerokoscBloku, float wysokoscBloku, const sf::Texture& tekstura, std::vector<std::vector<Blok>>& rzad);
void rysujBloki(sf::RenderWindow& window, std::vector<std::vector<Blok>>& rzad);
void odbijanieBloki(pilka& p1, float&dx, float& dy, float zmianaPromienia, int& punkty, std::vector<std::vector<Blok>>& rzad, Gracz& gracz);
#endif