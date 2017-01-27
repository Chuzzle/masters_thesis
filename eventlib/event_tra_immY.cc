#include "event_tra_immY.h"

using namespace std;

double Event_tra_immY::update_prob(double t) {
  prob = (constants.get_prob("PROB_TRANSMISSION_CAR_IMM") * pop.get_carriers() +
          constants.get_prob("PROB_TRANSMISSION_INF_IMM") * pop.get_infected())*
          pop.get_pop("YOUNG_IMMUNE") / pop.get_total_pop();
  return prob;
}

void Event_tra_immY::execute_event() {
  pop.move_pop("YOUNG_IMMUNE", "YOUNG_CARRIERS");
}
