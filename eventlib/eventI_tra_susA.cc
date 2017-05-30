#include "eventI_tra_susA.h"

using namespace std;

double EventI_tra_susA::update_prob(double t) {
  prob = (constants.get_prob("PROB_TRANSMISSION_CAR_SUS") * pop.get_carriers_invasive() +
          constants.get_prob("PROB_TRANSMISSION_INF_SUS") * pop.get_infected_invasive())*
          pop.get_pop("ADULT_SUSC") / pop.get_total_pop();
  return prob;
}

void EventI_tra_susA::execute_event() {
  pop.move_pop("ADULT_SUSC", "ADULT_INF_INVASIVE");
}

string EventI_tra_susA::description() {
  return "Transmission of invasive strain to susceptible adult";
}
