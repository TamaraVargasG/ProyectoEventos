#include "SalesSystem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

SalesSystem::SalesSystem() : nombreEvento(""), totalEntradas(0), entradasVendidas(0), numSegmentos(0),
descuentoPorcentaje(0), descuentoLimite(0), maxCodigos(0), totalCedulas(0), segmentos(nullptr),
codigoDescuento(nullptr), porcentajeDescuento(nullptr), cedulas(nullptr), entradasPorCedula(nullptr) {
}

SalesSystem::~SalesSystem() {
    delete[] segmentos;
    delete[] codigoDescuento;      // Aseg�rate de liberar memoria para arreglo de c�digos
    delete[] porcentajeDescuento;  // Aseg�rate de liberar memoria para arreglo de porcentajes
    delete[] cedulas;              // Aseg�rate de liberar memoria para arreglo de c�dulas
    delete[] entradasPorCedula;    // Aseg�rate de liberar memoria para arreglo de entradas por c�dula
}
void SalesSystem::configurarEvento() {
    cout << "Ingrese el nombre del Evento: ";
    cin.ignore();
    getline(cin, nombreEvento);

    cout << "Ingrese el numero de Segmentos: ";
    cin >> numSegmentos;
    segmentos = new Segmento[numSegmentos];

    for (int i = 0; i < numSegmentos; ++i) {
        int filas, columnas;
        float precio;
        cout << "Segmento " << i + 1 << ":\n";
        cout << "Ingrese el numero de filas: ";
        cin >> filas;
        cout << "Ingrese el numero de columnas: ";
        cin >> columnas;
        cout << "Ingrese el precio del Segmento $: ";
        cin >> precio;
        segmentos[i].configurar(filas, columnas, precio);
        totalEntradas += filas * columnas;
    }
}

void SalesSystem::configurarDescuento() {
    cout << "Ingrese el numero de c�digos de descuento a generar: ";
    cin >> maxCodigos;
    codigoDescuento = new string[maxCodigos];
    porcentajeDescuento = new int[maxCodigos];

    srand(time(0));  // Semilla para generar c�digos aleatorios

    for (int i = 0; i < maxCodigos; ++i) {
        int porcentaje;
        cout << "Ingrese el porcentaje de descuento para el c�digo " << i + 1 << ": ";
        cin >> porcentaje;
        porcentajeDescuento[i] = porcentaje;

        // Generar un c�digo alfanum�rico aleatorio de 8 caracteres
        string codigo = "";
        for (int j = 0; j < 8; ++j) {
            char c = (rand() % 36);
            if (c < 10)
                codigo += ('0' + c);  // N�meros 0-9
            else
                codigo += ('A' + c - 10);  // Letras A-Z
        }
        codigoDescuento[i] = codigo;
        cout << "C�digo generado: " << codigo << " con " << porcentaje << "% de descuento.\n";
    }
}
int SalesSystem::verificarCodigoDescuento(string codigo) {
    for (int i = 0; i < maxCodigos; ++i) {
        if (codigoDescuento[i] == codigo)
            return porcentajeDescuento[i];
    }
    return 0;  // C�digo no v�lido, sin descuento
}
bool SalesSystem::registrarCompra(string cedula, int entradas) {
    for (int i = 0; i < totalCedulas; ++i) {
        if (cedulas[i] == stoi(cedula)) {
            if (entradasPorCedula[i] + entradas > 5) {
                cout << "La c�dula " << cedula << " no puede comprar m�s de 5 entradas en total.\n";
                return false;
            }
            entradasPorCedula[i] += entradas;
            return true;
        }
    }
    // Nueva c�dula, registramos la compra
    cedulas[totalCedulas] = stoi(cedula);
    entradasPorCedula[totalCedulas] = entradas;
    totalCedulas++;
    return true;
}
bool SalesSystem::validarCedula(const string& cedula) {
    if (cedula.length() != 5) {
        cout << "La c�dula debe tener exactamente 5 d�gitos." << endl;
        return false;
    }

    for (char c : cedula) {
        if (!isdigit(c)) {
            cout << "La c�dula solo debe contener n�meros." << endl;
            return false;
        }
    }

    return true;
}

void SalesSystem::venderEntrada() {
    cout << "Vender entradas para el evento: " << nombreEvento << endl;
    cout << "Entradas disponibles: " << totalEntradas - entradasVendidas << endl;

    string idComprador, nombreComprador, fechaNacimiento;
    int numEntradas;

    // Solicitar la c�dula y validar
    cout << "Ingrese su c�dula (5 d�gitos): ";
    cin >> idComprador;

    // Limpiar el buffer para evitar problemas con getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Validar la c�dula
    while (!validarCedula(idComprador)) {
        cout << "Ingrese su c�dula (5 d�gitos): ";
        cin >> idComprador;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpiar el buffer
    }

    // Registrar la compra con 0 entradas para verificar la c�dula
    if (!registrarCompra(idComprador, 0)) {
        cout << "Error al registrar la c�dula. No puede proceder con la compra." << endl;
        return;
    }

    // Solicitar el nombre y fecha de nacimiento
    cout << "Ingrese su Nombre: ";
    getline(cin, nombreComprador);

    cout << "Ingrese su fecha de nacimiento (DD/MM/AAAA): ";
    getline(cin, fechaNacimiento);

    // Solicitar el n�mero de entradas
    cout << "Ingrese el numero de entradas a comprar: ";
    cin >> numEntradas;

    // Verificar si el n�mero de entradas es v�lido
    if (!registrarCompra(idComprador, numEntradas)) {
        return;
    }

    float total = 0;
    int segmentoSeleccionado, fila, columna;
    // Ciclo para elegir asientos
    for (int i = 0; i < numEntradas; ++i) {
        cout << "Seleccione el segmento (1 a " << numSegmentos << "): ";
        cin >> segmentoSeleccionado;

        // Validaci�n de rango del segmento
        if (segmentoSeleccionado < 1 || segmentoSeleccionado > numSegmentos) {
            cout << "Segmento inv�lido. Por favor, seleccione un segmento v�lido.\n";
            --i;
            continue;
        }

        cout << "Seleccione la fila: ";
        cin >> fila;
        cout << "Seleccione la columna: ";
        cin >> columna;

        // Validar si el asiento est� disponible
        if (!segmentos[segmentoSeleccionado - 1].ocuparAsiento(fila - 1, columna - 1)) {
            cout << "Asiento ocupado. Seleccione otro asiento.\n";
            --i;
            continue;
        }

        // Acumulando el total
        total += segmentos[segmentoSeleccionado - 1].getPrecio();
    }

    // Aplicar descuento si el usuario tiene un c�digo
    string codigo;
    cout << "Ingrese el c�digo de descuento (si tiene, o presione Enter para continuar): ";
    cin.ignore();  // Limpiar el buffer
    getline(cin, codigo);

    // Verificar y aplicar descuento
    int descuento = verificarCodigoDescuento(codigo);
    if (descuento > 0) {
        float descuentoAplicado = total * (descuento / 100.0);
        total -= descuentoAplicado;
        cout << "Se ha aplicado un descuento de " << descuento << "%: -$" << descuentoAplicado << endl;
    }

    // Actualizar el n�mero de entradas vendidas
    entradasVendidas += numEntradas;

    // Mostrar el total a pagar
    cout << "Total a pagar: $" << total << endl;
    cout << "Compra realizada con �xito.\n";
}

void SalesSystem::consultarEstadoVentas() {
    cout << "Estado de las ventas para el evento: " << nombreEvento << endl;
    cout << "Entradas vendidas: " << entradasVendidas << "/" << totalEntradas << endl;

    for (int i = 0; i < numSegmentos; ++i) {
        cout << "Segmento " << i + 1 << " (Precio: $" << segmentos[i].getPrecio() << "):\n";
        segmentos[i].mostrarMatriz();
        cout << endl;
    }
}

void SalesSystem::acercaDe() {
    cout << "Sistema de ventas para eventos\n";
    cout << "Desarrollado por: Tamara Vargas\n";
}
