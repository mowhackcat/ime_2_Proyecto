#pragma once
#include <string>
#include <iostream>
using namespace std;

class Integrantes{

private:
string Nombre;
string Rol;

public:
Integrantes(const string& nombre, const string& rol);
string getNombre() const;
string getRol() const;

void  Presentarse(Integrantes& integrante) {
    cout << "Hola, " << integrante.getNombre() << ", soy " << Nombre << " y mi rol es " << Rol << "." << endl;}
};