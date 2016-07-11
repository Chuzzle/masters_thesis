#include <map>
#include <vector>
//#include <cmath>
#include <limits>

#include "constants_runspec.h"
#include "population.h"
#include "illegal_time_exception.h"
#include "event.h"

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
