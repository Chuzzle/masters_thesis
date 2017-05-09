#include "event_noninv_infI.h"

using namespace std;

double Event_noninv_infI::update_prob(double t) {
  prob = constants.get_prob("PROB_NON_INVASION") * pop.get_pop("INFANTS_INF");
  return prob;
}

void Event_noninv_infI::execute_event() {
  pop.move_pop("INFANTS_INF", "INFANTS_CARRIERS");
}

string Event_noninv_infI::description() {
  return "Infant infected becoming carrier";
}
