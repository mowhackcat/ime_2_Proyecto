#include "Equipo.h"
#include "Robot.h"
#include <iostream>

//Constructor
Equipo::Equipo(const string& nombreEquipo) : nombreEquipo(nombreEquipo) {}

//Metodo para agregar integrantes
void Equipo::agregarIntegrante(const Integrantes&i) {integrantes.push_back(i);}

//Metodo para agregar robots
void Equipo::agregarRobot(const Robot& r) {robots.push_back(r);}

//Getter para nombre del equipo
string Equipo::getNombreEquipo() const {return nombreEquipo;}

//Getter para obtener nombre de los integrantes del equipo
const vector<Integrantes>& Equipo::getIntegrantes() const {return integrantes;}

//Getter para obtener nombre de los robots del equipo
const vector<Robot>& Equipo::getRobots() const {return robots;}

//Metodo para mostrar todos los componentes del equipo 
//Nombre del equipo, integrantes y robots
//Numero de integrantes y robots

void Equipo::mostrarResumen() const {
    cout << "Nombre del equipo: " << nombreEquipo << endl;
    cout << "Numero de Integrantes: " << integrantes.size() << endl;

    for (const auto& integrante : integrantes) {
        cout << "- " << integrante.getNombre()
             << "---> Rol: " << integrante.getRol() << endl;
    }

    cout << "Numero de Robots: " << robots.size() << endl;

    for (const auto& robot : robots) {
        cout << "- " << robot.getNombre()
             << "---> Tipo: " << robot.getTipo() << endl;
    }

    cout << "---------------------------------------------------" << endl;

}