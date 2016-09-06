#include "event_death_sicA.h"

using namespace std;

double Event_death_sicA::update_prob(double t) {
  prob = constants.get_prob("FATALITY")*pop.get_pop("ADULT_SICK");
  return prob;
}

void Event_death_sicA::execute_event() {
  pop.decrease_pop("ADULT_SICK");
}
