#include "event_rec_sicA.h"

using namespace std;

double Event_rec_sicA::update_prob(double t, Population& pop) {
  prob = constants.get_prob("PROB_REC_SICA") * pop.get_pop("ADULT_SICK");
  return prob;
}

void Event_rec_sicA::execute_event(Population& pop) {
  pop.move_pop("ADULT_SICK", "ADULT_IMMUNE");
}
