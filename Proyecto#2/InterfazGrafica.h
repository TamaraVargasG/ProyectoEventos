#pragma once
#ifndef INTERFAZ_GRAFICA_H
#define INTERFAZ_GRAFICA_H
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "CrearEvento.h"
#include "ConfigurarSegmento.h"
#include "ConfigurarDescuento.h"
#include "VenderEntrada.h"
#include "Estado.h"
#include "Botones.h"

class InterfazGrafica {
public:
    // Constructor
    InterfazGrafica();

    // para ejecutar la interfaz
    void ejecutar();

private:
    
    sf::RenderWindow window;

    // Instancias de las clases de acción
    CrearEvento crearEvento;
    ConfigurarSegmento configurarSegmento;
    ConfigurarDescuento configurarDescuento;
    VenderEntrada venderEntrada;
    Estado estado;

    // para dibujar el menú
    void dibujarMenu();

    // para manejar los eventos del menú
    void manejarEventos(sf::Event event);

    //  para manejar la lógica de cada acción
    void manejarAccion(int accion);
};

#endif
