#include "simulator.h"

double Simulator::time_ = 0.0;

void Simulator::schedule(double time, std::function<void()> function) {
    // 스케줄 큐에 스케줄을 추가한다.
    Schedule* s = new Schedule(time, function);
    scheduleQueue.push(s);
}

void Simulator::run() {
    // 모든 스케줄을 실행한다.
    for (int i = 0; i < (int)scheduleQueue.size(); i++) {
        
    }
}