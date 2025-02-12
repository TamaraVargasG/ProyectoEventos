#include "CrearEvento.h"
#include <iostream>
#include <string>

CrearEvento::CrearEvento(float x, float y)
    : txtNombreEvento(x, y, 300, 30, "Nombre del Evento"),
    txtCantidadSegmentos(x, y + 100, 300, 30, "Cantidad de Segmentos"),
    btnGuardarEvento(sf::Vector2f(500, 100)),
    btnRegresarEvento(sf::Vector2f(500, 200)),
    cantidadSegmentos(0) {

    btnGuardarEvento.setSize(sf::Vector2f(200, 50));
    btnGuardarEvento.setFillColor(sf::Color::Green);

    btnRegresarEvento.setSize(sf::Vector2f(200, 50));
    btnRegresarEvento.setFillColor(sf::Color::Red);
}

void CrearEvento::manejarEventos(sf::Event& event, sf::RenderWindow& window) {
    // Maneja los eventos de los cuadros de texto
    txtNombreEvento.manejarEvento(event, window);
    txtCantidadSegmentos.manejarEvento(event, window);

    // Si el botón de "Guardar Evento" es clickeado
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (btnGuardarEvento.getGlobalBounds().contains(mousePos)) {
        procesarEntradaCantidadSegmentos();
    }

    // Si el botón de "Regresar" es clickeado
    if (btnRegresarEvento.getGlobalBounds().contains(mousePos)) {
        // Se regresa al menú principal
        cout << "Regresando al menú principal." << endl;
    }
}

void CrearEvento::mostrar(sf::RenderWindow& window) {
    // Dibujar los cuadros de texto y botones
    txtNombreEvento.dibujar(window);
    txtCantidadSegmentos.dibujar(window);
    window.draw(btnGuardarEvento);
    window.draw(btnRegresarEvento);
}

void CrearEvento::procesarEntradaCantidadSegmentos() {
    std::string textoSegmentos = txtCantidadSegmentos.getTexto();

    // Validar la entrada
    if (textoSegmentos.empty() || !std::all_of(textoSegmentos.begin(), textoSegmentos.end(), ::isdigit)) {
        cerr << "Error: La entrada no es un número válido." << endl;
        return;
    }

    cantidadSegmentos = std::stoi(textoSegmentos);
    if (cantidadSegmentos <= 0) {
        cerr << "Error: El número de segmentos debe ser mayor a 0." << endl;
        return;
    }

    cout << "Número de segmentos configurado: " << cantidadSegmentos << endl;
}
