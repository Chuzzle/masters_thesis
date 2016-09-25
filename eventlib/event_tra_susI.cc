#include "event_tra_susI.h"

using namespace std;

double Event_tra_susI::update_prob(double t) {
  prob = constants.get_prob("PROB_TRANSMISSION") * pop.get_infectuous() * pop.get_pop("INFANTS_SUSC");
  return prob;
}

void Event_tra_susI::execute_event() {
  pop.move_pop("INFANTS_SUSC", "INFANTS_INF");
}
