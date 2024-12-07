#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Usuario {
    string nombre;
    string contrasena;
    string rol; // "admin", "manager" o "empleado"
};

void registrarUsuario(Usuario &usuario) {
    cout << "Introduce el nombre del usuario: ";
    cin >> usuario.nombre;
    cout << "Introduce la contraseña del usuario: ";
    cin >> usuario.contrasena;
    cout << "Introduce el rol del usuario (admin, manager, empleado): ";
    cin >> usuario.rol;
}
bool autenticarUsuario(const Usuario &usuario, string &rol) {
    string nombre, contrasena;
    cout << "Ingrese su nombre de usuario: ";
    cin >> nombre;
    cout << "Ingrese su contraseña: ";
    cin >> contrasena;
    cout << "Ingrese su rol (admin, manager, empleado): ";
    cin >> rol;

    if (usuario.nombre == nombre && usuario.contrasena == contrasena && usuario.rol == rol) {
        return true;
    }
    return false;
}

bool autenticarUsuario(const Usuario usuarios[], int cantidad, string &rol) {
    string nombre, contrasena;
    cout << "Ingrese su nombre de usuario: ";
    cin >> nombre;
    cout << "Ingrese su contraseña: ";
    cin >> contrasena;

    for (int i = 0; i < cantidad; ++i) {
        if (usuarios[i].nombre == nombre && usuarios[i].contrasena == contrasena) {
            rol = usuarios[i].rol;
            return true;
        }
    }
    return false;
}

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
    ifstream archivo("Vehiculos.csv");
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
    ifstream archivo("Clientes.csv");;
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
    ifstream archivo("Repuestos.csv");
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
        cerr << "No se pudo abrir el archivo de vehiculos." << endl;
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

void borrarVehiculo(vehiculo vehiculos[], int &cantidadVehiculos, const string &placa) {
    int i;
    for (i = 0; i < cantidadVehiculos; ++i) {
        if (vehiculos[i].placa == placa) {
            break;
        }
    }
    if (i < cantidadVehiculos) {
        for (int j = i; j < cantidadVehiculos - 1; ++j) {
            vehiculos[j] = vehiculos[j + 1];
        }
        cantidadVehiculos--;
    }
    guardarVehiculos(vehiculos, cantidadVehiculos);
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

void borrarRepuesto(repuesto repuestos[], int &cantidadRepuestos, const string &modelo_repuesto) {
    int i;
    for (i = 0; i < cantidadRepuestos; ++i) {
        if (repuestos[i].modelo_repuesto == modelo_repuesto) {
            break;
        }
    }
    if (i < cantidadRepuestos) {
        for (int j = i; j < cantidadRepuestos - 1; ++j) {
            repuestos[j] = repuestos[j + 1];
        }
        cantidadRepuestos--;
    }
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

void actualizarVehiculo(vehiculo vehiculos[], int cantidadVehiculos, Cliente clientes[], int cantidadClientes, const vehiculo& vehiculoActualizado) {
    for (int i = 0; i < cantidadVehiculos; ++i) {
        if (vehiculos[i].placa == vehiculoActualizado.placa) {
            vehiculos[i] = vehiculoActualizado; 
            break;
        }
    }
    for (int i = 0; i < cantidadClientes; ++i) {
        if (clientes[i].cedula == vehiculoActualizado.cedula_cliente) {
            clientes[i].cedula = vehiculoActualizado.cedula_cliente; 
        }
    }
    guardarVehiculos(vehiculos, cantidadVehiculos);
    guardarClientes(clientes, cantidadClientes);
}

void actualizarRepuesto(repuesto repuestos[], int cantidadRepuestos, vehiculo vehiculos[], int cantidadVehiculos, const repuesto& repuestoActualizado) {
    for (int i = 0; i < cantidadRepuestos; ++i) {
        if (repuestos[i].modelo_repuesto == repuestoActualizado.modelo_repuesto) {
            repuestos[i] = repuestoActualizado; 
            break;
        }
    }
    for (int i = 0; i < cantidadVehiculos; ++i) {
        if (vehiculos[i].modelo == repuestoActualizado.modelo_carro) {
            vehiculos[i].modelo = repuestoActualizado.modelo_carro; 
        }
    }
    guardarRepuestos(repuestos, cantidadRepuestos);
    guardarVehiculos(vehiculos, cantidadVehiculos);
}

void insertarCliente(Cliente clientes[], int &cantidadClientes, const Cliente& nuevoCliente) {
    if (cantidadClientes < 1000) {
        clientes[cantidadClientes] = nuevoCliente;
        cantidadClientes++;
        guardarClientes(clientes, cantidadClientes);
    } else {
        cerr << "No se puede insertar más clientes, limite alcanzado." << endl;
    }
}


void insertarVehiculo(vehiculo vehiculos[], int &cantidadVehiculos, const vehiculo& nuevoVehiculo) {
    if (cantidadVehiculos < 1000) {
        vehiculos[cantidadVehiculos] = nuevoVehiculo;
        cantidadVehiculos++;
        guardarVehiculos(vehiculos, cantidadVehiculos);
    } else {
        cerr << "No se puede insertar más vehiculos, limite alcanzado." << endl;
    }
}


void insertarRepuesto(repuesto repuestos[], int &cantidadRepuestos, const repuesto& nuevoRepuesto) {
    if (cantidadRepuestos < 1000) {
        repuestos[cantidadRepuestos] = nuevoRepuesto;
        cantidadRepuestos++;
        guardarRepuestos(repuestos, cantidadRepuestos);
    } else {
        cerr << "No se puede insertar más repuestos, limite alcanzado." << endl;
    }
}

void guardarVehiculosTemp(const vehiculo vehiculos[], int cantidad) {
    ofstream archivo("Vehiculos_temp.csv");
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
        cerr << "No se pudo abrir el archivo temporal de vehículos." << endl;
    }
}

void guardarClientesTemp(const Cliente clientes[], int cantidad) {
    ofstream archivo("Clientes_temp.csv");
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
        cerr << "No se pudo abrir el archivo temporal de clientes." << endl;
    }
}

void guardarRepuestosTemp(const repuesto repuestos[], int cantidad) {
    ofstream archivo("Repuestos_temp.csv");
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
        cerr << "No se pudo abrir el archivo temporal de repuestos." << endl;
    }
}

void confirmarCambios() {
    char confirmar;
    cout << "Desea confirmar los cambios realizados? (s/n): ";
    cin >> confirmar;
    
    if (confirmar == 's' || confirmar == 'S') {
        rename("Vehiculos_temp.csv", "Vehiculos.csv");
        rename("Clientes_temp.csv", "Clientes.csv");
        rename("Repuestos_temp.csv", "Repuestos.csv");
        cout << "Cambios confirmados y aplicados." << endl;
    } else {
        remove("Vehiculos_temp.csv");
        remove("Clientes_temp.csv");
        remove("Repuestos_temp.csv");
        cout << "Cambios descartados." << endl;
    }
}

string getCurrentTimestamp() {
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    stringstream timestamp;
    timestamp << put_time(localtime(&now_c), "%Y-%m-%d_%H-%M-%S");
    return timestamp.str();
}

void createBackup(const string& sourceFile) {
    string timestamp = getCurrentTimestamp();
    string backupFile = "backups/" + sourceFile.substr(0, sourceFile.find_last_of('.')) + "_" + timestamp + sourceFile.substr(sourceFile.find_last_of('.'));
    ifstream src(sourceFile, ios::binary);
    ofstream dst(backupFile, ios::binary);
    dst << src.rdbuf();
    src.close();
    dst.close();
}

void backupAllFiles() {
    system("mkdir backups");
    string sourceFile1 = "Vehiculos.csv";
    string sourceFile2 = "Repuestos.csv";
    string sourceFile3 = "Clientes.csv";
    createBackup(sourceFile1);
    cout << "Copia de seguridad creada para " << sourceFile1 << " exitosamente." << endl;
    createBackup(sourceFile2);
    cout << "Copia de seguridad creada para " << sourceFile2 << " exitosamente." << endl;
    createBackup(sourceFile3);
    cout << "Copia de seguridad creada para " << sourceFile3 << " exitosamente." << endl;
}

int main() {
    system("mkdir backups");
    atexit(backupAllFiles);
    string sourceFile1 = "Vehiculos.csv";
    string sourceFile2 = "Repuestos.csv";
    string sourceFile3 = "Clientes.csv";
    vehiculo vehiculos[1000];
    Cliente clientes[1000];
    repuesto repuestos[1000];
    int cantidadVehiculos = 0;
    int cantidadClientes = 0;
    int cantidadRepuestos = 0;
    int opcion = 0;
    string cedulaABorrar;
    char continuar = 'n';
    Usuario user;
    string rol;

  registrarUsuario(user);

    if (!autenticarUsuario(user, rol)) {
        cout << "Usuario o contraseña incorrectos." << endl;
        return 1;
    }
	  do {
      
	cout << "Â¿Que archivo desea ver?\n";
        cout << "1. Vehiculos\n";
        cout << "2. Clientes\n"; 
        cout << "3. Repuestos\n";
	if (rol == "admin" ) {	  
        cout << "4. Borrar Vehículo\n";
        cout << "5. Borrar Cliente\n";
        cout << "6. Borrar Repuesto\n";	
        cout << "7. Actualizar Cliente\n";
        cout << "8. Actualizar vehiculo\n";
        cout << "9. Actualizar repuesto\n";
	}
	 if (rol == "admin" || rol == "manager") {	  
        cout << "10. Insertar Cliente\n";
        cout << "11. Insertar Vehiculo\n"; 
        cout << "12. Insertar Repuesto\n";
	 }
	cout << "desea buscar algo en especifico?\n";
        cout << "13. Buscar Vehiculo\n";
        cout << "14. Buscar Cliente\n";
        cout << "15. Buscar Repuesto\n";
        cout << "16. Confirmar Cambios\n";
        cout << "17. Salir\n";
        cout << "Ingrese su opcion: "; 
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
		   if (rol == "admin") {
                    string placa;
                    cout << "Ingrese la placa del vehículo a borrar: ";
                    cin >> placa;
                    borrarVehiculo(vehiculos, cantidadVehiculos, placa);
                } else {
                    cout << "No tiene permiso para realizar esta acción." << endl;
                }
                break;

            case 5:
		    if (rol == "admin") {
                    string cedula;
                    cout << "Ingrese la cédula del cliente a borrar: ";
                    cin >> cedula;
                    borrarCliente(clientes, cantidadClientes, vehiculos, cantidadVehiculos, repuestos, cantidadRepuestos, cedula);
                } else {
                    cout << "No tiene permiso para realizar esta acción." << endl;
                }
            
            case 6:  if (rol == "admin") {
                    string modelo_repuesto;
                    cout << "Ingrese el modelo del repuesto a borrar: ";
                    cin >> modelo_repuesto;
                    borrarRepuesto(repuestos, cantidadRepuestos, modelo_repuesto);
                } else {
                    cout << "No tiene permiso para realizar esta acción." << endl;
                }
                break;
        
           case 7:
                if (rol == "admin") {
                    leerClientes(clientes, cantidadClientes);
                    leervehiculos(vehiculos, cantidadVehiculos);

                    {
                        Cliente clienteActualizado;
                        cout << "Introduce la cedula del cliente a actualizar: ";
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
                        cout << "Introduce la nueva direccion: ";
                        getline(cin, clienteActualizado.direccion);
                        cout << "Está activo? (1 para sí, 0 para no): ";
                        cin >> clienteActualizado.activo;

                       void actualizarCliente(Cliente clientes[], int cantidadClientes, const Cliente &clienteActualizado);
                        cout << "Cliente con cedula " << clienteActualizado.cedula << " ha sido actualizado y los datos asociados han sido actualizados." << endl;
                    }
                } else {
                    cout << "No tiene permiso para realizar esta acción." << endl;
                }
                break;
                
            case 8:
            	if (rol == "admin") {
                    leerClientes(clientes, cantidadClientes);
                    leervehiculos(vehiculos, cantidadVehiculos);

                    {
                        vehiculo vehiculoActualizado;
                        cout << "Introduce la placa del vehículo a actualizar: ";
                        cin >> vehiculoActualizado.placa;
                        cout << "Introduce el nuevo modelo: ";
                        cin.ignore(); 
                        getline(cin, vehiculoActualizado.modelo);
                        cout << "Introduce la nueva marca: ";
                        getline(cin, vehiculoActualizado.marca);
                        cout << "Introduce el nuevo color: ";
                        getline(cin, vehiculoActualizado.color);
                        cout << "Introduce el año: ";
                        getline(cin, vehiculoActualizado.year);
                        cout << "Introduce el kilometraje: ";
                        getline(cin, vehiculoActualizado.kilometraje);
                        cout << "Está rentado? (1 para sí, 0 para no): ";
                        cin >> vehiculoActualizado.rentado;
                        cin.ignore();
                        cout << "Introduce el tipo de motor: ";
                        getline(cin, vehiculoActualizado.motor);
                        cout << "Introduce el precio de renta: ";
                        getline(cin, vehiculoActualizado.precio_renta);
                        cout << "Introduce la cédula del cliente: ";
                        getline(cin, vehiculoActualizado.cedula_cliente);
                        cout << "Introduce la fecha de entrega: ";
                        getline(cin, vehiculoActualizado.fecha_entrega);

                        void actualizarVehiculo(vehiculo vehiculos[], int cantidadVehiculos, const vehiculo &vehiculoActualizado);
                        cout << "Vehículo con placa " << vehiculoActualizado.placa << " ha sido actualizado y los datos asociados han sido actualizados." << endl;
                    }
                } else {
                    cout << "No tiene permiso para realizar esta acción." << endl;
                }
                break;

        case 9:
        	
        if (rol == "admin" ) {
        leervehiculos(vehiculos, cantidadVehiculos);
        leerRepuestos(repuestos, cantidadRepuestos);

        {
            repuesto repuestoActualizado;
            cout << "Introduce el modelo del repuesto a actualizar: ";
            cin >> repuestoActualizado.modelo_repuesto;
            cout << "Introduce la nueva marca: ";
            cin.ignore(); 
            getline(cin, repuestoActualizado.marca_repuesto);
            cout << "Introduce el nuevo nombre del repuesto: ";
            getline(cin, repuestoActualizado.nombre_repuesto);
            cout << "Introduce el modelo del carro: ";
            getline(cin, repuestoActualizado.modelo_carro);
            cout << "Introduce el año del auto: ";
            getline(cin, repuestoActualizado.year_auto);
            cout << "Introduce el precio: ";
            getline(cin, repuestoActualizado.precio);
            cout << "Hay existencias? (1 para sí, 0 para no): ";
            cin >> repuestoActualizado.existencias;

           void actualizarRepuesto(repuesto repuestos[], int cantidadRepuestos, const repuesto &repuestoActualizado);
            cout << "Repuesto con modelo " << repuestoActualizado.modelo_repuesto << " ha sido actualizado y los datos asociados han sido actualizados." << endl;
        }
    } else {
        cout << "No tiene permiso para realizar esta acción." << endl;
    }
    break;

            case 10: 
		if (rol == "admin" || rol == "manager") {
		{
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
                cout << "Está activo? (1 para si, 0 para no): ";
                cin >> nuevoCliente.activo;

                insertarCliente(clientes, cantidadClientes, nuevoCliente);
                cout << "Cliente insertado con exito." << endl;
    } break;
            
            case 11:  if (rol == "admin" || rol == "manager"){
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
	    }else {
        cout << "No tiene permiso para realizar esta acción." << endl;
    }
        break;
			
		case 12:  if (rol == "admin" || rol == "manager") {
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
		} else {
        cout << "No tiene permiso para realizar esta acción." << endl;
    }
                break;
            }
        case 13: buscarVehiculo(vehiculos, cantidadVehiculos);
		 break;
	    case 14: buscarCliente(clientes, cantidadClientes); 
		break;
	    case 15: buscarRepuesto(repuestos, cantidadRepuestos); 
		break;
        case 16: {
            confirmarCambios();
            break;
        }
            case 17: {
                cout << "Saliendo del programa.\n" << endl;
                return 0;
            }
        }

        cout << "Desea continuar viendo otro archivo? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    try{
        createBackup(sourceFile1);
        cout<<"Copia de seguridad creada para "<<sourceFile1<<" exitosamente."<<endl;
        createBackup(sourceFile2);
        cout<<"Copia de seguridad creada para "<<sourceFile2<<" exitosamente."<<endl;
        createBackup(sourceFile3);
        cout<<"Copia de seguridad creada para "<<sourceFile3<<" exitosamente."<<endl;
    } catch(const exception& e){
        cerr<<"Error al crear la copia de seguridad: "<<e.what()<<endl;
    }

    return 0;
}

