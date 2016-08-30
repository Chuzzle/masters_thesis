#include "event_death_sicA.h"

using namespace std;

double Event_death_sicA::update_prob(double t, Population& pop) {
  return constants.get_prob("FATALITY")*pop.get_pop("ADULT_SICK");
}

void Event_death_sicA::execute_event(Population& pop) {
  pop.decrease_pop("ADULT_SICK");
}
