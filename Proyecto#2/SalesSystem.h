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
    string* codigoDescuento;    // Arreglo de c�digos alfanum�ricos
    int* porcentajeDescuento;   // Arreglo de porcentajes de descuento
    int* cedulas;               // Arreglo para almacenar las c�dulas
    int* entradasPorCedula;     // Arreglo para el n�mero de entradas compradas por cada c�dula
    int totalCedulas;

public:
    SalesSystem();
    ~SalesSystem();
    void configurarEvento();
    void configurarDescuento();
    void venderEntrada();
    void consultarEstadoVentas();
    void acercaDe();

    //void configurarDescuento();  // Generar c�digos y descuentos
    int verificarCodigoDescuento(string codigo);  // Retorna el porcentaje de descuento para un c�digo
    bool registrarCompra(string cedula, int entradas);
    bool validarCedula(const string& cedula);   // M�todo para validar la c�dula
};

#endif

