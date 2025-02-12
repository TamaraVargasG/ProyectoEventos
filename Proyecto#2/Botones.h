#pragma once
#ifndef BOTONES_H
#define BOTONES_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <functional>  // Para std::function
#include <iostream>
using namespace std;
class Botones {
public:
    
    Botones(float x, float y, float ancho, float alto, const std::string& etiqueta, const sf::Font& font, unsigned int tamano = 20);

    // Método para detectar si el botón ha sido presionado
    bool estaPresionado(const sf::Vector2i& mousePos) const;

    // Método para ejecutar la acción asociada
    void ejecutarAccion() const;

    // Método para dibujar el botón en la ventana
    void dibujar(sf::RenderWindow& window) const;

    // Método para asignar una acción al botón
    void setAccion(const function<void()>& nuevaAccion);

private:
    sf::RectangleShape botones;  // Forma del botón
    sf::Text texto;            // Texto que aparecerá en el botón
    function<void()> accion;  //ejecutar cuando el botón sea presionado
};

#endif 
