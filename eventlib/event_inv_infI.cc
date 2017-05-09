#include "event_inv_infI.h"

using namespace std;

double Event_inv_infI::update_prob(double t) {
  prob = constants.get_prob("PROB_INVASION") * pop.get_pop("INFANTS_INF");
  return prob;
}

void Event_inv_infI::execute_event() {
  pop.move_pop("INFANTS_INF", "INFANTS_SICK");
}

string Event_inv_infI::description() {
  return "Invasive disease of an infected infant";
}
