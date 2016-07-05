#include <vector>
#include <limits>

#include "population.h"
#include "constants.h"
#include "event.h"
#include "simulation_data.h"

#ifndef SIMULATE_H
#define SIMULATE_H

Simulation_data simulate(Population& pop, std::vector<Event>& ev);

#endif
