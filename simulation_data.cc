#include "simulation_data.h"

using namespace std;

Simulation_data::Simulation_data(int num_events, Population& population) : event_counts(num_events, 0), timestamps(0), pop(population), snaps(Population(pop));

}

void Simulation_data::update(int event_index, double t) {
  timestamps.push_back(t);
  snaps.push_back(Population(pop));
  ++event_counts[event_index];
}
