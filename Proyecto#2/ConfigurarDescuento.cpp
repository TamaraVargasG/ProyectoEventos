#include "ConfigurarDescuento.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

ConfigurarDescuento::ConfigurarDescuento(float x, float y)
    : txtCantidad(x, y, 300, 30, "Cantidad Usos"),
    txtDescuento(x, y + 100, 300, 30, "Cantidad Descuento (%)"),
    btnGuardar(sf::Vector2f(500, 100)),
    cantidad(0),
    descuento(0),
    codigoDescuento("") {

    btnGuardar.setSize(sf::Vector2f(200, 50));
    btnGuardar.setFillColor(sf::Color::Green);
}

void ConfigurarDescuento::manejarEventos(sf::Event& event, sf::RenderWindow& window) {
    // Maneja los eventos de los cuadros de texto
    txtCantidad.manejarEvento(event, window);
    txtDescuento.manejarEvento(event, window);

    // Si el botón de "Guardar" es clickeado
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (btnGuardar.getGlobalBounds().contains(mousePos)) {
        // Obtener los datos ingresados
        string textoCantidad = txtCantidad.getTexto();
        string textoDescuento = txtDescuento.getTexto();

        // Validar y procesar los datos
        if (!textoCantidad.empty() && !textoDescuento.empty()) {
            cantidad = stoi(textoCantidad);
            descuento = stoi(textoDescuento);

            // Generar y mostrar el código de descuento
            codigoDescuento = generarCodigoDescuento();
            cout << "Código de descuento generado: " << codigoDescuento << endl;
        }
    }
}

void ConfigurarDescuento::mostrar(sf::RenderWindow& window) {
    // Dibujar los cuadros de texto y el botón de guardar
    txtCantidad.dibujar(window);
    txtDescuento.dibujar(window);
    window.draw(btnGuardar);
}

string ConfigurarDescuento::generarCodigoDescuento() {
    // Generar un código alfanumérico aleatorio
    string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string codigo = "";

    // Usar la hora actual como semilla para la generación aleatoria
    srand(time(0));

    // Generar un código de 8 caracteres
    for (int i = 0; i < 8; i++) {
        int index = rand() % caracteres.size();
        codigo += caracteres[index];
    }

    return codigo;
}
