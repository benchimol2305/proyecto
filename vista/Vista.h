#ifndef VISTA_H
#define VISTA_H

#include <iostream>
#include "../modelo/Vehiculo.h"
#include "../modelo/Cliente.h"
#include "../modelo/Repuesto.h"

using namespace std;

void buscarVehiculo(const Vehiculo vehiculos[], int cantidad);
void buscarCliente(const Cliente clientes[], int cantidad);
void buscarRepuesto(const Repuesto repuestos[], int cantidad);

#endif // VISTA_H
