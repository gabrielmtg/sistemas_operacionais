#ifndef ROUND_ROBIN
#define ROUND_ROBIN

#include "Process.h"

#include <iostream>
#include <queue>
#include <vector>

class RoundRobin {

private:
    int quantum;
    int tempo_atual;
    std::queue<int> prontos;
    std::vector<Process> processos;
    
public:
    RoundRobin(int quantum);
    ~RoundRobin();

    void execute();
    void addProcess(const Process &p);
    void printResults() const;
};

#endif

RoundRobin::RoundRobin(int quantum) : quantum(quantum), tempo_atual(0) {}

RoundRobin::~RoundRobin() {}

void RoundRobin::execute() {
    if (processos.empty()) {
        std::cout<< "lista de processos vazia!!" << std::endl;
    }

    for (int i = 0; i < processos.size(); i++) {
        prontos.push(i);
    }

    while (!prontos.empty()) {
        int process_index = prontos.front();
        prontos.pop();

        Process &processo_atual = processos[process_index];

        tempo_atual += processo_atual.execute(quantum);

        if (processo_atual.isDone()) {
            processo_atual.setTurnarroundTime(tempo_atual);
            processo_atual.setWaitingTime(processo_atual.getTurnArroundTime() - processo_atual.getburst_time());
            std::cout<< "processo " << processo_atual.getId() << " concluido no tempo " << tempo_atual << std::endl;
        } else {
            std::cout<< "processo " << processo_atual.getId() << " foi interrompido" << std::endl;
            prontos.push(process_index);
        }
    }
}

void RoundRobin::addProcess(const Process &p) {
    processos.push_back(p);
}