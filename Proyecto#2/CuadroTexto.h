#pragma once
#ifndef CUADROTEXTO_H
#define CUADROTEXTO_H
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include <string>

class CuadroTexto {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;
    std::string contenido;

public:
    CuadroTexto(float x, float y, float width, float height, const string& texto);

    // Dibujar el cuadro de texto en la ventana
    void dibujar(sf::RenderWindow& window);

    //  para manejar eventos clic y escritura
    void manejarEvento(sf::Event event, sf::RenderWindow& window);

    //  para obtener el texto introducido
    string getTexto() const;
};

#endif
