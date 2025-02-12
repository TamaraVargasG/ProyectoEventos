#include "VenderEntrada.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

map<string, int> VenderEntrada::comprasRealizadas;
map<string, double> VenderEntrada::descuentos;

VenderEntrada::VenderEntrada(float x, float y)
    : txtNombre(x, y, 300, 30, "Nombre"),
    txtFechaNacimiento(x, y + 50, 300, 30, "Fecha de Nacimiento (dd/mm/aaaa)"),
    txtCedula(x, y + 100, 300, 30, "C�dula (8 d�gitos)"),
    txtCodigoDescuento(x, y + 150, 300, 30, "C�digo de Descuento"),
    txtCantidadEntradas(x, y + 200, 300, 30, "Cantidad de Entradas"),
    btnGuardar(sf::Vector2f(500, 100)),
    nombre(""), fechaNacimiento(""), cedula(""), codigoDescuento(""), cantidadEntradas(0), procesarVenta(false) {

    btnGuardar.setSize(sf::Vector2f(200, 50));
    btnGuardar.setFillColor(sf::Color::Green);
}

void VenderEntrada::manejarEventos(sf::Event& event, sf::RenderWindow& window) {
    // Maneja los eventos de los cuadros de texto
    txtNombre.manejarEvento(event, window);
    txtFechaNacimiento.manejarEvento(event, window);
    txtCedula.manejarEvento(event, window);
    txtCodigoDescuento.manejarEvento(event, window);
    txtCantidadEntradas.manejarEvento(event, window);

    // Si el bot�n de "Guardar" es clickeado
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (btnGuardar.getGlobalBounds().contains(mousePos)) {
        // Obtener los datos ingresados
        nombre = txtNombre.getTexto();
        fechaNacimiento = txtFechaNacimiento.getTexto();
        cedula = txtCedula.getTexto();
        codigoDescuento = txtCodigoDescuento.getTexto();
        cantidadEntradas = std::stoi(txtCantidadEntradas.getTexto());

        // Verificar si la c�dula ya compr� m�s de 5 entradas
        if (!verificarCedula(cedula)) {
            cout << "La c�dula ya ha comprado m�s de 5 entradas." << endl;
            return;
        }

        // Iniciar la compra de entradas
        procesarVenta = true;
    }
}

void VenderEntrada::mostrar(sf::RenderWindow& window) {
    // Si estamos procesando la venta, mostrar los detalles adicionales
    if (procesarVenta) {
        // Mostrar cuadros para seleccionar los segmentos y espacios
        for (int i = 0; i < cantidadEntradas; ++i) {
            // Crear cuadro de texto para cada entrada (segmento y espacio)
            CuadroTexto txtSegmento(500, 100 + (i * 50), 300, 30, "Segmento (para entrada " + to_string(i + 1) + ")");
            CuadroTexto txtEspacio(500, 150 + (i * 50), 300, 30, "Espacio (para entrada " + to_string(i + 1) + ")");

            txtSegmento.dibujar(window);
            txtEspacio.dibujar(window);

            // L�gica para guardar los valores introducidos cuando se hace clic en "Guardar"
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (btnGuardar.getGlobalBounds().contains(mousePos)) {
                // Obtener los valores de los cuadros de texto para segmento y espacio
                string segmentoStr = txtSegmento.getTexto();
                string espacioStr = txtEspacio.getTexto();

                // Convertir a enteros (o validar si es posible convertirlos)
                int segmento = stoi(segmentoStr);
                int espacio = stoi(espacioStr);

                // Guardar los valores en el vector de entradas (segmento, espacio)
                entradas.push_back(std::make_pair(segmento, espacio));

                // Mostrar un mensaje de confirmaci�n o lo que se necesite
                cout << "Entrada " << i + 1 << " guardada: Segmento " << segmento << ", Espacio " << espacio << endl;
            }
        }

        // Mostrar el resumen de la venta y el total
        double total = calcularTotal();
        cout << "Total a pagar: " << total << endl;
    }
    else {
        // Si no estamos procesando la venta, dibujar la informaci�n personal
        txtNombre.dibujar(window);
        txtFechaNacimiento.dibujar(window);
        txtCedula.dibujar(window);
        txtCodigoDescuento.dibujar(window);
        txtCantidadEntradas.dibujar(window);

        // Dibujar el bot�n de guardar
        window.draw(btnGuardar);
    }
}


bool VenderEntrada::verificarCedula(const std::string& cedula) {
    // L�gica para verificar cu�ntas entradas ha comprado la c�dula
    if (comprasRealizadas.find(cedula) != comprasRealizadas.end() && comprasRealizadas[cedula] >= 5) {
        return false;  // La c�dula ya ha comprado 5 entradas
    }

    comprasRealizadas[cedula] += cantidadEntradas;  // Actualizar la cantidad de entradas compradas
    return true;
}

double VenderEntrada::calcularTotal() {
    // Precio base de una entrada
    double precioBase = 100.0;  // Este valor puede ajustarse seg�n la l�gica de tu sistema.

    // Si hay un descuento, aplicarlo
    if (!codigoDescuento.empty() && descuentos.find(codigoDescuento) != descuentos.end()) {
        double descuento = descuentos[codigoDescuento];  // Descuento aplicado por c�digo
        precioBase *= (1 - descuento);  // Aplicar el descuento
    }

    // Calcular el total
    return precioBase * cantidadEntradas;
}

// Generar un c�digo de descuento alfanum�rico
std::string generarCodigoDescuento() {
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string codigo;
    int longitud = 8;  // Longitud del c�digo

    for (int i = 0; i < longitud; i++) {
        codigo += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return codigo;
}

void VenderEntrada::agregarDescuento(double porcentaje) {
    string codigo = generarCodigoDescuento();
    descuentos[codigo] = porcentaje / 100.0;  // Guardar descuento como un porcentaje
    cout << "C�digo de descuento generado: " << codigo << endl;
}
