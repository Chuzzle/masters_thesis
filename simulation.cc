#include "simulation.h"

using namespace std;

Simulation::Simulation(Population& population, vector<Event>& ev) : pop(population), events(ev), event_count(ev.size()) {
  snaps[0.] = Population(pop);
  //int num_events(ev.size());
  //event_count(num_events);
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

Population Simulation::get_state_at(double t) {
  // if (t > NUM_DAYS) throw Illegal_time_exception();
  // auto iter = snaps.begin();
  // while (iter->first < t) ++iter;
  // --iter;
  // Population p(iter->second);
  // return p;
  return Population(pop);
}
