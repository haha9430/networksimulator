#ifndef SIMULATOR_H
#define SIMULATOR_H

#define RANDOM_SEED 369369

#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>

class Simulator;

class Schedule {
private:
  double time_;
  // 사용법 검색해볼 것, callback 구조
  std::function<void()> function_;

public:
  double time() { return time_; }
  void call() { function_(); }

  Schedule(double time, std::function<void()> function)
      : time_(time), function_(function) {}

  bool operator<(Schedule s) const {
    return this->time_ > s.time();
  }
};

class Simulator {
private:
  static double time_;
  static std::priority_queue<Schedule> scheduleQueue;

public:
  static double now() { return time_; }

  static void prepare() { srand(RANDOM_SEED); }

  static void schedule(double time, std::function<void()> function);

  static void run();
  
};

#endif