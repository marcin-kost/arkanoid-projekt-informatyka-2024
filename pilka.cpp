#include "pilka.hpp"
#include <iostream>

pilka::pilka(float x_in, float y_in, float promien_in):przegrana(false)
{
    position.x = x_in;
    position.y = y_in;

    ball.setRadius(promien_in);
    ball.setFillColor(sf::Color(150, 50, 250));

    ball.setOutlineThickness(2);
    ball.setOutlineColor(sf::Color::Blue);
    ball.setPosition(position);
}
void pilka::przesun(float x_in, float y_in)
{
    sf::Vector2f pos;
    pos.x = x_in;
    pos.y = y_in;
    ball.move(pos);
}
void pilka::zmienPromien(int o_ile) {
    float promien = ball.getRadius() + o_ile; 
    if(promien > 5.f){
    ball.setRadius(promien); 
    }
}
void pilka::odbij(pilka& p1, sf::RenderWindow& window, float& dx, float& dy) {

    if (p1.getPos().x + 2 * p1.getPromien() == window.getSize().x || p1.getPos().x == 0) {
        dx = -dx;
    }

    if (p1.getPos().y == 0) {
        dy = -dy;
    }
    if (p1.getPos().y + 2 * p1.getPromien() == window.getSize().y) {
        dx = 0;
        dy = 0;
        przegrana = true;
    }
}
void pilka::zmienPos(float x, float y) { ball.setPosition(x, y); }