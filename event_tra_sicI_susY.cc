#include "event_tra_sicI_susY.h"

double Event_tra_sicI_susY::update_prob() {
  prob = constants.get_prob("PROB_TRA_SICA_SUSA")*pop.get_pop("INFANTS_SICK")*pop.get_pop("YOUNG_SUSC");
  return prob;
}

void Event_tra_sicI_susY::execute_event() {
  pop.move_pop("YOUNG_SUSC", "YOUNG_SICK");
}
