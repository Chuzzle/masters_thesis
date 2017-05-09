#include "event_birth.h"

using namespace std;

double Event_birth::update_prob(double t) {
  int adults = pop.get_pop("ADULT_SUSC") + pop.get_pop("ADULT_IMMUNE") + pop.get_pop("ADULT_CARRIERS");
  prob = constants.get_prob("PROB_BIRTH_PER_ADULT") * adults;
  return prob;
}

void Event_birth::execute_event() {
  pop.increment_pop("INFANTS_SUSC");
}

string Event_birth::description() {
  return "Birth of an infant susceptible";
}
