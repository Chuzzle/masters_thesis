#include "event_rec_carI.h"

using namespace std;

double Event_rec_carI::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CAR") * pop.get_pop("INFANTS_CARRIERS");
  return prob;
}

void Event_rec_carI::execute_event() {
  pop.move_pop("INFANTS_CARRIERS", "INFANTS_IMMUNE");
}
