#include "event_age_immY_immA.h"

using namespace std;

double Event_age_immY_immA::update_prob(double t) {
  prob = constants.get_prob("PROB_AGING_YOUNG_ADULT") * pop.get_pop("YOUNG_IMMUNE");
  return prob;
}

void Event_age_immY_immA::execute_event() {
  pop.move_pop("YOUNG_IMMUNE", "ADULT_IMMUNE");
}
