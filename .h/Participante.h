//Sinonimo Tradicional de Pragma once
#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include <string>
using namespace std;

class Participante
{
private:
    string nombre;
    string carrera;

public:
    Participante(string n, string c);//Constructor que recibe el nombre y la carrera del participante

    string getNombre();
    string getCarrera();
};

#endif