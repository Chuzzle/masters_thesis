#include "eventI_inv_infA.h"

using namespace std;

double EventI_inv_infA::update_prob(double t) {
  prob = constants.get_prob("PROB_INVASION_INVASIVE") * pop.get_pop("ADULT_INF_INVASIVE");
  return prob;
}

void EventI_inv_infA::execute_event() {
  pop.move_pop("ADULT_INF_INVASIVE", "ADULT_SICK_INVASIVE");
}

string EventI_inv_infA::description() {
  return "Invasive disease of an invasive strain on an infected adult";
}
