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
int year;
int kilometraje;
bool rentado;
string motor;
float precio_renta;
string cedula_cliente;
string fecha_entrega;
};

struct Cliente
{
    string cedula;
    string nombre;
    string apellido;
    string email;
    int cantidad_vehiculos_rentados;
    bool activo;
    string direccion;
};

struct repuesto
{
string modelo_repuesto;
string marca_repuesto;
string nombre_repuesto;
string modelo_carro;
int year_auto;
float precio;
bool existencias;
};
void leervehiculos(vehiculo vehiculos[], int&cantidad){
    ifstream archivo("Vehiculos.csv");
    string linea;
    cantidad=0;
    while (getline(archivo, linea) && cantidad < 100) {
        stringstream ss(linea);
        getline(ss, vehiculos[cantidad].modelo, ',');
        getline(ss, vehiculos[cantidad].marca, ',');
        getline(ss, vehiculos[cantidad].placa, ',');
        getline(ss, vehiculos[cantidad].color, ',');
        ss >> vehiculos[cantidad].year; ss.ignore(1);
        ss >> vehiculos[cantidad].kilometraje; ss.ignore(1);
        ss >> vehiculos[cantidad].rentado; ss.ignore(1);
        getline(ss, vehiculos[cantidad].motor, ',');
        ss >> vehiculos[cantidad].precio_renta; ss.ignore(1);
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
    while (getline(archivo, linea) && cantidad < 100) { 
        stringstream ss(linea); 
        getline(ss, clientes[cantidad].cedula, ',');
        getline(ss, clientes[cantidad].nombre, ',');
        getline(ss, clientes[cantidad].apellido, ','); 
        getline(ss, clientes[cantidad].email, ','); 
        ss >> clientes[cantidad].cantidad_vehiculos_rentados; ss.ignore(1); 
        getline(ss, clientes[cantidad].direccion, ','); 
        ss >> clientes[cantidad].activo;
        cantidad++;
 } 
archivo.close(); 
}
void leerRepuestos(repuesto repuestos[], int &cantidad){
    ifstream archivo("Repuestos.csv");
    string linea;
    cantidad= 0;
    while (getline(archivo, linea) && cantidad < 1000)
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
    int cantidadVehiculos;
    int cantidadClientes;
    int cantidadRepuestos;

    