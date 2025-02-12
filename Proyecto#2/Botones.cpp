#include "Botones.h"

Botones::Botones(float x, float y, float ancho, float alto, const std::string& etiqueta, const sf::Font& font, unsigned int tamano) {
    botones.setSize(sf::Vector2f(ancho, alto));  // Tama�o del bot�n
    botones.setPosition(x, y);                   // Posici�n del bot�n
    botones.setFillColor(sf::Color::Cyan);       // Color de fondo por defecto del bot�n

    texto.setFont(font);  // Asignar la fuente
    texto.setString(etiqueta);  // Texto del bot�n
    texto.setCharacterSize(tamano);  // Tama�o de texto
    texto.setFillColor(sf::Color::Black);  // Color del texto
    // Centrar el texto en el bot�n
    sf::FloatRect textBounds = texto.getLocalBounds();
    texto.setOrigin(textBounds.width / 2, textBounds.height / 2);
    texto.setPosition(x + ancho / 2, y + alto / 2);
}

bool Botones::estaPresionado(const sf::Vector2i& mousePos) const {
    return botones.getGlobalBounds().contains(sf::Vector2f(mousePos));
}

void Botones::ejecutarAccion() const {
    if (accion) {
        accion();  // Llamar a la funci�n asociada
    }
}

void Botones::dibujar(sf::RenderWindow& window) const {
    window.draw(botones);
    window.draw(texto);
}

void Botones::setAccion(const std::function<void()>& nuevaAccion) {
    accion = nuevaAccion;
}
