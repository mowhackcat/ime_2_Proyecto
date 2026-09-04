#pragma once
#include <string>
#include <iostream>

using namespace std;

class Robot{
private:
    string nombre;
    string tipo;

public:

    Robot(const string& n, const string& t)
    {
        nombre = n;
        tipo = t;
    }

    string getNombre() const
    {
        return nombre;
    }

    string getTipo() const  
    {
        return tipo;
    }
};