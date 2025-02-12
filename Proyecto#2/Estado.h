#pragma once
#ifndef ESTADO_H
#define ESTADO_H
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <sstream>

class Estado {
public:
    // Constructor
    Estado(vector<vector<pair<int, bool>>>& segmentos, vector<int>& precios);

    // Mostrar el estado de los segmentos
    void mostrar();

private:
    // Datos de los segmentos y precios
    vector<vector<pair<int, bool>>>& segmentos; // Segmentos y estado vacío o ocupado
    vector<int>& precios; // Precios de cada segmento
};

#endif
