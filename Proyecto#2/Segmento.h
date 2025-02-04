#pragma once
#ifndef SEGMENTO_H
#define SEGMENTO_H
#include <iostream>
#include <string>
using namespace std;

class Segmento {
private:
    int filas;
    int columnas;
    char** matriz;
    float precio;

public:
    Segmento();
    ~Segmento();
    void configurar(int filas, int columnas, float precio);
    void inicializarMatriz();
    bool ocuparAsiento(int fila, int columna);
    bool asientoOcupado(int fila, int columna) const;
    void mostrarMatriz() const;
    int getFilas() const;
    int getColumnas() const;
    float getPrecio() const;
};

#endif
