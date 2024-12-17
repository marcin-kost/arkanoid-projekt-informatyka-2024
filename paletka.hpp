#pragma once
#ifndef PALETKA_HPP
#define PALETKA_HPP

#include <SFML/Graphics.hpp>

class Paletka {
private: 
    sf::RectangleShape paddle;

public:
    Paletka(float x_in, float y_in);
    void przesun(float x_in);
    sf::RectangleShape getPaletka() const { return paddle; }
    sf::Vector2f getPos() const { return paddle.getPosition(); }
};
#endif