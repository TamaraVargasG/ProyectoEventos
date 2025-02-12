#include <SFML/Graphics.hpp>
#include "CuadroTexto.h"
#include "Graficos.h"
#include "ConfiguracionEvento.h"
#include "ConfigurarSegmento.h"
#include "ConfigurarDescuento.h"
#include "VenderEntrada.h"
#include "Estado.h"
#include "InterfazGrafica.h"

//int main() {
//    // Crear la ventana
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Sistema de Ventas");
//
//    // Crear las clases necesarias
//    InterfazGrafica interfaz;
//    ConfiguracionEvento configuracionEvento;
//    ConfigurarSegmento configurarSegmento;
//    ConfigurarDescuento configurarDescuento;
//    VenderEntrada venderEntrada;
//    Estado estado;
//
//    // Variables para el ciclo principal
//    bool corriendo = true;
//
//    // Bucle principal
//    while (window.isOpen()) {
//        sf::Event event;
//
//        while (window.pollEvent(event)) {
//            // Cerrar la ventana
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//
//            // Llamar a los eventos de la interfaz y las clases
//            interfaz.manejarEventos(event, window);
//            configuracionEvento.manejarEvento(event, window);
//            configurarSegmento.manejarEvento(event, window);
//            configurarDescuento.manejarEvento(event, window);
//            venderEntrada.manejarEvento(event, window);
//        }
//
//        // Dibujar todo en la ventana
//        window.clear(sf::Color::Black); // Limpiar pantalla
//        interfaz.dibujar(window); // Dibujar la interfaz gráfica
//        configuracionEvento.dibujar(window); // Dibujar cuadro de configuración de evento
//        configurarSegmento.dibujar(window); // Dibujar cuadro de configuración de segmentos
//        configurarDescuento.dibujar(window); // Dibujar cuadro de configuración de descuento
//        venderEntrada.dibujar(window); // Dibujar cuadro de vender entrada
//        estado.dibujar(window); // Dibujar estado actual
//
//        // Mostrar los cambios en la ventana
//        window.display();
//    }
//
//    return 0;
//}
