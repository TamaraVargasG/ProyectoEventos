#include "SalesSystem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

SalesSystem::SalesSystem() : nombreEvento(""), totalEntradas(0), entradasVendidas(0),
numSegmentos(0), descuentoPorcentaje(0), descuentoLimite(0), codigoDescuento("")
{
	segmentos = nullptr;
}

SalesSystem::~SalesSystem()
{
	for (int i = 0; i < numSegmentos; ++i) {
		for (int j = 0; j < segmentos[i].filas; ++j) {
			delete[]segmentos[i].matriz[j];
		}
		delete[]segmentos[i].matriz;
	}
	delete[]segmentos;
}

void SalesSystem::inicializarMatriz(Segmento& segmento)
{
	segmento.matriz = new char* [segmento.filas];
	for (int i = 0; i < segmento.filas; ++i) {
		segmento.matriz[i] = new char[segmento.columnas];
		for (int j = 0; j < segmento.columnas; ++j) {
			segmento.matriz[i][j] = 176;
		}
	}
}

void SalesSystem::configurarEvento()
{
	cout << "Ingrese el nombre del Evento: ";
	cin.ignore(10000, '\n');
	getline(cin, nombreEvento);


	cout << "Ingrese el numero de Segmentos: ";
	cin >> numSegmentos;
	cout << "\n";
	cin.ignore();

	segmentos = new Segmento[numSegmentos];

	for (int i = 0; i < numSegmentos; ++i) {
		cout << "Segmento " << i + 1 << ":" << endl;
		cout << "Ingrese el numero de filas: ";
		cin >> segmentos[i].filas;
		cout << "Ingrese el numero de columnas: ";
		cin >> segmentos[i].columnas;
		cin.ignore();
		cout << "Ingrese el precio del Segmento $: ";
		cin >> segmentos[i].precio;
		cin.ignore();
		cout << "\n";
		inicializarMatriz(segmentos[i]);
		totalEntradas += segmentos[i].filas * segmentos[i].columnas;

	}
}

void SalesSystem::configurarDescuento()
{
	cout << "Ingrese el procentaje de descuento (sin %): ";
	cin >> descuentoPorcentaje;
	cout << "Ingrese el limite de personas con descuentos: ";
	cin >> descuentoLimite;
	cout << "Ingrese el codigo de descuento (alfanumerico): ";
	cin >> codigoDescuento;
}

void SalesSystem::venderEntrada()
{
	cout << "Vender entradas para el evento: " << nombreEvento << endl;
	cout << "Entradas disponibles: " << totalEntradas - entradasVendidas << endl;

	string idComprador, nombreComprador, fechaNacimiento;
	int numEntradas;
	cout << "Ingrese su ID (0-8): ";
	cin >> idComprador;
	cout << "Ingrese su Nombre: ";
	cin.ignore();
	getline(cin, nombreComprador);
	cout << "Ingrese su fecha de nacimiento (DD/MM/AAAA): ";
	getline(cin, fechaNacimiento);

	cout << "Ingrese el numero de entras a comprar: ";
	cin >> numEntradas;

	if (numEntradas > 5) {
		cout << "No puede comprar mas de 5 entradas por persona." << endl;
		return;
	}

	char tieneDescuento;
	cout << "Tiene codigo de descuento? (s/n): ";
	cin >> tieneDescuento;
	cout << "\n";

	float total = 0;
	int entradasConDescuento = 0;

	if (tieneDescuento == 's' || tieneDescuento == 'S') {
		string codigoIngresado;
		cout << "Ingrese su codigo de descuento: ";
		cin >> codigoIngresado;

		if (codigoIngresado == codigoDescuento) {
			cout << "Codigo de descuento valido.\n";
		}
		else {
			cout << "Codigo de descuento invalido.\n";
			tieneDescuento = 'n';
		}
	}

	int segmentoSeleccionado, fila, columna;

	for (int i = 0; i < numEntradas; ++i) {
		cout << "Seleccione el segmento (1 a " << numSegmentos << ") en el que desea comprar: ";
		cin >> segmentoSeleccionado;

		if (segmentoSeleccionado < 1 || segmentoSeleccionado > numSegmentos) {
			cout << "Segmento invalido.Intente nuevamente." << endl;
			--i;
			continue;

		}

		cout << "Seleccione la fila: ";
		cin >> fila;
		cout << "Seleccione la columna: ";
		cin >> columna;
		cout << "\n";

		if (segmentos[segmentoSeleccionado - 1].matriz[fila - 1][columna - 1] == 178) {
			cout << "Asiento ocupado.Seleccione otro asiento." << endl;
			--i;
			continue;
		}

		segmentos[segmentoSeleccionado - 1].matriz[fila - 1][columna - 1] = 178;
		total += segmentos[segmentoSeleccionado - 1].precio;

		if (tieneDescuento == 's' || tieneDescuento == 'S') {
			if (entradasConDescuento < descuentoLimite) {
				total -= total * descuentoPorcentaje / 100.0f;
				entradasConDescuento++;

			}
		}
	}
	entradasVendidas += numEntradas;

	cout << "Total a pagar: " << total << endl;
	cout << "Compra realizada con exito. " << endl;

}

void SalesSystem::consultarEstadoVentas()
{
	cout << "Estado de las ventas para el evento: " << nombreEvento << endl;
	cout << "Entradas vendidas: " << entradasVendidas << "/" << totalEntradas << endl;
	cout << "Entradas disponibles: " << totalEntradas - entradasVendidas << endl;

	for (int s = 0; s < numSegmentos; s++) {
		cout << "Segmento " << s + 1 << " (Precio: " << segmentos[s].precio << "):\n";
		for (int i = 0; i < segmentos[s].filas; i++) {
			for (int j = 0; j < segmentos[s].columnas; j++) {
				cout << segmentos[s].matriz[i][j] << ' ';
			}
			cout << endl;
			cout << endl;
		}
		cout << endl;
	}
}

void SalesSystem::acerdaDe()
{
	cout << "Sistema de ventas para eventos \n";
	cout << "Desarrollado por: Tamara Vargas" << endl;
}