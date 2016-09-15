#include "event_tra_carA_susI.h"

using namespace std;

double Event_tra_carA_susI::update_prob() {
  prob = constants.get_prob("PROB_TRA_CARA_SUSA") * pop.get_pop("ADULT_CARRIERS") * pop.get_pop("INFANTS_SUSC");
  return prob;
}

void Event_tra_carA_susI::execute_event() {
  pop.move_pop("INFANTS_SUSC", "INFANTS_CARRIERS");
}
