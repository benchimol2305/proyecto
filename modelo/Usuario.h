#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

class Usuario {
public:
    string nombre;
    string contrasena;
    string rol; // "admin", "manager" o "empleado"

    void registrar();
    bool autenticar(string &rol) const;
};

#endif // USUARIO_H
