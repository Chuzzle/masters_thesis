#include "event_tra_immY.h"

using namespace std;

double Event_tra_immY::update_prob(double t) {
  prob = constants.get_prob("PROB_TRA_IMM") * pop.get_infectuous() * pop.get_pop("YOUNG_IMMUNE");
  return prob;
}

void Event_tra_immY::execute_event() {
  pop.move_pop("YOUNG_IMMUNE", "YOUNG_CARRIERS");
}
