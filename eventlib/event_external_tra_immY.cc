#include "event_external_tra_immY.h"

using namespace std;

double Event_external_tra_immY::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = (constants.get_prob("PROB_TRANSMISSION_CAR_IMM") * pop_other.get_carriers() +
            constants.get_prob("PROB_TRANSMISSION_INF_IMM") * pop_other.get_infected())*
            pop.get_pop("YOUNG_IMMUNE") / (pop_other.get_total_pop() + pop.get_total_pop());
  } else { prob = 0; }
  return prob;
}

void Event_external_tra_immY::execute_event() {
  pop.move_pop("YOUNG_IMMUNE", "YOUNG_CARRIERS");
}
