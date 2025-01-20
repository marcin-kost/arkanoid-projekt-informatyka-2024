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

//void napis(sf::Text tekst_liczba, int liczba, sf::RenderWindow& window) {
//	std::string tekst = std::to_string(liczba);
//	std::string punkty = "Punkty: ";
//	punkty += tekst;
//	tekst_liczba.setString(punkty);
//	window.draw(tekst_liczba);
//}
//
//void f_czas(sf::RenderWindow& window, pilka p1, sf::Clock stoper, sf::Font font, bool przegrana, sf::Time& stoper_elapsed, sf::Time stoper_pauza_elapsed) {
//
//	if (!p1.przegrana) stoper_elapsed = stoper.getElapsedTime() - stoper_pauza_elapsed;
//	std::string sekundy = std::to_string(stoper_elapsed.asMilliseconds() / 1000);
//	std::string milisekundy = std::to_string(stoper_elapsed.asMilliseconds() / 100 % 10);
//	Napis czas_wyswietl("  Czas: " + sekundy + "." + milisekundy, 165, 755, 40, sf::Color::White, font, sf::Text::Regular);
//	window.draw(czas_wyswietl.getNapis());
//};
//
//void pomoc(sf::Keyboard::Key F1, sf::Keyboard::Key Escape, Prostokat& paletka, float predkosc_paletki, float dx, float dy, sf::RenderWindow& window, sf::Clock stoper_pauza, Napis pomoc_napis, sf::Clock zegar, Napis odliczanie, pilka p1, Prostokat przeszkoda, Napis punkty_tekst, int& punkty, sf::Time stoper_pauza_elapsed, bool czy_level, Nieregularny bomba, Prostokat serce1, Prostokat serce2, Prostokat serce3, std::vector<std::vector<Blok>>& rzad) {
//
//	pomoc_napis.ustaw_na_srodku(window);
//
//	stoper_pauza.restart();
//	window.clear();
//	window.draw(pomoc_napis.getNapis());
//	window.display();
//	while (!sf::Keyboard::isKeyPressed(Escape)) {
//		zegar.restart();
//	}
//	if (czy_level == true) {
//
//		if (dx != 0 && dy != 0) {
//			for (int i = 3; i > 0; --i) {
//				std::string liczba = std::to_string(i);
//				odliczanie.zmienTekst(liczba);
//				window.clear();
//				window.draw(serce1.getProstokat());
//				window.draw(serce2.getProstokat());
//				window.draw(serce3.getProstokat());
//				window.draw(bomba.getNiereg());
//				rysujBloki(window, rzad);
//				window.draw(paletka.getProstokat());
//				window.draw(p1.getPilka());
//				window.draw(przeszkoda.getProstokat());
//				napis(punkty_tekst.getNapis(), punkty, window);
//				window.draw(odliczanie.getNapis());
//				window.display();
//				while (zegar.getElapsedTime().asSeconds() < 1) {
//				};
//
//				zegar.restart();
//			}
//			stoper_pauza_elapsed += stoper_pauza.getElapsedTime();
//		}
//	}
//}
//
//void mechanika(sf::Clock& zegar, pilka& p1, Prostokat& paletka, Prostokat& przeszkoda, sf::RenderWindow& window, float& dx, float& dy, int& punkty, Nieregularny& bomba, std::vector<std::vector<Blok>>& rzad) {
//	if (zegar.getElapsedTime().asMilliseconds() > 1.0f) {
//
//		p1.odbij(p1, window, dx, dy);
//		p1.przesun(dx, dy);
//		odbijanieBloki(p1, dx, dy, 0.f, punkty, rzad);
//		paletka.odbijProstokat(p1, paletka, dx, dy);
//		przeszkoda.odbijProstokat(p1, przeszkoda, dx, dy);
//		if (bomba.czySpadl() == true) bomba.generuj(p1);
//		if (bomba.czySpadl() == false) bomba.spadanie();
//		zegar.restart();
//	}
//}
//
//void poruszanie(sf::Keyboard::Key D, sf::Keyboard::Key A, sf::Keyboard::Key F1, Prostokat& paletka, float predkosc_paletki, sf::RenderWindow& window) {
//	if (sf::Keyboard::isKeyPressed(D) && paletka.getPos().x <= window.getSize().x - 150) {
//		paletka.przesun(predkosc_paletki);
//	}
//	if (sf::Keyboard::isKeyPressed(A) && paletka.getPos().x >= 0) {
//		paletka.przesun(-predkosc_paletki);
//	}
//}
//
//void zapisz(float& dx, float& dy, pilka& p1, Prostokat& paletka, Nieregularny& bomba, int& punkty, sf::Clock& stoper, std::vector<std::vector<Blok>>& rzad, Gracz& gracz, int& ktory_level) {
//
//	std::ofstream zapis("stan_gry.txt");
//
//	if (zapis) {
//		zapis << "Level " << ktory_level << "\n";
//		zapis << "Pilka " << p1.getPos().x << " " << p1.getPos().y << " "
//			<< dx << " " << dy << "\n";
//		zapis << "Paletka " << paletka.getPos().x << " " << paletka.getPos().y << "\n";
//		zapis << "Zycia " << gracz.zycia << "\n";
//		zapis << "Punkty " << punkty << "\n";
//		zapis << "Czas " << stoper.getElapsedTime().asMilliseconds() << "\n";
//
//		for (size_t i = 0; i < rzad.size(); ++i) {
//			for (size_t j = 0; j < rzad[i].size(); ++j) {
//				const auto& blok = rzad[i][j];
//				zapis << "Bloki "
//					<< blok.getPos().x << " "
//					<< blok.getPos().y << " "
//					<< blok.zniszczony << "\n";
//			}
//		}
//		zapis.close();
//	}
//}
//
//void odczyt(float& dx, float& dy, pilka& p1, Prostokat& paletka, Nieregularny& bomba, int& punkty, sf::Clock& stoper, std::vector<std::vector<Blok>>& rzad, Gracz& gracz, int& ktory_level, sf::Texture tekstura_bloku, sf::Time stoper_elapsed) {
//	std::ifstream odczyt("stan_gry.txt");
//
//	if (odczyt) {
//		std::string label;
//		odczyt >> label >> ktory_level; 
//
//		float pilka_x, pilka_y;
//		odczyt >> label >> pilka_x >> pilka_y >> dx >> dy;
//		p1.zmienPos(pilka_x, pilka_y);
//
//		float paletka_x, paletka_y;
//		odczyt >> label >> paletka_x >> paletka_y; 
//		paletka.zmienPos(paletka_x, paletka_y);
//
//		odczyt >> label >> gracz.zycia; 
//		odczyt >> label >> punkty;      
//
//		int czas;
//		odczyt >> label >> czas;       
//		stoper.restart();
//		stoper_elapsed -= sf::milliseconds(czas); 
//
//		rzad.clear();
//		std::vector<Blok> temp_blocks;
//		while (odczyt >> label) {
//			if (label == "Bloki") {
//				float blok_x, blok_y;
//				bool zniszczony;
//				odczyt >> blok_x >> blok_y >> zniszczony;
//				temp_blocks.push_back(Blok(blok_x, blok_y, zniszczony, tekstura_bloku));
//			}
//		}
//
//		
//		int blocks_per_row = 10; 
//		int num_rows = (temp_blocks.size() + blocks_per_row - 1) / blocks_per_row;
//
//		rzad.resize(num_rows);
//		for (int i = 0; i < temp_blocks.size(); ++i) {
//			int row = i / blocks_per_row;
//			rzad[row].push_back(temp_blocks[i]);
//		}
//	}
//}
//
//
//void wyjscie(sf::Keyboard::Key(Escape), sf::RenderWindow& window, sf::Font font, sf::Clock zegar) {
//	Napis wyjscie_napis(" Czy na pewno chcesz wyjsc? ", 300, 200, 50, sf::Color::White, font, sf::Text::Regular);
//	wyjscie_napis.ustaw_na_srodku(window);
//	window.display();
//	while (!sf::Keyboard::isKeyPressed(Escape)) {
//		zegar.restart();
//	}
//	if (sf::Keyboard::isKeyPressed(Escape) == sf::Keyboard::Escape) {
//		if (sf::Keyboard::isKeyPressed(Escape) == sf::Keyboard::Enter) {
//			window.close();
//		}
//	};
//}
//
//void resetuj_level(Prostokat& paletka, float& predkosc_paletki, float& dx, float& dy, sf::RenderWindow& window, sf::Clock& stoper_pauza, Napis& pomoc_napis, sf::Clock& zegar, Napis& odliczanie, pilka& p1, Prostokat& przeszkoda, Napis& punkty_tekst, int& punkty, sf::Time& stoper_pauza_elapsed, bool& czy_level, Nieregularny& bomba, Prostokat& serce1, Prostokat& serce2, Prostokat& serce3, Gracz& gracz, sf::Clock& stoper, sf::Time& stoper_elapsed, std::vector<std::vector<Blok>>& rzad, int& ktory_level, sf::Texture& tekstura_bloku, sf::Texture& serce_czerwone) {
//	window.clear();
//
//	// Resetowanie pozycji paletki
//	paletka.zmienPos(400, 735);
//
//	// Resetowanie pozycji przeszkody w zale¿noœci od poziomu
//	if (ktory_level == 1) przeszkoda.zmienPos(1500, 3500);
//	if (ktory_level == 2) przeszkoda.zmienPos(150, 350);
//
//	// Resetowanie pozycji pi³ki
//	p1.zmienPos(480, 380);
//
//	// Resetowanie stoperów
//	stoper_elapsed = sf::Time::Zero;
//
//	// Resetowanie punktów i ¿ycia
//	punkty = 0;
//	gracz.zycia = 3;
//
//	// Resetowanie bomby
//	bomba.zmienPos(0, 0);
//
//	// Resetowanie bloków
//	for (auto& kolumna : rzad) {
//		for (auto it = kolumna.begin(); it != kolumna.end(); ) {
//			it->zniszczony = false;
//			++it;
//		}
//	}
//}
//
//
//void menu(sf::Font font, sf::RenderWindow& window, sf::Keyboard::Key M, sf::Keyboard::Key Escape, sf::Clock zegar,
//	sf::Keyboard::Key F1, sf::Keyboard::Key A, Prostokat& paletka, float predkosc_paletki, float dx, float dy,
//	sf::Clock stoper_pauza, Napis pomoc_napis, Napis odliczanie, pilka p1, Prostokat przeszkoda,
//	Napis punkty_tekst, int& punkty, sf::Time stoper_pauza_elapsed, bool czy_level, Nieregularny& bomba, Prostokat serce1, Prostokat serce2, Prostokat serce3, Gracz gracz, std::vector<std::vector<Blok>>& rzad, sf::Clock& stoper, int& ktory_level, sf::Texture tekstura_bloku, sf::Time stoper_elapsed, sf::Texture& serce_czerwone, sf::Texture& serce_szare) {
//	Napis menu_napis_level(" Wybierz level ", 300, 200, 50, sf::Color::White, font, sf::Text::Regular);
//	menu_napis_level.ustaw_na_srodku(window);
//	Napis menu_napis_zapisz("", 300, +menu_napis_level.getBounds().top + 50, 50, sf::Color::White, font, sf::Text::Regular);
//	if (czy_level) {
//		menu_napis_zapisz.zmienTekst("Zapisz gre");
//	}
//	else menu_napis_zapisz.zmienTekst("Wczytaj gre");
//	menu_napis_zapisz.ustaw_na_srodku(window);
//	Napis menu_napis_pomoc(" Pomoc ", 300, menu_napis_zapisz.getBounds().top + 50, 50, sf::Color::White, font, sf::Text::Regular);
//	menu_napis_pomoc.ustaw_na_srodku(window);
//	Napis menu_napis_wyjscie(" Wyjscie ", 300, menu_napis_pomoc.getBounds().top + 50, 50, sf::Color::White, font, sf::Text::Regular);
//	menu_napis_wyjscie.ustaw_na_srodku(window);
//
//	Napis menu_napis_level_1(" Level 1 ", 300, 200, 50, sf::Color::White, font, sf::Text::Regular);
//	menu_napis_level_1.ustaw_na_srodku(window);
//	Napis menu_napis_level_2(" Level 2 ", 300, +menu_napis_level_1.getBounds().top + 50, 50, sf::Color::White, font, sf::Text::Regular);
//	menu_napis_level_2.ustaw_na_srodku(window);
//	
//
//	int menu_wybrane = 0;
//	int level_wybrane = 1;
//
//	if (sf::Keyboard::isKeyPressed(M)) {
//		while (!sf::Keyboard::isKeyPressed(Escape)) {
//			window.clear();
//			window.draw(menu_napis_level.getNapis());
//			window.draw(menu_napis_zapisz.getNapis());
//			window.draw(menu_napis_pomoc.getNapis());
//			window.draw(menu_napis_wyjscie.getNapis());
//
//			sf::Event event; 
//			while (window.pollEvent(event)) {
//				if (event.type == sf::Event::KeyReleased) {
//					
//					if (event.key.code == sf::Keyboard::Down && menu_wybrane < 3) {
//						menu_wybrane++;
//					}
//					
//					if (event.key.code == sf::Keyboard::Up && menu_wybrane > 0) {
//						menu_wybrane--;
//					}
//				}
//			}
//
//			if (menu_wybrane == 0) {
//				bool wybrano = false;
//				menu_napis_level.obwodka(window, 2, sf::Color::White);
//				if (event.key.code == sf::Keyboard::Enter) {
//					while (!wybrano && !sf::Keyboard::isKeyPressed(Escape)) {  // Modified condition
//						sf::Event levelEvent;
//						window.clear();
//
//						// Update visual state before drawing
//						if (level_wybrane == 1) {
//							menu_napis_level_1.obwodka(window, 2, sf::Color::White);
//							menu_napis_level_2.obwodka(window, 0, sf::Color::White);
//						}
//						else if (level_wybrane == 2) {
//							menu_napis_level_1.obwodka(window, 0, sf::Color::White);
//							menu_napis_level_2.obwodka(window, 2, sf::Color::White);
//						}
//
//						// Draw the level options
//						window.draw(menu_napis_level_1.getNapis());
//						window.draw(menu_napis_level_2.getNapis());
//						window.display();
//
//						// Handle events
//						while (window.pollEvent(levelEvent)) {
//							if (levelEvent.type == sf::Event::KeyReleased) {
//								// Handle navigation
//								if (levelEvent.key.code == sf::Keyboard::Down && level_wybrane == 1) {
//									level_wybrane = 2;
//								}
//								if (levelEvent.key.code == sf::Keyboard::Up && level_wybrane == 2) {
//									level_wybrane = 1;
//								}
//								// Handle selection
//								if (levelEvent.key.code == sf::Keyboard::Enter) {
//								 resetuj_level(paletka, predkosc_paletki, dx, dy, window, stoper_pauza, pomoc_napis, zegar, odliczanie,
//									 p1, przeszkoda, punkty_tekst, punkty, stoper_pauza_elapsed, czy_level, bomba,
//									 serce1, serce2, serce3, gracz, stoper, stoper_elapsed, rzad, ktory_level,
//									 tekstura_bloku, serce_czerwone);
//									ktory_level = level_wybrane;
//									czy_level = true;
//									wybrano = true;
//									return;
//								}
//							}
//						}
//					}
//				}
//			}
//			else {
//				menu_napis_level.obwodka(window, 0, sf::Color::White);
//			}
//
//			if (menu_wybrane == 1) {
//				menu_napis_zapisz.obwodka(window, 2, sf::Color::White);
//				if (event.key.code == sf::Keyboard::Enter) {
//					if (czy_level) {
//						zapisz(dx, dy, p1, paletka, bomba, punkty, stoper, rzad, gracz, ktory_level);
//					}
//					if(!czy_level) {
//						odczyt(dx, dy, p1, paletka, bomba, punkty, stoper, rzad, gracz, ktory_level, tekstura_bloku, stoper_elapsed); 
//					window.clear();
//					czy_level = true;
//					return;
//					}
//				};
//			}
//			else {
//				menu_napis_zapisz.obwodka(window, 0, sf::Color::White);
//			}
//
//			if (menu_wybrane == 2) {
//				menu_napis_pomoc.obwodka(window, 2, sf::Color::White);
//
//				if (event.key.code == sf::Keyboard::Enter) {
//					window.clear();
//					pomoc(F1, Escape, paletka, predkosc_paletki, dx, dy, window, stoper_pauza, pomoc_napis, zegar, odliczanie, p1, przeszkoda, punkty_tekst, punkty, stoper_pauza_elapsed, czy_level, bomba, serce1, serce2, serce3, rzad);
//				};
//			}
//			else {
//				menu_napis_pomoc.obwodka(window, 0, sf::Color::White);
//			}
//
//			if (menu_wybrane == 3) {
//				menu_napis_wyjscie.obwodka(window, 2, sf::Color::White);
//				if (event.key.code == sf::Keyboard::Enter) {
//					window.clear();
//					Napis wyjscie_napis(" Czy na pewno chcesz wyjsc? ", 300, 200, 50, sf::Color::White, font, sf::Text::Regular);
//					wyjscie_napis.ustaw_na_srodku(window);
//					window.draw(wyjscie_napis.getNapis());
//					window.display();
//					bool wyjdz = false;
//					while (!wyjdz) {
//						while (window.pollEvent(event)) {
//							if (event.type == sf::Event::KeyPressed) {
//								if (event.key.code == sf::Keyboard::Enter) {
//									window.close();
//									wyjdz = true;
//								}
//								else if (event.key.code == sf::Keyboard::Escape) {
//									wyjdz = true;
//								}
//								menu(font, window, sf::Keyboard::M, sf::Keyboard::Escape, zegar,
//									sf::Keyboard::F1, sf::Keyboard::A, paletka, predkosc_paletki, dx, dy,
//									stoper_pauza, pomoc_napis, odliczanie, p1, przeszkoda, punkty_tekst, punkty, stoper_pauza_elapsed, czy_level, bomba, serce1, serce2, serce3, gracz, rzad, stoper, ktory_level, tekstura_bloku, stoper_elapsed, serce_czerwone, serce_szare);
//							}
//						}
//					}
//
//				};
//			}
//			else {
//				menu_napis_wyjscie.obwodka(window, 0, sf::Color::White);
//			}
//			window.display();
//		}
//	}
//}
//
//void zycia(Nieregularny bomba, Prostokat paletka, Prostokat& serce1, Prostokat& serce2, Prostokat& serce3, Gracz& gracz, sf::Texture& serce_szare) {
//	if (bomba.getPos().x < paletka.getPos().x + 150 && bomba.getPos().x + bomba.getSize().width > paletka.getPos().x && bomba.getPos().y + bomba.getSize().height == paletka.getPos().y) {
//		gracz.zycia--;
//	}
//	if (gracz.zycia == 2) serce3.ustaw_teksture(serce_szare);
//	if (gracz.zycia == 1) serce2.ustaw_teksture(serce_szare);
//	if (gracz.zycia == 0) serce1.ustaw_teksture(serce_szare);
//}
//
//void rysuj_wszystko(sf::RenderWindow& window, Nieregularny& bomba, Prostokat& serce1, Prostokat& serce2, Prostokat& serce3, pilka& p1, Napis& punkty_tekst, int& punkty, Prostokat& paletka, Prostokat& przeszkoda, sf::Clock stoper, sf::Font font, sf::Time& stoper_elapsed, sf::Time& stoper_pauza_elapsed, std::vector<std::vector<Blok>>& rzad) {
//	window.clear();
//	window.draw(bomba.getNiereg());
//	window.draw(serce1.getProstokat());
//	window.draw(serce2.getProstokat());
//	window.draw(serce3.getProstokat());
//	rysujBloki(window, rzad);
//	window.draw(p1.getPilka());
//	napis(punkty_tekst.getNapis(), punkty, window);
//	window.draw(paletka.getProstokat());
//	window.draw(przeszkoda.getProstokat());
//	f_czas(window, p1, stoper, font, p1.przegrana, stoper_elapsed, stoper_pauza_elapsed);
//	window.display();
//
//}
//
//void level(sf::Keyboard::Key F1, sf::Keyboard::Key Escape, Prostokat& paletka, float predkosc_paletki, float dx, float dy, sf::RenderWindow& window, sf::Clock& stoper_pauza, Napis& pomoc_napis, sf::Clock& zegar, Napis& odliczanie, pilka& p1, Prostokat& przeszkoda, Napis& punkty_tekst, int& punkty, sf::Time& stoper_pauza_elapsed, bool& czy_level, Nieregularny& bomba, Prostokat& serce1, Prostokat& serce2, Prostokat& serce3, Gracz& gracz, sf::Texture& serce_szare, sf::Font& font, sf::Event& event, sf::Clock& stoper, sf::Time& stoper_elapsed, std::vector<std::vector<Blok>>& rzad, int& ktory_level, sf::Texture tekstura_bloku, sf::Texture& serce_czerwone) {
//
//	while (window.isOpen()) {
//
//		sf::Event event;
//
//		while (window.pollEvent(event)) {
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		poruszanie(sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::F1, paletka, predkosc_paletki, window);
//		if (event.key.code == sf::Keyboard::F1)
//			pomoc(sf::Keyboard::F1, sf::Keyboard::Escape, paletka, predkosc_paletki, dx, dy, window, stoper_pauza, pomoc_napis, zegar, odliczanie, p1, przeszkoda, punkty_tekst, punkty, stoper_pauza_elapsed, czy_level, bomba, serce1, serce2, serce3, rzad);
//		mechanika(zegar, p1, paletka, przeszkoda, window, dx, dy, punkty, bomba, rzad);
//		
//		menu(font, window, sf::Keyboard::M, sf::Keyboard::Escape, zegar,
//			sf::Keyboard::F1, sf::Keyboard::A, paletka, predkosc_paletki, dx, dy,
//			stoper_pauza, pomoc_napis, odliczanie, p1, przeszkoda, punkty_tekst, punkty, stoper_pauza_elapsed, czy_level, bomba, serce1, serce2, serce3, gracz, rzad, stoper, ktory_level, tekstura_bloku, stoper_elapsed, serce_czerwone, serce_szare);
//		zycia(bomba, paletka, serce1, serce2, serce3, gracz, serce_szare);
//		rysuj_wszystko(window, bomba, serce1, serce2, serce3, p1, punkty_tekst, punkty, paletka, przeszkoda, stoper, font, stoper_elapsed, stoper_pauza_elapsed, rzad);
//	}
//}

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
		/*menu(font, window, sf::Keyboard::M, sf::Keyboard::Escape, zegar,
			sf::Keyboard::F1, sf::Keyboard::A, paletka, predkosc_paletki, dx, dy,
			stoper_pauza, pomoc_napis, odliczanie, p1, przeszkoda, punkty_tekst, punkty, stoper_pauza_elapsed, czy_level, bomba, serce1, serce2, serce3, gracz, rzad, stoper, ktory_level, tekstura_bloku, stoper_elapsed, serce_czerwone, serce_szare);
			
		}*/

		/*if (ktory_level == 1) {
		przeszkoda.zmien_rozmiar(0.f, 0.f);
		}
		if (ktory_level == 2) {
		przeszkoda.zmien_rozmiar(700.f, 20.f);
		level.gra();
		}*/
		}
	return 0;
}
