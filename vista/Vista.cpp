#include "Vista.h"

using namespace std;

void buscarVehiculo(const Vehiculo vehiculos[], int cantidad) {
    string modeloBuscado;
    cout << "Ingrese el modelo del vehiculo que desea buscar: ";
    cin >> modeloBuscado;

    bool encontrado = false;
    cout << "Vehiculos encontrados:\n";
    for (int i = 0; i < cantidad; i++) {
        if (vehiculos[i].modelo == modeloBuscado) {
            cout << "Modelo: " << vehiculos[i].modelo << "\n"
                 << "Marca: " << vehiculos[i].marca << "\n"
                 << "Placa: " << vehiculos[i].placa << "\n"
                 << "Color: " << vehiculos[i].color << "\n"
                 << "Fecha de salida: " << vehiculos[i].year << "\n"
                 << "Kilometraje: " << vehiculos[i].kilometraje << "\n"
                 << "Rentado: " << (vehiculos[i].rentado ? "Si" : "No") << "\n"
                 << "Motor: " << vehiculos[i].motor << "\n"
                 << "Precio de renta: " << vehiculos[i].precio_renta << "\n"
                 << "Cedula del cliente: " << vehiculos[i].cedula_cliente << "\n"
                 << "Fecha de entrega: " << vehiculos[i].fecha_entrega << "\n\n";
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "Vehiculo no encontrado.\n";
    }
}

void buscarCliente(const Cliente clientes[], int cantidad) {
    string cedulaBuscada;
    cout << "Ingrese la cedula del cliente que desea buscar: ";
    cin >> cedulaBuscada;

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i].cedula == cedulaBuscada) {
            cout << "Cliente encontrado:\n"
                 << "Cedula: " << clientes[i].cedula << "\n"
                 << "Nombre: " << clientes[i].nombre << "\n"
                 << "Apellido: " << clientes[i].apellido << "\n"
                 << "Email: " << clientes[i].email << "\n"
                 << "Cantidad de vehiculos rentados: " << clientes[i].cantidad_vehiculos_rentados << "\n"
                 << "Direccion: " << clientes[i].direccion << "\n"
                 << "Activo: " << (clientes[i].activo ? "Si" : "No") << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Cliente no encontrado.\n";
    }
}

void buscarRepuesto(const Repuesto repuestos[], int cantidad) {
    string marcaBuscada;
    cout << "Ingrese la marca del repuesto que desea buscar: ";
    cin >> marcaBuscada;

    bool encontrado = false;
    cout << "Repuestos encontrados:\n";
    for (int i = 0; i < cantidad; i++) {
        if (repuestos[i].marca_repuesto == marcaBuscada) {
            cout << "Modelo del repuesto: " << repuestos[i].modelo_repuesto << "\n"
                 << "Marca del repuesto: " << repuestos[i].marca_repuesto << "\n"
                 << "Nombre del repuesto: " << repuestos[i].nombre_repuesto << "\n"
                 << "Modelo del carro: " << repuestos[i].modelo_carro << "\n"
                 << "Fecha de salida del auto: " << repuestos[i].year_auto << "\n"
                 << "Precio: " << repuestos[i].precio << "\n"
                 << "Existencias: " << (repuestos[i].existencias ? "Si" : "No") << "\n\n";
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "Repuesto no encontrado.\n";
    }
}
