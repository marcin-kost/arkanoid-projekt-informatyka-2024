#include "blok.hpp"
#include <iostream>

Blok::Blok(float x_in, float y_in, bool zniszczony, const sf::Texture& tekstura) {
	blok.setSize(sf::Vector2f(100, 50));
	blok.setFillColor(sf::Color::White);
	blok.setOutlineColor(sf::Color::Black);
	blok.setOutlineThickness(1.0f);
	blok.setPosition(x_in, y_in);
	blok.setTexture(&tekstura);
	this->zniszczony = zniszczony;
}

void utworzSiatkeBlokow(float startX, float startY, int liczbaWierszy, int liczbaKolumn, float szerokoscBloku, float wysokoscBloku, const sf::Texture& tekstura, std::vector<std::vector<Blok>>& rzad) {


	for (int i = 0; i < liczbaWierszy; ++i) {
		std::vector<Blok> kolumna; // Tworzenie jednego wiersza
		for (int j = 0; j < liczbaKolumn; ++j) {
			float x = startX + j * szerokoscBloku;
			float y = startY + i * wysokoscBloku;

			kolumna.emplace_back(x, y, false, tekstura); // Dodanie nowego bloku
		}
		rzad.push_back(kolumna); // Dodanie wiersza do wektora siatki
	}
}

void rysujBloki(sf::RenderWindow& window, std::vector<std::vector<Blok>>& rzad) {
	for (auto& kolumna : rzad) {
		for (auto& blok : kolumna) {
			if(!blok.zniszczony)
			window.draw(blok.getBlok());
		}
	}
}

void odbijanieBloki(pilka& p1, float& dx, float& dy, float zmianaPromienia, int& punkty, std::vector<std::vector<Blok>>& rzad, Gracz& gracz) {
	sf::Vector2f pozycjaPilki = p1.getPos();
	float promien = p1.getPromien();

	for (auto& kolumna : rzad) { 
		for (auto it = kolumna.begin(); it != kolumna.end(); ) { 
			sf::Vector2f pozycjaBloku = it->getPos();
			sf::Vector2f rozmiarBloku = { 100.f, 50.f }; 
			
			if (pozycjaPilki.x + promien > pozycjaBloku.x && pozycjaPilki.x + promien < pozycjaBloku.x + rozmiarBloku.x && (pozycjaPilki.y == pozycjaBloku.y + rozmiarBloku.y || pozycjaPilki.y + 2*promien == pozycjaBloku.y)&& it->zniszczony == false) {
				dy = -dy;
				
				it->zniszczony = true;
				gracz.punkty +=10;
				p1.zmienPromien(zmianaPromienia);
				++it;
				continue; 
			}
			if (pozycjaPilki.y + promien > pozycjaBloku.y && pozycjaPilki.y + promien < pozycjaBloku.y + rozmiarBloku.y && (pozycjaPilki.x == pozycjaBloku.x + rozmiarBloku.x || pozycjaPilki.x + 2*promien == pozycjaBloku.x) && it->zniszczony == false) {
				dx = -dx;

				it->zniszczony = true;
				gracz.punkty += 10;
				p1.zmienPromien(zmianaPromienia);
				++it;
				continue; 
			}
			//lewy dolny rog
			if ((pozycjaPilki.x + promien < pozycjaBloku.x && pozycjaPilki.x + 2*promien > pozycjaBloku.x && pozycjaPilki.y < pozycjaBloku.y + rozmiarBloku.y && pozycjaPilki.y + promien > pozycjaBloku.y + rozmiarBloku.y) && it->zniszczony == false) {
				dx = -dx;
				
				it->zniszczony = true;
				gracz.punkty += 10;
				p1.zmienPromien(zmianaPromienia);
				++it;
				continue;
			}
			//lewy gorny rog
			if ((pozycjaPilki.x + promien < pozycjaBloku.x && pozycjaPilki.x + 2*promien > pozycjaBloku.x && pozycjaPilki.y + promien < pozycjaBloku.y && pozycjaPilki.y + 2*promien > pozycjaBloku.y) && it->zniszczony == false) {
				dx = -dx;
				
				it->zniszczony = true;
				gracz.punkty += 10;
				p1.zmienPromien(zmianaPromienia);
				++it;
				continue;
			}
			//prawy dolny rog
			if ((pozycjaPilki.x < pozycjaBloku.x + rozmiarBloku.x && pozycjaPilki.x + promien > pozycjaBloku.x + rozmiarBloku.x && pozycjaPilki.y < pozycjaBloku.y + rozmiarBloku.y && pozycjaPilki.y + promien > pozycjaBloku.y + rozmiarBloku.y) && it->zniszczony == false) {
				dx = -dx;
				
				it->zniszczony = true;
				gracz.punkty += 10;
				p1.zmienPromien(zmianaPromienia);
				++it;
				continue;
			}
			//prawy gorny rog
			if ((pozycjaPilki.x < pozycjaBloku.x + rozmiarBloku.x && pozycjaPilki.x + promien > pozycjaBloku.x + rozmiarBloku.x && pozycjaPilki.y + promien < pozycjaBloku.y && pozycjaPilki.y + 2*promien > pozycjaBloku.y) && it->zniszczony == false) {
				dx = -dx;
				
				it->zniszczony = true;
				gracz.punkty += 10;
				p1.zmienPromien(zmianaPromienia);
				++it;
				continue;
			}
			else {
				++it;
			}
		}
	}
}