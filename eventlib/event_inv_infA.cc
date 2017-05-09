#include "event_inv_infA.h"

using namespace std;

double Event_inv_infA::update_prob(double t) {
  prob = constants.get_prob("PROB_INVASION") * pop.get_pop("ADULT_INF");
  return prob;
}

void Event_inv_infA::execute_event() {
  pop.move_pop("ADULT_INF", "ADULT_SICK");
}

string Event_inv_infA::description() {
  return "Invasive disease on an infected adult";
}
