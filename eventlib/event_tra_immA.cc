#include "event_tra_immA.h"

using namespace std;

double Event_tra_immA::update_prob(double t) {
  prob = (constants.get_prob("PROB_TRANSMISSION_CAR_IMM") * pop.get_carriers() +
          constants.get_prob("PROB_TRANSMISSION_INF_IMM") * pop.get_infected())*
          pop.get_pop("ADULT_IMMUNE") / pop.get_total_pop();
  return prob;
}

void Event_tra_immA::execute_event() {
  pop.move_pop("ADULT_IMMUNE", "ADULT_CARRIERS");
}
