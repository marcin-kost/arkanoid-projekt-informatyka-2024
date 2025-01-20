#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "paletka.hpp"
#include "pilka.hpp"
#include "blok.hpp"
#include "napis.hpp"
#include "nieregularny.hpp"
#include "gracz.hpp"
#include <fstream>
#include <iostream>

class Level {
private:
    sf::Font& font;
    sf::RenderWindow& window;
    sf::Keyboard::Key M, Escape, F1, A, D;
    sf::Clock &zegar, &stoper_pauza, &stoper;
    Prostokat& paletka;
    float& predkosc_paletki, dx, dy;
    Napis &pomoc_napis, &odliczanie, &punkty_tekst;
    pilka& p1;
    Prostokat& przeszkoda, &serce1, &serce2, &serce3;
    int& punkty;
    sf::Time& stoper_pauza_elapsed, &stoper_elapsed;
    bool& czy_level;
    Nieregularny& bomba;
    Gracz& gracz;
    std::vector<std::vector<Blok>>& rzad;
    int& ktory_level;
    sf::Texture& tekstura_bloku, &serce_czerwone, &serce_szare;
    sf::Event& event;

public:
    Level(sf::Font& font, sf::RenderWindow& window, sf::Keyboard::Key M, sf::Keyboard::Key Escape, sf::Clock& zegar,
        sf::Keyboard::Key F1, sf::Keyboard::Key A, sf::Keyboard::Key D, Prostokat& paletka, float& predkosc_paletki,
        float& dx, float& dy, sf::Clock& stoper_pauza, Napis& pomoc_napis, Napis& odliczanie, pilka& p1,
        Prostokat& przeszkoda, Napis& punkty_tekst, int& punkty, sf::Time& stoper_pauza_elapsed,
        bool& czy_level, Nieregularny& bomba, Prostokat& serce1, Prostokat& serce2, Prostokat& serce3, Gracz& gracz,
        std::vector<std::vector<Blok>>& rzad, sf::Clock& stoper, int& ktory_level, sf::Texture& tekstura_bloku,
        sf::Time& stoper_elapsed, sf::Texture& serce_czerwone, sf::Texture& serce_szare, sf::Event& event);

    void napis();
    void f_czas();
    void pomoc();
    void mechanika();
    void poruszanie();
    void zapisz();
    void odczyt();
    void wyjscie();
    void resetuj_level();
    void menu();
    void zycia();
    void rysuj_wszystko();
    void gra();
};
