#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado : public Persona {
private:
    string cargo;
    double salario;

public:
    // Constructor por defecto
    Empleado() {}

    // Constructor parametrizado
    Empleado(string nombre, string apellido, string id, string telefono,
             string cargo, double salario)
        : Persona(nombre, apellido, id, telefono) {
        this->cargo = cargo;
        this->salario = salario;
    }

    // Getters
    string getCargo() { return cargo; }
    double getSalario() { return salario; }

    // Setters
    void setCargo(string cargo) { this->cargo = cargo; }
    void setSalario(double salario) { this->salario = salario; }

    // Método para actualizar salario
    void actualizarSalario(double nuevoSalario) {
        salario = nuevoSalario;
    }

    // Sobrescritura (Polimorfismo)
    void mostrarInformacion() override {
        Persona::mostrarInformacion();
        cout << "Cargo: " << cargo << endl;
        cout << "Salario: " << salario << endl;
    }
};

#endif
