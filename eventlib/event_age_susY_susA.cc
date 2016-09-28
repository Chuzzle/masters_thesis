#include "event_age_susY_susA.h"

using namespace std;

double Event_age_susY_susA::update_prob(double t) {
  prob = constants.get_prob("PROB_AGING_YOUNG_ADULT") * pop.get_pop("YOUNG_SUSC");
  return prob;
}

void Event_age_susY_susA::execute_event() {
  pop.move_pop("YOUNG_SUSC", "ADULT_SUSC");
}
