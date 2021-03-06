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
  Simulation(std::vector<Population>& populations,  const std::vector<Event*>& ev);
  void simulate();
  std::vector<Population> get_state_at(double t);
  std::vector<int> get_event_counts() {return std::vector<int>(event_count);};
  std::vector<int> get_events_at(double t);
  bool is_done() {return done;};
private:
  std::vector<Population>& pops;
  std::vector<Event*> events;
  std::map<double, std::vector<Population>> snaps;
  std::map<double, std::vector<int>> snaps_events;

  std::vector<int> event_count;

  std::default_random_engine generator;
  std::uniform_real_distribution<double> rnd_gen;

  Constants_runspec constants;

  bool done = false;
};

#endif
