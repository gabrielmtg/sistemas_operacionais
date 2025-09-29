#ifndef PROCESS
#define PROCESS

#include <algorithm>

class Process {

private:
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnarround_time;

public:
    Process(int id, int burst_time);
    ~Process();

    int execute(int t);
    bool isDone() const;

    int getId() const;
    int getburst_time() const;
    int getRemaingTime() const;
    int getWaitingTime() const;
    int getTurnArroundTime() const;

    void setWaitingTime(int t);
    void setTurnarroundTime(int t);
};

#endif

Process::Process(int id, int burst_time) : id(id), burst_time(burst_time), remaining_time(burst_time), waiting_time(0), turnarround_time(0) {}

Process::~Process(){}

int Process::execute(int t) {
    int tempo_executado = std::min(t, remaining_time);
    remaining_time -= tempo_executado;
    return tempo_executado;
}

bool Process::isDone() const {
    return remaining_time == 0;
}

int Process::getId() const {
    return id;
}

int Process::getburst_time() const {
    return burst_time;
}

int Process::getRemaingTime() const {
    return remaining_time;
}

int Process::getWaitingTime() const {
    return waiting_time;
}

int Process::getTurnArroundTime() const {
    return turnarround_time;
}

void Process::setWaitingTime(int t) {
    waiting_time = t;
}

void Process::setTurnarroundTime(int t) {
    turnarround_time = t;
}
