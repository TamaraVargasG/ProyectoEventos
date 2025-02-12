#pragma once
#ifndef CREAREVENTO_H
#define CREAREVENTO_H
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "CuadroTexto.h" 

class CrearEvento {
public:
    CrearEvento(float x, float y);

    void manejarEventos(sf::Event& event, sf::RenderWindow& window);
    void mostrar(sf::RenderWindow& window);

private:
    // Cuadros de texto para ingresar el nombre y la cantidad de segmentos
    CuadroTexto txtNombreEvento;
    CuadroTexto txtCantidadSegmentos;

    // Botones
    sf::RectangleShape btnGuardarEvento;
    sf::RectangleShape btnRegresarEvento;

    // para procesar la entrada de cantidad de segmentos
    void procesarEntradaCantidadSegmentos();

    //  para almacenar la cantidad de segmentos configurados
    int cantidadSegmentos;
};

#endif 

