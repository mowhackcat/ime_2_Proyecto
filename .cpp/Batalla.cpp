#include <iostream>
#include "Batalla.h"
#include <cstdlib>
using namespace std;

Pelea::Pelea(Robot r1,Robot r2){
    Robot robot1 = r1;
    Robot robot2 = r2;

    int resultado = rand ()%2;

    if (resultado==0){
        ganador = robot1;
    }else{
        ganador = robot2;
    }
}
