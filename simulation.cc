#include "simulation.h"
#include <iostream>
using namespace std;

Simulation::Simulation(Population& population, const vector<Event*>& ev) : pop(population), events(ev), event_count(ev.size()) {
  snaps[0.] = Population(pop);
  random_device rd;
  generator.seed(rd());
}

void Simulation::simulate() {
  int event_index;
  double t = 0.01, sum_probs = 0., time_delta, event_help, cum_probs;

  while (t <= constants.get_int("NUM_DAYS")) {
    sum_probs = 0.;
    for_each(events.begin(), events.end(), [&] (Event* ev) {sum_probs += ev->update_prob(t, pop); return;});

    time_delta = -log(rnd_gen(generator)) / sum_probs;

    if (time_delta + t > floor(t+1)) { //If the events are frequent enough, this should not be necessary. It does, however, make for more efficient measurements.
      t = floor(t+1);
      snaps[t] = Population(pop);
      continue;
    }

    event_help = sum_probs * rnd_gen(generator);

    for (event_index = 0, cum_probs = 0.; event_index < events.size()-1; ++event_index) {
      cum_probs += events[event_index]->prob;
      if (cum_probs >= event_help) break;
    }

    events[event_index]->execute_event(pop);
    t += time_delta;
    snaps[t] = Population(pop);
    ++event_count[event_index];

  }
  done = true;
}

Population Simulation::get_state_at(double t) {
  if (t > constants.get_int("NUM_DAYS") || t < 0) throw Illegal_time_exception();
  if (snaps.count(t) != 0) return Population(snaps[t]);
  auto res = find_if(snaps.begin(), snaps.end(), [&] (map<double, Population>::value_type obj) {return obj.first > t;} );
  --res;
  return Population(res->second);
}
