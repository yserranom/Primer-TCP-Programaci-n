# Mini-ERP para MIPYME - Soluciones S.A.

##  Descripción del Proyecto

**Soluciones S.A.** es un emprendimiento familiar dedicado a la venta de productos tecnológicos y servicios. Debido a su crecimiento acelerado, los procesos administrativos actuales (registro manual en papel, control de inventario y análisis limitado) resultan ineficientes y propensos a errores.

Ante esta problemática, se ha desarrollado un sistema tipo **Mini-ERP en consola** que permite automatizar la gestión empresarial, mejorar la organización de la información y facilitar la toma de decisiones mediante reportes y estadísticas.

##  Objetivo del Sistema

Desarrollar un sistema que permita gestionar de forma eficiente:

-  **Productos** - Control de inventario y stock
-  **Clientes** - Gestión de datos e historial de compras
-  **Empleados** - Administración de personal y salarios
-  **Ventas** - Registro de transacciones y actualización automática de stock

### Garantías del Sistema

- Automatización de procesos
- Integridad de los datos
- Facilidad de uso mediante menús interactivos
- Generación de estadísticas y reportes

##  Diseño Orientado a Objetos

### Diagrama de Clases

```Persona (abstract)
├── Empleado
│   ├── cargo (string)
│   ├── salario (double)
│   └── actualizarSalario()
└── Cliente
    ├── correo (string)
    ├── historialCompras (vector<Venta>)
    ├── agregarCompra()
    ├── mostrarHistorial()
    └── calcularTotalGastado()

Producto
├── id, nombre, categoria, precio, costo, stock
├── actualizarStock()
├── hayStockSuficiente()
└── getMargen()

Venta
├── idVenta, idCliente, fecha, total
├── productosVendidos (vector<ProductoVendido>)
├── calcularTotal()
└── printVenta()

ProductoVendido (struct)
├── idProducto
└── cantidad

```

### Clase Base: Persona

**Atributos:**
- `nombre` (string)
- `apellido` (string)
- `ID` (string)
- `teléfono` (string)

**Métodos:**
- Getters y setters
- `mostrarInformacion()` (virtual)

### Clase Empleado (Hereda de Persona)

**Atributos adicionales:**
- `cargo` (string)
- `salario` (double)

**Métodos:**
- `mostrarInformacionCompleta()`
- `actualizarSalario()`

### Clase Cliente (Hereda de Persona)

**Atributos adicionales:**
- `correo` (string)
- `historialCompras` (vector<double>)

**Métodos:**
- `agregarCompra()`
- `mostrarHistorial()`
- `totalGastado()`

### Clase Producto

**Atributos:**
- `id` (int)
- `nombre` (string)
- `categoría` (string)
- `precio` (double)
- `stock` (int)

**Métodos:**
- Getters y setters
- `reducirStock()` (con validación)
- `aumentarStock()`

### Clase Venta

**Atributos:**
- `id` (int)
- `clienteId` (string)
- `productos` (vector<Producto>)
- `total` (double)

**Métodos:**
- `agregarProducto()`
- `calcularTotal()`
- `mostrarResumenVenta()`

##  Fórmulas y Cálculos Implementados

### Costo Total del Inventario

$$C_{inventario} = \sum_{i=1}^{n} (stock_i \times precio_i)$$

### Promedio de Ventas por Cliente

$$Promedio_{c} = \frac{\sum_{i=1}^{m} totalVentas_i}{m}$$

### Promedio de Precios por Categoría

$$Promedio_{cat} = \frac{\sum precio_i}{\text{cantidad de productos en la categoría}}$$

### Margen de Ganancia

$$Margen = Precio\ de\ Venta - Costo$$

##  Estructuras de Datos Utilizadas

### Vectores
- Lista de productos (`vector<Producto>`)
- Lista de clientes (`vector<Cliente>`)
- Lista de empleados (`vector<Empleado>`)
- Lista de ventas (`vector<Venta>`)

### Mapas (propuestos para futuras mejoras)
- Agrupar productos por categoría: `map<string, vector<Producto>>`
- Asociar ventas por cliente: `map<string, vector<Venta>>`
- Controlar stock por producto: `map<int, int>`

##  Reglas de Negocio

1.  **No se puede vender un producto sin stock suficiente**
2.  **No se puede eliminar un cliente con compras registradas**
3.  Los cálculos deben implementarse dentro de las clases
4.  Los filtros y estadísticas deben usar vectores

## 🖥️ Menú Principal del Sistema

```

===== MINI ERP =====

1. Productos
2. Clientes
3. Empleados
4. Ventas
5. Salir

```

### Submenús por Módulo

Cada módulo (Productos, Clientes, Empleados, Ventas) incluye:

-  Crear (Agregar)
-  Modificar (según módulo)
-  Eliminar
-  Consultar
-  Mostrar todos
-  Estadísticas específicas

## 🔧 Requerimientos Funcionales por Módulo

### Gestión de Productos

- [x] Agregar productos
- [x] Modificar productos
- [x] Eliminar productos
- [x] Consultar productos por ID
- [x] Filtrar productos con stock crítico (implementable)
- [x] Identificar producto más caro/más barato (implementable)

### Gestión de Clientes

- [x] Agregar clientes
- [x] Modificar clientes
- [x] Eliminar clientes (con restricción)
- [x] Consultar historial de compras
- [x] Calcular total gastado por cliente

### Gestión de Empleados

- [x] Agregar empleados
- [x] Modificar empleados
- [x] Eliminar empleados
- [x] Consultar información completa
- [x] Salario promedio (implementable)
- [x] Empleado con mayor salario (implementable)

### Gestión de Ventas

- [x] Registrar ventas con:
  - Selección de cliente
  - Selección de productos
  - Actualización automática del stock
  - Cálculo del total
- [x] Mostrar todas las ventas
- [x] Resumen por venta

##  Estructura de Archivos del Proyecto

```

mini-erp/
├── Persona.h          # Clase base (abstracta)
├── Empleado.h         # Herencia de Persona
├── Cliente.h          # Herencia de Persona
├── Producto.h         # Clase producto
├── Venta.h            # Clase venta
├── main.cpp           # Programa principal y menús
└── README.md          # Este archivo

```

##  Cómo Compilar y Ejecutar

### Requisitos Previos

- Compilador de C++ (g++ recomendado, versión C++11 o superior)
- Terminal o consola

### Compilación

```bash
# Compilar todos los archivos
g++ main.cpp -o mini-erp

# O con flags adicionales
g++ main.cpp -std=c++11 -Wall -o mini-erp
```

Ejecución

```bash
# En Linux/Mac
./mini-erp

# En Windows
mini-erp.exe
```

Ejemplo de Compilación Rápida

```bash
git clone https://github.com/tu-usuario/mini-erp.git
cd mini-erp
g++ main.cpp -o erp
./erp
```

💡 Ejemplo de Uso

1. Agregar un Producto

```
--- MENU PRODUCTOS ---
1. Agregar producto
Opción: 1
ID: 101
Nombre: Laptop Gaming
Categoria: Electrónica
Precio: 850.00
Stock: 10
Producto agregado.
```

2. Registrar un Cliente

```
--- MENU CLIENTES ---
1. Agregar cliente
Opción: 1
Nombre: Juan
Apellido: Pérez
ID: C001
Teléfono: 56783796
Correo: juan@gmail.com
Cliente agregado.
```

3. Realizar una Venta

```
--- MENU VENTAS ---
1. Registrar venta
Opción: 1
ID Venta: 1001
ID Cliente: C001
ID Producto: 101
Cantidad: 1
Agregar otro producto? (s/n): n
Venta registrada exitosamente.
```
##   Autores

Desarrollado como parte del primer examen parcial de la asignatura de Programación — Carrera: Ingeniería de Telecomunicaciones y Electrónica.

1. Yadian Serrano Martín 
2. Juan Luis Ruiz Sosa 
3. Adriana Reyes Camejo
4. Ariel Alonso Calzada
5. Yonathan Roque Izquierdo
