#include "event_rec_immY.h"

using namespace std;

double Event_rec_immY::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_IMMY") * pop.get_pop("YOUNG_IMMUNE");
  return prob;
}

void Event_rec_immY::execute_event() {
  pop.move_pop("YOUNG_IMMUNE", "YOUNG_SUSC");
}

string Event_rec_immY::description() {
  return "Immune young losing immunity and becoming susceptible";
}
