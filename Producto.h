#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    int id;
    string nombre;
    string categoria;
    double precio;
    int stock;

public:
    // Constructor por defecto
    Producto() {
        id = 0;
        nombre = "";
        categoria = "";
        precio = 0.0;
        stock = 0;
    }

    // Constructor parametrizado
    Producto(int id, string nombre, string categoria, double precio, int stock) {
        this->id = id;
        this->nombre = nombre;
        this->categoria = categoria;
        this->precio = precio;
        this->stock = stock;
    }

    // Getters
    int getId() { return id; }
    string getNombre() { return nombre; }
    string getCategoria() { return categoria; }
    double getPrecio() { return precio; }
    int getStock() { return stock; }

    // Setters
    void setNombre(string nombre) { this->nombre = nombre; }
    void setCategoria(string categoria) { this->categoria = categoria; }
    void setPrecio(double precio) { this->precio = precio; }
    void setStock(int stock) { this->stock = stock; }

    // Reducir stock (validado)
    bool reducirStock(int cantidad) {
        if (cantidad <= stock) {
            stock -= cantidad;
            return true;
        }
        return false;
    }

    // Aumentar stock
    void aumentarStock(int cantidad) {
        stock += cantidad;
    }

    // Mostrar información
    void mostrarInformacion() {
        cout << "ID: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Categoria: " << categoria << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Stock: " << stock << endl;
    }
};

#endif
