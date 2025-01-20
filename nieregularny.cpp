#include "nieregularny.hpp"
#include "pilka.hpp"
Nieregularny::Nieregularny(float x_in, float y_in) {

	nieregularny.setPointCount(10);

	nieregularny.setPoint(0, sf::Vector2f(0.f, 0.f));
	nieregularny.setPoint(1, sf::Vector2f(45.f, 0.f));
	nieregularny.setPoint(2, sf::Vector2f(30.f, 15.f));
	nieregularny.setPoint(3, sf::Vector2f(37.5f, 22.5f));
	nieregularny.setPoint(4, sf::Vector2f(37.5f, 52.5f));
	nieregularny.setPoint(5, sf::Vector2f(30.f, 60.f));
	nieregularny.setPoint(6, sf::Vector2f(15.f, 60.f));
	nieregularny.setPoint(7, sf::Vector2f(7.4f, 52.5f));
	nieregularny.setPoint(8, sf::Vector2f(7.5f, 22.5f));
	nieregularny.setPoint(9, sf::Vector2f(15.f, 15.f));

	//nieregularny.setPosition(x_in, y_in);

	nieregularny.setFillColor(sf::Color::Green);
	nieregularny.setScale(1.2, 1.1);
}

void Nieregularny::spadanie() {
	sf::Vector2f pos;
	pos.x = 0;
	pos.y = 1.5;
	nieregularny.move(pos);
	if (getPos().y >= 800) { 
		czy_spadl = true; 
	}
};

void Nieregularny::generuj(pilka& p1) {
		int x = rand() % static_cast<int>(p1.getPos().x);
		nieregularny.setPosition(x, 0);
		czy_spadl = false;
}
void Nieregularny::zmienPos(float x, float y) { nieregularny.setPosition(x, y); }