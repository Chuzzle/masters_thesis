#include "eventI_rec_carY_imm.h"

using namespace std;

double EventI_rec_carY_imm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARY_IMM") * pop.get_pop("YOUNG_CARRIERS_INVASIVE");
  return prob;
}

void EventI_rec_carY_imm::execute_event() {
  pop.move_pop("YOUNG_CARRIERS_INVASIVE", "YOUNG_IMMUNE");
}

string EventI_rec_carY_imm::description() {
  return "Young carrier becoming immune and losing carriage of invasive strain";
}
