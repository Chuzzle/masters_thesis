#include "event_inv_carY.h"

using namespace std;

double Event_inv_carY::update_prob(double t) {
  prob = constants.get_prob("INVASIVENESS_A") * pop.get_pop("YOUNG_CARRIERS");
  return prob;
}

void Event_inv_carY::execute_event() {
  pop.move_pop("YOUNG_CARRIERS", "YOUNG_SICK");
}
