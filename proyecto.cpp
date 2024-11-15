#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

struct vehiculo
{
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

struct Cliente
{
    string cedula;
    string nombre;
    string apellido;
    string email;
    string cantidad_vehiculos_rentados;
    bool activo;
    string direccion;
};

struct repuesto
{
string modelo_repuesto;
string marca_repuesto;
string nombre_repuesto;
string modelo_carro;
string year_auto;
string precio;
bool existencias;
};
void leervehiculos(vehiculo vehiculos[], int &cantidad){
    ifstream archivo("Vehiculos.csv");
    string linea;
    cantidad=0;
    while (getline(archivo, linea) && cantidad < 1) {
       stringstream ss(linea);
        getline(ss, vehiculos[cantidad].modelo, ',');
        getline(ss, vehiculos[cantidad].marca, ',');
        getline(ss, vehiculos[cantidad].placa, ',');
        getline(ss, vehiculos[cantidad].color, ',');
        ss >> vehiculos[cantidad].year;
        ss.ignore();
        ss >> vehiculos[cantidad].kilometraje;
        ss.ignore();
        string rentado;
        getline(ss, rentado, ',');
        vehiculos[cantidad].rentado = (rentado == "si");
        getline(ss, vehiculos[cantidad].motor, ',');
        ss >> vehiculos[cantidad].precio_renta;
        ss.ignore();
        getline(ss, vehiculos[cantidad].cedula_cliente, ',');
        getline(ss, vehiculos[cantidad].fecha_entrega, ',');
        cantidad++;
       
    }
    archivo.close();
}
void leerClientes(Cliente clientes[], int &cantidad) {
    ifstream archivo("Clientes.csv");
    string linea; 
    cantidad = 0;
    while (getline(archivo, linea) && cantidad < 2) { 
        stringstream ss(linea); 
        getline(ss, clientes[cantidad].cedula, ',');
        getline(ss, clientes[cantidad].nombre, ',');
        getline(ss, clientes[cantidad].apellido, ','); 
        getline(ss, clientes[cantidad].email, ','); 
        ss >> clientes[cantidad].cantidad_vehiculos_rentados; ss.ignore(1); 
        getline(ss, clientes[cantidad].direccion, ',');
        ss>> clientes[cantidad].activo;
        cantidad++;
 } 
archivo.close(); 
}
void leerRepuestos(repuesto repuestos[], int &cantidad){
    ifstream archivo("Repuestos.csv");
    string linea;
    cantidad= 0;
    while (getline(archivo, linea) && cantidad < 2)
    {
        stringstream ss(linea);
        getline(ss, repuestos[cantidad].modelo_repuesto, ',');
        getline(ss, repuestos[cantidad].marca_repuesto, ',');
        getline(ss, repuestos[cantidad].nombre_repuesto, ','); 
        getline(ss, repuestos[cantidad].modelo_carro, ','); 
        ss >> repuestos[cantidad].year_auto; ss.ignore(1);
        ss >> repuestos[cantidad].precio; ss.ignore(1);
        ss >> repuestos[cantidad].existencias; cantidad++;
    }
    archivo.close();

    }


int main (){
    vehiculo vehiculos[1000];
    Cliente clientes[10000];
    repuesto repuestos[1000];
    int cantidadVehiculos=0;
    int cantidadClientes=0;
    int cantidadRepuestos=0;
    int opcion;
    char continuar;
    
    do
    {
        cout << "que archivo desea ver?\n";
        cout << "1. vehiculos\n";
        cout << "2. Clientes\n"; 
        cout << "3. Repuestos\n";
        cout << "4. Salir\n"; 
        cout << "Ingrese su opcion: "; 
        cin >> opcion; 
        cin.ignore(100,'\n');
        switch (opcion)
        {
        case 1:
            leervehiculos(vehiculos, cantidadVehiculos);
            cout<<"datos de vehiculo: \n";
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
                    << vehiculos[i].cedula_cliente<< ", " 
                    << vehiculos[i].fecha_entrega << endl;
            }
            break;
        
        case 2:
            leerClientes(clientes, cantidadClientes); 
            cout << "Datos de Clientes:\n";
            for (int i = 0; i < cantidadClientes; i++) { 
                 cout << clientes[i].cedula << ", " 
                    << clientes[i].nombre << ", " 
                    << clientes[i].apellido<< ", " 
                    << clientes[i].email << ", " 
                    << clientes[i].cantidad_vehiculos_rentados<< ", " 
                    << clientes[i].direccion << ", "
                    << clientes[i].activo << "," <<endl;
            }
            break;

        case 3:
            leerRepuestos(repuestos, cantidadRepuestos);
            cout<< "Datos de los repuestos: \n";
            for (int i = 0; i < cantidadRepuestos; i++) { 
                 cout << repuestos[i].modelo_repuesto << ", " 
                    << repuestos[i].marca_repuesto<< ", " 
                    << repuestos[i].nombre_repuesto<< ", " 
                    << repuestos[i].modelo_carro << ", " 
                    << repuestos[i].year_auto<< ", " 
                    << repuestos[i].precio << ", "
                    << repuestos[i].existencias << ", " <<endl;
            }
            break;
        case 4:
            cout<<"saliendo del programa\n";
            return 0;
        default:
            cout<< "opcion no valida, por favor ingrese algo correcto\n";
            continue;        

        }
        cout<<"desea continuar viendo otro archivo? (s/n): ";
        cin >> continuar;
    } while (continuar=='s' || continuar== 'S');
    
    return 0;
}     
