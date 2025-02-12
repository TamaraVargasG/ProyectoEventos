#pragma once
#ifndef VENDERENTRADA_H
#define VENDERENTRADA_H
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "CuadroTexto.h"  // Asegúrate de tener esta clase implementada correctamente
#include <map>
#include <vector>
#include <string>

class VenderEntrada {
public:
    VenderEntrada(float x, float y);

    void manejarEventos(sf::Event& event, sf::RenderWindow& window);
    void mostrar(sf::RenderWindow& window);

private:
    // Cuadros de texto para la información personal
    CuadroTexto txtNombre;
    CuadroTexto txtFechaNacimiento;
    CuadroTexto txtCedula;
    CuadroTexto txtCodigoDescuento;
    CuadroTexto txtCantidadEntradas;

    // Botón de guardar
    sf::RectangleShape btnGuardar;

    // Variables de estado
    string nombre;
    string fechaNacimiento;
    string cedula;
    string codigoDescuento;
    int cantidadEntradas;

    // Almacenar información de los segmentos y espacios comprados
    vector<pair<int, int>> entradas;  //  (segmento, espacio)
    bool procesarVenta;

    // Función para verificar si una cédula ya compró más de 5 entradas
    bool verificarCedula(const string& cedula);

    // Función para generar el total a pagar y aplicar descuento
    double calcularTotal();

    void agregarDescuento(double porcentaje);

    // Mapa para almacenar el historial de compras por cédula
    static map<string, int> comprasRealizadas;

    // Mapa para almacenar los códigos de descuento
    static map<string, double> descuentos;
};

#endif 

