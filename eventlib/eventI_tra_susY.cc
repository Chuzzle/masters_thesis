#include "eventI_tra_susY.h"

using namespace std;

double EventI_tra_susY::update_prob(double t) {
  prob = (constants.get_prob("PROB_TRANSMISSION_CAR_SUS") * pop.get_carriers_invasive() +
          constants.get_prob("PROB_TRANSMISSION_INF_SUS") * pop.get_infected_invasive())*
          pop.get_pop("YOUNG_SUSC") / pop.get_total_pop();
  return prob;
}

void EventI_tra_susY::execute_event() {
  pop.move_pop("YOUNG_SUSC", "YOUNG_INF_INVASIVE");
}

string EventI_tra_susY::description() {
  return "Transmission of invasive strain to susceptible young";
}
