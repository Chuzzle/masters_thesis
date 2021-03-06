#include "eventI_external_tra_immI.h"

using namespace std;

double EventI_external_tra_immI::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = (constants.get_prob("PROB_TRANSMISSION_CAR_IMM") * pop_other.get_carriers_invasive() +
            constants.get_prob("PROB_TRANSMISSION_INF_IMM") * pop_other.get_infected_invasive())*
            pop.get_pop("INFANTS_IMMUNE") / (pop_other.get_total_pop() + pop.get_total_pop());
  } else { prob = 0; }
  return prob;
}

void EventI_external_tra_immI::execute_event() {
  pop.move_pop("INFANTS_IMMUNE", "INFANTS_CARRIERS_INVASIVE");
}

string EventI_external_tra_immI::description() {
  return "Transmission of an invasive strain to an immune infant from an external pop";
}
