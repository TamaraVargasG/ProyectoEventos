#include <SFML/Graphics.hpp> 
#include <iostream>          
#include <string> 
#include "SalesSystem.h"  // Asegúrate de tener los archivos SalesSystem.h y SalesSystem.cpp en el mismo directorio
using namespace std;

int main() {
    SalesSystem sistema;
    int opcion;

    do {
        cout << "\n==== SISTEMA DE VENTAS ====\n";
        cout << "1. Configurar Evento\n";
        cout << "2. Configurar Descuentos\n";
        cout << "3. Vender Entrada\n";
        cout << "4. Consultar Estado de las Ventas\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            sistema.configurarEvento();
            break;
        case 2:
            sistema.configurarDescuento();
            break;
        case 3:
            sistema.venderEntrada();
            break;
        case 4:
            sistema.consultarEstadoVentas();
            break;
        case 5:
            cout << "Saliendo del sistema. ¡Hasta pronto!\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 5);

    return 0;
}
