#include "RoundRobin.h"

#include <cstdlib>

int main() {

    int num_processos = (rand() % 100) + 1;

    RoundRobin escalonador = RoundRobin(3);

    for (int i = 0; i <= num_processos; i++ ) {
        int n = (rand() % 10) + 1;
        escalonador.addProcess(Process(i, n));
    }

    escalonador.execute();

    return 0;
}