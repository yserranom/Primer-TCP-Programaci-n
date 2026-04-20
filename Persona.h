#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    string apellido;
    string id;
    string telefono;

public:
    // Constructor por defecto
    Persona() {}

    // Constructor parametrizado
    Persona(string nombre, string apellido, string id, string telefono) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->id = id;
        this->telefono = telefono;
    }

    // Getters
    string getNombre() { return nombre; }
    string getApellido() { return apellido; }
    string getId() { return id; }
    string getTelefono() { return telefono; }

    // Setters
    void setNombre(string nombre) { this->nombre = nombre; }
    void setApellido(string apellido) { this->apellido = apellido; }
    void setId(string id) { this->id = id; }
    void setTelefono(string telefono) { this->telefono = telefono; }

    // Métodos virtuales
    virtual void mostrarInformacion() {
        cout << "Nombre: " << nombre << " " << apellido << endl;
        cout << "ID: " << id << endl;
        cout << "Teléfono: " << telefono << endl;
    }

    // Destructor virtual (buena práctica)
    virtual ~Persona() {}
};

#endif
