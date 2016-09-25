#include "event_external_tra_susI.h"

using namespace std;

double Event_external_tra_susI::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = constants.get_prob("PROB_TRANSMISSION") * pop.get_pop("INFANTS_SUSC") * pop_other.get_infectuous();
  } else { prob = 0; }
  return prob;
}

void Event_external_tra_susI::execute_event() {
  pop.move_pop("INFANTS_SUSC", "INFANTS_INF");
}
