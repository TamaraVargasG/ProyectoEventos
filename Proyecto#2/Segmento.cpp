#include "Segmento.h"
#include <iostream>
using namespace std;

Segmento::Segmento() : filas(0), columnas(0), matriz(nullptr), precio(0.0f) {}

Segmento::~Segmento() {
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void Segmento::configurar(int f, int c, float p) {
    filas = f;
    columnas = c;
    precio = p;
    inicializarMatriz();
}

void Segmento::inicializarMatriz() {
    matriz = new char* [filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new char[columnas];
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = 176;  // Asiento disponible
        }
    }
}

bool Segmento::ocuparAsiento(int fila, int columna) {
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas && matriz[fila][columna] == 176) {
        matriz[fila][columna] = 178;  // Asiento ocupado
        return true;
    }
    return false;
}

bool Segmento::asientoOcupado(int fila, int columna) const {
    return matriz[fila][columna] == 178;
}

void Segmento::mostrarMatriz() const {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }
}

int Segmento::getFilas() const { return filas; }
int Segmento::getColumnas() const { return columnas; }
float Segmento::getPrecio() const { return precio; }
