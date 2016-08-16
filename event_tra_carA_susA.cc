#include "event_tra_carA_susA.h"

using namespace std;

double Event_tra_carA_susA::update_prob(double t, Population& pop) {
  prob = constants.get_prob("PROB_TRA_CARA_SUSA") * pop.get_pop("ADULT_SUSC") * pop.get_pop("ADULT_CARRIERS");
  return prob;
}

void Event_tra_carA_susA::execute_event(Population& pop) {
  pop.move_pop("ADULT_SUSC", "ADULT_CARRIERS");
}
