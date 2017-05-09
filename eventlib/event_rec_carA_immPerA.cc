#include "event_rec_carA_immPerA.h"

using namespace std;

double Event_rec_carA_immPerA::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARA_IMM_PER") * pop.get_pop("ADULT_CARRIERS");
  return prob;
}

void Event_rec_carA_immPerA::execute_event() {
  pop.move_pop("ADULT_CARRIERS", "ADULT_IMMUNE_PER");
}

string Event_rec_carA_immPerA::description() {
  return "Adult carrier becoming permanently immune and losing carriage";
}
