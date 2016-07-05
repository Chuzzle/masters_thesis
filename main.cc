#include <vector>

#include "simulate.h"
#include "constants.h"
#include "population.h"
#include "pop_init.h"
#include "event_newday.h"

using namespace std;

int main() {
  Pop_init init;
  Population pop(init);

  vector<Event> events;
  events.push_back(Event_newday());

  Simulation_data res = simulate(pop, events);
}
