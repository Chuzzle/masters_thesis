#include "eventI_tra_susI.h"

using namespace std;

double EventI_tra_susI::update_prob(double t) {
  prob = (constants.get_prob("PROB_TRANSMISSION_CAR_SUS") * pop.get_carriers_invasive() +
          constants.get_prob("PROB_TRANSMISSION_INF_SUS") * pop.get_infected_invasive())*
          pop.get_pop("INFANTS_SUSC") / pop.get_total_pop();
  return prob;
}

void EventI_tra_susI::execute_event() {
  pop.move_pop("INFANTS_SUSC", "INFANTS_INF_INVASIVE");
}

string EventI_tra_susI::description() {
  return "Transmission of invasive strain to susceptible infant";
}
