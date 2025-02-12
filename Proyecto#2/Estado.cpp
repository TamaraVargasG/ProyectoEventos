#include "Estado.h"

Estado::Estado(vector<vector<std::pair<int, bool>>>& segmentos, vector<int>& precios)
    : segmentos(segmentos), precios(precios) {
}

void Estado::mostrar() {
    // Variables para calcular el total
    int totalAsientos = 0;
    int asientosVendidos = 0;
    double dineroRecibido = 0.0;

    // Mostrar los segmentos
    for (int i = 0; i < segmentos.size(); ++i) {
        cout << "Segmento " << i + 1 << " (Precio: " << precios[i] << "):\n";

        int asientosEnSegmento = 0;
        int asientosOcupados = 0;

        // Mostrar los espacios de cada segmento
        for (int j = 0; j < segmentos[i].size(); ++j) {
            // Simbolos: 176 = Vacío, 177 = Reservado, 178 = Ocupado
            char simbolo = segmentos[i][j].second ? (segmentos[i][j].first == 0 ? 177 : 178) : 176;
            cout << simbolo << " ";

            // Contar los asientos
            asientosEnSegmento++;
            if (segmentos[i][j].first == 1) {
                asientosOcupados++;
                dineroRecibido += precios[i];
            }
        }

        // Mostrar el resumen del segmento
        totalAsientos += asientosEnSegmento;
        asientosVendidos += asientosOcupados;

        cout << "\nTotal de asientos en este segmento: " << asientosEnSegmento << "\n";
        cout << "Asientos ocupados en este segmento: " << asientosOcupados << "\n";
        cout << "Dinero acumulado por este segmento: " << asientosOcupados * precios[i] << "\n\n";
    }

    // Mostrar el total global
    cout << "Total de asientos en el evento: " << totalAsientos << "\n";
    cout << "Asientos vendidos: " << asientosVendidos << "\n";
    cout << "Dinero total por ventas: " << dineroRecibido << "\n";
}
