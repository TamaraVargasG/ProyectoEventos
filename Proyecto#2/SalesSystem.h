#pragma once
#ifndef SALESSYSTEM_H
#define SALESSYSTEM_H
#include <iostream>
#include <string>
#include "Segmento.h"
using namespace std;
#include <cctype> 
class SalesSystem {
private:
    string nombreEvento;
    int totalEntradas;
    int entradasVendidas;
    int numSegmentos;
    Segmento* segmentos;

    int descuentoPorcentaje;
    int descuentoLimite;

    int maxCodigos;
    string* codigoDescuento;    // Arreglo de códigos alfanuméricos
    int* porcentajeDescuento;   // Arreglo de porcentajes de descuento
    int* cedulas;               // Arreglo para almacenar las cédulas
    int* entradasPorCedula;     // Arreglo para el número de entradas compradas por cada cédula
    int totalCedulas;

public:
    SalesSystem();
    ~SalesSystem();
    void configurarEvento();
    void configurarDescuento();
    void venderEntrada();
    void consultarEstadoVentas();
    void acercaDe();

    //void configurarDescuento();  // Generar códigos y descuentos
    int verificarCodigoDescuento(string codigo);  // Retorna el porcentaje de descuento para un código
    bool registrarCompra(string cedula, int entradas);
    bool validarCedula(const string& cedula);   // Método para validar la cédula
};

#endif

