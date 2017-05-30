#include "eventI_rec_carA_immPerA.h"

using namespace std;

double EventI_rec_carA_immPerA::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARA_IMM_PER") * pop.get_pop("ADULT_CARRIERS_INVASIVE");
  return prob;
}

void EventI_rec_carA_immPerA::execute_event() {
  pop.move_pop("ADULT_CARRIERS_INVASIVE", "ADULT_IMMUNE_PER");
}

string EventI_rec_carA_immPerA::description() {
  return "Adult carrier of an invasive strain becoming permanently immune and losing carriage";
}
