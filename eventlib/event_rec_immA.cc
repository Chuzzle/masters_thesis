#include "event_rec_immA.h"

using namespace std;

double Event_rec_immA::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_IMMA") * pop.get_pop("ADULT_IMMUNE");
  return prob;
}

void Event_rec_immA::execute_event() {
  pop.move_pop("ADULT_IMMUNE", "ADULT_SUSC");
}

string Event_rec_immA::description() {
  return "Immune adult losing immunity and becoming susceptible";
}
