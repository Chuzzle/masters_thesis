#include "eventI_age_carY_carA.h"

using namespace std;

double EventI_age_carY_carA::update_prob(double t) {
  prob = constants.get_prob("PROB_AGING_YOUNG_ADULT") * pop.get_pop("YOUNG_CARRIERS_INVASIVE");
  return prob;
}

void EventI_age_carY_carA::execute_event() {
  pop.move_pop("YOUNG_CARRIERS_INVASIVE", "ADULT_CARRIERS_INVASIVE");
}

string EventI_age_carY_carA::description() {
  return "Young carrier of invasive strain aging to adult carrier of invasive strain";
}
