#include "pilka.hpp"

pilka::pilka(float x_in, float y_in, float promien_in)
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
    float promien = ball.getRadius() + o_ile;       // Zaktualizuj promieñ
    if(promien > 5.f){
    ball.setRadius(promien);    // Ustaw nowy promieñ w SF
    }
}