#include "event_age_carY_carA.h"

using namespace std;

double Event_age_carY_carA::update_prob(double t) {
  prob = constants.get_prob("PROB_AGING_YOUNG_ADULT") * pop.get_pop("YOUNG_CARRIERS");
  return prob;
}

void Event_age_carY_carA::execute_event() {
  pop.move_pop("YOUNG_CARRIERS", "ADULT_CARRIERS");
}

string Event_age_carY_carA::description() {
  return "Young carrier aging to adult carrier";
}
