#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

using namespace std;

class Vehiculo {
public:
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

#endif // VEHICULO_H
