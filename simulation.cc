#include "simulation.h"

using namespace std;

int Simulation::simulate(Population& pop, vector<Event>& events;) {
  double t = 0, delta_time;
  vector<double> probabilities;
  int event_index;
  while (t <= NUM_DAYS) {
    transform(events.begin(), events.end(), probabilities.begin(), [t, &pop](auto ev){return ev.find_rate(t, pop)});
    get_event(probabilities, event_index, delta_time);
    t += delta_time;
    events[event_index].execute_event(t, pop);
  }
}

int Simulation::reset() {
  delete data;
  data = new Simulation_data();
  return 1;
}
