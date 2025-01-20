#include "gracz.hpp"
#include <iostream>

// Konstruktor
Gracz::Gracz(std::string imie, int id, int& punkty) {
}

void Gracz::nadaj_imie(sf::RenderWindow& window, sf::Keyboard::Key Enter, sf::Font font) {
    sf::Event event{};
    imie.clear();

    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::TextEntered) {

                if (event.text.unicode == '\b' && !imie.empty()) {
                    imie.pop_back();  // Obs�uga Backspace
                }
                else if (event.text.unicode < 128 && event.text.unicode >= 32) {
                    imie += static_cast<char>(event.text.unicode);
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == Enter) {
                std::cout << "Imi� gracza: " << imie << "  Punkty: " << punkty << std::endl;
                return;
            }
        }

        // Wy�wietlanie wpisywanego imienia na ekranie
        window.clear();
        sf::Text text(imie, font, 30);  // `someFont` musi by� za�adowan� czcionk�
        text.setPosition(100, 100);
        text.setFillColor(sf::Color::White);
        window.draw(text);
        window.display();
    }
}

