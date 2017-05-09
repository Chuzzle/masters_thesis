#include "event_death_immA.h"

using namespace std;

double Event_death_immA::update_prob(double t) {
  prob = constants.get_prob("PROB_DEATH_AGE") * pop.get_pop("ADULT_IMMUNE");
  return prob;
}

void Event_death_immA::execute_event() {
  pop.decrease_pop("ADULT_IMMUNE");
}

string Event_death_immA::description() {
  return "Death of an adult immune";
}
