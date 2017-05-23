#include "eventI_rec_carA_imm.h"

using namespace std;

double EventI_rec_carA_imm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARA_IMM") * pop.get_pop("ADULT_CARRIERS_INVASIVE");
  return prob;
}

void EventI_rec_carA_imm::execute_event() {
  pop.move_pop("ADULT_CARRIERS_INVASIVE", "ADULT_IMMUNE");
}

string EventI_rec_carA_imm::description() {
  return "Adult carrier becoming immune and losing carriage of invasive strain";
}
