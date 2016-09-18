#include "event_tra_sicA1_susA2.h"

using namespace std;

double Event_tra_sicA1_susA2::update_prob(double t) {
  if (constants.is_encountered()) {
    prob = pop.get_pop("ADULT_SICK") * pop_2.get_pop("ADULT_SUSC") * constants.get_prob("PROB_TRA_SICA_SUSA");
  } else {
    prob = 0;
  }
  return prob;
}

void Event_tra_sicA1_susA2::execute_event() {
  pop_2.move_pop("ADULT_SUSC", "ADULT_SICK");
}
