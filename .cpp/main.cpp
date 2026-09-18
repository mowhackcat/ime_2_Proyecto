//Libreria para cout y cin
#include <iostream>

//Libreria para usar strings
#include <string>

//libreria para usar listas dinamicas
#include <vector>

//Libreria para usar limites de datos
#include <limits>

//Libreria para usar numeros aleatorios
#include <cstdlib>

//Libreria para usar tiempo
#include <ctime>

//Inlcuir archivos .h
#include "Participante.h"
#include "Robot.h"
#include "Equipo.h"
#include "Batalla.h"

using namespace std;

//Funcion para solicitar una cantidad al usuario y validar que sea un numero entero positivo
int solicitarCantidad(const string& mensaje, bool permitirCero)
{
    int cantidad;

    while (true)
    {
        cout << mensaje;

        if (cin >> cantidad && cantidad >= 0 && (permitirCero || cantidad > 0))
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return cantidad;
        }
        //Limpiar error de entrada
        cin.clear();
        //Limpiar el buffer de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingresa una cantidad valida." << endl;
    }
}


void registrarEquipo(Equipo& equipo)
{
    int cantidadParticipantes;

    cout << endl;
    cout << "====================================================" << endl;
    cout << "              REGISTRO DEL EQUIPO" << endl;
    cout << "====================================================" << endl;

    cout << "Registro del equipo: " << equipo.getNombre() << endl;

    cantidadParticipantes = solicitarCantidad(
        "Ingresa el numero de participantes del equipo: ", true
    );

    for (int i = 0; i < cantidadParticipantes; i++)
    {
        string nombre;
        string carrera;

        cout << endl;
        cout << "---------------- PARTICIPANTE " << i + 1 << " ----------------" << endl;

        cout << "Escribe el nombre del participante: ";
        getline(cin, nombre);

        cout << "Escribe la carrera del participante: ";
        getline(cin, carrera);

        Participante participante(nombre, carrera);

        equipo.agregarParticipante(participante);
    }

    int cantidadRobots;

    cout << endl;
    cout << "====================================================" << endl;
    cout << "                 REGISTRO DE ROBOTS" << endl;
    cout << "====================================================" << endl;

    cantidadRobots = solicitarCantidad(
        "Ingresa el numero de robots del equipo: ", true
    );

    for (int i = 0; i < cantidadRobots; i++)
    {
        string nombre;
        string tipo;

        cout << endl;
        cout << "-------------------- ROBOT " << i + 1 << " --------------------" << endl;

        cout << "Escribe el nombre del robot: ";
        getline(cin, nombre);
        
        cout << "Tipos de robots disponibles:" << endl; 
        cout << "sumo," << endl;
        cout << "seguidor de linea," << endl;
        cout << "laberinto," << endl; 
        cout << "velocista" << endl;

        cout << "Escribe el tipo de robot: ";
        getline(cin, tipo);

        while (tipo != "sumo" &&
               tipo != "seguidor de linea" &&
               tipo != "laberinto" &&
               tipo != "velocista")
        {
            cout << "Tipo de robot no valido. Intenta nuevamente: ";
            getline(cin, tipo);
        }

        Robot robot(nombre, tipo);

        equipo.agregarRobot(robot);
    }

    cout << endl;
    cout << "Equipo registrado correctamente." << endl;
}


void mostrarRegistro(vector<Equipo>& equipos)
{
    cout << endl;
    cout << "====================================================" << endl;
    cout << "           REGISTRO DE EQUIPOS Y PARTICIPANTES" << endl;
    cout << "====================================================" << endl;

    for (Equipo& equipo : equipos)
    {
        cout << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Nombre del Equipo: " << equipo.getNombre() << endl;
        cout << "----------------------------------------------------" << endl;

        cout << "Participantes en el equipo: " << endl;

        for (Participante& participante : equipo.getParticipantes())
        {
            cout << "~ " << participante.getNombre()
                 << " ~ " << participante.getCarrera() << endl;
        }

        cout << endl;

        cout << "Robots en el equipo: " << endl;

        for (Robot& robot : equipo.getRobots())
        {
            cout << "~ " << robot.getNombre()
                 << " ~ " << robot.getTipo() << endl;
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

    cout << endl;
    cout << "====================================================" << endl;
    cout << "                  COMPETENCIA" << endl;
    cout << "====================================================" << endl;

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

        cout << endl;
        cout << "====================================================" << endl;
        cout << "                 DISCIPLINA: " << tipo << endl;
        cout << "====================================================" << endl;

        for (size_t i = robotsDelTipo.size(); i > 1; i--)
        {
            size_t indice = i - 1;
            size_t j = rand() % i;

            Robot* temporal = robotsDelTipo[indice];
            robotsDelTipo[indice] = robotsDelTipo[j];
            robotsDelTipo[j] = temporal;
        }

        if (robotsDelTipo.size() == 0)
        {
            cout << "No hay robots registrados en esta disciplina." << endl;
        }
        else
        {
            for (size_t i = 0; i < robotsDelTipo.size(); i += 2)
            {
                if (i + 1 >= robotsDelTipo.size())
                {
                    cout << endl;
                    cout << "---------------- SIN RIVAL ----------------" << endl;

                    cout << "El robot "
                         << robotsDelTipo[i]->getNombre()
                         << " no tiene rival." << endl;
                }
                else
                {
                    cout << endl;
                    cout << "------------------ BATALLA ------------------" << endl;

                    Batalla batalla(
                        *robotsDelTipo[i],
                        *robotsDelTipo[i + 1]
                    );

                    batalla.mostrarBatalla();

                    cout << "----------------------------------------------" << endl;
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

    cout << endl;
    cout << "====================================================" << endl;
    cout << "        SISTEMA DE COMPETENCIA DE ROBOTICA" << endl;
    cout << "====================================================" << endl;

    cout << endl;
    cout << "Bienvenido a la competencia de robots" << endl;

    cout << endl;
    cout << "----------------------------------------------------" << endl;

    cantidadEquipos = solicitarCantidad(
        "Ingresa la cantidad de equipos que participaran: ", false
    );

    for (int i = 0; i < cantidadEquipos; i++)
    {
        string nombreEquipo;

        cout << endl;
        cout << "====================================================" << endl;
        cout << "                     EQUIPO " << i + 1 << endl;
        cout << "====================================================" << endl;

        cout << "Nombre del equipo: ";
        getline(cin, nombreEquipo);

        Equipo equipo(nombreEquipo);

        registrarEquipo(equipo);

        equipos.push_back(equipo);
    }

    mostrarRegistro(equipos);

    iniciarCompetencia(equipos);

    cout << endl;
    cout << "====================================================" << endl;
    cout << "              COMPETENCIA FINALIZADA." << endl;
    cout << "====================================================" << endl;

    return 0;
}