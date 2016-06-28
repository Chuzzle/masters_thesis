#include <vector>

#include "population.h"

#ifndef SIMULATION_DATA_H
#define

class Simulation_data {
public:
  Simulation_data(int num_events, Population& pop);
  void update(int event_index, double t);
private:
  Population& pop;
  std::vector<Population> snaps;
  std::vector<double> timestamps;
  std::vector<int> event_counts;
}

#endif
