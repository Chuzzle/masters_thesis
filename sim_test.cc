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
  events.push_back(&ev);

  Simulation sim(pop, events);

  cout << "Simulation object initialized" << endl;

  sim.simulate();

  cout << "I guess somehow this worked?" << endl;

  vector<int> counts = sim.get_event_counts();

  for_each(counts.begin(), counts.end(), [](int n) {cout << n << " ";} );
  cout << endl;
}
