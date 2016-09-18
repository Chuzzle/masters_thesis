#include "event_age_susI_susY.h"

using namespace std;

double Event_age_susI_susY::update_prob(double t) {
  prob = constants.get_prob("PROB_AGING_INF_YOU") * pop.get_pop("INFANTS_SUSC");
  return prob;
}

void Event_age_susI_susY::execute_event() {
  pop.move_pop("INFANTS_SUSC", "YOUNG_SUSC");
}
