#include <iostream>
#include <vector>
#include <algorithm>

#include "simulation.h"
#include "event_tra_sicA_susA.h"
#include "population.h"
#include "constants.h"
#include "constants_runspec.h"

using namespace std;

int main () {
  Population pop;
  vector<Event*> events;
  Event_tra_sicA_susA ev;
  Event_rec_sicA ev2;
  events.push_back(&ev);
  event.push_back(&ev2);

  Simulation sim(pop, events);

  cout << "Simulation object initialized" << endl;

  sim.simulate();

  cout << "I guess somehow this worked?" << endl;

  vector<int> counts = sim.get_event_counts();

  for_each(counts.begin(), counts.end(), [](int n) {cout << n << " ";} );
  cout << endl;

  cout << "The new populations are: " << endl;
  cout << "Susceptible: " << pop.get_pop(ADULT_SUSC) << ", Sick: " << pop.get_pop(ADULT_SICK) << " and immune: " << pop.get_pop(ADULT_IMMUNE) << endl;

  cout << "Testing the get_state_at() function, time = 5:\n";
  Population res = sim.get_state_at(5.);
  cout << "Susceptible: " << res.get_pop(ADULT_SUSC) << ", sick: " << res.get_pop(ADULT_SICK) << " and immune: " << pop.get_pop(ADULT_IMMUNE) << endl;
}
