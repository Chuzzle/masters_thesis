#include "event_rec_sicI.h"

using namespace std;

double Event_rec_sicI::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_SIC") * pop.get_pop("INFANTS_SICK");
  return prob;
}

void Event_rec_sicI::execute_event() {
  pop.move_pop("INFANTS_SICK", "INFANTS_IMMUNE_PER");
}
