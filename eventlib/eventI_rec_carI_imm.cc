#include "eventI_rec_carI_imm.h"

using namespace std;

double EventI_rec_carI_imm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARI_IMM") * pop.get_pop("INFANTS_CARRIERS_INVASIVE");
  return prob;
}

void EventI_rec_carI_imm::execute_event() {
  pop.move_pop("INFANTS_CARRIERS_INVASIVE", "INFANTS_IMMUNE");
}

string EventI_rec_carI_imm::description() {
  return "Infant carrier becoming immune and losing carriage of invasive strain";
}
