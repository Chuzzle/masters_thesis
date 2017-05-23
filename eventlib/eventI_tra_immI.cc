#include "eventI_tra_immI.h"

using namespace std;

double EventI_tra_immI::update_prob(double t) {
  prob = (constants.get_prob("PROB_TRANSMISSION_CAR_IMM") * pop.get_carriers_invasive() +
          constants.get_prob("PROB_TRANSMISSION_INF_IMM") * pop.get_infected_invasive())*
          pop.get_pop("INFANTS_IMMUNE") / pop.get_total_pop();
  return prob;
}

void EventI_tra_immI::execute_event() {
  pop.move_pop("INFANTS_IMMUNE", "INFANTS_CARRIERS_INVASIVE");
}

string EventI_tra_immI::description() {
  return "Immune infant becoming carrier of invasive strain";
}
