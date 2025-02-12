#pragma once
#ifndef SEGMENTO_H
#define SEGMENTO_H
#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Segmento {
public:
    Segmento(const string& nombre, int espacios, float precio);

    void setEspacios(int nuevosEspacios);
    void setPrecio(float nuevoPrecio);
    void ocuparEspacio(int espacio);
    bool estaOcupado(int espacio) const;

    string getNombre() const;
    float getPrecio() const;
    int getEspacios() const;
    int getEspacioLibre() const;  //para verificar el número de espacios disponibles

    vector<int> espacios;
    void redimensionarEspacios(int nuevoTamano) {
        espacios.resize(nuevoTamano);  
    }

private:
    std::string nombre;
    float precio;
    int espaciosTotales;
    vector<bool> espacios;  // Un vector que representa si el espacio está ocupado (true = ocupado, false = libre)
};

#endif

