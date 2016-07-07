#include <map>
#include <vector>
#include <cmath>

#include "constants_runspec.h"
#include "population.h"

#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation {
public:
  Simulation(Population& population, std::vector<Event>& ev);
  void simulate();
  Population get_state_at(double t);
private:
  Population& pop;
  std::vector<Event>& events;
  std::map<double, Population> snaps;
  std::vector<int> event_count;
  bool done = false;
};

#endif
