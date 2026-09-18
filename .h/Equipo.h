#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include <vector>
#include "Participante.h"
#include "Robot.h"

using namespace std;

class Equipo
{
private:
    string nombre;
    vector<Participante> participantes;
    vector<Robot> robots;

public:
    Equipo(string n);

    //Agregar un participante al vector de participantes del equipo
    void agregarParticipante(Participante participante);
    //Agregar un robot al vector de robots del equipo
    void agregarRobot(Robot robot);

    string getNombre();
    vector<Participante>& getParticipantes();
    vector<Robot>& getRobots();
};

#endif