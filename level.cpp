#include "level.hpp"

#ifndef LEVEL_HPP
#define LEVEL_HPP

Level::Level(sf::Font& font, sf::RenderWindow& window, sf::Keyboard::Key M, sf::Keyboard::Key Escape, sf::Clock& zegar,
	sf::Keyboard::Key F1, sf::Keyboard::Key A, sf::Keyboard::Key D, Prostokat& paletka, float& predkosc_paletki,
	float& dx, float& dy, sf::Clock& stoper_pauza, Napis& pomoc_napis, Napis& odliczanie, pilka& p1,
	Prostokat& przeszkoda, Napis& punkty_tekst, int& punkty, sf::Time& stoper_pauza_elapsed,
	bool& czy_level, Nieregularny& bomba, Prostokat& serce1, Prostokat& serce2, Prostokat& serce3, Gracz& gracz,
	std::vector<std::vector<Blok>>& rzad, sf::Clock& stoper, int& ktory_level, sf::Texture& tekstura_bloku,
	sf::Time& stoper_elapsed, sf::Texture& serce_czerwone, sf::Texture& serce_szare, sf::Event& event)
	: font(font), window(window), M(M), Escape(Escape), zegar(zegar), F1(F1), A(A), D(D),
	paletka(paletka), predkosc_paletki(predkosc_paletki), dx(dx), dy(dy), stoper_pauza(stoper_pauza),
	pomoc_napis(pomoc_napis), odliczanie(odliczanie), p1(p1), przeszkoda(przeszkoda), punkty_tekst(punkty_tekst),
	punkty(punkty), stoper_pauza_elapsed(stoper_pauza_elapsed), czy_level(czy_level), bomba(bomba),
	serce1(serce1), serce2(serce2), serce3(serce3), gracz(gracz), rzad(rzad), stoper(stoper),
	ktory_level(ktory_level), tekstura_bloku(tekstura_bloku), stoper_elapsed(stoper_elapsed),
	serce_czerwone(serce_czerwone), serce_szare(serce_szare), event(event) {}

void Level::napis() {
	int liczba = 0;
	std::string tekst = std::to_string(gracz.punkty);
	std::string punkty = "Punkty: ";
	punkty += tekst;
	punkty_tekst.zmienTekst(punkty);
}

void Level::f_czas() {

	stoper_elapsed = stoper.getElapsedTime() - stoper_pauza_elapsed;
	std::string sekundy = std::to_string(stoper_elapsed.asMilliseconds() / 1000);
	std::string milisekundy = std::to_string(stoper_elapsed.asMilliseconds() / 100 % 10);
	std::cout << stoper_elapsed.asSeconds() << std::endl;
	Napis czas_wyswietl("  Czas: " + sekundy + "." + milisekundy, 165, 755, 40, sf::Color::White, font, sf::Text::Regular);
	window.draw(czas_wyswietl.getNapis());
};

void Level::pomoc() {

	pomoc_napis.ustaw_na_srodku(window);

	stoper_pauza.restart();
	window.clear();
	window.draw(pomoc_napis.getNapis());
	window.display();
	while (!sf::Keyboard::isKeyPressed(Escape)) {
		zegar.restart();
	}
	if (czy_level == true) {

		if (dx != 0 && dy != 0) {
			for (int i = 3; i > 0; --i) {
				std::string liczba = std::to_string(i);
				odliczanie.zmienTekst(liczba);
				window.clear();
				window.draw(serce1.getProstokat());
				window.draw(serce2.getProstokat());
				window.draw(serce3.getProstokat());
				window.draw(bomba.getNiereg());
				rysujBloki(window, rzad);
				window.draw(paletka.getProstokat());
				window.draw(p1.getPilka());
				window.draw(przeszkoda.getProstokat());
				napis();
				window.draw(odliczanie.getNapis());
				window.display();
				while (zegar.getElapsedTime().asSeconds() < 1) {
				};

				zegar.restart();
			}
			stoper_pauza_elapsed += stoper_pauza.getElapsedTime();
		}
	}
}

void Level::mechanika() {
	if (zegar.getElapsedTime().asMilliseconds() > 1.0f) {

		p1.odbij(p1, window, dx, dy);
		p1.przesun(dx, dy);
		odbijanieBloki(p1, dx, dy, 0.f, punkty, rzad, gracz);
		paletka.odbijProstokat(p1, paletka, dx, dy);
		przeszkoda.odbijProstokat(p1, przeszkoda, dx, dy);
		if (bomba.czySpadl() == true) bomba.generuj(p1);
		if (bomba.czySpadl() == false) bomba.spadanie();
		zegar.restart();
	}
}

void Level::poruszanie() {
	if (sf::Keyboard::isKeyPressed(D) && paletka.getPos().x <= window.getSize().x - 150) {
		paletka.przesun(predkosc_paletki);
	}
	if (sf::Keyboard::isKeyPressed(A) && paletka.getPos().x >= 0) {
		paletka.przesun(-predkosc_paletki);
	}
}

void Level::zapisz() {

	std::ofstream zapis("stan_gry.txt");

	if (zapis) {
		zapis << "Level " << ktory_level << "\n";
		zapis << "Pilka " << p1.getPos().x << " " << p1.getPos().y << " "
			<< dx << " " << dy << "\n";
		zapis << "Paletka " << paletka.getPos().x << " " << paletka.getPos().y << "\n";
		zapis << "Zycia " << gracz.zycia << "\n";
		zapis << "Punkty " << punkty << "\n";
		zapis << "Czas " << stoper.getElapsedTime().asMilliseconds() << "\n";

		for (size_t i = 0; i < rzad.size(); ++i) {
			for (size_t j = 0; j < rzad[i].size(); ++j) {
				const auto& blok = rzad[i][j];
				zapis << "Bloki "
					<< blok.getPos().x << " "
					<< blok.getPos().y << " "
					<< blok.zniszczony << "\n";
			}
		}
		zapis.close();
	}
}

void Level::odczyt() {
	std::ifstream odczyt("stan_gry.txt");

	if (odczyt) {
		std::string label;
		odczyt >> label >> ktory_level;

		float pilka_x, pilka_y;
		odczyt >> label >> pilka_x >> pilka_y >> dx >> dy;
		p1.zmienPos(pilka_x, pilka_y);

		float paletka_x, paletka_y;
		odczyt >> label >> paletka_x >> paletka_y;
		paletka.zmienPos(paletka_x, paletka_y);

		odczyt >> label >> gracz.zycia;
		odczyt >> label >> punkty;

		int czas;
		odczyt >> label >> czas;
		stoper.restart();
		stoper_elapsed -= sf::milliseconds(czas);

		rzad.clear();
		std::vector<Blok> temp_blocks;
		while (odczyt >> label) {
			if (label == "Bloki") {
				float blok_x, blok_y;
				bool zniszczony;
				odczyt >> blok_x >> blok_y >> zniszczony;
				temp_blocks.push_back(Blok(blok_x, blok_y, zniszczony, tekstura_bloku));
			}
		}


		int blocks_per_row = 10;
		int num_rows = (temp_blocks.size() + blocks_per_row - 1) / blocks_per_row;

		rzad.resize(num_rows);
		for (int i = 0; i < temp_blocks.size(); ++i) {
			int row = i / blocks_per_row;
			rzad[row].push_back(temp_blocks[i]);
		}
	}
}

void Level::wyjscie() {
	Napis wyjscie_napis(" Czy na pewno chcesz wyjsc? ", 300, 200, 50, sf::Color::White, font, sf::Text::Regular);
	wyjscie_napis.ustaw_na_srodku(window);
	window.display();
	while (!sf::Keyboard::isKeyPressed(Escape)) {
		zegar.restart();
	}
	if (sf::Keyboard::isKeyPressed(Escape) == sf::Keyboard::Escape) {
		if (sf::Keyboard::isKeyPressed(Escape) == sf::Keyboard::Enter) {
			window.close();
		}
	};
}

void Level::resetuj_level() {
	window.clear();


	if (ktory_level == 1) przeszkoda.zmienPos(1500, 3500);
	if (ktory_level == 2) przeszkoda.zmienPos(150, 350);

	paletka.zmienPos(400, 735);
	p1.zmienPos(480, 380);
	bomba.zmienPos(0, 0);

	stoper_elapsed = sf::Time::Zero;

	gracz.punkty = 0;
	gracz.zycia = 3;


	for (auto& kolumna : rzad) {
		for (auto it = kolumna.begin(); it != kolumna.end(); ) {
			it->zniszczony = false;
			++it;
		}
	}
	zycia();
	gra();
}

void Level::menu() {
	Napis menu_napis_level(" Wybierz level ", 300, 200, 50, sf::Color::White, font, sf::Text::Regular);
	menu_napis_level.ustaw_na_srodku(window);
	Napis menu_napis_zapisz("", 300, +menu_napis_level.getBounds().top + 50, 50, sf::Color::White, font, sf::Text::Regular);
	if (czy_level) {
		menu_napis_zapisz.zmienTekst("Zapisz gre");
	}
	else menu_napis_zapisz.zmienTekst("Wczytaj gre");
	menu_napis_zapisz.ustaw_na_srodku(window);
	Napis menu_napis_pomoc(" Pomoc ", 300, menu_napis_zapisz.getBounds().top + 50, 50, sf::Color::White, font, sf::Text::Regular);
	menu_napis_pomoc.ustaw_na_srodku(window);
	Napis menu_napis_wyjscie(" Wyjscie ", 300, menu_napis_pomoc.getBounds().top + 50, 50, sf::Color::White, font, sf::Text::Regular);
	menu_napis_wyjscie.ustaw_na_srodku(window);

	Napis menu_napis_level_1(" Level 1 ", 300, 200, 50, sf::Color::White, font, sf::Text::Regular);
	menu_napis_level_1.ustaw_na_srodku(window);
	Napis menu_napis_level_2(" Level 2 ", 300, +menu_napis_level_1.getBounds().top + 50, 50, sf::Color::White, font, sf::Text::Regular);
	menu_napis_level_2.ustaw_na_srodku(window);


	int menu_wybrane = 0;
	int level_wybrane = 1;

	if (sf::Keyboard::isKeyPressed(M)) {
		while (!sf::Keyboard::isKeyPressed(Escape)) {
			window.clear();
			window.draw(menu_napis_level.getNapis());
			window.draw(menu_napis_zapisz.getNapis());
			window.draw(menu_napis_pomoc.getNapis());
			window.draw(menu_napis_wyjscie.getNapis());

			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::KeyReleased) {

					if (event.key.code == sf::Keyboard::Down && menu_wybrane < 3) {
						menu_wybrane++;
					}

					if (event.key.code == sf::Keyboard::Up && menu_wybrane > 0) {
						menu_wybrane--;
					}
				}
			}

			if (menu_wybrane == 0) {
				bool wybrano = false;
				menu_napis_level.obwodka(window, 2, sf::Color::White);
				if (event.key.code == sf::Keyboard::Enter) {
					while (!wybrano && !sf::Keyboard::isKeyPressed(Escape)) {
						sf::Event levelEvent;
						window.clear();

						if (level_wybrane == 1) {
							menu_napis_level_1.obwodka(window, 2, sf::Color::White);
							menu_napis_level_2.obwodka(window, 0, sf::Color::White);
						}
						else if (level_wybrane == 2) {
							menu_napis_level_1.obwodka(window, 0, sf::Color::White);
							menu_napis_level_2.obwodka(window, 2, sf::Color::White);
						}

						window.draw(menu_napis_level_1.getNapis());
						window.draw(menu_napis_level_2.getNapis());
						window.display();

						while (window.pollEvent(levelEvent)) {
							if (levelEvent.type == sf::Event::KeyReleased) {
								if (levelEvent.key.code == sf::Keyboard::Down && level_wybrane == 1) {
									level_wybrane = 2;
								}
								if (levelEvent.key.code == sf::Keyboard::Up && level_wybrane == 2) {
									level_wybrane = 1;
								}
								if (levelEvent.key.code == sf::Keyboard::Enter) {
									resetuj_level();
									ktory_level = level_wybrane;
									czy_level = true;
									wybrano = true;
									gra();
									return;
								}
							}
						}
					}
				}
			}
			else {
				menu_napis_level.obwodka(window, 0, sf::Color::White);
			}

			if (menu_wybrane == 1) {
				menu_napis_zapisz.obwodka(window, 2, sf::Color::White);
				if (event.key.code == sf::Keyboard::Enter) {
					if (czy_level) {
						zapisz();
					}
					if (!czy_level) {
						odczyt();
						window.clear();
						czy_level = true;
						return;
					}
				};
			}
			else {
				menu_napis_zapisz.obwodka(window, 0, sf::Color::White);
			}

			if (menu_wybrane == 2) {
				menu_napis_pomoc.obwodka(window, 2, sf::Color::White);

				if (event.key.code == sf::Keyboard::Enter) {
					window.clear();
					pomoc();
				};
			}
			else {
				menu_napis_pomoc.obwodka(window, 0, sf::Color::White);
			}

			if (menu_wybrane == 3) {
				menu_napis_wyjscie.obwodka(window, 2, sf::Color::White);
				if (event.key.code == sf::Keyboard::Enter) {
					window.clear();
					Napis wyjscie_napis(" Czy na pewno chcesz wyjsc? ", 300, 200, 50, sf::Color::White, font, sf::Text::Regular);
					wyjscie_napis.ustaw_na_srodku(window);
					window.draw(wyjscie_napis.getNapis());
					window.display();
					bool wyjdz = false;
					while (!wyjdz) {
						while (window.pollEvent(event)) {
							if (event.type == sf::Event::KeyPressed) {
								if (event.key.code == sf::Keyboard::Enter) {
									window.close();
									wyjdz = true;
								}
								else if (event.key.code == sf::Keyboard::Escape) {
									wyjdz = true;
								}
								menu();
							}
						}
					}

				};
			}
			else {
				menu_napis_wyjscie.obwodka(window, 0, sf::Color::White);
			}
			window.display();
		}
	}
}

void Level::zycia() {

	if (bomba.getPos().x < paletka.getPos().x + 150 && bomba.getPos().x + bomba.getSize().width > paletka.getPos().x && bomba.getPos().y + bomba.getSize().height == paletka.getPos().y) {
		gracz.zycia-=0.25f;
		std::cout << "1" << std::endl;
	}
	if (gracz.zycia == 2) serce3.ustaw_teksture(serce_szare);
	if (gracz.zycia == 1) serce2.ustaw_teksture(serce_szare);
	if (gracz.zycia == 0) { p1.przegrana = true; serce1.ustaw_teksture(serce_szare); };
	if (gracz.zycia == 3) {
		serce1.ustaw_teksture(serce_czerwone);
		serce2.ustaw_teksture(serce_czerwone);
		serce3.ustaw_teksture(serce_czerwone);
	}
}

void Level::rysuj_wszystko() {
	window.clear();
	window.draw(bomba.getNiereg());
	window.draw(serce1.getProstokat());
	window.draw(serce2.getProstokat());
	window.draw(serce3.getProstokat());
	rysujBloki(window, rzad);
	window.draw(p1.getPilka());
	napis();
	window.draw(punkty_tekst.getNapis());
	window.draw(paletka.getProstokat());
	window.draw(przeszkoda.getProstokat());
	f_czas();
	window.display();

}

void Level::gra() {
	while (window.isOpen()) {

		sf::Event event;

		if (ktory_level == 1) przeszkoda.zmienPos(1500, 3500);
		if (ktory_level == 2) przeszkoda.zmienPos(150, 350);

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		poruszanie();
		if (event.key.code == sf::Keyboard::F1) pomoc();
		mechanika();
		menu();
		zycia();
		rysuj_wszystko();
	}
}

#endif