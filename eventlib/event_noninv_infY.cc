#include "event_noninv_infY.h"

using namespace std;

double Event_noninv_infY::update_prob(double t) {
  prob = constants.get_prob("PROB_NON_INVASION") * pop.get_pop("YOUNG_INF");
  return prob;
}

void Event_noninv_infY::execute_event() {
  pop.move_pop("YOUNG_INF", "YOUNG_CARRIERS");
}
