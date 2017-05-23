#include "eventI_rec_carY_noImm.h"

using namespace std;

double EventI_rec_carY_noImm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARY_NOIMM") * pop.get_pop("YOUNG_CARRIERS_INVASIVE");
  return prob;
}

void EventI_rec_carY_noImm::execute_event() {
  pop.move_pop("YOUNG_CARRIERS_INVASIVE", "YOUNG_SUSC");
}

string EventI_rec_carY_noImm::description() {
  return "Young carrier losing carriage of invasive strain without becoming immune";
}
