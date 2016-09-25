#include "event_noninv_infA.h"

using namespace std;

double Event_noninv_infA::update_prob(double t) {
  prob = constants.get_prob("PROB_NON_INVASION") * pop.get_pop("ADULT_INF");
  return prob;
}

void Event_noninv_infA::execute_event() {
  pop.move_pop("ADULT_INF", "ADULT_CARRIERS");
}
