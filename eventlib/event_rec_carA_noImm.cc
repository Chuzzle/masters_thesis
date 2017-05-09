#include "event_rec_carA_noImm.h"

using namespace std;

double Event_rec_carA_noImm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARA_NOIMM") * pop.get_pop("ADULT_CARRIERS");
  return prob;
}

void Event_rec_carA_noImm::execute_event() {
  pop.move_pop("ADULT_CARRIERS", "ADULT_SUSC");
}

string Event_rec_carA_noImm::description() {
  return "Adult carrier losing carriage and becoming susceptible";
}
