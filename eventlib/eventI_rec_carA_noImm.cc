#include "eventI_rec_carA_noImm.h"

using namespace std;

double EventI_rec_carA_noImm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARA_NOIMM") * pop.get_pop("ADULT_CARRIERS_INVASIVE");
  return prob;
}

void EventI_rec_carA_noImm::execute_event() {
  pop.move_pop("ADULT_CARRIERS_INVASIVE", "ADULT_SUSC");
}

string EventI_rec_carA_noImm::description() {
  return "Adult carrier losing carriage of invasive strain and becoming susceptible";
}
