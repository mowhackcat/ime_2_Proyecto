#pragma once 
#include <string>
#include <iostream>

using namespace std;

class Participante
{
private:

    string nombre;
    string carrera;

public:

<<<<<<< Updated upstream
string getNombre() const;
string getRol() const;


Integrantes(const string& nombre, const string& rol);
string getNombre() const;
string getRol() const;


=======
    Participante(string n, string c)
    {
        nombre = n;
        carrera = c;
    }

    string getNombre()
    {
        return nombre;
    }

    string getCarrera()
    {
        return carrera;
    }
>>>>>>> Stashed changes
};