#pragma once
#include <string>
using namespace std;

class Integrantes{

private:
string Nombre;
string Rol;

public:

string getNombre(){
    return Nombre;
}

string getRol(){
    return Rol;
}

Integrantes(const string& nombre, const string& rol);
string getNombre() const;
string getRol() const;

void  Presentarse(Integrantes& integrante) {
getNombre();
getRol();}
};