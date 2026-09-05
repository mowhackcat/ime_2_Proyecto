#include "Integrantes.h"
using namespace std;

Integrantes::Integrantes(const string& nombre, const string& rol){
    Nombre = nombre;
    Rol = rol;
}

string Integrantes::getNombre() const{
    return Nombre;
}
string Integrantes::getRol() const{
    return Rol;
}

void Presentarse(Integrantes& integrante){
    integrante.getNombre();
    integrante.getRol();
}
