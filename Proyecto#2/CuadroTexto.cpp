#include "CuadroTexto.h"
#include <SFML/Graphics.hpp>

CuadroTexto::CuadroTexto(float x, float y, float width, float height, const string& texto) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);

    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("No se pudo cargar la fuente");
    }

    text.setFont(font);
    text.setString(texto);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 10, y + 10);

    contenido = ""; // Inicializar el contenido como vacío
}

void CuadroTexto::dibujar(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

void CuadroTexto::manejarEvento(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::TextEntered) {
        // Si el evento es una entrada de texto, agregar el carácter al contenido
        if (event.text.unicode < 128) { // Solo caracteres ASCII
            if (event.text.unicode == 8 && contenido.length() > 0) { // Si es Backspace, eliminar un carácter
                contenido.pop_back();
            }
            else {
                contenido += static_cast<char>(event.text.unicode);
            }

            // Actualizar el texto del cuadro de texto con el contenido ingresado
            text.setString(contenido);
        }
    }

    // Si se hace clic en el cuadro, podrías cambiar el color para mostrar que está seleccionado
    if (event.type == sf::Event::MouseButtonPressed) {
        if (shape.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            shape.setFillColor(sf::Color::Yellow); // Cambiar el color al hacer clic
        }
        else {
            shape.setFillColor(sf::Color::White); // Volver al color original si no se hizo clic
        }
    }
}

string CuadroTexto::getTexto() const {
    return contenido;
}
