#include "eventI_tra_immY.h"

using namespace std;

double EventI_tra_immY::update_prob(double t) {
  prob = (constants.get_prob("PROB_TRANSMISSION_CAR_IMM") * pop.get_carriers_invasive() +
          constants.get_prob("PROB_TRANSMISSION_INF_IMM") * pop.get_infected_invasive())*
          pop.get_pop("YOUNG_IMMUNE") / pop.get_total_pop();
  return prob;
}

void EventI_tra_immY::execute_event() {
  pop.move_pop("YOUNG_IMMUNE", "YOUNG_CARRIERS_INVASIVE");
}

string EventI_tra_immY::description() {
  return "Immune young becoming carrier of invasive strain";
}
