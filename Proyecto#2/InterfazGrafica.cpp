#include "InterfazGrafica.h"
#include <iostream>

InterfazGrafica::InterfazGrafica() : window(sf::VideoMode(1000, 800), "Menú Principal") {}

void InterfazGrafica::ejecutar() {
    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            manejarEventos(event);
        }

        window.clear();
        dibujarMenu();
        window.display();
    }
}

void InterfazGrafica::dibujarMenu() {
    // Aquí puedes usar cuadros de texto o botones visuales, pero para simplificar, usaremos solo texto en la pantalla
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error al cargar la fuente." << endl;
    }

    sf::Text textoMenu;
    textoMenu.setFont(font);
    textoMenu.setCharacterSize(20);
    textoMenu.setFillColor(sf::Color::Black);
    textoMenu.setPosition(50, 50);
    textoMenu.setString("Menú Principal:\n1. Crear Evento\n2. Configurar Segmento\n3. Configurar Descuento\n4. Vender Entrada\n5. Estado");

    window.draw(textoMenu);
}

void InterfazGrafica::manejarEventos(sf::Event event) {
    
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode >= '1' && event.text.unicode <= '5') {
            int opcion = event.text.unicode - '0';  // Convertir el número del carácter a entero
            manejarAccion(opcion);
        }
    }
}

void InterfazGrafica::manejarAccion(int accion) {
    switch (accion) {
    case 1:
        crearEvento.mostrar(window);
        break;
    case 2:
        configurarSegmento.mostrar(window);
        break;
    case 3:
        configurarDescuento.mostrar(window);
        break;
    case 4:
        venderEntrada.mostrar(window);
        break;
    case 5:
        estado.mostrar(window);
        break;
    default:
        break;
    }
}
