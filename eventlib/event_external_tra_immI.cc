#include "event_external_tra_immI.h"

using namespace std;

double Event_external_tra_immI::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = (constants.get_prob("PROB_TRANSMISSION_CAR_IMM") * pop_other.get_carriers() +
            constants.get_prob("PROB_TRANSMISSION_INF_IMM") * pop_other.get_infected())*
            pop.get_pop("INFANTS_IMMUNE") / (pop_other.get_total_pop() + pop.get_total_pop());
  } else { prob = 0; }
  return prob;
}

void Event_external_tra_immI::execute_event() {
  pop.move_pop("INFANTS_IMMUNE", "INFANTS_CARRIERS");
}

string Event_external_tra_immI::description() {
  return "Transmission to an immune infant from an external pop";
}
