#pragma once
#include <string>
using namespace std;

class Integrantes{

private:
string Nombre;
string Rol;

public:

string returnNombre(){
    return Nombre;
}

string returnRol(){
    return Rol;
}

Integrantes(const string& nombre, const string& rol);
string getNombre() const;
string getRol() const;

void  Presentarse(Integrantes& integrante) {
returnNombre();
returnRol();}
};