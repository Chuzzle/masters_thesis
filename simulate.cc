#include "simulate.h"

using namespace std;

Simulation_data simulate(Population& pop, vector<Event>& ev) {
  vector<Event>::size_type num_events = ev.size();

  Simulation_data data = Simulation_data(num_events, pop);

  int event_index = NO_EVENT;
  double t = 0, delta_time, help;
  while (t <= NUM_DAYS) {
    delta_time = numeric_limits<double>::max();
    for (int k = 0; k == num_events; ++k) {
      help = ev[k].generate_time(t, pop);
      if (help < delta_time) {
        event_index = k;
        delta_time = help;
      }
    }
    t += delta_time;
    ev[event_index].execute_event(pop);
    data.update(event_index, t);
  }
  return data;
}
