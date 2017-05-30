#include "eventI_noninv_infY.h"

using namespace std;

double EventI_noninv_infY::update_prob(double t) {
  prob = constants.get_prob("PROB_NON_INVASION_INVASIVE") * pop.get_pop("YOUNG_INF_INVASIVE");
  return prob;
}

void EventI_noninv_infY::execute_event() {
  pop.move_pop("YOUNG_INF_INVASIVE", "YOUNG_CARRIERS_INVASIVE");
}

string EventI_noninv_infY::description() {
  return "Young infected becoming carrier of an invasive strain";
}
