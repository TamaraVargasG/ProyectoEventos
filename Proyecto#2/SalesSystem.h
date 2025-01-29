#pragma once
#ifndef SALES_SYSTEM_H
#define SALES_SYSTEM_H

#include <string>
#include <iostream>
using namespace std;

class SalesSystem
{
private:
	string nombreEvento;
	int totalEntradas;
	int entradasVendidas;
	int numSegmentos;

	struct Segmento {
		int filas;
		int columnas;
		char** matriz;
		float precio;
	} *segmentos;

	int descuentoPorcentaje;
	int descuentoLimite;
	string codigoDescuento;
	void inicializarMatriz(Segmento& segmento);

public:
	SalesSystem();
	~SalesSystem();
	void configurarEvento();
	void configurarDescuento();
	void venderEntrada();
	void consultarEstadoVentas();
	void acerdaDe();


};
#endif
