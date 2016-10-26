#include "event_tra_immI.h"

using namespace std;

double Event_tra_immI::update_prob(double t) {
  prob = constants.get_prob("PROB_TRA_IMM") * pop.get_infectuous() * pop.get_pop("INFANTS_IMMUNE") / pop.get_total_pop();
  return prob;
}

void Event_tra_immI::execute_event() {
  pop.move_pop("INFANTS_IMMUNE", "INFANTS_CARRIERS");
}
