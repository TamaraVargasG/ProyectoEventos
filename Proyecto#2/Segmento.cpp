#include "Segmento.h"

Segmento::Segmento(const string& nombre, int espacios, float precio)
    : nombre(nombre), precio(precio), espaciosTotales(espacios) {
    // Inicializar todos los espacios como libres (false)
    espacios.resize(espaciosTotales, false);
}

void Segmento::setEspacios(int nuevosEspacios) {
    espaciosTotales = nuevosEspacios;
    espacios.resize(espaciosTotales, false);  // Redimensionamos el vector
}

void Segmento::setPrecio(float nuevoPrecio) {
    precio = nuevoPrecio;
}

void Segmento::ocuparEspacio(int espacio) {
    if (espacio >= 0 && espacio < espaciosTotales) {
        espacios[espacio] = true;  // Marcar como ocupado
    }
}

bool Segmento::estaOcupado(int espacio) const {
    if (espacio >= 0 && espacio < espaciosTotales) {
        return espacios[espacio];  // Retorna si el espacio está ocupado
    }
    return false;
}

string Segmento::getNombre() const {
    return nombre;
}

float Segmento::getPrecio() const {
    return precio;
}

int Segmento::getEspacios() const {
    return espaciosTotales;
}

int Segmento::getEspacioLibre() const {
    int libres = 0;
    for (bool ocupado : espacios) {
        if (!ocupado) {
            libres++;
        }
    }
    return libres;  // Retorna la cantidad de espacios libres
}
