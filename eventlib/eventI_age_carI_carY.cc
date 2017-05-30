#include "eventI_age_carI_carY.h"

using namespace std;

double EventI_age_carI_carY::update_prob(double t) {
  prob = constants.get_prob("PROB_AGING_INF_YOU")*pop.get_pop("INFANTS_CARRIERS_INVASIVE");
  return prob;
}

void EventI_age_carI_carY::execute_event() {
  pop.move_pop("INFANTS_CARRIERS_INVASIVE", "YOUNG_CARRIERS_INVASIVE");
}

string EventI_age_carI_carY::description() {
  return "Infant carrier of invasive strain aging to young carrier of invasive strain";
}
