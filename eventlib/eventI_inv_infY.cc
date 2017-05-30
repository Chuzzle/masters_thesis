#include "eventI_inv_infY.h"

using namespace std;

double EventI_inv_infY::update_prob(double t) {
  prob = constants.get_prob("PROB_INVASION_INVASIVE") * pop.get_pop("YOUNG_INF_INVASIVE");
  return prob;
}

void EventI_inv_infY::execute_event() {
  pop.move_pop("YOUNG_INF_INVASIVE", "YOUNG_SICK_INVASIVE");
}

string EventI_inv_infY::description() {
  return "Invasive disease of an invasive strain of an infected young";
}
