#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <vector>
#include <string>
#include "Producto.h"

class Venta {
private:
    int id;
    std::string clienteId;
    std::vector<Producto> productos;
    double total;

public:
    // Constructor por defecto
    Venta() {
        id = 0;
        clienteId = "";
        total = 0.0;
    }

    // Constructor con parámetros
    Venta(int id, std::string clienteId) {
        this->id = id;
        this->clienteId = clienteId;
        this->total = 0.0;
    }

    // Getters
    int getID() const { return id; }
    std::string getClienteId() const { return clienteId; }
    double getTotal() const { return total; }

    // Agregar producto a la venta
    void agregarProducto(Producto& producto, int cantidad) {
        if (producto.getStock() >= cantidad) {
            producto.reducirStock(cantidad);

            for (int i = 0; i < cantidad; i++) {
                productos.push_back(producto);
            }
            total += producto.getPrecio() * cantidad;
        } else {
            std::cout << "Stock insuficiente para el producto: "
                      << producto.getNombre() << "\n";
        }
    }

    // Calcular total
    void calcularTotal() {
        total = 0.0;
        for (const Producto& p : productos) {
            total += p.getPrecio();
        }
    }

    // Mostrar resumen
    void mostrarResumenVenta() const {
        std::cout << "\n====== RESUMEN DE VENTA =====\n";
        std::cout << "ID Venta: " << id << "\n";
        std::cout << "Cliente ID: " << clienteId << "\n";
        std::cout << "\nProductos:\n";
        for (const Producto& p : productos) {
            std::cout << "- " << p.getNombre() << " $" << p.getPrecio() << "\n";
        }
        std::cout << "\nTotal: $" << total << "\n";
        std::cout << "==============================\n";
    }
};

#endif
