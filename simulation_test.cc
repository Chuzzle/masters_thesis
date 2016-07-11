#include <vector>
#include <iostream>

#include "simulation.h"
#include "constants_runspec.h"
#include "population.h"
#include "event_newday.h"
#include "event.h"

using namespace std;

int main() {
  Population pop;
  vector<Event*> events;
  Event_newday ev;
  events.push_back(&ev);
  Simulation sim(pop, events);
  cout << "Simulation initialized" << endl;
  cout << sim.is_done() << endl;

  sim.simulate();
  cout << "Simulation performed (waaah I didn't think this would work)" << endl;

  auto counts = sim.get_event_counts();
  cout << "Number of events:" << endl;
  cout << counts[0] << endl;
}
