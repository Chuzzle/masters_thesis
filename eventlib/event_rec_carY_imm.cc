#include "event_rec_carY_imm.h"

using namespace std;

double Event_rec_carY_imm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARY_IMM") * pop.get_pop("YOUNG_CARRIERS");
  return prob;
}

void Event_rec_carY_imm::execute_event() {
  pop.move_pop("YOUNG_CARRIERS", "YOUNG_IMMUNE");
}

string Event_rec_carY_imm::description() {
  return "Young carrier becoming immune and losing carriage";
}
