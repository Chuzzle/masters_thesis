#include "event_death_susA.h"

using namespace std;

double Event_death_susA::update_prob(double t) {
  prob = constants.get_prob("PROB_DEATH_AGE") * pop.get_pop("ADULT_SUSC");
  return prob;
}

void Event_death_susA::execute_event() {
  pop.decrease_pop("ADULT_SUSC");
}
