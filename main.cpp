#include <iostream>
#include <vector>
#include "Producto.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Venta.h"

using namespace std;

// ==================== FUNCIONES AUXILIARES ====================

int buscarProducto(vector<Producto>& productos, int id) {
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

int buscarCliente(vector<Cliente>& clientes, string id) {
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

// ========= MENÚ PRODUCTOS =========
void menuProductos(vector<Producto>& productos) {
    int opcion;
    do {
        cout << "\n--- MENU PRODUCTOS ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Eliminar producto\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            int id, stock;
            string nombre, categoria;
            double precio;

            cout << "ID: "; cin >> id;
            cout << "Nombre: "; cin >> nombre;
            cout << "Categoria: "; cin >> categoria;
            cout << "Precio: "; cin >> precio;
            cout << "Stock: "; cin >> stock;

            productos.push_back(Producto(id, nombre, categoria, precio, stock));
            cout << "Producto agregado.\n";

        } else if (opcion == 2) {
            for (auto& p : productos) {
                p.mostrarInformacion();
                cout << "---\n";
            }
        } else if (opcion == 3) {
            int id;
            cout << "ID del producto a eliminar: ";
            cin >> id;

            int pos = buscarProducto(productos, id);
            if (pos != -1) {
                productos.erase(productos.begin() + pos);
                cout << "Producto eliminado.\n";
            } else {
                cout << "No encontrado.\n";
            }
        }
    } while (opcion != 0);
}

// ============ MENU CLIENTES ============
void menuClientes(vector<Cliente>& clientes) {
    int opcion;
    do {
        cout << "\n--- MENU CLIENTES ---\n";
        cout << "1. Agregar cliente\n";
        cout << "2. Mostrar clientes\n";
        cout << "3. Mostrar historial de un cliente\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre, apellido, id, telefono, correo;

            cout << "Nombre: "; cin >> nombre;
            cout << "Apellido: "; cin >> apellido;
            cout << "ID: "; cin >> id;
            cout << "Telefono: "; cin >> telefono;
            cout << "Correo: "; cin >> correo;

            clientes.push_back(Cliente(nombre, apellido, id, telefono, correo));
            cout << "Cliente agregado.\n";

        } else if (opcion == 2) {
            for (auto& c : clientes) {
                c.mostrarInformacion();
                cout << "---\n";
            }
        } else if (opcion == 3) {
            string id;
            cout << "ID del cliente: ";
            cin >> id;
            int pos = buscarCliente(clientes, id);
            if (pos != -1) {
                clientes[pos].mostrarHistorial();
            } else {
                cout << "Cliente no encontrado.\n";
            }
        }
    } while (opcion != 0);
}

// ============ MENÚ EMPLEADOS ============
void menuEmpleados(vector<Empleado>& empleados) {
    int opcion;
    do {
        cout << "\n--- MENU EMPLEADOS ---\n";
        cout << "1. Agregar empleado\n";
        cout << "2. Mostrar empleados\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre, apellido, id, telefono, cargo;
            double salario;

            cout << "Nombre: "; cin >> nombre;
            cout << "Apellido: "; cin >> apellido;
            cout << "ID: "; cin >> id;
            cout << "Telefono: "; cin >> telefono;
            cout << "Cargo: "; cin >> cargo;
            cout << "Salario: "; cin >> salario;

            empleados.push_back(Empleado(nombre, apellido, id, telefono, cargo, salario));
            cout << "Empleado agregado.\n";

        } else if (opcion == 2) {
            for (auto& e : empleados) {
                e.mostrarInformacion();
                cout << "---\n";
            }
        }
    } while (opcion != 0);
}

// ============ MENÚ VENTAS ============
void menuVentas(vector<Venta>& ventas, vector<Producto>& productos, vector<Cliente>& clientes) {
    int opcion;
    do {
        cout << "\n--- MENU VENTAS ---\n";
        cout << "1. Registrar venta\n";
        cout << "2. Mostrar ventas\n";
        cout << "0. Volver\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            int idVenta;
            string idCliente;

            cout << "ID Venta: "; cin >> idVenta;
            cout << "ID Cliente: "; cin >> idCliente;

            int posCliente = buscarCliente(clientes, idCliente);
            if (posCliente == -1) {
                cout << "Cliente no encontrado.\n";
                continue;
            }

            Venta nuevaVenta(idVenta, idCliente);
            int idProducto, cantidad;
            char continuar;

            do {
                cout << "ID Producto: "; cin >> idProducto;
                cout << "Cantidad: "; cin >> cantidad;

                int posProducto = buscarProducto(productos, idProducto);
                if (posProducto != -1) {
                    nuevaVenta.agregarProducto(productos[posProducto], cantidad);
                } else {
                    cout << "Producto no encontrado.\n";
                }

                cout << "Agregar otro producto? (s/n): ";
                cin >> continuar;
            } while (continuar == 's' || continuar == 'S');

            ventas.push_back(nuevaVenta);
            clientes[posCliente].agregarCompra(nuevaVenta.getTotal());
            cout << "Venta registrada exitosamente.\n";

        } else if (opcion == 2) {
            for (auto& v : ventas) {
                v.mostrarResumenVenta();
            }
        }
    } while (opcion != 0);
}

// ============ MAIN ============
int main() {
    vector<Producto> productos;
    vector<Cliente> clientes;
    vector<Empleado> empleados;
    vector<Venta> ventas;

    int opcion;
    do {
        cout << "\n===== MINI ERP =====\n";
        cout << "1. Productos\n";
        cout << "2. Clientes\n";
        cout << "3. Empleados\n";
        cout << "4. Ventas\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuProductos(productos);
                break;
            case 2:
                menuClientes(clientes);
                break;
            case 3:
                menuEmpleados(empleados);
                break;
            case 4:
                menuVentas(ventas, productos, clientes);
                break;
        }
    } while (opcion != 0);

    cout << "Saliendo del sistema...\n";
    return 0;
}
