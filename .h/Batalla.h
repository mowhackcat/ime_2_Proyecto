#include <Robot.h>

class Pelea{
    private:
    Robot robot1;
    Robot robot2;
    Robot ganador;

    public:
    Pelea(Robot r1, Robot r2);

    void mostrarBatalla();
};
