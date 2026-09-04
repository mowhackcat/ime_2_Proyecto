#pragma once
#include <string>
using namespace std;

class Integrantes{

private:
string Nombre;
string Rol;

public:

string getNombre() const;
string getRol() const;


Integrantes(const string& nombre, const string& rol);
string getNombre() const;
string getRol() const;


};