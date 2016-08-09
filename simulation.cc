#include "simulation.h"

using namespace std;

Simulation::Simulation(Population& population, const vector<Event*>& ev) : pop(population), events(ev), event_count(ev.size()) {
  snaps[0.] = Population(pop);
  //int num_events(ev.size());
  //event_count(num_events);
}

void Simulation::simulate() {
  int event_index = NO_EVENT, num_events = events.size();
  double t = 0.01, sum_probs = 0., time_delta, event_help, cum_probs;

  while (t <= NUM_DAYS) {
    int n = 0;
    for_each(events.begin(), events.end(), [&sum_probs, &pop, t] (Event& ev) {sum_probs += ev.update_prob(t, pop) return;});

    time_gen.param(sum_probs);
    time_delta = time_gen(generator);

    event_help = sum_probs * event_gen(generator);

    cum_probs = events[0].prob;
    n = 0;
    while (cum_probs < event_help) {
      ++n;
      cum_probs += events[n].prob; //Check out how you did this in the earlier project.
    }

    /* 1. Find the sum of the probabilities -
    2. Find the time for the next event -

    3. Find the index for the next event
    4. Exectute the given event + update time
    5. Update probabilities for each event

    This means I should have:
    2 rng objects to generate the vals I need.
    The rest should probably just be local variables in the simulate() member function?
     */




    // delta_time = numeric_limits<double>::max();
    // for (auto k = 0; k != num_events; ++k) {
    //   help = events[k]->generate_time(t, pop);
    //   if (help < delta_time) {
    //     event_index = k;
    //     delta_time = help;
    //   }
    // }

    t += delta_time;
    events[event_index]->execute_event(pop);
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
