#include "event_tra_sicA_susA.h"

using namespace std;

double Event_tra_sicA_susA::update_prob(double t, Population& pop) {
  prob = pop.get_pop(ADULT_SUSC) * pop.get_pop(ADULT_SICK) * PROB_TRA_SICA_SUSA;
  if (prob > 1) prob = 1.;
  return prob;
}

void Event_tra_sicA_susA::execute_event(Population& pop) {
  pop.move_pop(ADULT_SUSC, ADULT_SICK);
}
