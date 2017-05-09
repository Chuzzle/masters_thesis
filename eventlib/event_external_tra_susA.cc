#include "event_external_tra_susA.h"

using namespace std;

double Event_external_tra_susA::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = (constants.get_prob("PROB_TRANSMISSION_CAR_SUS") * pop_other.get_carriers() +
            constants.get_prob("PROB_TRANSMISSION_INF_SUS") * pop_other.get_infected())*
            pop.get_pop("ADULT_SUSC") / (pop_other.get_total_pop() + pop.get_total_pop());
  } else { prob = 0; }
  return prob;
}

void Event_external_tra_susA::execute_event() {
  pop.move_pop("ADULT_SUSC", "ADULT_INF");
}

string Event_external_tra_susA::description() {
  return "Transmission to a susceptible adult from an external pop";
}
