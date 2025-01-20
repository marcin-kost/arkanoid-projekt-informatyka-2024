#include "Paletka.hpp"

Prostokat::Prostokat(float x_in, float y_in, float szer, float dlug) {
	prostokat.setSize(sf::Vector2f(szer, dlug));
	prostokat.setFillColor(sf::Color::White);
	prostokat.setPosition(x_in, y_in);
}

void Prostokat::przesun(float x_in) {
	prostokat.move(x_in, 0);
}
void Prostokat::odbijProstokat(pilka& p1, Prostokat& paletka, float& dx, float& dy) {
	sf::Vector2f pozycjaPilki = p1.getPos();
	sf::Vector2f pozycjaProstokata = paletka.getPos();
	sf::Vector2f rozmiarProstokata = prostokat.getSize();
	float promien = p1.getPromien();

	if (pozycjaPilki.x + 1.5*promien > pozycjaProstokata.x && pozycjaPilki.x + 0.5*promien < pozycjaProstokata.x + rozmiarProstokata.x && pozycjaPilki.y + 2 * promien + 1 >= pozycjaProstokata.y) {
		dy = -dy;
	}
	if (pozycjaPilki.x + 1.5 * promien > pozycjaProstokata.x && pozycjaPilki.x + 0.5 * promien < pozycjaProstokata.x + rozmiarProstokata.x && pozycjaPilki.y - 1 >= pozycjaProstokata.y+rozmiarProstokata.y) {
		dy = -dy;
	}
	//narozniki
	if (((pozycjaPilki.x <= pozycjaProstokata.x + rozmiarProstokata.x && pozycjaPilki.x + promien > pozycjaProstokata.x + rozmiarProstokata.x && dx < 0) || (pozycjaPilki.x + 2 * promien >= pozycjaProstokata.x && pozycjaPilki.x + promien < pozycjaProstokata.x && dx > 0)) && pozycjaPilki.y + promien <= pozycjaProstokata.y && pozycjaPilki.y + 2 * promien > pozycjaProstokata.y) {
		dx = -dx;
		dy = -dy;
	};
	if (((pozycjaPilki.x <= pozycjaProstokata.x + rozmiarProstokata.x && pozycjaPilki.x + promien > pozycjaProstokata.x + rozmiarProstokata.x && dx < 0) || (pozycjaPilki.x + 2 * promien >= pozycjaProstokata.x && pozycjaPilki.x + promien < pozycjaProstokata.x && dx > 0)) && pozycjaPilki.y + promien <= pozycjaProstokata.y && pozycjaPilki.y + 2 * promien > pozycjaProstokata.y) {
		dx = -dx;
		dy = -dy;
	};
}
void Prostokat::ustaw_teksture(const sf::Texture& tekstura) { prostokat.setTexture(&tekstura); }
void Prostokat::zmien_rozmiar(float szer, float dlug) { prostokat.setSize(sf::Vector2f(szer, dlug)); }