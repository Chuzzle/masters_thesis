#include "event_tra_susA.h"

using namespace std;

double Event_tra_susA::update_prob(double t) {
  prob = constants.get_prob("PROB_TRANSMISSION") * pop.get_infectuous() * pop.get_pop("ADULT_SUSC") / pop.get_total_pop();
  return prob;
}

void Event_tra_susA::execute_event() {
  pop.move_pop("ADULT_SUSC", "ADULT_INF");
}
