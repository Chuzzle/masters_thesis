#include "event_external_tra_susA.h"

using namespace std;

double Event_external_tra_susA::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = constants.get_prob("PROB_TRANSMISSION") * pop.get_pop("ADULT_SUSC") * pop_other.get_infectuous();
  } else { prob = 0; }
  return prob;
}

void Event_external_tra_susA::execute_event() {
  pop.move_pop("ADULT_SUSC", "ADULT_INF");
}
