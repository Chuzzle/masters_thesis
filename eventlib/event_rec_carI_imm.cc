#include "event_rec_carI_imm.h"

using namespace std;

double Event_rec_carI_imm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARI_IMM") * pop.get_pop("INFANTS_CARRIERS");
  return prob;
}

void Event_rec_carI_imm::execute_event() {
  pop.move_pop("INFANTS_CARRIERS", "INFANTS_IMMUNE");
}

string Event_rec_carI_imm::description() {
  return "Infant carrier becoming immune and losing carriage";
}
