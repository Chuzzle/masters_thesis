#include "event_tra_carI_susA.h"

using namespace std;

double Event_tra_carI_susA::update_prob() {
  prob = constants.get_prob("PROB_TRA_CARA_SUSA") * pop.get_pop("INFANTS_CARRIERS") * pop.get_pop("ADULT_SUSC");
  return prob;
}

virtual Event_tra_carI_susA::execute_event() {
  pop.move_pop("ADULT_SUSC", "ADULT_CARRIERS");
}
