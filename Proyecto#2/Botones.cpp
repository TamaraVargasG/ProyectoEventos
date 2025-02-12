#include "Botones.h"

Botones::Botones(float x, float y, float ancho, float alto, const std::string& etiqueta, const sf::Font& font, unsigned int tamano) {
    botones.setSize(sf::Vector2f(ancho, alto));  // Tamaño del botón
    botones.setPosition(x, y);                   // Posición del botón
    botones.setFillColor(sf::Color::Cyan);       // Color de fondo por defecto del botón

    texto.setFont(font);  // Asignar la fuente
    texto.setString(etiqueta);  // Texto del botón
    texto.setCharacterSize(tamano);  // Tamaño de texto
    texto.setFillColor(sf::Color::Black);  // Color del texto
    // Centrar el texto en el botón
    sf::FloatRect textBounds = texto.getLocalBounds();
    texto.setOrigin(textBounds.width / 2, textBounds.height / 2);
    texto.setPosition(x + ancho / 2, y + alto / 2);
}

bool Botones::estaPresionado(const sf::Vector2i& mousePos) const {
    return botones.getGlobalBounds().contains(sf::Vector2f(mousePos));
}

void Botones::ejecutarAccion() const {
    if (accion) {
        accion();  // Llamar a la función asociada
    }
}

void Botones::dibujar(sf::RenderWindow& window) const {
    window.draw(botones);
    window.draw(texto);
}

void Botones::setAccion(const std::function<void()>& nuevaAccion) {
    accion = nuevaAccion;
}
