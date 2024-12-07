#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

class Cliente {
public:
    string cedula;
    string nombre;
    string apellido;
    string email;
    string cantidad_vehiculos_rentados;
    bool activo;
    string direccion;
};

#endif // CLIENTE_H
