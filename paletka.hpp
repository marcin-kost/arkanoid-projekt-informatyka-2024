#pragma once
#ifndef Paletka_HPP
#define Paletka_HPP

#include <SFML/Graphics.hpp>
#include "pilka.hpp"

class Prostokat {
private: 
    sf::RectangleShape prostokat;
    float szer;
    float dlug;
public:
    Prostokat(float x_in, float y_in, float szer, float dlug);
    void przesun(float x_in);
    sf::RectangleShape getProstokat() const { return prostokat; }
    sf::Vector2f getPos() const { return prostokat.getPosition(); }
    void odbijProstokat(pilka& p1, Prostokat& paletka, float& dx, float& dy);
    void ustaw_teksture(const sf::Texture& tekstura);
    void zmien_rozmiar(float szer, float dlug);
    void zmienPos(float x, float y) { prostokat.setPosition(x, y); }
};
#endif