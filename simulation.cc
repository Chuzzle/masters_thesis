#include "simulation.h"

using namespace std;

Simulation::Simulation(Population& population, const vector<Event*>& ev) : pop(population), events(ev), event_count(ev.size()) {
  snaps[0.] = Population(pop);
  //int num_events(ev.size());
  //event_count(num_events);
}

void Simulation::simulate() {
  int event_index = NO_EVENT;
  double t = 0.01, sum_probs = 0., time_delta, event_help, cum_probs;

  while (t <= NUM_DAYS) {
    int n = 0;
    for_each(events.begin(), events.end(), [&] (Event* ev) {sum_probs += ev->update_prob(t, pop); return;});

    time_delta = -log(event_gen(generator)) * sum_probs;

    if (time_delta + t > floor(t+1)) { //If the events are frequent enough, this should not be necessary.
      t = floor(t+1);
      continue;
    }

    event_help = sum_probs * event_gen(generator);

    cum_probs = events[0]->prob;
    event_index = 0;
    while (cum_probs < event_help) {
      ++event_index;
      cum_probs += events[n]->prob;
    }

    events[event_index]->execute_event(pop);
    t += time_delta;

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
