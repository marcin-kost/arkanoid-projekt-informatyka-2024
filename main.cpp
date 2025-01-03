#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <vector>
#include "paletka.hpp"
#include "pilka.hpp"
#include "blok.hpp"

void odbij(pilka& p1, sf::RenderWindow& window, float& dx, float& dy) {

    if (p1.getPos().x > window.getSize().x - 2*p1.getPromien() || p1.getPos().x < 0) {
        dx = -dx; 
    }

    if (p1.getPos().y > window.getSize().y - 2 * p1.getPromien() || p1.getPos().y < 0) {
        dy = -dy; 
    }
}


int main() {
    srand(time(NULL));

    float predkosc_paletki = 0.5f;

    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    Paletka pad(450, 735); 
    pilka p1(480,380, 30);
    int x = 0, y = 0;
    float dx = 0.5f, dy = -0.5f;
    utworzSiatkeBlokow(0.0f, 0.0f, 5, 10, 100.0f, 50.0f);
    
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
        if (zegar.getElapsedTime().asMilliseconds() > 1.0f) {
            odbij(p1, window, dx, dy);
            
            p1.przesun(dx, dy);
            zegar.restart();
        }


        window.clear();
        rysujBloki(window);
        odbijanieBloki(p1, dx, dy, 0.f);
        odbijPaletka(p1, pad, dx, dy);
        window.draw(pad.getPaletka());
        window.draw(p1.getPilka());
        window.display();
    }
    return 0;
}
