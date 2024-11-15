
#include <SFML/Graphics.hpp>
#include <iostream>
class paletka {
private:
    sf::Vector2f position;
    float vx = 10;
    sf::RectangleShape paddle;

public:
    paletka(float x_in, float y_in);
    void przesun(float x_in);
    sf::RectangleShape getPaletka() { return paddle; }
    sf::Vector2f getPos() { return paddle.getPosition(); }
};

paletka::paletka(float x_in, float y_in) {
    position.x = x_in;
    position.y = y_in;
    paddle.setSize(sf::Vector2f(100, 20));
    paddle.setFillColor(sf::Color::White);
    paddle.setPosition(position);
}
void paletka::przesun(float x_in)
{
    sf::Vector2f pos;
    pos.x = x_in;
    paddle.move(pos);
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    paletka pad(450, 390);
    int x = 0, y = 0;
    sf::Clock zegar;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.key.code == sf::Keyboard::D)
            {
                pad.przesun(10);
            }
            if (event.key.code == sf::Keyboard::A)
            {
                pad.przesun(-10);
            }
        }
        window.clear();
        window.draw(pad.getPaletka());
        window.display();
    }
    return 0;
}