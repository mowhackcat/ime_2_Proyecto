//Libreria para cout y cin
#include <iostream>
//Libreria para usar strings
#include <string>
//libreria para usar listas dinamicas
#include <vector>

#include <cstdlib>

#include <ctime>

//Inlcuir archivos .h
#include "Participante.h"
#include "Robot.h"
#include "Equipo.h"
#include "Batalla.h"

using namespace std;

void registrarEquipo(Equipo& equipo) 
{
    int cantidadParticipantes;
    cout << "Registro del equipo: " << equipo.getNombre() << endl;

    cout << "Ingresa el numero de participantes del equipo: ";
    cin >> cantidadParticipantes;

    cin.ignore(); // Limpiar el buffer de entrada

    for (int i = 0; i <cantidadParticipantes; i++)
    {
        string nombre;
        string carrera;

        cout << "Escribe el nombre del participante: ";
        getline(cin, nombre);
        
        cout << "Escribe la carrera del participante: ";
        getline(cin,carrera);

        Participante participante(nombre, carrera);

        equipo.agregarParticipante(participante);
    }

    int cantidadRobots;
    cout << "Ingresa el numero de robots del equipo: ";
    cin >> cantidadRobots;

    cin.ignore(); // Limpiar el buffer de entrada

    for (int i = 0; i < cantidadRobots; i++)
    {
        string nombre;
        string tipo;

        cout << "Escribe el nombre del robot: ";
        getline(cin, nombre);

        cout << "Escribe el tipo del robot: ";
        getline(cin, tipo);

        Robot robot(nombre, tipo);

        equipo.agregarRobot(robot);
    }
}

void mostrarRegistro(vector<Equipo>& equipos)
{
    cout << "----------------------------------------------------"<< endl;
    cout << "Registro de equipos y participantes" << endl;

    for (Equipo& equipo : equipos)
    {
        cout << "Nombre del Equipo: " << equipo.getNombre() << endl;
        cout << "Participantes en el equipo: " << endl;

        for (Participante& participante : equipo.getParticipantes())
        {
            cout << "~ " << participante.getNombre() 
                 << "~ " << participante.getCarrera() << endl;
        }

        cout << "Robots en el equipo: " << endl;

        for (Robot& robot : equipo.getRobots())
        {
            cout << "~ " << robot.getNombre() 
                 << "~ " << robot.getTipo() << endl;
        }
    }
}

void iniciarCompetencia(vector<Equipo>& equipos)
{
    string tipos[] =
    {
        "sumo",
        "seguidor de linea",
        "laberinto",
        "velocista"
    };

    cout << "----------------------------------------------------"<< endl;
    cout << "Competencia" << endl;

    for (int t = 0; t < 4; t++)
    {
        string tipo = tipos[t];
        vector<Robot*> robotsDelTipo;

        for (Equipo& equipo : equipos)
        {
            for (Robot& robot : equipo.getRobots())
            {
                if (robot.getTipo() == tipo)
                {
                    robotsDelTipo.push_back(&robot);
                }
            }
        }

        cout << "Disciplina: " << tipo << endl;

        if (robotsDelTipo.size() == 0)
        {
            cout << "No hay robots registrados en esta disciplina." << endl;
        }
        else
        {
            for (int i = 0; i < robotsDelTipo.size(); i += 2)
            {
                if (i + 1 >= robotsDelTipo.size())
                {
                    cout << "El robot "
                         << robotsDelTipo[i]->getNombre()
                         << " no tiene rival." << endl;
                }
                else
                {
                    Batalla batalla(
                        *robotsDelTipo[i],
                        *robotsDelTipo[i + 1]
                    );

                    batalla.mostrarBatalla();
                }
            }
        }
    }
}


//Inicia el programa
int main()
{
    srand(time(0));

    vector<Equipo> equipos;

    int cantidadEquipos;

    cout << "----------------------------------------------------"<< endl;
    cout << "Bienvenido a la competencia de robots" << endl;
    cout << "Ingresa la cantidad de equipos que participaran: ";
    cin >> cantidadEquipos;

    cin.ignore(); // Limpiar el buffer de entrada

    for (int i = 0; i <cantidadEquipos; i++)
    {
        string nombreEquipo;

        cout << "Nombre del equipo: ";
        getline(cin, nombreEquipo);

        Equipo equipo(nombreEquipo);

        registrarEquipo(equipo);

        equipos.push_back(equipo);
    }

    mostrarRegistro(equipos);

    iniciarCompetencia(equipos);

    cout << "----------------------------------------------------"<< endl;
    cout << "Competencia finalizada." << endl;

    return 0;
}