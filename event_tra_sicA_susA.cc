#include "event_tra_sicA_susA.h"

using namespace std;

double Event_tra_sicA_susA::update_prob(double t, Population& pop) {
  prob = pop.get_pop(constants.get_int("ADULT_SUSC")) * pop.get_pop(constants.get_int("ADULT_SICK")) * constants.get_prob("PROB_TRA_SICA_SUSA");
  //if (prob > 1) prob = 1.;
  return prob;
}

void Event_tra_sicA_susA::execute_event(Population& pop) {
  pop.move_pop(constants.get_int("ADULT_SUSC"), constants.get_int("ADULT_CARRIERS"));
}
