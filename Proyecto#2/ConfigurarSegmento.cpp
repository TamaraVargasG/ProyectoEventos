#include "ConfigurarSegmento.h"
#include <iostream>
#include <string>
#include <vector>

ConfigurarSegmento::ConfigurarSegmento(float x, float y, int cantidadSegmentos)
    : txtElegirSegmento(x, y, 300, 30, "Elegir Segmento"),
    txtElegirEspacio(x, y + 100, 300, 30, "Elegir Espacio"),
    txtPrecio(x, y + 200, 300, 30, "Precio"),
    btnGuardar(sf::Vector2f(500, 100)),
    btnEliminar(sf::Vector2f(500, 200)),
    cantidadSegmentos(cantidadSegmentos),
    segmentoSeleccionado(-1),
    espacioSeleccionado(-1),
    precio(0) {

    btnGuardar.setSize(sf::Vector2f(200, 50));
    btnGuardar.setFillColor(sf::Color::Green);

    btnEliminar.setSize(sf::Vector2f(200, 50));
    btnEliminar.setFillColor(sf::Color::Red);
}

void ConfigurarSegmento::manejarEventos(sf::Event& event, sf::RenderWindow& window) {
    // Maneja los eventos de los cuadros de texto
    txtElegirSegmento.manejarEvento(event, window);
    txtElegirEspacio.manejarEvento(event, window);
    txtPrecio.manejarEvento(event, window);

    // Si el botón de "Guardar" es clickeado
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (btnGuardar.getGlobalBounds().contains(mousePos)) {
        // Obtener los datos ingresados
        string textoSegmento = txtElegirSegmento.getTexto();
        string textoEspacio = txtElegirEspacio.getTexto();
        string textoPrecio = txtPrecio.getTexto();

        // Validar y actualizar los datos
        if (!textoSegmento.empty() && !textoEspacio.empty() && !textoPrecio.empty()) {
            int segmento = stoi(textoSegmento);
            int espacio = stoi(textoEspacio);
            float precio = stof(textoPrecio);
            actualizarSegmento(segmento, espacio, precio);
        }
    }

    // Si el botón de "Eliminar" es clickeado
    if (btnEliminar.getGlobalBounds().contains(mousePos)) {
        // Obtener los datos ingresados para eliminar
        string textoSegmento = txtElegirSegmento.getTexto();
        string textoEspacio = txtElegirEspacio.getTexto();

        if (!textoSegmento.empty() && !textoEspacio.empty()) {
            int segmento = stoi(textoSegmento);
            int espacio = stoi(textoEspacio);
            eliminarSegmento(segmento, espacio);
        }
    }
}

void ConfigurarSegmento::mostrar(sf::RenderWindow& window) {
    // Dibujar los cuadros de texto y botones
    txtElegirSegmento.dibujar(window);
    txtElegirEspacio.dibujar(window);
    txtPrecio.dibujar(window);
    window.draw(btnGuardar);
    window.draw(btnEliminar);
}

void ConfigurarSegmento::actualizarSegmento(int segmento, int espacio, float precio) {
    // Validar segmento y espacio
    if (segmento > 0 && segmento <= cantidadSegmentos && espacio > 0) {
        // Aquí se actualizaría la información de los segmentos (esto puede depender de cómo estés almacenando los datos)
        cout << "Segmento " << segmento << ", Espacio " << espacio << ", Precio actualizado a " << precio << endl;

        // Aquí puedes almacenar o modificar la información del segmento en la estructura correspondiente (array, lista, etc.)
    }
    else {
        cerr << "Error: Segmento o espacio inválido." << endl;
    }
}

void ConfigurarSegmento::eliminarSegmento(int segmento, int espacio) {
    // Validar segmento y espacio
    if (segmento > 0 && segmento <= cantidadSegmentos && espacio > 0) {
        // Aquí se eliminaría el espacio del segmento (esto puede depender de cómo estés almacenando los datos)
        cout << "Eliminando espacio " << espacio << " en el segmento " << segmento << endl;

        // Aquí puedes eliminar el espacio correspondiente de la estructura de datos
    }
    else {
        cerr << "Error: Segmento o espacio inválido." << endl;
    }
}
