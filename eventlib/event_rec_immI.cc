#include "event_rec_immI.h"

using namespace std;

double Event_rec_immI::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_IMMI") * pop.get_pop("INFANTS_IMMUNE");
  return prob;
}

void Event_rec_immI::execute_event() {
  pop.move_pop("INFANTS_IMMUNE", "INFANTS_SUSC");
}
