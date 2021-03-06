#include "event_rec_carA_imm.h"

using namespace std;

double Event_rec_carA_imm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARA_IMM") * pop.get_pop("ADULT_CARRIERS");
  return prob;
}

void Event_rec_carA_imm::execute_event() {
  pop.move_pop("ADULT_CARRIERS", "ADULT_IMMUNE");
}

string Event_rec_carA_imm::description() {
  return "Adult carrier becoming immune and losing carriage";
}
