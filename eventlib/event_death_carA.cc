#include "event_death_carA.h"

using namespace std;

double Event_death_carA::update_prob(double t) {
  prob = constants.get_prob("PROB_DEATH_AGE") * pop.get_pop("ADULT_CARRIERS");
  return prob;
}

void Event_death_carA::execute_event() {
  pop.decrease_pop("ADULT_CARRIERS");
}
