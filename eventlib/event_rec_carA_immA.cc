#include "event_rec_carA_immA.h"

using namespace std;

double Event_rec_carA_immA::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CAR") * pop.get_pop("ADULT_CARRIERS");
  return prob;
}

void Event_rec_carA_immA::execute_event() {
  pop.move_pop("ADULT_CARRIERS", "ADULT_IMMUNE");
}
