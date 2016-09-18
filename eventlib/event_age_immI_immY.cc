#include "event_age_immI_immY.h"

using namespace std;

double Event_age_immI_immY::update_prob(double t) {
  prob = constants.get_prob("PROB_AGING_INFANTS_YOUNG") * pop.get_pop("INFANTS_IMMUNE");
  return prob;
}

void Event_age_immI_immY::execute_event() {
  pop.move_pop("INFANTS_IMMUNE", "YOUNG_IMMUNE");
}
