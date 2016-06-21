#include <vector>
#include <algorithm>

#include "event.h"
#include "population.h"
#include "constants.h"

#ifndef SIMULATION_H
#define SIMULATION_H

Class Simulation {
public:
  explicit Simulation(Population& population, std::vector<Event>& ev) : pop(population), events(ev), data(new Simulation_data);
  int simulate();
  int reset();
private:
  int get_event(std::vector<double>& probabilities, int& event_index);
  Population& pop;
  Simulation_data* data;
  std::vector<Event>& events;
}

#endif
