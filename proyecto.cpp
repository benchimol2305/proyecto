#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct vehiculo {
    string modelo;
    string marca;
    string placa;
    string color;
    string year;
    string kilometraje;
    bool rentado;
    string motor;
    string precio_renta;
    string cedula_cliente;
    string fecha_entrega;
};

struct Cliente {
    string cedula;
    string nombre;
    string apellido;
    string email;
    string cantidad_vehiculos_rentados;
    bool activo;
    string direccion;
};

struct repuesto {
    string modelo_repuesto;
    string marca_repuesto;
    string nombre_repuesto;
    string modelo_carro;
    string year_auto;
    string precio;
    bool existencias;
};

void leervehiculos(vehiculo vehiculos[], int &cantidad) {
    ifstream archivo("../proyec.bin/Vehiculos.csv");
    string linea;
    cantidad = 0;
    while (getline(archivo, linea) && cantidad < 1000) {
        stringstream ss(linea);
        getline(ss, vehiculos[cantidad].modelo, ',');
        getline(ss, vehiculos[cantidad].marca, ',');
        getline(ss, vehiculos[cantidad].placa, ',');
        getline(ss, vehiculos[cantidad].color, ',');
        getline(ss, vehiculos[cantidad].year, ',');
        getline(ss, vehiculos[cantidad].kilometraje, ',');
        string rentado;
        getline(ss, rentado, ',');
        vehiculos[cantidad].rentado = (rentado == "si");
        getline(ss, vehiculos[cantidad].motor, ',');
        getline(ss, vehiculos[cantidad].precio_renta, ',');
        getline(ss, vehiculos[cantidad].cedula_cliente, ',');
        getline(ss, vehiculos[cantidad].fecha_entrega, ',');
        cantidad++;
    }
    archivo.close();
}

void leerClientes(Cliente clientes[], int &cantidad) {
    ifstream archivo("../proyec.bin/Clientes.csv");;
    string linea; 
    cantidad = 0;
    while (getline(archivo, linea) && cantidad < 1000) {
        stringstream ss(linea);
        getline(ss, clientes[cantidad].cedula, ',');
        getline(ss, clientes[cantidad].nombre, ',');
        getline(ss, clientes[cantidad].apellido, ','); 
        getline(ss, clientes[cantidad].email, ','); 
        getline(ss, clientes[cantidad].cantidad_vehiculos_rentados, ','); 
        getline(ss, clientes[cantidad].direccion, ',');
        string activo;
        getline(ss, activo, ',');
        clientes[cantidad].activo = (activo == "true");
        cantidad++;
    }
    archivo.close();
}

void leerRepuestos(repuesto repuestos[], int &cantidad) {
    ifstream archivo("../proyec.bin/Repuestos.csv");
    string linea;
    cantidad = 0;
    while (getline(archivo, linea) && cantidad < 1000) {
        stringstream ss(linea);
        getline(ss, repuestos[cantidad].modelo_repuesto, ',');
        getline(ss, repuestos[cantidad].marca_repuesto, ',');
        getline(ss, repuestos[cantidad].nombre_repuesto, ','); 
        getline(ss, repuestos[cantidad].modelo_carro, ','); 
        getline(ss, repuestos[cantidad].year_auto, ',');
        getline(ss, repuestos[cantidad].precio, ',');
        string existencias;
        getline(ss, existencias, ',');
        repuestos[cantidad].existencias = (existencias == "true");
        cantidad++;
    }
    archivo.close();
}

void buscarVehiculo(const vehiculo vehiculos[], int cantidad) {
    string modeloBuscado;
    cout << "Ingrese el modelo del vehículo que desea buscar: ";
    cin >> modeloBuscado;

bool encontrado = false;
    cout << "Vehículos encontrados:\n";
    for (int i = 0; i < cantidad; i++) {
        if (vehiculos[i].modelo == modeloBuscado) {
            cout << "Modelo: " << vehiculos[i].modelo << "\n"
                 << "Marca: " << vehiculos[i].marca << "\n"
                 << "Placa: " << vehiculos[i].placa << "\n"
                 << "Color: " << vehiculos[i].color << "\n"
                 << "Año: " << vehiculos[i].year << "\n"
                 << "Kilometraje: " << vehiculos[i].kilometraje << "\n"
                 << "Rentado: " << (vehiculos[i].rentado ? "Sí" : "No") << "\n"
                 << "Motor: " << vehiculos[i].motor << "\n"
                 << "Precio de renta: " << vehiculos[i].precio_renta << "\n"
                 << "Cédula del cliente: " << vehiculos[i].cedula_cliente << "\n"
                 << "Fecha de entrega: " << vehiculos[i].fecha_entrega << "\n\n";
            encontrado = true;
        }
    }

  if (!encontrado) {
        cout << "Vehículo no encontrado.\n";
    }
}

void buscarCliente(const Cliente clientes[], int cantidad) {
    string cedulaBuscada;
    cout << "Ingrese la cédula del cliente que desea buscar: ";
    cin >> cedulaBuscada;

 bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i].cedula == cedulaBuscada) {
            cout << "Cliente encontrado:\n"
                 << "Cédula: " << clientes[i].cedula << "\n"
                 << "Nombre: " << clientes[i].nombre << "\n"
                 << "Apellido: " << clientes[i].apellido << "\n"
                 << "Email: " << clientes[i].email << "\n"
                 << "Cantidad de vehículos rentados: " << clientes[i].cantidad_vehiculos_rentados << "\n"
                 << "Dirección: " << clientes[i].direccion << "\n"
                 << "Activo: " << (clientes[i].activo ? "Sí" : "No") << "\n";
            encontrado = true;
            break;
        }
    } 
if (!encontrado) {
        cout << "Cliente no encontrado.\n";
    }
}

void buscarRepuesto(const repuesto repuestos[], int cantidad) {
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
                 << "Año del auto: " << repuestos[i].year_auto << "\n"
                 << "Precio: " << repuestos[i].precio << "\n"
                 << "Existencias: " << (repuestos[i].existencias ? "Sí" : "No") << "\n\n";
            encontrado = true;
        }
    }
 if (!encontrado) {
        cout << "Repuesto no encontrado.\n";
    }
}

void guardarVehiculos(const vehiculo vehiculos[], int cantidad) {
    ofstream archivo("Vehiculos.csv");
    if (archivo.is_open()) {
        for (int i = 0; i < cantidad; ++i) {
            archivo << vehiculos[i].modelo << ","
                    << vehiculos[i].marca << ","
                    << vehiculos[i].placa << ","
                    << vehiculos[i].color << ","
                    << vehiculos[i].year << ","
                    << vehiculos[i].kilometraje << ","
                    << (vehiculos[i].rentado ? "si" : "no") << ","
                    << vehiculos[i].motor << ","
                    << vehiculos[i].precio_renta << ","
                    << vehiculos[i].cedula_cliente << ","
                    << vehiculos[i].fecha_entrega << endl;
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo de vehículos." << endl;
    }
}

void guardarClientes(const Cliente clientes[], int cantidad) {
    ofstream archivo("Clientes.csv");
    if (archivo.is_open()) {
        for (int i = 0; i < cantidad; ++i) {
            archivo << clientes[i].cedula << ","
                    << clientes[i].nombre << ","
                    << clientes[i].apellido << ","
                    << clientes[i].email << ","
                    << clientes[i].cantidad_vehiculos_rentados << ","
                    << clientes[i].direccion << ","
                    << (clientes[i].activo ? "true" : "false") << endl;
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo de clientes." << endl;
    }
}

void guardarRepuestos(const repuesto repuestos[], int cantidad) {
    ofstream archivo("Repuestos.csv");
    if (archivo.is_open()) {
        for (int i = 0; i < cantidad; ++i) {
            archivo << repuestos[i].modelo_repuesto << ","
                    << repuestos[i].marca_repuesto << ","
                    << repuestos[i].nombre_repuesto << ","
                    << repuestos[i].modelo_carro << ","
                    << repuestos[i].year_auto << ","
                    << repuestos[i].precio << ","
                    << (repuestos[i].existencias ? "true" : "false") << endl;
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo de repuestos." << endl;
    }
}

void borrarCliente(Cliente clientes[], int &cantidadClientes, vehiculo vehiculos[], int &cantidadVehiculos, repuesto repuestos[], int &cantidadRepuestos, const string &cedula) {
    int i;
    for (i = 0; i < cantidadClientes; ++i) {
        if (clientes[i].cedula == cedula) {
            break;
        }
    }
    if (i < cantidadClientes) {
        for (int j = i; j < cantidadClientes - 1; ++j) {
            clientes[j] = clientes[j + 1];
        }
        cantidadClientes--;
    }
    
    for (int i = 0; i < cantidadVehiculos; ++i) {
        if (vehiculos[i].cedula_cliente == cedula) {
            vehiculos[i].cedula_cliente = ""; 
        }
    }
    
    guardarClientes(clientes, cantidadClientes);
    guardarVehiculos(vehiculos, cantidadVehiculos);
    guardarRepuestos(repuestos, cantidadRepuestos);
}

void actualizarCliente(Cliente clientes[], int cantidadClientes, vehiculo vehiculos[], int cantidadVehiculos, const Cliente& clienteActualizado) {
    for (int i = 0; i < cantidadClientes; ++i) {
        if (clientes[i].cedula == clienteActualizado.cedula) {
            clientes[i] = clienteActualizado; 
            break;
        }
    }
    
    for (int i = 0; i < cantidadVehiculos; ++i) {
        if (vehiculos[i].cedula_cliente == clienteActualizado.cedula) {
            vehiculos[i].cedula_cliente = clienteActualizado.cedula; 
        }
    }
    guardarClientes(clientes, cantidadClientes);
    guardarVehiculos(vehiculos, cantidadVehiculos);
}

void insertarCliente(Cliente clientes[], int &cantidadClientes, const Cliente& nuevoCliente) {
    if (cantidadClientes < 1000) {
        clientes[cantidadClientes] = nuevoCliente;
        cantidadClientes++;
        guardarClientes(clientes, cantidadClientes);
    } else {
        cerr << "No se puede insertar mas clientes, limite alcanzado." << endl;
    }
}

void insertarVehiculo(vehiculo vehiculos[], int &cantidadVehiculos, const vehiculo& nuevoVehiculo) {
    if (cantidadVehiculos < 1000) {
        vehiculos[cantidadVehiculos] = nuevoVehiculo;
        cantidadVehiculos++;
        guardarVehiculos(vehiculos, cantidadVehiculos);
    } else {
        cerr << "No se puede insertar mas vehículos, limite alcanzado." << endl;
    }
}

void insertarRepuesto(repuesto repuestos[], int &cantidadRepuestos, const repuesto& nuevoRepuesto) {
    if (cantidadRepuestos < 1000) {
        repuestos[cantidadRepuestos] = nuevoRepuesto;
        cantidadRepuestos++;
        guardarRepuestos(repuestos, cantidadRepuestos);
    } else {
        cerr << "No se puede insertar mas repuestos, limite alcanzado." << endl;
    }
}


int main() {
    vehiculo vehiculos[1000];
    Cliente clientes[1000];
    repuesto repuestos[1000];
    int cantidadVehiculos = 0;
    int cantidadClientes = 0;
    int cantidadRepuestos = 0;
    int opcion = 0;
    string cedulaABorrar;
    char continuar = 'n';
    
       do {
        cout << "¿Qué archivo desea ver?\n";
        cout << "1. Vehículos\n";
        cout << "2. Clientes\n"; 
        cout << "3. Repuestos\n";
        cout << "4. Borrar Cliente\n";
        cout << "5. Actualizar Cliente\n";
        cout << "6. Insertar Cliente\n";
        cout << "7. Insertar Vehículo\n"; 
        cout << "8. Insertar Repuesto\n"; 
        cout << "9. Buscar Vehículo\n";
        cout << "10. Buscar Cliente\n";
           
        cout << "12. Salir\n";
        cout << "Ingrese su opción: "; 
        cin >> opcion; 
        cin.ignore(100, '\n');
        
        switch (opcion) {
            case 1:
                leervehiculos(vehiculos, cantidadVehiculos);
                cout << "Datos de Vehículos:\n";
                for (int i = 0; i < cantidadVehiculos; i++) {
                    cout << vehiculos[i].modelo << ", " 
                         << vehiculos[i].marca << ", " 
                         << vehiculos[i].placa << ", " 
                         << vehiculos[i].color << ", " 
                         << vehiculos[i].year << ", " 
                         << vehiculos[i].kilometraje << ", "
                         << vehiculos[i].rentado << ", "
                         << vehiculos[i].motor << ", " 
                         << vehiculos[i].precio_renta << ", " 
                         << vehiculos[i].cedula_cliente << ", " 
                         << vehiculos[i].fecha_entrega << endl;
                }
                break;
            case 2:
                leerClientes(clientes, cantidadClientes); 
                cout << "Datos de Clientes:\n";
                for (int i = 0; i < cantidadClientes; i++) { 
                    cout << clientes[i].cedula << ", " 
                         << clientes[i].nombre << ", " 
                         << clientes[i].apellido << ", " 
                         << clientes[i].email << ", " 
                         << clientes[i].cantidad_vehiculos_rentados << ", " 
                         << clientes[i].direccion << ", "
                         << clientes[i].activo << endl;
                }
                break;

            case 3:
                leerRepuestos(repuestos, cantidadRepuestos);
                cout << "Datos de Repuestos:\n";
                for (int i = 0; i < cantidadRepuestos; i++) { 
                    cout << repuestos[i].modelo_repuesto << ", " 
                         << repuestos[i].marca_repuesto << ", " 
                         << repuestos[i].nombre_repuesto << ", " 
                         << repuestos[i].modelo_carro << ", " 
                         << repuestos[i].year_auto << ", " 
                         << repuestos[i].precio << ", "
                         << repuestos[i].existencias << endl;
                }
                break;

            case 4:
                leerClientes(clientes, cantidadClientes);
                leervehiculos(vehiculos, cantidadVehiculos);
                leerRepuestos(repuestos, cantidadRepuestos);

                cout << "Introduce la cedula del cliente a borrar: ";
                cin >> cedulaABorrar;
                borrarCliente(clientes, cantidadClientes, vehiculos, cantidadVehiculos, repuestos, cantidadRepuestos, cedulaABorrar);
                cout << "Cliente con cedula " << cedulaABorrar << " ha sido borrado, y los datos asociados han sido actualizados." << endl;
                break;

            case 5:
                leerClientes(clientes, cantidadClientes);
                leervehiculos(vehiculos, cantidadVehiculos);

                {
                    Cliente clienteActualizado;
                    cout << "Introduce la cédula del cliente a actualizar: ";
                    cin >> clienteActualizado.cedula;
                    cout << "Introduce el nuevo nombre: ";
                    cin.ignore(); 
                    getline(cin, clienteActualizado.nombre);
                    cout << "Introduce el nuevo apellido: ";
                    getline(cin, clienteActualizado.apellido);
                    cout << "Introduce el nuevo email: ";
                    getline(cin, clienteActualizado.email);
                    cout << "Introduce la cantidad de vehículos rentados: ";
                    getline(cin, clienteActualizado.cantidad_vehiculos_rentados);
                    cout << "Introduce la nueva dirección: ";
                    getline(cin, clienteActualizado.direccion);
                    cout << "Esta activo? (1 para si, 0 para no): ";
                    cin >> clienteActualizado.activo;

                    actualizarCliente(clientes, cantidadClientes, vehiculos, cantidadVehiculos, clienteActualizado);
                    cout << "Cliente con cedula " << clienteActualizado.cedula << " ha sido actualizado y los datos asociados han sido actualizados." << endl;
                }
                break;

            case 6: {
                Cliente nuevoCliente;
                cout << "Introduce la cedula del nuevo cliente: ";
                cin >> nuevoCliente.cedula;
                cout << "Introduce el nombre del nuevo cliente: ";
                cin.ignore(); 
                getline(cin, nuevoCliente.nombre);
                cout << "Introduce el apellido del nuevo cliente: ";
                getline(cin, nuevoCliente.apellido);
                cout << "Introduce el email del nuevo cliente: ";
                getline(cin, nuevoCliente.email);
                cout << "Introduce la cantidad de vehiculos rentados: ";
                getline(cin, nuevoCliente.cantidad_vehiculos_rentados);
                cout << "Introduce la direccion del nuevo cliente: ";
                getline(cin, nuevoCliente.direccion);
                cout << "¿Está activo? (1 para si, 0 para no): ";
                cin >> nuevoCliente.activo;

                insertarCliente(clientes, cantidadClientes, nuevoCliente);
                cout << "Cliente insertado con exito." << endl;
                break;
            }
            case 7: {
                vehiculo nuevoVehiculo;
                cout << "Introduce el modelo del nuevo vehiculo: ";
                cin >> nuevoVehiculo.modelo;
                cout << "Introduce la marca del nuevo vehiculo: ";
                cin.ignore(); 
                getline(cin, nuevoVehiculo.marca);
                cout << "Introduce la placa del nuevo vehiculo: ";
                getline(cin, nuevoVehiculo.placa);
                cout << "Introduce el color del nuevo vehiculo: ";
                getline(cin, nuevoVehiculo.color);
                cout << "Introduce el año del nuevo vehiculo: ";
                getline(cin, nuevoVehiculo.year);
                cout << "Introduce el kilometraje del nuevo vehiculo: ";
                getline(cin, nuevoVehiculo.kilometraje);
                cout << "Esta rentado? (1 para sí, 0 para no): ";
                cin >> nuevoVehiculo.rentado;
                cout << "Introduce el motor del nuevo vehículo: ";
                cin.ignore(); 
                getline(cin, nuevoVehiculo.motor);
                cout << "Introduce el precio de renta del nuevo vehiculo: ";
                getline(cin, nuevoVehiculo.precio_renta);
                cout << "Introduce la cédula del cliente: ";
                getline(cin, nuevoVehiculo.cedula_cliente);
                cout << "Introduce la fecha de entrega: ";
                getline(cin, nuevoVehiculo.fecha_entrega);

                insertarVehiculo(vehiculos, cantidadVehiculos, nuevoVehiculo);
                cout << "Vehiculo insertado con exito." << endl;
                break;
            }
            case 8: {
                repuesto nuevoRepuesto;
                cout << "Introduce el modelo del nuevo repuesto: ";
                cin >> nuevoRepuesto.modelo_repuesto;
                cout << "Introduce la marca del nuevo repuesto: ";
                cin.ignore(); 
                getline(cin, nuevoRepuesto.marca_repuesto);
                cout << "Introduce el nombre del nuevo repuesto: ";
                getline(cin, nuevoRepuesto.nombre_repuesto);
                cout << "Introduce el modelo del carro: ";
                getline(cin, nuevoRepuesto.modelo_carro);
                cout << "Introduce el año del auto: ";
                getline(cin, nuevoRepuesto.year_auto);
                cout << "Introduce el precio del repuesto: ";
                getline(cin, nuevoRepuesto.precio);
                cout << "Hay existencias? (1 para si, 0 para no): ";
                cin >> nuevoRepuesto.existencias;

                insertarRepuesto(repuestos, cantidadRepuestos, nuevoRepuesto);
                cout << "Repuesto insertado con exito." << endl;
                break;
            }
            case 9: {
                cout << "Saliendo del programa.\n" << endl;
                return 0;
            }
        }

        cout << "Desea continuar viendo otro archivo? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    return 0;
}

