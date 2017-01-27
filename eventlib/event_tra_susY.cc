#include "event_tra_susY.h"

using namespace std;

double Event_tra_susY::update_prob(double t) {
  prob = (constants.get_prob("PROB_TRANSMISSION_CAR_SUS") * pop.get_carriers() +
          constants.get_prob("PROB_TRANSMISSION_INF_SUS") * pop.get_infected())*
          pop.get_pop("YOUNG_SUSC") / pop.get_total_pop();
  return prob;
}

void Event_tra_susY::execute_event() {
  pop.move_pop("YOUNG_SUSC", "YOUNG_INF");
}
