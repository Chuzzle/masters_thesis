#include "event_tra_carA_susY.h"

using namespace std;

double event_tra_carA_susY::update_prob() {
  prob = constants.get_prob("PROB_TRA_CARA_SUSA") * pop.get_pop("ADULT_CARRIERS") * pop.get_pop("YOUNG_SUSC");
  return prob;
}

void Event_tra_carA_susY::execute_event() {
  pop.move_pop("YOUNG_SUSC", "YOUNG_CARRIERS");
}
