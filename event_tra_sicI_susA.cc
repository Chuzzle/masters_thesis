#include "event_tra_sicI_susA.h"

using namespace std;

double Event_tra_sicI_susA::update_prob() {
  prob = constants.get_prob("PROB_TRA_SICA_SUSA") * pop.get_pop("ADULT_SUSC") * pop.get_pop("INFANTS_SICK");
  return prob;
}

void Event_tra_sicI_susA::execute_event() {
  pop.move_pop("ADULT_SUSC", "ADULT_SICK");
}
