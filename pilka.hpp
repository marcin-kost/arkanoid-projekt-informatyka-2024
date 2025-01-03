#pragma once
#ifndef PILKA_HPP
#define PILKA_HPP

#include <SFML/Graphics.hpp>

class pilka {
private:
    sf::Vector2f position;
    sf::CircleShape ball;
public:
    pilka(float x_in, float y_in, float promien_in);
    void przesun(float x_in, float y_in);
    void zmienPromien(int o_ile);
    sf::CircleShape& getPilka() { return ball; }
    sf::Vector2f getPos() { return ball.getPosition(); }
    float getPromien() const { return ball.getRadius(); }
};


#endif