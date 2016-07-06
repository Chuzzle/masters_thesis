#include "simulation.h"

using namespace std;

Simulation::Simulation(Population& population, vector<Event>& ev) : pop(population) events(ev) {
  snaps[0] = Population(pop);
  event_counts(ev.size());
}
