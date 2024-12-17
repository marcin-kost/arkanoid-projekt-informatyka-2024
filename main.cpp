#include <SFML/Graphics.hpp>
#include <iostream>
#include<time.h>
#include "paletka.hpp"
#include "pilka.hpp"

void odbij(pilka& p1, Paletka& pad, sf::RenderWindow& window, int& dx, int& dy) {

    if (p1.getPos().x > window.getSize().x - 40 || p1.getPos().x < 0) {
        dx = -dx; 
    }

    if (p1.getPos().y > window.getSize().y - 40 || p1.getPos().y < 0) {
        dy = -dy; 
    }

    if (p1.getPos().x + 20 >= pad.getPos().x && p1.getPos().x <= pad.getPos().x + 150 &&
        p1.getPos().y + 38 <= pad.getPos().y && p1.getPos().y + 42 >= pad.getPos().y) {
        dy = -dy; 
        
    }
     
}


int main() {
    srand(time(NULL));

    float predkosc_paletki = 0.7;

    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    Paletka pad(450, 750); 
    pilka p1(480,380);
    int x = 0, y = 0;
    int dx = rand()%5+1, dy = rand() % 5+1;
    sf::Clock zegar;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && pad.getPos().x <= 850) {
            pad.przesun(predkosc_paletki);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && pad.getPos().x >= 0) {
            pad.przesun(-predkosc_paletki);
        }
        if (zegar.getElapsedTime().asMilliseconds() > 10.0f) {
        
            odbij(p1, pad, window, dx, dy);
            p1.przesun(dx, dy);
            zegar.restart();
        }
        std::cout << "p1: " << p1.getPos().x << ", " << p1.getPos().y << std::endl;
        std::cout << "pad: " << pad.getPos().x << ", " << pad.getPos().y << std::endl;

        window.clear();
        window.draw(pad.getPaletka());
        window.draw(p1.getPilka());
        window.display();
    }
    return 0;
}
