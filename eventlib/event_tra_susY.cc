#include "event_tra_susY.h"

using namespace std;

double Event_tra_susY::update_prob(double t) {
  prob = constants.get_prob("PROB_TRANSMISSION") * pop.get_infectuous() * pop.get_pop("YOUNG_SUSC");
  return prob;
}

void Event_tra_susY::execute_event() {
  pop.move_pop("YOUNG_SUSC", "YOUNG_INF");
}
