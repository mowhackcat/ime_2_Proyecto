#pragma once
#include <string>
#include <vector>
#include "Integrantes.h"
#include "Robot.h"
using namespace std;

class Equipo {
private:
    string nombreEquipo;
    vector<Integrantes> integrantes;
    vector<Robot> robots;

public:
    //Constructor
    explicit Equipo(const string& nombreEquipo);

    void agregarIntegrante(const Integrantes& i);
    void agregarRobot(const Robot& r);

    string getNombreEquipo() const;
    const vector<Integrantes>& getIntegrantes() const;
    const vector<Robot>& getRobots() const;

    void mostrarResumen() const;
};