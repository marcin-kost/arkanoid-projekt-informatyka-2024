#include "paletka.hpp"

Paletka::Paletka(float x_in, float y_in) {
    paddle.setSize(sf::Vector2f(150, 20));
    paddle.setFillColor(sf::Color::White);
    paddle.setPosition(x_in, y_in);
}

void Paletka::przesun(float x_in) {
    paddle.move(x_in, 0);
}
//sf::RectangleShape getPaletka() const { return paddle; }
//sf::Vector2f getPos() const { return paddle.getPosition(); }