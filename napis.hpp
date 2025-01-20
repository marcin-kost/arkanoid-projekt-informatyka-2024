#pragma once
#ifndef NAPIS_HPP
#define NAPIS_HPP

#include <SFML/Graphics.hpp>

class Napis {
private:
	sf::Text napis;
public:
	Napis(const std::string& tekst, int x_in, int y_in, int rozmiar, sf::Color kolor, const sf::Font& font, sf::Text::Style styl);
	sf::Text& getNapis() { return napis; }
	sf::FloatRect getBounds() const { return napis.getGlobalBounds(); }
	void zmienTekst(std::string tekst);
	void obwodka(sf::RenderWindow& window, float grubosc, sf::Color kolor);
	void ustaw_na_srodku(sf::RenderWindow& window);
};

#endif