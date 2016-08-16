#include "event_rec_carA.h"

using namespace std;

double Event_rec_carA::update_prob(double t, Population& pop) {
  prob = constants.get_prob("PROB_REC_CARA") * pop.get_pop("ADULT_CARRIERS");
  return prob;
}

void Event_rec_carA::execute_event(Population& pop) {
  pop.move_pop("ADULT_CARRIERS", "ADULT_IMMUNE");
}
