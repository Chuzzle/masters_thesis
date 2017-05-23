#include "eventI_death_sicA.h"

using namespace std;

double EventI_death_sicA::update_prob(double t) {
  prob = constants.get_prob("FATALITY")*pop.get_pop("ADULT_SICK_INVASIVE");
  return prob;
}

void EventI_death_sicA::execute_event() {
  pop.decrease_pop("ADULT_SICK_INVASIVE");
}

string EventI_death_sicA::description() {
  return "Death of a sick adult of the invasive strain";
}
