#include "simulation.h"
#include <iostream>
using namespace std;

Simulation::Simulation(vector<Population>& populations, const vector<Event*>& ev) : pops(populations), events(ev), event_count(ev.size()) {
  snaps[0.] = vector<Population>(pops);
  snaps_events[0.] = vector<int>(ev.size());
  random_device rd;
  generator.seed(rd());
}

void Simulation::simulate() {

  int event_index;
  double t = 0.01, sum_probs = 0., time_delta, event_help, cum_probs;

  while (t <= constants.get_int("NUM_DAYS")) {
    sum_probs = 0.;
    for_each(events.begin(), events.end(), [&] (Event* ev) {sum_probs += ev->update_prob(t); return;});
    time_delta = -log(rnd_gen(generator)) / sum_probs;
    if (time_delta + t > floor(t+1)) { //If the events are frequent enough, this should not be necessary. It does, however, make for more efficient measurements.
      t = floor(t+1);
      snaps[t] = vector<Population>(pops);
      snaps_events[t] = vector<int>(event_count);
      continue;
    }

    event_help = sum_probs * rnd_gen(generator);
    for (event_index = 0, cum_probs = 0.; event_index < events.size()-1; ++event_index) {
      cum_probs += events[event_index]->prob;
      if (cum_probs >= event_help) break;
    }
    events[event_index]->execute_event();
    t += time_delta;
    //snaps[t] = vector<Population>(pops);
    ++event_count[event_index];
  }
  done = true;
}

vector<Population> Simulation::get_state_at(double t) {
  if (t > constants.get_int("NUM_DAYS") || t < 0) throw Illegal_time_exception();
  if (snaps.count(t) != 0) return vector<Population>(snaps[t]);
  auto res = find_if(snaps.begin(), snaps.end(), [&] (map<double, vector<Population>>::value_type obj) {return obj.first > t;} );
  --res;
  return vector<Population>(res->second);
}

vector<int> Simulation::get_events_at(double t) {
  if (t > constants.get_int("NUM_DAYS") || t < 0 ) throw Illegal_time_exception();
  if (snaps_events.count(t) != 0) return vector<int>(snaps_events[t]);
  auto res = find_if(snaps_events.begin(), snaps_events.end(), [&] (map<double, vector<int>>::value_type obj) {return obj.first > t;});
  --res;
  return vector<int>(res->second);
}
