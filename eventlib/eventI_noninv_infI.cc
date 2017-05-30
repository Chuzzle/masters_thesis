#include "eventI_noninv_infI.h"

using namespace std;

double EventI_noninv_infI::update_prob(double t) {
  prob = constants.get_prob("PROB_NON_INVASION_INVASIVE") * pop.get_pop("INFANTS_INF_INVASIVE");
  return prob;
}

void EventI_noninv_infI::execute_event() {
  pop.move_pop("INFANTS_INF_INVASIVE", "INFANTS_CARRIERS_INVASIVE");
}

string EventI_noninv_infI::description() {
  return "Infant infected becoming carrier of an invasive strain";
}
