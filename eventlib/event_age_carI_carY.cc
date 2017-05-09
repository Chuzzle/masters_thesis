#include "event_age_carI_carY.h"

using namespace std;

double Event_age_carI_carY::update_prob(double t) {
  prob = constants.get_prob("PROB_AGING_INF_YOU")*pop.get_pop("INFANTS_CARRIERS");
  return prob;
}

void Event_age_carI_carY::execute_event() {
  pop.move_pop("INFANTS_CARRIERS", "YOUNG_CARRIERS");
}

string Event_age_carI_carY::description() {
  return "Infant carrier aging to young carrier";
}
