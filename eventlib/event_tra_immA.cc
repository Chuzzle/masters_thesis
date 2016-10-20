#include "event_tra_immA.h"

using namespace std;

double Event_tra_immA::update_prob(double t) {
  prob = constants.get_prob("PROB_TRA_IMM") * pop.get_infectuous() * pop.get_pop("ADULT_IMMUNE");
  return prob;
}

void Event_tra_immA::execute_event() {
  pop.move_pop("ADULT_IMMUNE", "ADULT_CARRIERS");
}
