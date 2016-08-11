#include "simulation.h"

using namespace std;

Simulation::Simulation(Population& population, const vector<Event*>& ev) : pop(population), events(ev), event_count(ev.size()) {
  snaps[0.] = Population(pop);
  generator.seed(time(0));
}

void Simulation::simulate() {
  int event_index = NO_EVENT;
  double t = 0.01, sum_probs = 0., time_delta, event_help, cum_probs;

  while (t <= NUM_DAYS) {
    int n = 0;
    sum_probs = 0.;
    for_each(events.begin(), events.end(), [&] (Event* ev) {sum_probs += ev->update_prob(t, pop); return;});

    time_delta = -log(event_gen(generator)) / sum_probs;

    if (time_delta + t > floor(t+1)) { //If the events are frequent enough, this should not be necessary.
      t = floor(t+1);
      snaps[t] = Population(pop);
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
  if (t > NUM_DAYS || t < 0) throw Illegal_time_exception();
  if (snaps.count(t) != 0) return snaps[t];
  auto res = find_if(snaps.begin(), snaps.end(), [&] (map<double, Population>::value_type obj) {return obj.first > t;} );
  --res;
  return Population(res->second);
}
