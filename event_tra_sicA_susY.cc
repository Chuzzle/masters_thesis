#include "event_tra_sicA_susY.h"

using namespace std;

double Event_tra_sicA_susY::update_prob() {
  prob = constants.get_prob("PROB_TRA_SICA_SUSA") * pop.get_pop("ADULT_SICK") * pop.get_pop("YOUNG_SUSC");
  return prob;
}

void Event_tra_sicA_susY::execute_event() {
  pop.move_pop("YOUNG_SUSC", "YOUNG_SICK");
}
