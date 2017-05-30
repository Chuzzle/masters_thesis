#include "eventI_external_tra_susA.h"

using namespace std;

double EventI_external_tra_susA::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = (constants.get_prob("PROB_TRANSMISSION_CAR_SUS") * pop_other.get_carriers_invasive() +
            constants.get_prob("PROB_TRANSMISSION_INF_SUS") * pop_other.get_infected_invasive())*
            pop.get_pop("ADULT_SUSC") / (pop_other.get_total_pop() + pop.get_total_pop());
  } else { prob = 0; }
  return prob;
}

void EventI_external_tra_susA::execute_event() {
  pop.move_pop("ADULT_SUSC", "ADULT_INF_INVASIVE");
}

string EventI_external_tra_susA::description() {
  return "Transmission of an invasive strain to a susceptible adult from an external pop";
}
