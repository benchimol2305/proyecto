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
    string edula;
    string nombre;
    string apellido;
    string email;
    int cantidad_vehiculos_rentados;
    bool activo;
    string direccion;
};
