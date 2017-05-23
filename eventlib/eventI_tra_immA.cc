#include "eventI_tra_immA.h"

using namespace std;

double EventI_tra_immA::update_prob(double t) {
  prob = (constants.get_prob("PROB_TRANSMISSION_CAR_IMM") * pop.get_carriers_invasive() +
          constants.get_prob("PROB_TRANSMISSION_INF_IMM") * pop.get_infected_invasive())*
          pop.get_pop("ADULT_IMMUNE") / pop.get_total_pop();
  return prob;
}

void EventI_tra_immA::execute_event() {
  pop.move_pop("ADULT_IMMUNE", "ADULT_CARRIERS_INVASIVE");
}

string EventI_tra_immA::description() {
  return "Immune adult becoming carrier of invasive strain";
}
