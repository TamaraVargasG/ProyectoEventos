#pragma once
#ifndef CONFIGURARSEGMENTO_H
#define CONFIGURARSEGMENTO_H
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "CuadroTexto.h" 

class ConfigurarSegmento {
public:
    ConfigurarSegmento(float x, float y, int cantidadSegmentos);

    void manejarEventos(sf::Event& event, sf::RenderWindow& window);
    void mostrar(sf::RenderWindow& window);

    // Métodos para obtener el nuevo estado de los segmentos 
    void actualizarSegmento(int segmento, int espacio, float precio);
    void eliminarSegmento(int segmento, int espacio);

private:
    // Cuadros de texto para los datos de segmento, espacio y precio
    CuadroTexto txtElegirSegmento;
    CuadroTexto txtElegirEspacio;
    CuadroTexto txtPrecio;

    // Botones 
    sf::RectangleShape btnGuardar;
    sf::RectangleShape btnEliminar;

    // Variables para estado
    int cantidadSegmentos;
    int segmentoSeleccionado;
    int espacioSeleccionado;
    float precio;
};

#endif 
