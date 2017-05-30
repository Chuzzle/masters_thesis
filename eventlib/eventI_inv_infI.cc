#include "eventI_inv_infI.h"

using namespace std;

double EventI_inv_infI::update_prob(double t) {
  prob = constants.get_prob("PROB_INVASION_INVASIVE") * pop.get_pop("INFANTS_INF_INVASIVE");
  return prob;
}

void EventI_inv_infI::execute_event() {
  pop.move_pop("INFANTS_INF_INVASIVE", "INFANTS_SICK_INVASIVE");
}

string EventI_inv_infI::description() {
  return "Invasive disease of an invasive strain of an infected infant";
}
