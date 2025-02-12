#pragma once
#ifndef CONFIGURARDESCUENTO_H
#define CONFIGURARDESCUENTO_H
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "CuadroTexto.h" 

class ConfigurarDescuento {
public:
    ConfigurarDescuento(float x, float y);

    void manejarEventos(sf::Event& event, sf::RenderWindow& window);
    void mostrar(sf::RenderWindow& window);

    // Para código alfanumérico 
    string generarCodigoDescuento();

private:
    // Cuadros de texto para cantidad y descuento
    CuadroTexto txtCantidad;
    CuadroTexto txtDescuento;

    // Botón de guardar
    sf::RectangleShape btnGuardar;

    // Variables de estado
    int cantidad;
    int descuento;
    string codigoDescuento;
};

#endif 

