#include "eventI_external_tra_immA.h"

using namespace std;

double EventI_external_tra_immA::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = (constants.get_prob("PROB_TRANSMISSION_CAR_IMM") * pop_other.get_carriers_invasive() +
            constants.get_prob("PROB_TRANSMISSION_INF_IMM") * pop_other.get_infected_invasive())*
            pop.get_pop("ADULT_IMMUNE") / (pop.get_total_pop() + pop_other.get_total_pop());
  } else { prob = 0; }
  return prob;
}

void EventI_external_tra_immA::execute_event() {
  pop.move_pop("ADULT_IMMUNE", "ADULT_CARRIERS_INVASIVE");
}

string EventI_external_tra_immA::description() {
  return "Transmission of an invasive strain to an immune adult from external pop";
}
