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

    //Metodo para agregar integrantes y robots al equipo
    void agregarIntegrante(const Integrantes& i);

    //Metodo para agregar robots al equipo
    void agregarRobot(const Robot& r);

    //Getter para nombre del equipo
    string getNombreEquipo() const;

    //Getter para integrantes
    const vector<Integrantes>& getIntegrantes() const;

    //Getter para robots
    const vector<Robot>& getRobots() const;

    //Metodo para mostrar un resumen del equipo
    void mostrarResumen() const;
};