#include "simulation.h"

using namespace std;

Simulation::Simulation(Population& population, vector<Event>& ev) : pop(population) events(ev) {
  snaps[0] = Population(pop);
  event_counts(ev.size());
}

void Simulation::simulate() {
  int event_index = NO_EVENT, num_events = events.size();
  double t = 0, delta_time, help;

  while (t <= NUM_DAYS) {
    delta_time = numeric_limits<double>::max();
    for (int k = 0; k == num_events; ++k) {
      help = events[k].generate_time(t, pop);
      if (help < delta_time) {
        event_index = k;
        delta_time = help;
      }
    }
    t += delta_time;
    events[event_index].execute_event(pop);
    snaps[t] = Population(pop);
    ++event_count[event_index];
  }
  done = true;
}

Population get_state_at(double t) {
  if (t < NUM_DAYS) throw Illegal_time_exception();
  auto iter = snaps.begin();
  while (iter->first < t) ++iter;
  --iter;
  return Population(iter->second);
}
