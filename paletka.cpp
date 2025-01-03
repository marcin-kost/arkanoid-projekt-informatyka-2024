#include "paletka.hpp"

Paletka::Paletka(float x_in, float y_in) {
	paddle.setSize(sf::Vector2f(150, 20));
	paddle.setFillColor(sf::Color::White);
	paddle.setPosition(x_in, y_in);
}

void Paletka::przesun(float x_in) {
	paddle.move(x_in, 0);
}
void odbijPaletka(pilka& p1, Paletka& pad, float& dx, float& dy) {
	sf::Vector2f pozycjaPilki = p1.getPos();
	sf::Vector2f pozycjaPaletki = pad.getPos();
	float promien = p1.getPromien();

	if (pozycjaPilki.x + promien >= pozycjaPaletki.x && pozycjaPilki.x + promien <= pozycjaPaletki.x + 150 && pozycjaPilki.y + 2*promien >= pozycjaPaletki.y) {
		dy = -dy;
	}
	if ((pozycjaPilki.x == pozycjaPaletki.x + 150 || pozycjaPilki.x + 2*promien == pozycjaPaletki.x) && pozycjaPilki.y + promien >= pozycjaPaletki.y && pozycjaPilki.y + promien <= pozycjaPaletki.y + 20) dx = -dx;

}

