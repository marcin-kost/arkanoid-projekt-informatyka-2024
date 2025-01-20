#define _CRT_SECURE_NO_DEPRECATE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include "paletka.hpp"
#include "pilka.hpp"
#include "blok.hpp"
#include "napis.hpp"
#include "nieregularny.hpp"
#include "gracz.hpp"
#include <fstream>
#include "level.hpp"

int main() {
	srand(time(NULL));

	float predkosc_paletki = 0.6f;

	sf::Font font;
	if (!font.loadFromFile("ByteBounce.ttf"))
	{
		std::cout << "font error";
	}

	Napis pomoc_napis("Pomoc:\nA - w lewo\nD - w prawo\nEsc - powrot", 300, 200, 50, sf::Color::White, font, sf::Text::Regular);

	Napis odliczanie(" ", 500, 400, 90, sf::Color::Red, font, sf::Text::Regular);

	Napis punkty_tekst(" ", 5, 755, 40, sf::Color::White, font, sf::Text::Regular);


	sf::Texture tekstura_bloku;
	tekstura_bloku.loadFromFile("blok_caly.jpg", sf::IntRect(0, 0, 100, 50));

	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
	Prostokat paletka(450, 735, 150, 20);
	Prostokat przeszkoda(150, 350, 700, 20);

	Prostokat serce1(940, 745, 60, 60);
	Prostokat serce2(serce1.getPos().x - 45, 745, 60, 60);
	Prostokat serce3(serce2.getPos().x - 45, 745, 60, 60);
	sf::Texture serce_czerwone;
	serce_czerwone.loadFromFile("serce.png", sf::IntRect(0, 0, 400, 400));
	sf::Texture serce_szare;
	serce_szare.loadFromFile("serce_szare.png", sf::IntRect(0, 0, 400, 400));
	serce1.ustaw_teksture(serce_czerwone);
	serce2.ustaw_teksture(serce_czerwone);
	serce3.ustaw_teksture(serce_czerwone);

	pilka p1(480, 380, 20);
	Nieregularny bomba(0, 0);
	int x = 0, y = 0;
	float dx = 0.5f, dy = -0.5f;
	int punkty;
	bool czy_level = false;
	int ktory_level = 0;
	punkty = 0;
	
	std::vector<std::vector<Blok>> rzad;
	utworzSiatkeBlokow(0.0f, 0.0f, 5, 10, 100.0f, 50.0f, tekstura_bloku, rzad);

	Gracz gracz("", 0, punkty);
	Gracz lista_graczy[10];

	sf::Clock zegar;
	sf::Clock stoper;
	sf::Clock stoper_pauza;
	sf::Time stoper_elapsed = sf::Time::Zero;
	sf::Time stoper_pauza_elapsed = sf::Time::Zero;
	
	sf::Event event;

	Level level(font, window, sf::Keyboard::Key::M, sf::Keyboard::Key::Escape, zegar,
		sf::Keyboard::Key::F1, sf::Keyboard::Key::A, sf::Keyboard::Key::D, paletka, predkosc_paletki,
		dx, dy, stoper_pauza, pomoc_napis, odliczanie, p1, przeszkoda, punkty_tekst, punkty,
		stoper_pauza_elapsed, czy_level, bomba, serce1, serce2, serce3, gracz, rzad, zegar,
		ktory_level, tekstura_bloku, stoper_elapsed, serce_czerwone, serce_szare, event);

		while (window.isOpen()) {
			if (!czy_level) {

				level.menu();
			}
			if (czy_level) level.gra();
		}
	return 0;
}
