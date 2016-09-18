#include <map>
#include <vector>
#include <cmath>
#include <numeric>
#include <limits>
#include <algorithm>
#include <ctime>

#include "constants_runspec.h"
#include "population.h"
#include "illegal_time_exception.h"
#include "eventlib/event.h"

#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation {
public:
  Simulation(Population& population,  const std::vector<Event*>& ev);
  void simulate();
  Population get_state_at(double t);
  std::vector<int> get_event_counts() {return std::vector<int>(event_count);};
  bool is_done() {return done;};
private:
  Population& pop;
  std::vector<Event*> events;
  std::map<double, Population> snaps;
  std::vector<int> event_count;

  std::default_random_engine generator;
  std::uniform_real_distribution<double> rnd_gen;

  Constants_runspec constants;

  bool done = false;
};

#endif
