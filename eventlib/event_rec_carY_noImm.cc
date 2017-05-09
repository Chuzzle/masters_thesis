#include "event_rec_carY_noImm.h"

using namespace std;

double Event_rec_carY_noImm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARY_NOIMM") * pop.get_pop("YOUNG_CARRIERS");
  return prob;
}

void Event_rec_carY_noImm::execute_event() {
  pop.move_pop("YOUNG_CARRIERS", "YOUNG_SUSC");
}

string Event_rec_carY_noImm::description() {
  return "Young carrier losing carriage without becoming immune";
}
