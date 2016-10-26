#include "event_external_tra_immI.h"

using namespace std;

double Event_external_tra_immI::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = constants.get_prob("PROB_TRA_IMM") * pop.get_pop("INFANTS_IMMUNE") * pop_other.get_infectuous()/ (pop.get_total_pop() + pop_other.get_total_pop());
  } else { prob = 0; }
  return prob;
}

void Event_external_tra_immI::execute_event() {
  pop.move_pop("INFANTS_IMMUNE", "INFANTS_CARRIERS");
}
