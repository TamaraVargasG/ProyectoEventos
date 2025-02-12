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

    // M�todo para detectar si el bot�n ha sido presionado
    bool estaPresionado(const sf::Vector2i& mousePos) const;

    // M�todo para ejecutar la acci�n asociada
    void ejecutarAccion() const;

    // M�todo para dibujar el bot�n en la ventana
    void dibujar(sf::RenderWindow& window) const;

    // M�todo para asignar una acci�n al bot�n
    void setAccion(const function<void()>& nuevaAccion);

private:
    sf::RectangleShape botones;  // Forma del bot�n
    sf::Text texto;            // Texto que aparecer� en el bot�n
    function<void()> accion;  //ejecutar cuando el bot�n sea presionado
};

#endif 
