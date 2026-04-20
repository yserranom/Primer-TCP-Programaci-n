#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"
#include <vector>

class Cliente : public Persona {
private:
    string correo;
    vector<double> historialCompras;  // total de cada compra

public:
    // Constructor por defecto
    Cliente() {}

    // Constructor parametrizado
    Cliente(string nombre, string apellido, string id, string telefono,
            string correo)
        : Persona(nombre, apellido, id, telefono) {
        this->correo = correo;
    }

    // Getter y Setter
    string getCorreo() { return correo; }
    void setCorreo(string correo) { this->correo = correo; }

    // Agregar compra
    void agregarCompra(double total) {
        historialCompras.push_back(total);
    }

    // Mostrar historial
    void mostrarHistorial() {
        cout << "Historial de compras:\n";
        for (double compra : historialCompras) {
            cout << "- $" << compra << endl;
        }
    }

    // Calcular total gastado
    double totalGastado() {
        double total = 0;
        for (double compra : historialCompras) {
            total += compra;
        }
        return total;
    }

    // Sobrescritura
    void mostrarInformacion() override {
        Persona::mostrarInformacion();
        cout << "Correo: " << correo << endl;
        cout << "Total gastado: $" << totalGastado() << endl;
    }
};

#endif
