#include "eventI_death_carA.h"

using namespace std;

double EventI_death_carA::update_prob(double t) {
  prob = constants.get_prob("PROB_DEATH_AGE") * pop.get_pop("ADULT_CARRIERS_INVASIVE");
  return prob;
}

void EventI_death_carA::execute_event() {
  pop.decrease_pop("ADULT_CARRIERS_INVASIVE");
}

string EventI_death_carA::description() {
  return "Death of an adult carrier of invasive strain";
}
