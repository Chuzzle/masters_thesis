#include "event_inv_carA.h"

using namespace std;

double Event_inv_carA::update_prob(double t) {
  prob = constants.get_prob("INVASIVENESS_A")*pop.get_pop("ADULT_CARRIERS");
  return prob;
}

void Event_inv_carA::execute_event() {
  pop.move_pop("ADULT_CARRIERS", "ADULT_SICK");
}
