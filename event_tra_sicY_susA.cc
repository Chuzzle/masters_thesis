#include "event_tra_sicY_susA.h"

using namespace std;

double Event_tra_sicY_susA::update_prob() {
  prob = constants.get_prob("PROB_TRA_SICA_SUSA") * pop.get_pop("YOUNG_SICK") * pop.get_pop("ADULT_SUSC");
  return prob;
}

void Event_tra_sicY_susA::execute_event() {
  pop.move_pop("ADULT_SUSC", "ADULT_SICK");
}
