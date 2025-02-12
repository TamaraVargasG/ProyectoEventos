#pragma once
#ifndef VENDERENTRADA_H
#define VENDERENTRADA_H
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "CuadroTexto.h"  // Aseg�rate de tener esta clase implementada correctamente
#include <map>
#include <vector>
#include <string>

class VenderEntrada {
public:
    VenderEntrada(float x, float y);

    void manejarEventos(sf::Event& event, sf::RenderWindow& window);
    void mostrar(sf::RenderWindow& window);

private:
    // Cuadros de texto para la informaci�n personal
    CuadroTexto txtNombre;
    CuadroTexto txtFechaNacimiento;
    CuadroTexto txtCedula;
    CuadroTexto txtCodigoDescuento;
    CuadroTexto txtCantidadEntradas;

    // Bot�n de guardar
    sf::RectangleShape btnGuardar;

    // Variables de estado
    string nombre;
    string fechaNacimiento;
    string cedula;
    string codigoDescuento;
    int cantidadEntradas;

    // Almacenar informaci�n de los segmentos y espacios comprados
    vector<pair<int, int>> entradas;  //  (segmento, espacio)
    bool procesarVenta;

    // Funci�n para verificar si una c�dula ya compr� m�s de 5 entradas
    bool verificarCedula(const string& cedula);

    // Funci�n para generar el total a pagar y aplicar descuento
    double calcularTotal();

    void agregarDescuento(double porcentaje);

    // Mapa para almacenar el historial de compras por c�dula
    static map<string, int> comprasRealizadas;

    // Mapa para almacenar los c�digos de descuento
    static map<string, double> descuentos;
};

#endif 

