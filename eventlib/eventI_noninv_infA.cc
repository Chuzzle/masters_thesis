#include "eventI_noninv_infA.h"

using namespace std;

double EventI_noninv_infA::update_prob(double t) {
  prob = constants.get_prob("PROB_NON_INVASION_INVASIVE") * pop.get_pop("ADULT_INF_INVASIVE");
  return prob;
}

void EventI_noninv_infA::execute_event() {
  pop.move_pop("ADULT_INF_INVASIVE", "ADULT_CARRIERS_INVASIVE");
}

string EventI_noninv_infA::description() {
  return "Infected adult becoming carrier of an invasive strain";
}
