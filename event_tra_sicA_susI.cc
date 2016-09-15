#include "event_tra_sicA_susI.h"

using namespace std;

double Event_tra_sicA_susI::update_prob() {
  prob = constants.get_prob("PROB_TRA_SICA_SUSA") * pop.get_pop("ADULT_SICK") * pop.get_pop("INFANTS_SUSC");
  return prob;
}

void Event_tra_sicA_susI::execute_event() {
  pop.move_pop("INFANTS_SUSC", "INFANTS_SICK");
}
