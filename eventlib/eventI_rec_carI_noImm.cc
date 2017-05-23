#include "eventI_rec_carI_noImm.h"

using namespace std;

double EventI_rec_carI_noImm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARI_NOIMM") * pop.get_pop("INFANTS_CARRIERS_INVASIVE");
  return prob;
}

void EventI_rec_carI_noImm::execute_event() {
  pop.move_pop("INFANTS_CARRIERS_INVASIVE", "INFANTS_SUSC");
}

string EventI_rec_carI_noImm::description() {
  return "Infant carrier losing carriage of invasive strain and becoming susceptible";
}
