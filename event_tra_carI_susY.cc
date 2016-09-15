#include "event_tra_carI_susY.h"

using namespace std;

double Event_tra_carI_susY::update_prob() {
  prob = constants.get_prob("PROB_TRA_CARA_SUSA") * pop.get_pop("INFANTS_CARRIERS") * pop.get_pop("YOUNG_SUSC");
  return prob;
}

void Event_tra_carI_susY::execute_event {
  pop.move_pop("YOUNG_SUSC", "YOUNG_CARRIERS");
}
