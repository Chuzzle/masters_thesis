#include "eventI_external_tra_susY.h"

using namespace std;

double EventI_external_tra_susY::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = (constants.get_prob("PROB_TRANSMISSION_CAR_SUS") * pop_other.get_carriers_invasive() +
            constants.get_prob("PROB_TRANSMISSION_INF_SUS") * pop_other.get_infected_invasive())*
            pop.get_pop("YOUNG_SUSC") / (pop_other.get_total_pop() + pop.get_total_pop());
  } else {prob = 0; }
  return prob;
}

void EventI_external_tra_susY::execute_event() {
  pop.move_pop("YOUNG_SUSC", "YOUNG_INF_INVASIVE");
}

string EventI_external_tra_susY::description() {
  return "Transmission of an invasive strain to a susceptible young from an external pop";
}
