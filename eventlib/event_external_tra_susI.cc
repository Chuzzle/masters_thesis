#include "event_external_tra_susI.h"

using namespace std;

double Event_external_tra_susI::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = (constants.get_prob("PROB_TRANSMISSION_CAR_SUS") * pop_other.get_carriers() +
            constants.get_prob("PROB_TRANSMISSION_INF_SUS") * pop_other.get_infected())*
            pop.get_pop("INFANTS_SUSC") / (pop_other.get_total_pop() + pop.get_total_pop());
  } else { prob = 0; }
  return prob;
}

void Event_external_tra_susI::execute_event() {
  pop.move_pop("INFANTS_SUSC", "INFANTS_INF");
}

string Event_external_tra_susI::description() {
  return "Transmission to a susceptible infant from an external pop";
}
