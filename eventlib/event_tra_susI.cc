#include "event_tra_susI.h"

using namespace std;

double Event_tra_susI::update_prob(double t) {
  prob = (constants.get_prob("PROB_TRANSMISSION_CAR_SUS") * pop.get_carriers() +
          constants.get_prob("PROB_TRANSMISSION_INF_SUS") * pop.get_infected())*
          pop.get_pop("INFANTS_SUSC") / pop.get_total_pop();
  return prob;
}

void Event_tra_susI::execute_event() {
  pop.move_pop("INFANTS_SUSC", "INFANTS_INF");
}

string Event_tra_susI::description() {
  return "Transmission to susceptible infant";
}
