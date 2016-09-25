#include "event_inv_infY.h"

using namespace std;

double Event_inv_infY::update_prob(double t) {
  prob = constants.get_prob("PROB_INVASION") * pop.get_pop("YOUNG_INF");
  return prob;
}

void Event_inv_infY::execute_event() {
  pop.move_pop("YOUNG_INF", "YOUNG_SICK");
}
