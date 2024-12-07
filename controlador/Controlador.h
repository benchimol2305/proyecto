#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../modelo/Usuario.h"
#include "../modelo/Vehiculo.h"
#include "../modelo/Cliente.h"
#include "../modelo/Repuesto.h"

using namespace std;

void registrarUsuario(Usuario &usuario);
bool autenticarUsuario(const Usuario &usuario, string &rol);
bool autenticarUsuario(const Usuario usuarios[], int cantidad, string &rol);
void leervehiculos(Vehiculo vehiculos[], int &cantidad);
void leerClientes(Cliente clientes[], int &cantidad);
void leerRepuestos(Repuesto repuestos[], int &cantidad);

void guardarVehiculos(const Vehiculo vehiculos[], int cantidad);
void guardarClientes(const Cliente clientes[], int cantidad);
void guardarRepuestos(const Repuesto repuestos[], int cantidad);

void guardarVehiculosTemp(const Vehiculo vehiculos[], int cantidad);
void guardarClientesTemp(const Cliente clientes[], int cantidad);
void guardarRepuestosTemp(const Repuesto repuestos[], int cantidad);

void confirmarCambios();

void borrarVehiculo(Vehiculo vehiculos[], int &cantidadVehiculos, const string &placa);
void borrarCliente(Cliente clientes[], int &cantidadClientes, Vehiculo vehiculos[], int &cantidadVehiculos, Repuesto repuestos[], int &cantidadRepuestos, const string &cedula);
void borrarRepuesto(Repuesto repuestos[], int &cantidadRepuestos, const string &modelo_repuesto);

void actualizarCliente(Cliente clientes[], int cantidadClientes, Vehiculo vehiculos[], int cantidadVehiculos, const Cliente& clienteActualizado);
void actualizarVehiculo(Vehiculo vehiculos[], int cantidadVehiculos, Cliente clientes[], int cantidadClientes, const Vehiculo& vehiculoActualizado);
void actualizarRepuesto(Repuesto repuestos[], int cantidadRepuestos, Vehiculo vehiculos[], int cantidadVehiculos, const Repuesto& repuestoActualizado);

void insertarCliente(Cliente clientes[], int &cantidadClientes, const Cliente& nuevoCliente);
void insertarVehiculo(Vehiculo vehiculos[], int &cantidadVehiculos, const Vehiculo& nuevoVehiculo);
void insertarRepuesto(Repuesto repuestos[], int &cantidadRepuestos, const Repuesto& nuevoRepuesto);

string getCurrentTimestamp();
void createBackup(const string& sourceFile);
void backupAllFiles();

#endif // CONTROLADOR_H
