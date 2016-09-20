#include "event_inv_carI.h"

using namespace std;

double Event_inv_carI::update_prob(double t) {
  prob = constants.get_prob("INVASIVENESS_A") * pop.get_pop("INFANTS_CARRIERS");
  return prob;
}

void Event_inv_carI::execute_event() {
  pop.move_pop("INFANTS_CARRIERS", "INFANTS_SICK");
}
