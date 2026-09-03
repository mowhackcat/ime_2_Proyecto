#pragma once
#include <string>
#include <iostream>

using namespace std;

class Robot{
private:
    string nombre;
    string tipo;

public:

    Robot(string n, string t)
    {
        nombre = n;
        tipo = t;
    }

    string getNombre()
    {
        return nombre;
    }

    string getTipo()
    {
        return tipo;
    }
};