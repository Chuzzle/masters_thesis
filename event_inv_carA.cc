#include "event_inv_carA.h"

using namespace std;

double Event_inv_carA::update_prob(double t, Population& pop) {
  prob = constants.get_prob("INVASIVENESS_A")*pop.get_pop(constants.get_int("ADULT_CARRIERS"));
  return prob;
}

void Event_inv_carA::execute_event(Population& pop) {
  pop.move_pop(constants.get_int("ADULT_CARRIERS"), constants.get_int("ADULT_SICK"));
}
