#include "napis.hpp"
#include <iostream>

Napis::Napis(const std::string& tekst, int x_in, int y_in, int rozmiar, sf::Color kolor, const sf::Font& font, sf::Text::Style styl) {
	napis.setString(tekst);
	napis.setCharacterSize(rozmiar);
	napis.setFillColor(kolor);
	napis.setPosition(x_in, y_in);
	napis.setFont(font);
	napis.setStyle(styl);
};
void Napis::zmienTekst(std::string tekst) {
	napis.setString(tekst);
};
void Napis::obwodka(sf::RenderWindow& window, float grubosc, sf::Color kolor) {
	int wys = getBounds().height;
	int szer = getBounds().width;
	int x = getBounds().left;
	int y = getBounds().top;
	sf::RectangleShape obwodka;
	obwodka.setOutlineThickness(grubosc);
	obwodka.setOutlineColor(kolor);
	obwodka.setFillColor(sf::Color::Transparent);
	obwodka.setPosition(x-2*grubosc-5, y-2*grubosc-10);
	obwodka.setSize(sf::Vector2f(szer+2*grubosc+10, wys+2*grubosc+20));
	window.draw(obwodka);
}
void Napis::ustaw_na_srodku(sf::RenderWindow& window) {
	int x = (window.getSize().x - getBounds().width) / 2;
	int y = napis.getPosition().y;
	napis.setPosition(x, y);

}